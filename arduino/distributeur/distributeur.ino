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

    Serial.print(F("Using key (for A and B):"));
    dump_byte_array(key.keyByte, MFRC522::MF_KEY_SIZE); Serial.println();
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

    // // Show some details of the PICC (that is: the tag/card)
    // Serial.print(F("Card UID:"));
    // dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
    // Serial.println();
    // Serial.print(F("PICC type: "));
    // MFRC522::PICC_Type piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
    // Serial.println(mfrc522.PICC_GetTypeName(piccType));

    // In this sample we use the second sector,
    // that is: sector #1, covering block #4 up to and including block #7
    byte sector         = 1;
    byte ValueBlock    = 6;
    byte trailerBlock   = 7;
    int32_t itemPrice = 1; // Evian = 1€
    MFRC522::StatusCode status;
    byte buffer[18];
    byte size = sizeof(buffer);
    int32_t value;

    // Authenticate using key A
    Serial.println(F("Authenticating using key A..."));
    status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));
    if (status != MFRC522::STATUS_OK) {
        Serial.print(F("PCD_Authenticate() failed: "));
        Serial.println(mfrc522.GetStatusCodeName(status));
        return;
    }

    status = mfrc522.MIFARE_GetValue(ValueBlock, &value);
    Serial.print("Solde avant : "); Serial.println(value);

    // We need a sector trailer that defines blocks 5 and 6 as Value Blocks and enables key B
    // The last block in a sector (block #3 for Mifare Classic 1K) is the Sector Trailer.
    // See http://www.nxp.com/documents/data_sheet/MF1S503x.pdf sections 8.6 and 8.7:
    //      Bytes 0-5:   Key A
    //      Bytes 6-8:   Access Bits
    //      Bytes 9:     User data
    //      Bytes 10-15: Key B (or user data)
    byte trailerBuffer[] = {
        255, 255, 255, 255, 255, 255,       // Keep default key A, à remplacer par la vraie valeur
        0, 0, 0,
        0,
        255, 255, 255, 255, 255, 255};      // Keep default key B, à remplacer par la vraie valeur
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
    Serial.println(F("Reading sector trailer..."));
    status = mfrc522.MIFARE_Read(trailerBlock, buffer, &size);
    if (status != MFRC522::STATUS_OK) {
        Serial.print(F("MIFARE_Read() failed: "));
        Serial.println(mfrc522.GetStatusCodeName(status));
        return;
    }
    // // Check if it matches the desired access pattern already;
    // // because if it does, we don't need to write it again...
    // if (    buffer[6] != trailerBuffer[6]
    //     ||  buffer[7] != trailerBuffer[7]
    //     ||  buffer[8] != trailerBuffer[8]) {
    //     // They don't match (yet), so write it to the PICC
    //     Serial.println(F("Writing new sector trailer..."));
    //     status = mfrc522.MIFARE_Write(trailerBlock, trailerBuffer, 16);
    //     if (status != MFRC522::STATUS_OK) {
    //         Serial.print(F("MIFARE_Write() failed: "));
    //         Serial.println(mfrc522.GetStatusCodeName(status));
    //         return;
    //     }
    // } // à commenter après les tests

    // Authenticate using key B
    Serial.println(F("Authenticating again using key B..."));
    status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B, trailerBlock, &key, &(mfrc522.uid));
    if (status != MFRC522::STATUS_OK) {
        Serial.print(F("PCD_Authenticate() failed: "));
        Serial.println(mfrc522.GetStatusCodeName(status));
        return;
    }

    // A value block has a 32 bit signed value stored three times
    // and an 8 bit address stored 4 times. Make sure that valueBlockA
    // and ValueBlock have that format (note that it will only format
    // the block when it doesn't comply to the expected format already).

    formatValueBlock(ValueBlock); // à commenter après les tests

    // Decrement 10 from the value of ValueBlock and store the result in ValueBlock.

    if (value>=0 && value>itemPrice){

      Serial.print("Soustrait prix boisson (1€) du bloc "); Serial.println(ValueBlock);
      status = mfrc522.MIFARE_Decrement(ValueBlock, itemPrice);
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("MIFARE_Decrement() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
          return;
      }

      status = mfrc522.MIFARE_Transfer(ValueBlock);
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("MIFARE_Transfer() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
          return;
      }

      // Show the new value of ValueBlock
      status = mfrc522.MIFARE_GetValue(ValueBlock, &value);
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("mifare_GetValue() failed: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
          return;
      }
      // status = mfrc522.MIFARE_SetValue(ValueBlock, 100);
      Serial.print(F("Solde après dans le bloc ")); Serial.print(ValueBlock);
      Serial.print(F(" = ")); Serial.println(value);
    }

    else{
      Serial.println("Solde insuffisant");
    }

    // Dump the sector data
    mfrc522.PICC_DumpMifareClassicSectorToSerial(&(mfrc522.uid), &key, sector);
    Serial.println();

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
