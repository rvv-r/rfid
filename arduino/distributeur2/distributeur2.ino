#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9           // Configurable, see typical pin layout above
#define SS_PIN          10          // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

MFRC522::MIFARE_Key key = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};

/**
 * Initialize.
 */
void setup() {
    Serial.begin(9600);	// Initialize serial communications with the PC
    while (!Serial);    // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
    SPI.begin();		// Init SPI bus
    mfrc522.PCD_Init();	// Init MFRC522 card

    // Serial.print(F("Using key (for A and B):")); dump_byte_array(key.keyByte, MFRC522::MF_KEY_SIZE); Serial.println();
}

/**
 * Main loop.
 */
void loop() {
    // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
    if ( ! mfrc522.PICC_IsNewCardPresent())
        return;

    // Select one of the cards
    if ( ! mfrc522.PICC_ReadCardSerial())
        return;

    // In this sample we use the second sector,
    // that is: sector #1, covering block #4 up to and including block #7
    byte sector         = 2;
    byte ValueBlock    = 8;
    byte trailerBlock   = 11;
    int32_t itemPrice = 1; // Evian = 1€
    MFRC522::StatusCode status;
    byte buffer[18];
    byte size = sizeof(buffer);
    int32_t value;

    // Authenticate using key A
    status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));
    if (status != MFRC522::STATUS_OK) {
        return;
    }

    status = mfrc522.MIFARE_GetValue(ValueBlock, &value);
    Serial.print("Solde : "); Serial.print(value); Serial.println("€");

    // Read the sector trailer as it is currently stored on the PICC
    // Serial.println(F("Reading sector trailer..."));
    status = mfrc522.MIFARE_Read(trailerBlock, buffer, &size);
    if (status != MFRC522::STATUS_OK) {
        return;
    }

    // Authenticate using key B
    status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B, trailerBlock, &key, &(mfrc522.uid));
    if (status != MFRC522::STATUS_OK) {
        return;
    }

    // Decrement itemPrice from the value of ValueBlock and store the result in ValueBlock.
    if (value>=0 && value>itemPrice){
      Serial.print("Achat boisson à "); Serial.print(itemPrice); Serial.println("€");
      Serial.println("Obtenu : Coca");
      Serial.print(F("Calcul du nouveau solde : ")); Serial.print(value-itemPrice); Serial.println("€");
      Serial.println();

      delay(200);

      status = mfrc522.MIFARE_Decrement(ValueBlock, itemPrice);
      if (status != MFRC522::STATUS_OK) {
          return;
      }

      status = mfrc522.MIFARE_Transfer(ValueBlock);
      if (status != MFRC522::STATUS_OK) {
          return;
      }

      // Show the new value of ValueBlock
      status = mfrc522.MIFARE_GetValue(ValueBlock, &value);
      Serial.print(F("Nouveau solde : ")); Serial.print(value); Serial.println("€");
      if (status != MFRC522::STATUS_OK) {
          return;
      }
    }

    else{
      Serial.println("Solde insuffisant");
      Serial.println();
    }

    // Dump the sector data
    // Serial.println();
    // mfrc522.PICC_DumpMifareClassicSectorToSerial(&(mfrc522.uid), &key, sector);
    // Serial.println();

    // Halt PICC
    mfrc522.PICC_HaltA();
    // Stop encryption on PCD
    mfrc522.PCD_StopCrypto1();
}

/**
 * Helper routine to dump a byte array as hex values to Serial.
 */
void dump_byte_array(byte *buffer, byte bufferSize) {
    for (byte i = 0; i < bufferSize; i++) {
        Serial.print(buffer[i] < 0x10 ? " 0" : " ");
        Serial.print(buffer[i], HEX);
    }
}

/**
 * Ensure that a given block is formatted as a Value Block.
 */
void formatValueBlock(byte blockAddr) {
    byte buffer[18];
    byte size = sizeof(buffer);
    MFRC522::StatusCode status;

    Serial.print(F("Lecture bloc ")); Serial.println(blockAddr);
    status = mfrc522.MIFARE_Read(blockAddr, buffer, &size);
    if (status != MFRC522::STATUS_OK) {
        Serial.print(F("MIFARE_Read() failed: "));
        Serial.println(mfrc522.GetStatusCodeName(status));
        return;
    }

    if (    (buffer[0] == (byte)~buffer[4])
        &&  (buffer[1] == (byte)~buffer[5])
        &&  (buffer[2] == (byte)~buffer[6])
        &&  (buffer[3] == (byte)~buffer[7])

        &&  (buffer[0] == buffer[8])
        &&  (buffer[1] == buffer[9])
        &&  (buffer[2] == buffer[10])
        &&  (buffer[3] == buffer[11])

        &&  (buffer[12] == (byte)~buffer[13])
        &&  (buffer[12] ==        buffer[14])
        &&  (buffer[12] == (byte)~buffer[15])) {
        Serial.println(F("Block has correct Value Block format."));
    }
    else {
        Serial.println(F("Formatting as Value Block..."));
        byte valueBlock[] = {
            0, 0, 0, 0,
            255, 255, 255, 255,
            0, 0, 0, 0,
            blockAddr, ~blockAddr, blockAddr, ~blockAddr };
        status = mfrc522.MIFARE_Write(blockAddr, valueBlock, 16);
        if (status != MFRC522::STATUS_OK) {
            Serial.print(F("MIFARE_Write() failed: "));
            Serial.println(mfrc522.GetStatusCodeName(status));
        }
    }
}
