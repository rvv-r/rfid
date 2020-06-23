#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9           // Configurable, see typical pin layout above
#define SS_PIN          10          // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

MFRC522::MIFARE_Key key1A = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};
MFRC522::MIFARE_Key key1B = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};

char userInput;

/**
   Initialize.
*/
void setup() {
  Serial.begin(9600); // Initialize serial communications with the PC
  while (!Serial);    // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  SPI.begin();        // Init SPI bus
  mfrc522.PCD_Init(); // Init MFRC522 card

  Serial.println(F("Using for key A :")); dump_byte_array(key1A.keyByte, MFRC522::MF_KEY_SIZE); Serial.println();

  Serial.println(F("Using for key B :")); dump_byte_array(key1B.keyByte, MFRC522::MF_KEY_SIZE); Serial.println();
}

/**
   Main loop.
*/
void loop() {

  if(Serial.available()>0){

    userInput=Serial.read(); Serial.println(userInput);

    // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
    if ( ! mfrc522.PICC_IsNewCardPresent())
      return;

    // Select one of the cards
    if ( ! mfrc522.PICC_ReadCardSerial())
      return;

    if (userInput=='a'){
      Serial.println(F("Card UID:"));
      dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
    }
    if (userInput=='b'){
      readBlock(1,4);
      }

    else if (userInput=='c'){
      readBlock(2,9);
    }
  }
}

/**
   Helper routine to dump a byte array as hex values to Serial.
*/
void dump_byte_array(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? "0" : "");
    Serial.print(buffer[i], HEX);
  }
}

void readBlock( byte sector,
                byte blockAddr) {

  MFRC522::PICC_Type piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);

  byte trailerBlock   = ((sector + 1) * 4) - 1;
  MFRC522::StatusCode status;
  byte buffer[18];
  byte size = sizeof(buffer);

  // Serial.println(F("Authenticating using key A..."));
  status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key1A, &(mfrc522.uid)); // Authenticate using key A
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("PCD_Authenticate() failed for keyA: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }

  //  Serial.println(F("Authenticating using key B..."));
  status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B, trailerBlock, &key1B, &(mfrc522.uid)); // Authenticate using key B
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("PCD_Authenticate() failed for keyB: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }

  // Show the whole sector as it currently is
  // Serial.print(F("Current data in sector ")); Serial.print(sector); Serial.println(F(" : "));
  // mfrc522.PICC_DumpMifareClassicSectorToSerial(&(mfrc522.uid), &key1A, sector);
  // Serial.println();

  Serial.print(F("Lecture bloc ")); Serial.print(blockAddr); Serial.println(F(" : ")); // Read data from the block
  status = (MFRC522::StatusCode) mfrc522.MIFARE_Read(blockAddr, buffer, &size);
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("MIFARE_Read() failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
  }
  dump_byte_array(buffer, 16); Serial.println();
  Serial.println();

  // mfrc522.PICC_HaltA(); // Halt PICC
  mfrc522.PCD_StopCrypto1(); // Stop encryption on PCD
}
