#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9           // Configurable, see typical pin layout above
#define SS_PIN          10          // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

// MFRC522::MIFARE_Key key0A = {keyByte: {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5}}; // écriture des clés de chaque secteur
// MFRC522::MIFARE_Key key0B = {keyByte: {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5}}; // écriture des clés de chaque secteur

MFRC522::MIFARE_Key key1A = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};
MFRC522::MIFARE_Key key1B = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};

MFRC522::MIFARE_Key key2A = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};
MFRC522::MIFARE_Key key2B = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};

MFRC522::MIFARE_Key key3A = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};
MFRC522::MIFARE_Key key3B = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};

MFRC522::MIFARE_Key key4A = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};
MFRC522::MIFARE_Key key4B = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};

MFRC522::MIFARE_Key key5A = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};
MFRC522::MIFARE_Key key5B = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};

MFRC522::MIFARE_Key key6A = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};
MFRC522::MIFARE_Key key6B = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};

MFRC522::MIFARE_Key key7A = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};
MFRC522::MIFARE_Key key7B = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};

MFRC522::MIFARE_Key key8A = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};
MFRC522::MIFARE_Key key8B = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};

MFRC522::MIFARE_Key key9A = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};
MFRC522::MIFARE_Key key9B = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};

MFRC522::MIFARE_Key key10A = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};
MFRC522::MIFARE_Key key10B = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};

MFRC522::MIFARE_Key key11A = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};
MFRC522::MIFARE_Key key11B = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};

MFRC522::MIFARE_Key key12A = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};
MFRC522::MIFARE_Key key12B = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};

MFRC522::MIFARE_Key key13A = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};
MFRC522::MIFARE_Key key13B = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};

MFRC522::MIFARE_Key key14A = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};
MFRC522::MIFARE_Key key14B = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};

MFRC522::MIFARE_Key key15A = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};
MFRC522::MIFARE_Key key15B = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};

char userInput;

/**
   Initialize.
*/
void setup() {
  Serial.begin(9600); // Initialize serial communications with the PC
  while (!Serial);    // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  SPI.begin();        // Init SPI bus
  mfrc522.PCD_Init(); // Init MFRC522 card

  // Serial.println(F("Using for key A :")); dump_byte_array(key1A.keyByte, MFRC522::MF_KEY_SIZE); Serial.println();
  //
  // Serial.println(F("Using for key B :")); dump_byte_array(key1B.keyByte, MFRC522::MF_KEY_SIZE); Serial.println();
}

/**
   Main loop.
*/
void loop() {

  if(Serial.available()>0){

    userInput=Serial.read(); Serial.println(userInput);

    if (userInput=='a'){  // porteNiveau1 Secteur 0
      if ( ! mfrc522.PICC_IsNewCardPresent())
      return;

      // Select one of the cards
      if ( ! mfrc522.PICC_ReadCardSerial())
          return;

      // Serial.println(F("Card UID:"));
      dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
    }


////////////////////////////////////////////////////////////////////////////////////////////

    else if (userInput=='b'){  // porteNiveau2 Secteur 1
      if ( ! mfrc522.PICC_IsNewCardPresent())
      return;

      // Select one of the cards
      if ( ! mfrc522.PICC_ReadCardSerial())
          return;

      byte sector = 1;
      byte blockAddr = 4;
      byte trailerBlock   = ((sector + 1) * 4) - 1;
      MFRC522::StatusCode status;
      byte buffer[18];
      byte size = sizeof(buffer);

      status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key1A, &(mfrc522.uid)); // Authenticate using key A
      if (status != MFRC522::STATUS_OK) {
        return;
      }

      status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B, trailerBlock, &key1B, &(mfrc522.uid)); // Authenticate using key B
      if (status != MFRC522::STATUS_OK) {
        return;
      }

      Serial.print(F("Lecture bloc ")); Serial.print(blockAddr); Serial.println(F(" : "));
      status = (MFRC522::StatusCode) mfrc522.MIFARE_Read(blockAddr, buffer, &size); // Read data from the block
      if (status != MFRC522::STATUS_OK) {
        return;
      }

      dump_byte_array(buffer, 16); Serial.println();

      mfrc522.PCD_StopCrypto1(); // Stop encryption on PCD
      }


////////////////////////////////////////////////////////////////////////////////////////////

    else if (userInput=='c'){ // porteNiveau3 Secteur 2
      if ( ! mfrc522.PICC_IsNewCardPresent())
      return;

      // Select one of the cards
      if ( ! mfrc522.PICC_ReadCardSerial())
          return;

      byte sector = 2;
      byte blockAddr = 8;
      byte trailerBlock   = ((sector + 1) * 4) - 1;
      MFRC522::StatusCode status;
      byte buffer[18];
      byte size = sizeof(buffer);

      status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key2A, &(mfrc522.uid)); // Authenticate using key A
      if (status != MFRC522::STATUS_OK) {
        return;
      }

      status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B, trailerBlock, &key2B, &(mfrc522.uid)); // Authenticate using key B
      if (status != MFRC522::STATUS_OK) {
        return;
      }

      Serial.print(F("Lecture bloc ")); Serial.print(blockAddr); Serial.println(F(" : "));
      status = (MFRC522::StatusCode) mfrc522.MIFARE_Read(blockAddr, buffer, &size); // Read data from the block
      if (status != MFRC522::STATUS_OK) {
        return;
      }

      dump_byte_array(buffer, 16); Serial.println();

      mfrc522.PCD_StopCrypto1(); // Stop encryption on PCD
    }


////////////////////////////////////////////////////////////////////////////////////////////

    else if (userInput=='d'){ // porteNiveau4 Secteur 3
      if ( ! mfrc522.PICC_IsNewCardPresent())
      return;

      // Select one of the cards
      if ( ! mfrc522.PICC_ReadCardSerial())
          return;

      byte sector = 3;
      byte blockAddr = 12;
      byte trailerBlock  = ((sector + 1) * 4) - 1;
      MFRC522::StatusCode status;
      byte buffer[18];
      byte size = sizeof(buffer);

      status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key3A, &(mfrc522.uid)); // Authenticate using key A
      if (status != MFRC522::STATUS_OK) {
        return;
      }

      status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B, trailerBlock, &key3B, &(mfrc522.uid)); // Authenticate using key B
      if (status != MFRC522::STATUS_OK) {
        return;
      }

      Serial.print(F("Lecture bloc ")); Serial.print(blockAddr); Serial.println(F(" : "));
      status = (MFRC522::StatusCode) mfrc522.MIFARE_Read(blockAddr, buffer, &size); // Read data from the block
      if (status != MFRC522::STATUS_OK) {
        return;
      }

      dump_byte_array(buffer, 16); Serial.println();

      mfrc522.PCD_StopCrypto1(); // Stop encryption on PCD
    }



////////////////////////////////////////////////////////////////////////////////////////////

    else if (userInput=='e'){ // hotelNiveau1 Secteur 4
      if ( ! mfrc522.PICC_IsNewCardPresent())
      return;

      // Select one of the cards
      if ( ! mfrc522.PICC_ReadCardSerial())
          return;

      byte sector = 4;
      byte blockAddr = 16;
      byte trailerBlock   = ((sector + 1) * 4) - 1;
      MFRC522::StatusCode status;
      byte buffer[18];
      byte size = sizeof(buffer);

      status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key4A, &(mfrc522.uid)); // Authenticate using key A
      if (status != MFRC522::STATUS_OK) {
        return;
      }

      status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B, trailerBlock, &key4B, &(mfrc522.uid)); // Authenticate using key B
      if (status != MFRC522::STATUS_OK) {
        return;
      }

      Serial.print(F("Lecture bloc ")); Serial.print(blockAddr); Serial.println(F(" : "));
      status = (MFRC522::StatusCode) mfrc522.MIFARE_Read(blockAddr, buffer, &size); // Read data from the block
      if (status != MFRC522::STATUS_OK) {
        return;
      }

      dump_byte_array(buffer, 16); Serial.println();

      mfrc522.PCD_StopCrypto1(); // Stop encryption on PCD
    }



////////////////////////////////////////////////////////////////////////////////////////////

    else if (userInput=='f'){ // hotelNiveau2 Secteur 5
      if ( ! mfrc522.PICC_IsNewCardPresent())
      return;

      // Select one of the cards
      if ( ! mfrc522.PICC_ReadCardSerial())
          return;

      byte sector = 5;
      byte blockAddr = 20;
      byte trailerBlock   = ((sector + 1) * 4) - 1;
      MFRC522::StatusCode status;
      byte buffer[18];
      byte size = sizeof(buffer);

      status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key5A, &(mfrc522.uid)); // Authenticate using key A
      if (status != MFRC522::STATUS_OK) {
        return;
      }

      status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B, trailerBlock, &key5B, &(mfrc522.uid)); // Authenticate using key B
      if (status != MFRC522::STATUS_OK) {
        return;
      }

      Serial.print(F("Lecture bloc ")); Serial.print(blockAddr); Serial.println(F(" : "));
      status = (MFRC522::StatusCode) mfrc522.MIFARE_Read(blockAddr, buffer, &size); // Read data from the block
      if (status != MFRC522::STATUS_OK) {
        return;
      }

      dump_byte_array(buffer, 16); Serial.println();

      mfrc522.PCD_StopCrypto1(); // Stop encryption on PCD
    }



////////////////////////////////////////////////////////////////////////////////////////////

    else if (userInput=='g'){ // hotelNiveau3 Secteur 6
      byte sector = 6;
      byte blockAddr = 24;
      byte trailerBlock   = ((sector + 1) * 4) - 1;
      MFRC522::StatusCode status;
      byte buffer[18];
      byte size = sizeof(buffer);

      status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key6A, &(mfrc522.uid)); // Authenticate using key A
      if (status != MFRC522::STATUS_OK) {
        return;
      }

      status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B, trailerBlock, &key6B, &(mfrc522.uid)); // Authenticate using key B
      if (status != MFRC522::STATUS_OK) {
        return;
      }

      Serial.print(F("Lecture bloc ")); Serial.print(blockAddr); Serial.println(F(" : "));
      status = (MFRC522::StatusCode) mfrc522.MIFARE_Read(blockAddr, buffer, &size); // Read data from the block
      if (status != MFRC522::STATUS_OK) {
        return;
      }

      dump_byte_array(buffer, 16); Serial.println();

      mfrc522.PCD_StopCrypto1(); // Stop encryption on PCD
    }



////////////////////////////////////////////////////////////////////////////////////////////

    else if (userInput=='h'){ // distributeurNiveau1 Secteur 7
      if ( ! mfrc522.PICC_IsNewCardPresent())
      return;

      // Select one of the cards
      if ( ! mfrc522.PICC_ReadCardSerial())
          return;

      // In this sample we use the second sector,
      // that is: sector #1, covering block #4 up to and including block #7
      byte sector         = 7;
      byte ValueBlock    = 28;
      byte trailerBlock   = ((sector + 1) * 4) - 1;
      int32_t itemPrice = 1; // Evian = 1€
      MFRC522::StatusCode status;
      byte buffer[18];
      byte size = sizeof(buffer);
      int32_t value;

      // Authenticate using key A
      status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key7A, &(mfrc522.uid));
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
      status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B, trailerBlock, &key7B, &(mfrc522.uid));
      if (status != MFRC522::STATUS_OK) {
          return;
      }

      // Decrement 10 from the value of ValueBlock and store the result in ValueBlock.
      if (value>=0 && value>itemPrice){
        Serial.print("Achat boisson à "); Serial.print(itemPrice); Serial.println("€");
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
        if (status != MFRC522::STATUS_OK) {
            return;
        }
        // status = mfrc522.MIFARE_SetValue(ValueBlock, 100);
        Serial.print(F("Nouveau solde :")); Serial.print(value); Serial.println("€");
        // Serial.print(", bloc "); Serial.print(ValueBlock);
        Serial.println("Obtenu : Coca");
        Serial.println();
      }

      else{
        Serial.println("Solde insuffisant");
        Serial.println();
      }

      // Dump the sector data
      // Serial.println();
      // mfrc522.PICC_DumpMifareClassicSectorToSerial(&(mfrc522.uid), &key7A, sector);
      // Serial.println();

      mfrc522.PCD_StopCrypto1(); // Stop encryption on PCD
    }


////////////////////////////////////////////////////////////////////////////////////////////

    else if (userInput=='i'){ // distributeurNiveau2 Secteur 8
      // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
        if ( ! mfrc522.PICC_IsNewCardPresent())
            return;

        // Select one of the cards
        if ( ! mfrc522.PICC_ReadCardSerial())
            return;

        // In this sample we use the second sector,
        byte sector         = 8;
        byte ValueBlock    = 32;
        byte trailerBlock   = ((sector + 1) * 4) - 1;
        int32_t itemPrice = 1; // Evian = 1€
        MFRC522::StatusCode status;
        byte buffer[18];
        byte size = sizeof(buffer);
        int32_t value;

        status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key8A, &(mfrc522.uid)); // Authenticate using key A
        if (status != MFRC522::STATUS_OK) {
            return;
        }

        status = mfrc522.MIFARE_GetValue(ValueBlock, &value);
        Serial.print("Solde : "); Serial.print(value); Serial.println("€");

        // Serial.println(F("Reading sector trailer..."));
        status = mfrc522.MIFARE_Read(trailerBlock, buffer, &size); // Read the sector trailer as it is currently stored on the PICC
        if (status != MFRC522::STATUS_OK) {
            return;
        }

        status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B, trailerBlock, &key8B, &(mfrc522.uid)); // Authenticate using key B
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

        // Stop encryption on PCD
        mfrc522.PCD_StopCrypto1();

    }


////////////////////////////////////////////////////////////////////////////////////////////

    else if (userInput=='j'){ // distributeurNiveau3 Secteur 9
      // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
      if ( ! mfrc522.PICC_IsNewCardPresent())
          return;

      // Select one of the cards
      if ( ! mfrc522.PICC_ReadCardSerial())
          return;

      // In this sample we use the second sector,
      // that is: sector #1, covering block #4 up to and including block #7
      byte sector         = 9;
      byte ValueBlock    = 36;
      byte trailerBlock   = ((sector + 1) * 4) - 1;
      int32_t itemPrice = 1; // Evian = 1€
      MFRC522::StatusCode status;
      byte buffer[18];
      byte size = sizeof(buffer);
      int32_t value;

      // Authenticate using key A
      status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key9A, &(mfrc522.uid));
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

      status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B, trailerBlock, &key9B, &(mfrc522.uid)); // Authenticate using key B
      if (status != MFRC522::STATUS_OK) {
          return;
      }

      if (value>=0 && value>itemPrice){
        Serial.print("Achat boisson à "); Serial.print(itemPrice); Serial.println("€");

        delay(300);

        status = mfrc522.MIFARE_SetValue(ValueBlock, value-itemPrice); // Decrement 10 from the value of ValueBlock and store the result in ValueBlock.
        if (status != MFRC522::STATUS_OK) {
            return;
        }

        status = mfrc522.MIFARE_GetValue(ValueBlock, &value); // Show the new value of ValueBlock
        if (status != MFRC522::STATUS_OK) {
            return;
        }
        Serial.print(F("Nouveau solde : ")); Serial.print(value); Serial.println("€");
        Serial.println("Obtenu : Coca");
        Serial.println();
      }

      else{
        Serial.println("Solde insuffisant");
        Serial.println();
      }

      // Dump the sector data
      // Serial.println();
      // mfrc522.PICC_DumpMifareClassicSectorToSerial(&(mfrc522.uid), &key, sector);
      // Serial.println();

      mfrc522.PCD_StopCrypto1();   // Stop encryption on PCD
    }
  }
}


///////////////////////////////////////////////////////////////////////////////

/**
   Helper routine to dump a byte array as hex values to Serial.
*/
void dump_byte_array(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? "0" : "");
    Serial.print(buffer[i], HEX);
  }
}

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
