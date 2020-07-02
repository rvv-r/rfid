/**
 * Ce programme est basé sur l'exemple ReadAndWrite.ino de la librairie MFRC522
 * ----------------------------------------------------------------------------
 * This is a MFRC522 library example; see https://github.com/miguelbalboa/rfid
 * for further details and other examples.
 *
 * NOTE: The library file MFRC522.h has a lot of useful info. Please read it.
 *
 * Released into the public domain.
 * ----------------------------------------------------------------------------
 *
 * Typical pin layout used:
 * -----------------------------------------------------------------------------------------
 *             MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
 *             Reader/PCD   Uno/101       Mega      Nano v3    Leonardo/Micro   Pro Micro
 * Signal      Pin          Pin           Pin       Pin        Pin              Pin
 * -----------------------------------------------------------------------------------------
 * RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST
 * SPI SS      SDA(SS)      10            53        D10        10               10
 * SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
 * SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
 * SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15
 *
 */

#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9
#define SS_PIN          10

MFRC522 mfrc522(SS_PIN, RST_PIN); // Créé une instance de MFRC522

#define NEW_UID {0x09, 0xCD, 0xF0, 0x5D}

MFRC522::MIFARE_Key key = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};

MFRC522::MIFARE_Key key0A =   {keyByte: {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5}};  MFRC522::MIFARE_Key key0B = {keyByte: {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5}};
MFRC522::MIFARE_Key key1A =   {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};  MFRC522::MIFARE_Key key1B = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};
MFRC522::MIFARE_Key key2A =   {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};  MFRC522::MIFARE_Key key2B = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};
MFRC522::MIFARE_Key key3A =   {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};  MFRC522::MIFARE_Key key3B = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};
MFRC522::MIFARE_Key key4A =   {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};  MFRC522::MIFARE_Key key4B = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};
MFRC522::MIFARE_Key key5A =   {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};  MFRC522::MIFARE_Key key5B = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};
MFRC522::MIFARE_Key key6A =   {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};  MFRC522::MIFARE_Key key6B = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};
MFRC522::MIFARE_Key key7A =   {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};  MFRC522::MIFARE_Key key7B = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};
MFRC522::MIFARE_Key key8A =   {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};  MFRC522::MIFARE_Key key8B = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};
MFRC522::MIFARE_Key key9A =   {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};  MFRC522::MIFARE_Key key9B = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};
MFRC522::MIFARE_Key key10A =  {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}}; MFRC522::MIFARE_Key key10B = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};
MFRC522::MIFARE_Key key11A =  {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}}; MFRC522::MIFARE_Key key11B = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};
MFRC522::MIFARE_Key key12A =  {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}}; MFRC522::MIFARE_Key key12B = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};
MFRC522::MIFARE_Key key13A =  {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}}; MFRC522::MIFARE_Key key13B = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};
MFRC522::MIFARE_Key key14A =  {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}}; MFRC522::MIFARE_Key key14B = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};
MFRC522::MIFARE_Key key15A =  {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}}; MFRC522::MIFARE_Key key15B = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};

char userInput;

byte sector1 = 1;
byte sector2 = 2;
byte sector3 = 3;
byte sector4 = 4;
byte sector5 = 5;
byte sector6 = 6;
byte sector7 = 7;
byte sector8 = 8;
byte sector9 = 9;

byte blockAddr1 = 4;
byte blockAddr2 = 8;
byte blockAddr3 = 12;
byte blockAddr4 = 16;
byte blockAddr5 = 20;
byte blockAddr6 = 24;
byte blockAddr7 = 28;
byte blockAddr8 = 32;
byte blockAddr9 = 36;

byte dataBlockporteNiveau1[]    = {
    0x72, 0x65, 0x74, 0x72, //  r, e, t, r
    0x6f, 0x50, 0x6f, 0x72, //  o, P, o, r,
    0x74, 0x65, 0x32, 0x00, //  t, e, 1, 0,
    0x00, 0x00, 0x00, 0x00  //  0, 0, 0, 0
};
byte dataBlockporteNiveau2[]    = {
    0x72, 0x65, 0x74, 0x72, //  r, e, t, r
    0x6f, 0x50, 0x6f, 0x72, //  o, P, o, r,
    0x74, 0x65, 0x33, 0x00, //  t, e, 2, 0,
    0x00, 0x00, 0x00, 0x00  //  0, 0, 0, 0
};
byte dataBlockporteNiveau3[]    = {
    0x72, 0x65, 0x74, 0x72, //  r, e, t, r
    0x6f, 0x50, 0x6f, 0x72, //  o, P, o, r,
    0x74, 0x65, 0x34, 0x00, //  t, e, 3, 0,
    0x00, 0x00, 0x00, 0x00  //  0, 0, 0, 0
};

byte ValueBlockhotelNiveau1 = 2;

byte dataBlockhotelNiveau2[]    = {
    0x02, 0x37, 0x00, 0x00,  //  chambre 237
    0x00, 0x00, 0x00, 0x00,  //  0, 0, 0, 0
    0x00, 0x00, 0x00, 0x00,  //  0, 0, 0, 0
    0x00, 0x00, 0x00, 0x00  //  0, 0, 0, 0
};
byte dataBlockhotelNiveau3[]    = {
    0x16, 0x04, 0x19, 0x98,  //  date : 16/04/1998
    0x00, 0x00, 0x00, 0x00,  //  0, 0, 0, 0
    0x00, 0x00, 0x00, 0x00,  //  0, 0, 0, 0
    0x00, 0x00, 0x00, 0x00  //  0, 0, 0, 0
};

byte trailerBlock1   = 7;
byte trailerBlock2   = 11;
byte trailerBlock3   = 15;
byte trailerBlock4   = 19;
byte trailerBlock5   = 23;
byte trailerBlock6   = 27;
byte trailerBlock7   = 31;
byte trailerBlock8   = 35;
byte trailerBlock9   = 39;

byte trailerBuffer[] = {
    255, 255, 255, 255, 255, 255,       // Keep default key A
    0, 0, 0,
    0,
    255, 255, 255, 255, 255, 255};      // Keep default key B

MFRC522::PICC_Type piccType;
MFRC522::StatusCode status;
byte buffer[18];
byte size = sizeof(buffer);

byte count = 0;

int32_t value;

/**
 * Initialisation
 */
void setup() {
    Serial.begin(9600); // Initialise les communications séries avec le PC
    while (!Serial);   // Ne fais rien si aucun port série n'est ouvert
    SPI.begin();        // Initialise le bus SPI
    mfrc522.PCD_Init(); // Initialise la carte MFRC522
}

/**
 *   Boucle principale
 */
void loop() {


  if(Serial.available()>0){

    userInput=Serial.read(); Serial.println(userInput);

    if (userInput == 'a'){ // porte Niveau 1 (Secteur 0)
      if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial() ) {
        delay(50);
        return;
      }

      byte newUid[] = NEW_UID;
      if ( mfrc522.MIFARE_SetUid(newUid, (byte)4, true) ) {
        Serial.println(F("Wrote new UID to card."));
      }

      mfrc522.PICC_HaltA(); // Halt PICC and re-select it so DumpToSerial doesn't get confused
      if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial() ) {
        return;
      }

      Serial.println(F("New UID and contents:"));
      mfrc522.PICC_DumpToSerial(&(mfrc522.uid)); // Dump the new memory contents

      delay(2000);
    }

////////////////////////////////////////////////////////////////////////////////////////////

    if (userInput == 'b'){ // porte Niveau 2 (Secteur 1)
      Serial.println("zbeub zbeub");
      if ( ! mfrc522.PICC_IsNewCardPresent()) // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
          return;

      if ( ! mfrc522.PICC_ReadCardSerial()) // Select one of the cards
          return;

      // Show some details of the PICC (that is: the tag/card)
      Serial.print(F("Card UID:")); dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size); Serial.println();
      Serial.print(F("PICC type: ")); piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
      Serial.println(mfrc522.PICC_GetTypeName(piccType));

      // Check for compatibility
      if (    piccType != MFRC522::PICC_TYPE_MIFARE_MINI
          &&  piccType != MFRC522::PICC_TYPE_MIFARE_1K
          &&  piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
          Serial.println(F("This sample only works with MIFARE Classic cards."));
          return;
      }

      Serial.println(F("Authenticating using key A..."));
      status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock1, &key, &(mfrc522.uid)); // Authenticate using key A
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("PCD_Authenticate() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
          return;
      }

      Serial.println(F("Current data in sector 1:"));
      mfrc522.PICC_DumpMifareClassicSectorToSerial(&(mfrc522.uid), &key, sector1); // Show the whole sector 1 as it currently is
      Serial.println();

      Serial.print(F("Reading data from block ")); Serial.print(blockAddr1);
      Serial.println(F(" ..."));
      status = (MFRC522::StatusCode) mfrc522.MIFARE_Read(blockAddr1, buffer, &size); // Read data from the block
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("MIFARE_Read() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
      }

      Serial.print(F("Data in block ")); Serial.print(blockAddr1); Serial.println(F(":"));
      dump_byte_array(buffer, 16); Serial.println(); // Print data from the block in buffer
      Serial.println();

      Serial.println(F("Authenticating again using key B..."));
      status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B, trailerBlock1, &key, &(mfrc522.uid)); // Authenticate using key B
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("PCD_Authenticate() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
          return;
      }

      Serial.print(F("Writing data into block ")); Serial.print(blockAddr1); Serial.println(F(" ..."));
      dump_byte_array(dataBlockporteNiveau1, 16); Serial.println();
      status = (MFRC522::StatusCode) mfrc522.MIFARE_Write(blockAddr1, dataBlockporteNiveau1, 16); // Write data to the block
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("MIFARE_Write() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
      }
      Serial.println();

      Serial.print(F("Reading data from block ")); Serial.print(blockAddr1); Serial.println(F(" ..."));
      status = (MFRC522::StatusCode) mfrc522.MIFARE_Read(blockAddr1, buffer, &size); // Read data from the block (again, should now be what we have written)
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("MIFARE_Read() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
      }
      Serial.print(F("Data in block ")); Serial.print(blockAddr1); Serial.println(F(":"));
      dump_byte_array(buffer, 16); Serial.println(); // Print data from the block in buffer

      // Check that data in block is what we have written  by counting the number of bytes that are equal
      Serial.println(F("Checking result..."));
      count = 0;
      for (byte i = 0; i < 16; i++) {
          if (buffer[i] == dataBlockporteNiveau1[i]) // Compare buffer (= what we've read) with dataBlockporteNiveau1k (= what we've written)
              count++;
      }
      Serial.print(F("Number of bytes that match = ")); Serial.println(count);
      if (count == 16) {
          Serial.println(F("Success :-)"));
      } else {
          Serial.println(F("Failure, no match :-("));
          Serial.println(F("  perhaps the write didn't work properly..."));
      }
      Serial.println();

      Serial.println(F("Current data in sector 1:"));
      mfrc522.PICC_DumpMifareClassicSectorToSerial(&(mfrc522.uid), &key, sector1); // Dump the sector data
      Serial.println();

      mfrc522.PCD_StopCrypto1(); // Stop encryption on PCD
    }

////////////////////////////////////////////////////////////////////////////////////////////

    if (userInput == 'c'){ // porte Niveau 3 (Secteur 2)
      if ( ! mfrc522.PICC_IsNewCardPresent()) // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
          return;
      if ( ! mfrc522.PICC_ReadCardSerial()) // Select one of the cards
          return;

      // Show some details of the PICC (that is: the tag/card)
      Serial.print(F("Card UID:")); dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size); Serial.println();
      Serial.print(F("PICC type: ")); piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
      Serial.println(mfrc522.PICC_GetTypeName(piccType));

      // Check for compatibility
      if (    piccType != MFRC522::PICC_TYPE_MIFARE_MINI
          &&  piccType != MFRC522::PICC_TYPE_MIFARE_1K
          &&  piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
          Serial.println(F("This sample only works with MIFARE Classic cards."));
          return;
      }

      Serial.println(F("Authenticating using key A..."));
      status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock2, &key, &(mfrc522.uid)); // Authenticate using key A
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("PCD_Authenticate() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
          return;
      }

      Serial.println(F("Current data in sector 2:"));
      mfrc522.PICC_DumpMifareClassicSectorToSerial(&(mfrc522.uid), &key, sector2); // Show the whole sector 2 as it currently is
      Serial.println();

      Serial.print(F("Reading data from block ")); Serial.print(blockAddr2);
      Serial.println(F(" ..."));
      status = (MFRC522::StatusCode) mfrc522.MIFARE_Read(blockAddr2, buffer, &size); // Read data from the block
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("MIFARE_Read() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
      }

      Serial.print(F("Data in block ")); Serial.print(blockAddr2); Serial.println(F(":"));
      dump_byte_array(buffer, 16); Serial.println(); // Print data from the block in buffer
      Serial.println();

      Serial.println(F("Authenticating again using key B..."));
      status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B, trailerBlock2, &key, &(mfrc522.uid)); // Authenticate using key B
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("PCD_Authenticate() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
          return;
      }

      Serial.print(F("Writing data into block ")); Serial.print(blockAddr2); Serial.println(F(" ..."));
      dump_byte_array(dataBlockporteNiveau2, 16); Serial.println();
      status = (MFRC522::StatusCode) mfrc522.MIFARE_Write(blockAddr2, dataBlockporteNiveau2, 16); // Write data to the block
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("MIFARE_Write() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
      }
      Serial.println();

      Serial.print(F("Reading data from block ")); Serial.print(blockAddr2); Serial.println(F(" ..."));
      status = (MFRC522::StatusCode) mfrc522.MIFARE_Read(blockAddr2, buffer, &size); // Read data from the block (again, should now be what we have written)
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("MIFARE_Read() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
      }
      Serial.print(F("Data in block ")); Serial.print(blockAddr2); Serial.println(F(":"));
      dump_byte_array(buffer, 16); Serial.println(); // Print data from the block in buffer

      // Check that data in block is what we have written  by counting the number of bytes that are equal
      Serial.println(F("Checking result..."));
      count = 0;
      for (byte i = 0; i < 16; i++) {
          if (buffer[i] == dataBlockporteNiveau2[i]) // Compare buffer (= what we've read) with dataBlockporteNiveau2 (= what we've written)
              count++;
      }
      Serial.print(F("Number of bytes that match = ")); Serial.println(count);
      if (count == 16) {
          Serial.println(F("Success :-)"));
      } else {
          Serial.println(F("Failure, no match :-("));
          Serial.println(F("  perhaps the write didn't work properly..."));
      }
      Serial.println();

      Serial.println(F("Current data in sector 2:"));
      mfrc522.PICC_DumpMifareClassicSectorToSerial(&(mfrc522.uid), &key, sector2); // Dump the sector 2 data
      Serial.println();

      mfrc522.PCD_StopCrypto1(); // Stop encryption on PCD
    }

////////////////////////////////////////////////////////////////////////////////////////////

    if (userInput == 'd'){ // porte Niveau 4 (Secteur 3)
      if ( ! mfrc522.PICC_IsNewCardPresent()) // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
          return;
      if ( ! mfrc522.PICC_ReadCardSerial()) // Select one of the cards
          return;

      // Show some details of the PICC (that is: the tag/card)
      Serial.print(F("Card UID:")); dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size); Serial.println();
      Serial.print(F("PICC type: ")); piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
      Serial.println(mfrc522.PICC_GetTypeName(piccType));

      // Check for compatibility
      if (    piccType != MFRC522::PICC_TYPE_MIFARE_MINI
          &&  piccType != MFRC522::PICC_TYPE_MIFARE_1K
          &&  piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
          Serial.println(F("This sample only works with MIFARE Classic cards."));
          return;
      }

      Serial.println(F("Authenticating using key A..."));
      status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock3, &key, &(mfrc522.uid)); // Authenticate using key A
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("PCD_Authenticate() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
          return;
      }

      Serial.println(F("Current data in sector 3:"));
      mfrc522.PICC_DumpMifareClassicSectorToSerial(&(mfrc522.uid), &key, sector3); // Show the whole sector 3 as it currently is
      Serial.println();

      Serial.print(F("Reading data from block ")); Serial.print(blockAddr3);
      Serial.println(F(" ..."));
      status = (MFRC522::StatusCode) mfrc522.MIFARE_Read(blockAddr3, buffer, &size); // Read data from the block
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("MIFARE_Read() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
      }

      Serial.print(F("Data in block ")); Serial.print(blockAddr3); Serial.println(F(":"));
      dump_byte_array(buffer, 16); Serial.println(); // Print data from the block in buffer
      Serial.println();

      Serial.println(F("Authenticating again using key B..."));
      status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B, trailerBlock3, &key, &(mfrc522.uid)); // Authenticate using key B
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("PCD_Authenticate() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
          return;
      }

      Serial.print(F("Writing data into block ")); Serial.print(blockAddr3); Serial.println(F(" ..."));
      dump_byte_array(dataBlockporteNiveau3, 16); Serial.println();
      status = (MFRC522::StatusCode) mfrc522.MIFARE_Write(blockAddr3, dataBlockporteNiveau3, 16); // Write data to the block
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("MIFARE_Write() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
      }
      Serial.println();

      Serial.print(F("Reading data from block ")); Serial.print(blockAddr3); Serial.println(F(" ..."));
      status = (MFRC522::StatusCode) mfrc522.MIFARE_Read(blockAddr3, buffer, &size); // Read data from the block (again, should now be what we have written)
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("MIFARE_Read() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
      }
      Serial.print(F("Data in block ")); Serial.print(blockAddr3); Serial.println(F(":"));
      dump_byte_array(buffer, 16); Serial.println(); // Print data from the block in buffer

      // Check that data in block is what we have written  by counting the number of bytes that are equal
      Serial.println(F("Checking result..."));
      count = 0;
      for (byte i = 0; i < 16; i++) {
          if (buffer[i] == dataBlockporteNiveau3[i]) // Compare buffer (= what we've read) with dataBlockporteNiveau3 (= what we've written)
              count++;
      }
      Serial.print(F("Number of bytes that match = ")); Serial.println(count);
      if (count == 16) {
          Serial.println(F("Success :-)"));
      } else {
          Serial.println(F("Failure, no match :-("));
          Serial.println(F("  perhaps the write didn't work properly..."));
      }
      Serial.println();

      Serial.println(F("Current data in sector 3:"));
      mfrc522.PICC_DumpMifareClassicSectorToSerial(&(mfrc522.uid), &key, sector3); // Dump the sector 3 data
      Serial.println();

      mfrc522.PCD_StopCrypto1(); // Stop encryption on PCD
    }

////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////     Hôtel     //////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////

    if (userInput == 'e'){ // hôtel Niveau 1 (Secteur 4)
      if ( ! mfrc522.PICC_IsNewCardPresent()) // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
          return;

      if ( ! mfrc522.PICC_ReadCardSerial()) // Select one of the cards
          return;

      // Show some details of the PICC (that is: the tag/card)
      Serial.print(F("Card UID:")); dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size); Serial.println();
      Serial.print(F("PICC type: ")); piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
      Serial.println(mfrc522.PICC_GetTypeName(piccType));

      // Check for compatibility
      if (    piccType != MFRC522::PICC_TYPE_MIFARE_MINI
          &&  piccType != MFRC522::PICC_TYPE_MIFARE_1K
          &&  piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
          Serial.println(F("This sample only works with MIFARE Classic cards."));
          return;
      }

      Serial.println(F("Authenticating using key A..."));
      status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock7, &key, &(mfrc522.uid)); // Authenticate using key A
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("PCD_Authenticate() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
          return;
      }

      Serial.println(F("Current data in sector:"));
      mfrc522.PICC_DumpMifareClassicSectorToSerial(&(mfrc522.uid), &key, sector4); // Show the whole sector 4 as it currently is
      Serial.println();

      // We need a sector trailer that defines blocks 5 and 6 as Value Blocks and enables key B
      // The last block in a sector (block #3 for Mifare Classic 1K) is the Sector Trailer.
      // See http://www.nxp.com/documents/data_sheet/MF1S503x.pdf sections 8.6 and 8.7:
      //      Bytes 0-5:   Key A
      //      Bytes 6-8:   Access Bits
      //      Bytes 9:     User data
      //      Bytes 10-15: Key B (or user data)
      // The access bits are stored in a peculiar fashion.
      // There are four groups:
      //      g[0]    Access bits for block 0 (for sectors 0-31)
      //              or blocks 0-4 (for sectors 32-39)
      //      g[1]    Access bits for block 1 (for sectors 0-31)
      //              or blocks 5-9 (for sectors 32-39)
      //      g[2]    Access bits for block 2 (for sectors 0-31)
      //              or blocks 10-14 (for sectors 32-39)
      //      g[3]    Access bits for the Sector Trailer: block 3 (for sectors 0-31)
      //              or block 15 (for sectors 32-39)
      // Each group has access bits [C1 C2 C3], in this code C1 is MSB and C3 is LSB.
      // Determine the bit pattern needed using MIFARE_SetAccessBits:
      //      g0=0    access bits for block 0 (of this sector) using [0 0 0] = 000b = 0
      //              which means key A|B have r/w for block 0 of this sector
      //              which (in this example) translates to block #4 within sector #1;
      //              this is the transport configuration (at factory delivery).
      //      g1=6    access bits for block 1 (of this sector) using [1 1 0] = 110b = 6
      //              which means block 1 (of this sector) is used as a value block,
      //              which (in this example) translates to block #5 within sector #1;
      //              where key A|B have r, key B has w, key B can increment,
      //              and key A|B can decrement, transfer, and restore.
      //      g2=6    same thing for block 2 (of this sector): set it to a value block;
      //              which (in this example) translates to block #6 within sector #1;
      //      g3=3    access bits for block 3 (of this sector): the Sector Trailer here;
      //              using [0 1 1] = 011b = 3 which means only key B has r/w access
      //              to the Sector Trailer (block 3 of this sector) from now on
      //              which (in this example) translates to block #7 within sector #1;
      mfrc522.MIFARE_SetAccessBits(&trailerBuffer[6], 0, 6, 6, 3);

      // Read the sector trailer as it is currently stored on the PICC
      Serial.println(F("Reading sector 4 trailer..."));
      status = mfrc522.MIFARE_Read(trailerBlock4, buffer, &size);
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("MIFARE_Read() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
          return;
      }
      // Check if it matches the desired access pattern already because if it does, we don't need to write it again...
      if (    buffer[6] != trailerBuffer[6]
          ||  buffer[7] != trailerBuffer[7]
          ||  buffer[8] != trailerBuffer[8]) {
          Serial.println(F("Writing new sector 4 trailer...")); // They don't match (yet), so write it to the PICC
          status = mfrc522.MIFARE_Write(trailerBlock4, trailerBuffer, 16);
          if (status != MFRC522::STATUS_OK) {
              Serial.print(F("MIFARE_Write() failed: "));
              Serial.println(mfrc522.GetStatusCodeName(status));
              return;
          }
      }

      Serial.println(F("Authenticating again using key B...")); // Authenticate using key B
      status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B, trailerBlock4, &key, &(mfrc522.uid));
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("PCD_Authenticate() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
          return;
      }

      // A value block has a 32 bit signed value stored three times
      // and an 8 bit address stored 4 times. Make sure that valueBlockA
      // and valueBlockB have that format (note that it will only format
      // the block when it doesn't comply to the expected format already).

      formatValueBlock(blockAddr4);

      status = mfrc522.MIFARE_SetValue(blockAddr4, 2); // Set value to 2
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("mifare_SetValue() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
          return;
      }

      status = mfrc522.MIFARE_GetValue(blockAddr4, &value); // Show the new value of valueBlockB
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("mifare_GetValue() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
          return;
      }

      Serial.print(F("New value of value block ")); Serial.print(blockAddr4); Serial.print(F(" = ")); Serial.println(value);

      mfrc522.PICC_DumpMifareClassicSectorToSerial(&(mfrc522.uid), &key, sector4); Serial.println(); // Dump the sector 4 data

      mfrc522.PCD_StopCrypto1(); // Stop encryption on PCD

    }
////////////////////////////////////////////////////////////////////////////////////////////

    if (userInput == 'f'){ // hôtel Niveau 2 (Secteur 5)
      if ( ! mfrc522.PICC_IsNewCardPresent()) // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
          return;
      if ( ! mfrc522.PICC_ReadCardSerial()) // Select one of the cards
          return;

      // Show some details of the PICC (that is: the tag/card)
      Serial.print(F("Card UID:")); dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size); Serial.println();
      Serial.print(F("PICC type: ")); piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
      Serial.println(mfrc522.PICC_GetTypeName(piccType));

      // Check for compatibility
      if (    piccType != MFRC522::PICC_TYPE_MIFARE_MINI
          &&  piccType != MFRC522::PICC_TYPE_MIFARE_1K
          &&  piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
          Serial.println(F("This sample only works with MIFARE Classic cards."));
          return;
      }

      Serial.println(F("Authenticating using key A..."));
      status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock5, &key, &(mfrc522.uid)); // Authenticate using key A
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("PCD_Authenticate() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
          return;
      }

      Serial.println(F("Current data in sector 5:"));
      mfrc522.PICC_DumpMifareClassicSectorToSerial(&(mfrc522.uid), &key, sector5); // Show the whole sector 5 as it currently is
      Serial.println();

      Serial.print(F("Reading data from block ")); Serial.print(blockAddr5);
      Serial.println(F(" ..."));
      status = (MFRC522::StatusCode) mfrc522.MIFARE_Read(blockAddr5, buffer, &size); // Read data from the block
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("MIFARE_Read() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
      }

      Serial.print(F("Data in block ")); Serial.print(blockAddr5); Serial.println(F(":"));
      dump_byte_array(buffer, 16); Serial.println(); // Print data from the block in buffer
      Serial.println();

      Serial.println(F("Authenticating again using key B..."));
      status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B, trailerBlock5, &key, &(mfrc522.uid)); // Authenticate using key B
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("PCD_Authenticate() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
          return;
      }

      Serial.print(F("Writing data into block ")); Serial.print(blockAddr5); Serial.println(F(" ..."));
      dump_byte_array(dataBlockhotelNiveau2, 16); Serial.println();
      status = (MFRC522::StatusCode) mfrc522.MIFARE_Write(blockAddr5, dataBlockhotelNiveau2, 16); // Write data to the block
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("MIFARE_Write() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
      }
      Serial.println();

      Serial.print(F("Reading data from block ")); Serial.print(blockAddr5); Serial.println(F(" ..."));
      status = (MFRC522::StatusCode) mfrc522.MIFARE_Read(blockAddr5, buffer, &size); // Read data from the block (again, should now be what we have written)
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("MIFARE_Read() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
      }
      Serial.print(F("Data in block ")); Serial.print(blockAddr5); Serial.println(F(":"));
      dump_byte_array(buffer, 16); Serial.println(); // Print data from the block in buffer

      // Check that data in block is what we have written  by counting the number of bytes that are equal
      Serial.println(F("Checking result..."));
      count = 0;
      for (byte i = 0; i < 16; i++) {
          if (buffer[i] == dataBlockhotelNiveau2[i]) // Compare buffer (= what we've read) with dataBlockhotelNiveau2 (= what we've written)
              count++;
      }
      Serial.print(F("Number of bytes that match = ")); Serial.println(count);
      if (count == 16) {
          Serial.println(F("Success :-)"));
      } else {
          Serial.println(F("Failure, no match :-("));
          Serial.println(F("  perhaps the write didn't work properly..."));
      }
      Serial.println();

      Serial.println(F("Current data in sector 5:"));
      mfrc522.PICC_DumpMifareClassicSectorToSerial(&(mfrc522.uid), &key, sector5); // Dump the sector 5 data
      Serial.println();

      mfrc522.PCD_StopCrypto1(); // Stop encryption on PCD
    }

////////////////////////////////////////////////////////////////////////////////////////////

    if (userInput == 'g'){ // hôtel Niveau 3 (Secteur 6)
      if ( ! mfrc522.PICC_IsNewCardPresent()) // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
          return;
      if ( ! mfrc522.PICC_ReadCardSerial()) // Select one of the cards
          return;

      // Show some details of the PICC (that is: the tag/card)
      Serial.print(F("Card UID:")); dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size); Serial.println();
      Serial.print(F("PICC type: ")); piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
      Serial.println(mfrc522.PICC_GetTypeName(piccType));

      // Check for compatibility
      if (    piccType != MFRC522::PICC_TYPE_MIFARE_MINI
          &&  piccType != MFRC522::PICC_TYPE_MIFARE_1K
          &&  piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
          Serial.println(F("This sample only works with MIFARE Classic cards."));
          return;
      }

      Serial.println(F("Authenticating using key A..."));
      status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock6, &key, &(mfrc522.uid)); // Authenticate using key A
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("PCD_Authenticate() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
          return;
      }

      Serial.println(F("Current data in sector 6:"));
      mfrc522.PICC_DumpMifareClassicSectorToSerial(&(mfrc522.uid), &key, sector6); // Show the whole sector 6 as it currently is
      Serial.println();

      Serial.print(F("Reading data from block ")); Serial.print(blockAddr6);
      Serial.println(F(" ..."));
      status = (MFRC522::StatusCode) mfrc522.MIFARE_Read(blockAddr6, buffer, &size); // Read data from the block
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("MIFARE_Read() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
      }

      Serial.print(F("Data in block ")); Serial.print(blockAddr6); Serial.println(F(":"));
      dump_byte_array(buffer, 16); Serial.println(); // Print data from the block in buffer
      Serial.println();

      Serial.println(F("Authenticating again using key B..."));
      status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B, trailerBlock6, &key, &(mfrc522.uid)); // Authenticate using key B
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("PCD_Authenticate() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
          return;
      }

      Serial.print(F("Writing data into block ")); Serial.print(blockAddr6); Serial.println(F(" ..."));
      dump_byte_array(dataBlockhotelNiveau3, 16); Serial.println();
      status = (MFRC522::StatusCode) mfrc522.MIFARE_Write(blockAddr6, dataBlockhotelNiveau3, 16); // Write data to the block
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("MIFARE_Write() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
      }
      Serial.println();

      Serial.print(F("Reading data from block ")); Serial.print(blockAddr6); Serial.println(F(" ..."));
      status = (MFRC522::StatusCode) mfrc522.MIFARE_Read(blockAddr6, buffer, &size); // Read data from the block (again, should now be what we have written)
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("MIFARE_Read() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
      }
      Serial.print(F("Data in block ")); Serial.print(blockAddr6); Serial.println(F(":"));
      dump_byte_array(buffer, 16); Serial.println(); // Print data from the block in buffer

      // Check that data in block is what we have written  by counting the number of bytes that are equal
      Serial.println(F("Checking result..."));
      count = 0;
      for (byte i = 0; i < 16; i++) {
          if (buffer[i] == dataBlockhotelNiveau3[i]) // Compare buffer (= what we've read) with dataBlockhotelNiveau3 (= what we've written)
              count++;
      }
      Serial.print(F("Number of bytes that match = ")); Serial.println(count);
      if (count == 16) {
          Serial.println(F("Success :-)"));
      } else {
          Serial.println(F("Failure, no match :-("));
          Serial.println(F("  perhaps the write didn't work properly..."));
      }
      Serial.println();

      Serial.println(F("Current data in sector 6:"));
      mfrc522.PICC_DumpMifareClassicSectorToSerial(&(mfrc522.uid), &key, sector6); // Dump the sector 6 data
      Serial.println();

      mfrc522.PCD_StopCrypto1(); // Stop encryption on PCD
    }

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////     Distributeur     //////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////

    if (userInput == 'h'){ // distributeur Niveau 1 (Secteur 7)
      if ( ! mfrc522.PICC_IsNewCardPresent()) // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
          return;

      if ( ! mfrc522.PICC_ReadCardSerial()) // Select one of the cards
          return;

      // Show some details of the PICC (that is: the tag/card)
      Serial.print(F("Card UID:")); dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size); Serial.println();
      Serial.print(F("PICC type: ")); piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
      Serial.println(mfrc522.PICC_GetTypeName(piccType));

      // Check for compatibility
      if (    piccType != MFRC522::PICC_TYPE_MIFARE_MINI
          &&  piccType != MFRC522::PICC_TYPE_MIFARE_1K
          &&  piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
          Serial.println(F("This sample only works with MIFARE Classic cards."));
          return;
      }

      Serial.println(F("Authenticating using key A..."));
      status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock7, &key, &(mfrc522.uid)); // Authenticate using key A
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("PCD_Authenticate() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
          return;
      }

      Serial.println(F("Current data in sector:"));
      mfrc522.PICC_DumpMifareClassicSectorToSerial(&(mfrc522.uid), &key, sector7); // Show the whole sector 4 as it currently is
      Serial.println();

      // We need a sector trailer that defines blocks 5 and 6 as Value Blocks and enables key B
      // The last block in a sector (block #3 for Mifare Classic 1K) is the Sector Trailer.
      // See http://www.nxp.com/documents/data_sheet/MF1S503x.pdf sections 8.6 and 8.7:
      //      Bytes 0-5:   Key A
      //      Bytes 6-8:   Access Bits
      //      Bytes 9:     User data
      //      Bytes 10-15: Key B (or user data)
      // The access bits are stored in a peculiar fashion.
      // There are four groups:
      //      g[0]    Access bits for block 0 (for sectors 0-31)
      //              or blocks 0-4 (for sectors 32-39)
      //      g[1]    Access bits for block 1 (for sectors 0-31)
      //              or blocks 5-9 (for sectors 32-39)
      //      g[2]    Access bits for block 2 (for sectors 0-31)
      //              or blocks 10-14 (for sectors 32-39)
      //      g[3]    Access bits for the Sector Trailer: block 3 (for sectors 0-31)
      //              or block 15 (for sectors 32-39)
      // Each group has access bits [C1 C2 C3], in this code C1 is MSB and C3 is LSB.
      // Determine the bit pattern needed using MIFARE_SetAccessBits:
      //      g0=0    access bits for block 0 (of this sector) using [0 0 0] = 000b = 0
      //              which means key A|B have r/w for block 0 of this sector
      //              which (in this example) translates to block #4 within sector #1;
      //              this is the transport configuration (at factory delivery).
      //      g1=6    access bits for block 1 (of this sector) using [1 1 0] = 110b = 6
      //              which means block 1 (of this sector) is used as a value block,
      //              which (in this example) translates to block #5 within sector #1;
      //              where key A|B have r, key B has w, key B can increment,
      //              and key A|B can decrement, transfer, and restore.
      //      g2=6    same thing for block 2 (of this sector): set it to a value block;
      //              which (in this example) translates to block #6 within sector #1;
      //      g3=3    access bits for block 3 (of this sector): the Sector Trailer here;
      //              using [0 1 1] = 011b = 3 which means only key B has r/w access
      //              to the Sector Trailer (block 3 of this sector) from now on
      //              which (in this example) translates to block #7 within sector #1;
      mfrc522.MIFARE_SetAccessBits(&trailerBuffer[6], 0, 6, 6, 3);

      // Read the sector trailer as it is currently stored on the PICC
      Serial.println(F("Reading sector 7 trailer..."));
      status = mfrc522.MIFARE_Read(trailerBlock7, buffer, &size);
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("MIFARE_Read() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
          return;
      }
      // Check if it matches the desired access pattern already because if it does, we don't need to write it again...
      if (    buffer[6] != trailerBuffer[6]
          ||  buffer[7] != trailerBuffer[7]
          ||  buffer[8] != trailerBuffer[8]) {
          Serial.println(F("Writing new sector 7 trailer...")); // They don't match (yet), so write it to the PICC
          status = mfrc522.MIFARE_Write(trailerBlock7, trailerBuffer, 16);
          if (status != MFRC522::STATUS_OK) {
              Serial.print(F("MIFARE_Write() failed: "));
              Serial.println(mfrc522.GetStatusCodeName(status));
              return;
          }
      }

      Serial.println(F("Authenticating again using key B...")); // Authenticate using key B
      status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B, trailerBlock7, &key, &(mfrc522.uid));
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("PCD_Authenticate() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
          return;
      }

      // A value block has a 32 bit signed value stored three times
      // and an 8 bit address stored 4 times. Make sure that valueBlockA
      // and valueBlockB have that format (note that it will only format
      // the block when it doesn't comply to the expected format already).

      formatValueBlock(blockAddr7);

      status = mfrc522.MIFARE_SetValue(blockAddr7, 2); // Set value to 2
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("mifare_SetValue() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
          return;
      }

      status = mfrc522.MIFARE_GetValue(blockAddr7, &value); // Show the new value of valueBlockB
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("mifare_GetValue() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
          return;
      }

      Serial.print(F("New value of value block ")); Serial.print(blockAddr7); Serial.print(F(" = ")); Serial.println(value);

      mfrc522.PICC_DumpMifareClassicSectorToSerial(&(mfrc522.uid), &key, sector7); Serial.println(); // Dump the sector 7 data

      mfrc522.PCD_StopCrypto1(); // Stop encryption on PCD
    }

////////////////////////////////////////////////////////////////////////////////////////////

    if (userInput == 'i'){ // distributeur Niveau 2 (Secteur 8)
      if ( ! mfrc522.PICC_IsNewCardPresent()) // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
          return;

      if ( ! mfrc522.PICC_ReadCardSerial()) // Select one of the cards
          return;

      // Show some details of the PICC (that is: the tag/card)
      Serial.print(F("Card UID:")); dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size); Serial.println();
      Serial.print(F("PICC type: ")); piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
      Serial.println(mfrc522.PICC_GetTypeName(piccType));

      // Check for compatibility
      if (    piccType != MFRC522::PICC_TYPE_MIFARE_MINI
          &&  piccType != MFRC522::PICC_TYPE_MIFARE_1K
          &&  piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
          Serial.println(F("This sample only works with MIFARE Classic cards."));
          return;
      }

      Serial.println(F("Authenticating using key A..."));
      status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock8, &key, &(mfrc522.uid)); // Authenticate using key A
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("PCD_Authenticate() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
          return;
      }

      Serial.println(F("Current data in sector:"));
      mfrc522.PICC_DumpMifareClassicSectorToSerial(&(mfrc522.uid), &key, sector8); // Show the whole sector 8 as it currently is
      Serial.println();

      // We need a sector trailer that defines blocks 5 and 6 as Value Blocks and enables key B
      // The last block in a sector (block #3 for Mifare Classic 1K) is the Sector Trailer.
      // See http://www.nxp.com/documents/data_sheet/MF1S503x.pdf sections 8.6 and 8.7:
      //      Bytes 0-5:   Key A
      //      Bytes 6-8:   Access Bits
      //      Bytes 9:     User data
      //      Bytes 10-15: Key B (or user data)
      // The access bits are stored in a peculiar fashion.
      // There are four groups:
      //      g[0]    Access bits for block 0 (for sectors 0-31)
      //              or blocks 0-4 (for sectors 32-39)
      //      g[1]    Access bits for block 1 (for sectors 0-31)
      //              or blocks 5-9 (for sectors 32-39)
      //      g[2]    Access bits for block 2 (for sectors 0-31)
      //              or blocks 10-14 (for sectors 32-39)
      //      g[3]    Access bits for the Sector Trailer: block 3 (for sectors 0-31)
      //              or block 15 (for sectors 32-39)
      // Each group has access bits [C1 C2 C3], in this code C1 is MSB and C3 is LSB.
      // Determine the bit pattern needed using MIFARE_SetAccessBits:
      //      g0=0    access bits for block 0 (of this sector) using [0 0 0] = 000b = 0
      //              which means key A|B have r/w for block 0 of this sector
      //              which (in this example) translates to block #4 within sector #1;
      //              this is the transport configuration (at factory delivery).
      //      g1=6    access bits for block 1 (of this sector) using [1 1 0] = 110b = 6
      //              which means block 1 (of this sector) is used as a value block,
      //              which (in this example) translates to block #5 within sector #1;
      //              where key A|B have r, key B has w, key B can increment,
      //              and key A|B can decrement, transfer, and restore.
      //      g2=6    same thing for block 2 (of this sector): set it to a value block;
      //              which (in this example) translates to block #6 within sector #1;
      //      g3=3    access bits for block 3 (of this sector): the Sector Trailer here;
      //              using [0 1 1] = 011b = 3 which means only key B has r/w access
      //              to the Sector Trailer (block 3 of this sector) from now on
      //              which (in this example) translates to block #7 within sector #1;
      mfrc522.MIFARE_SetAccessBits(&trailerBuffer[6], 0, 6, 6, 3);

      // Read the sector trailer as it is currently stored on the PICC
      Serial.println(F("Reading sector 8 trailer..."));
      status = mfrc522.MIFARE_Read(trailerBlock8, buffer, &size);
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("MIFARE_Read() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
          return;
      }
      // Check if it matches the desired access pattern already because if it does, we don't need to write it again...
      if (    buffer[6] != trailerBuffer[6]
          ||  buffer[7] != trailerBuffer[7]
          ||  buffer[8] != trailerBuffer[8]) {
          Serial.println(F("Writing new sector 8 trailer...")); // They don't match (yet), so write it to the PICC
          status = mfrc522.MIFARE_Write(trailerBlock8, trailerBuffer, 16);
          if (status != MFRC522::STATUS_OK) {
              Serial.print(F("MIFARE_Write() failed: "));
              Serial.println(mfrc522.GetStatusCodeName(status));
              return;
          }
      }

      Serial.println(F("Authenticating again using key B...")); // Authenticate using key B
      status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B, trailerBlock8, &key, &(mfrc522.uid));
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("PCD_Authenticate() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
          return;
      }

      // A value block has a 32 bit signed value stored three times
      // and an 8 bit address stored 4 times. Make sure that valueBlockA
      // and valueBlockB have that format (note that it will only format
      // the block when it doesn't comply to the expected format already).

      formatValueBlock(blockAddr8);

      status = mfrc522.MIFARE_SetValue(blockAddr8, 2); // Set value to 2
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("mifare_SetValue() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
          return;
      }

      status = mfrc522.MIFARE_GetValue(blockAddr8, &value); // Show the new value of valueBlockB
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("mifare_GetValue() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
          return;
      }

      Serial.print(F("New value of value block ")); Serial.print(blockAddr8); Serial.print(F(" = ")); Serial.println(value);

      mfrc522.PICC_DumpMifareClassicSectorToSerial(&(mfrc522.uid), &key, sector8); Serial.println(); // Dump the sector 8 data

      mfrc522.PCD_StopCrypto1(); // Stop encryption on PCD
    }

////////////////////////////////////////////////////////////////////////////////////////////

    if (userInput == 'j'){ // distributeur Niveau 3 (Secteur 9)
      if ( ! mfrc522.PICC_IsNewCardPresent()) // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
          return;

      if ( ! mfrc522.PICC_ReadCardSerial()) // Select one of the cards
          return;

      // Show some details of the PICC (that is: the tag/card)
      Serial.print(F("Card UID:")); dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size); Serial.println();
      Serial.print(F("PICC type: ")); piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
      Serial.println(mfrc522.PICC_GetTypeName(piccType));

      // Check for compatibility
      if (    piccType != MFRC522::PICC_TYPE_MIFARE_MINI
          &&  piccType != MFRC522::PICC_TYPE_MIFARE_1K
          &&  piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
          Serial.println(F("This sample only works with MIFARE Classic cards."));
          return;
      }

      Serial.println(F("Authenticating using key A..."));
      status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock9, &key, &(mfrc522.uid)); // Authenticate using key A
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("PCD_Authenticate() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
          return;
      }

      Serial.println(F("Current data in sector:"));
      mfrc522.PICC_DumpMifareClassicSectorToSerial(&(mfrc522.uid), &key, sector9); // Show the whole sector 9 as it currently is
      Serial.println();

      // We need a sector trailer that defines blocks 5 and 6 as Value Blocks and enables key B
      // The last block in a sector (block #3 for Mifare Classic 1K) is the Sector Trailer.
      // See http://www.nxp.com/documents/data_sheet/MF1S503x.pdf sections 8.6 and 8.7:
      //      Bytes 0-5:   Key A
      //      Bytes 6-8:   Access Bits
      //      Bytes 9:     User data
      //      Bytes 10-15: Key B (or user data)
      // The access bits are stored in a peculiar fashion.
      // There are four groups:
      //      g[0]    Access bits for block 0 (for sectors 0-31)
      //              or blocks 0-4 (for sectors 32-39)
      //      g[1]    Access bits for block 1 (for sectors 0-31)
      //              or blocks 5-9 (for sectors 32-39)
      //      g[2]    Access bits for block 2 (for sectors 0-31)
      //              or blocks 10-14 (for sectors 32-39)
      //      g[3]    Access bits for the Sector Trailer: block 3 (for sectors 0-31)
      //              or block 15 (for sectors 32-39)
      // Each group has access bits [C1 C2 C3], in this code C1 is MSB and C3 is LSB.
      // Determine the bit pattern needed using MIFARE_SetAccessBits:
      //      g0=0    access bits for block 0 (of this sector) using [0 0 0] = 000b = 0
      //              which means key A|B have r/w for block 0 of this sector
      //              which (in this example) translates to block #4 within sector #1;
      //              this is the transport configuration (at factory delivery).
      //      g1=6    access bits for block 1 (of this sector) using [1 1 0] = 110b = 6
      //              which means block 1 (of this sector) is used as a value block,
      //              which (in this example) translates to block #5 within sector #1;
      //              where key A|B have r, key B has w, key B can increment,
      //              and key A|B can decrement, transfer, and restore.
      //      g2=6    same thing for block 2 (of this sector): set it to a value block;
      //              which (in this example) translates to block #6 within sector #1;
      //      g3=3    access bits for block 3 (of this sector): the Sector Trailer here;
      //              using [0 1 1] = 011b = 3 which means only key B has r/w access
      //              to the Sector Trailer (block 3 of this sector) from now on
      //              which (in this example) translates to block #7 within sector #1;
      mfrc522.MIFARE_SetAccessBits(&trailerBuffer[6], 0, 6, 6, 3);

      // Read the sector trailer as it is currently stored on the PICC
      Serial.println(F("Reading sector 9 trailer..."));
      status = mfrc522.MIFARE_Read(trailerBlock9, buffer, &size);
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("MIFARE_Read() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
          return;
      }
      // Check if it matches the desired access pattern already because if it does, we don't need to write it again...
      if (    buffer[6] != trailerBuffer[6]
          ||  buffer[7] != trailerBuffer[7]
          ||  buffer[8] != trailerBuffer[8]) {
          Serial.println(F("Writing new sector 9 trailer...")); // They don't match (yet), so write it to the PICC
          status = mfrc522.MIFARE_Write(trailerBlock9, trailerBuffer, 16);
          if (status != MFRC522::STATUS_OK) {
              Serial.print(F("MIFARE_Write() failed: "));
              Serial.println(mfrc522.GetStatusCodeName(status));
              return;
          }
      }

      Serial.println(F("Authenticating again using key B...")); // Authenticate using key B
      status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B, trailerBlock9, &key, &(mfrc522.uid));
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("PCD_Authenticate() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
          return;
      }

      // A value block has a 32 bit signed value stored three times
      // and an 8 bit address stored 4 times. Make sure that valueBlockA
      // and valueBlockB have that format (note that it will only format
      // the block when it doesn't comply to the expected format already).

      formatValueBlock(blockAddr9);

      status = mfrc522.MIFARE_SetValue(blockAddr9, 2); // Set value to 2
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("mifare_SetValue() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
          return;
      }

      status = mfrc522.MIFARE_GetValue(blockAddr9, &value); // Show the new value of valueBlockB
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("mifare_GetValue() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
          return;
      }

      Serial.print(F("New value of value block ")); Serial.print(blockAddr9); Serial.print(F(" = ")); Serial.println(value);

      mfrc522.PICC_DumpMifareClassicSectorToSerial(&(mfrc522.uid), &key, sector9); Serial.println(); // Dump the sector 9 data

      mfrc522.PCD_StopCrypto1(); // Stop encryption on PCD
    }

  } // if userInput>0{}

} // main{}

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

    Serial.print(F("Reading block ")); Serial.println(blockAddr);
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
