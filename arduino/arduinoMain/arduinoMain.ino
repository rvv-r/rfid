/*
 * --------------------------------------------------------------------------------------------------------------------
 * Example sketch/program showing how to read data from a PICC to serial.
 * --------------------------------------------------------------------------------------------------------------------
 * This is a MFRC522 library example; for further details and other examples see: https://github.com/miguelbalboa/rfid
 *
 * Example sketch/program showing how to read data from a PICC (that is: a RFID Tag or Card) using a MFRC522 based RFID
 * Reader on the Arduino SPI interface.
 *
 * When the Arduino and the MFRC522 module are connected (see the pin layout below), load this sketch into Arduino IDE
 * then verify/compile and upload it. To see the output: use Tools, Serial Monitor of the IDE (hit Ctrl+Shft+M). When
 * you present a PICC (that is: a RFID Tag or Card) at reading distance of the MFRC522 Reader/PCD, the serial output
 * will show the ID/UID, type and any data blocks it can read. Note: you may see "Timeout in communication" messages
 * when removing the PICC from reading distance too early.
 *
 * If your reader supports it, this sketch/program will read all the PICCs presented (that is: multiple tag reading).
 * So if you stack two or more PICCs on top of each other and present them to the reader, it will first output all
 * details of the first and then the next PICC. Note that this may take some time as all data blocks are dumped, so
 * keep the PICCs at reading distance until complete.
 *
 * @license Released into the public domain.
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
 */

#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN          10         // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

MFRC522::MIFARE_Key key0A = {keyByte: {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5}}; // écriture des clés de chaque secteur
MFRC522::MIFARE_Key key0B = {keyByte: {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5}}; // écriture des clés de chaque secteur

MFRC522::MIFARE_Key key1A = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};
MFRC522::MIFARE_Key key1B = {keyByte: {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}};

//MFRC522::MIFARE_Key key1A = {keyByte: {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5}};
//MFRC522::MIFARE_Key key1B = {keyByte: {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5}};

MFRC522::MIFARE_Key key2A = {keyByte: {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5}};
MFRC522::MIFARE_Key key2B = {keyByte: {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5}};

MFRC522::MIFARE_Key key3A = {keyByte: {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5}};
MFRC522::MIFARE_Key key3B = {keyByte: {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5}};

MFRC522::MIFARE_Key key4A = {keyByte: {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5}};
MFRC522::MIFARE_Key key4B = {keyByte: {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5}};

MFRC522::MIFARE_Key key5A = {keyByte: {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5}};
MFRC522::MIFARE_Key key5B = {keyByte: {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5}};

MFRC522::MIFARE_Key key6A = {keyByte: {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5}};
MFRC522::MIFARE_Key key6B = {keyByte: {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5}};

MFRC522::MIFARE_Key key7A = {keyByte: {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5}};
MFRC522::MIFARE_Key key7B = {keyByte: {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5}};

MFRC522::MIFARE_Key key8A = {keyByte: {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5}};
MFRC522::MIFARE_Key key8B = {keyByte: {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5}};

MFRC522::MIFARE_Key key9A = {keyByte: {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5}};
MFRC522::MIFARE_Key key9B = {keyByte: {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5}};

MFRC522::MIFARE_Key key10A = {keyByte: {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5}};
MFRC522::MIFARE_Key key10B = {keyByte: {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5}};

MFRC522::MIFARE_Key key11A = {keyByte: {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5}};
MFRC522::MIFARE_Key key11B = {keyByte: {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5}};

MFRC522::MIFARE_Key key12A = {keyByte: {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5}};
MFRC522::MIFARE_Key key12B = {keyByte: {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5}};

MFRC522::MIFARE_Key key13A = {keyByte: {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5}};
MFRC522::MIFARE_Key key13B = {keyByte: {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5}};

MFRC522::MIFARE_Key key14A = {keyByte: {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5}};
MFRC522::MIFARE_Key key14B = {keyByte: {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5}};

MFRC522::MIFARE_Key key15A = {keyByte: {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5}};
MFRC522::MIFARE_Key key15B = {keyByte: {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5}};

char userInput;		//input série

void setup() {
	Serial.begin(9600);		// Initialize serial communications with the PC
	while (!Serial);		// Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
	SPI.begin();			// Init SPI bus
	mfrc522.PCD_Init();		// Init MFRC522
	delay(4);				// Optional delay. Some board do need more time after init to be ready, see Readme
	mfrc522.PCD_DumpVersionToSerial();	// Show details of PCD - MFRC522 Card Reader details
	//Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
}

void loop() {

  if(Serial.available()>0){

    userInput=Serial.read();

		switch (userInput){
			case 'a':		//porteNiveau1
<<<<<<< HEAD
        if ( ! mfrc522.PICC_IsNewCardPresent()) {
          return;
        }

        if ( ! mfrc522.PICC_ReadCardSerial()) {
          return;
        }
		    Serial.println(F("Card UID:")); 		    // Show some details of the PICC (that is: the tag/card)
		    dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
		    // Serial.println();
				// break;

			case 'b': //porteNiveau2
				readBlock(1, 5);
=======
        // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
            if ( ! mfrc522.PICC_IsNewCardPresent()) {
              return;
            }
    
        // Select one of the cards
            if ( ! mfrc522.PICC_ReadCardSerial()) {
              return;
            }
		    // Show some details of the PICC (that is: the tag/card)
		    Serial.println(F("Card UID:"));
		    dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
		    // Serial.println();
				break;

			case 'b': //porteNiveau2
				readBlock(1, 5);
				break;
>>>>>>> b394495095ec58ea22107cf80630b09a30a4b7a0

			case 'c': //porteNiveau3
				readBlock(2, 8);
				break;

			case 'd': //porteNiveau4
<<<<<<< HEAD
				readBlock(3, 11);
				break;

			case 'e': //hotelNiveau1
				readBlock(4, 15);
				break;

			case 'f': //hotelNiveau2
				readBlock(5, 19);
				break;

			case 'g': //hotelNiveau3
				readBlock(6, 23);
				break;

			case 'h': //distributeurNiveau1
				readBlock(7, 27);
				break;

			case 'i': //distributeurNiveau2
				readBlock(8, 31);
=======
				readBlock(3, 12);
				break;

			case 'e': //hotelNiveau1
				readBlock(4, 16);
				break;

			case 'f': //hotelNiveau2
				readBlock(5, 20);
				break;

			case 'g': //hotelNiveau3
				readBlock(6, 24);
				break;

			case 'h': //distributeurNiveau1
				readBlock(7, 28);
				break;

			case 'i': //distributeurNiveau2
			// readBlock(8, 32);
>>>>>>> b394495095ec58ea22107cf80630b09a30a4b7a0
				break;
			// dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
			// dump_byte_array(dataBlock, 16); Serial.println();
			// status = (MFRC522::StatusCode) mfrc522.MIFARE_Write(blockAddr, dataBlock, 16); //on écrit le nouveau solde au lieu de le décrémenter

			case 'j': //distributeurNiveau3
				break;

			default: return;
  	}
	}
}

/**
 * Helper routine to dump a byte array as hex values to Serial.
 */
void dump_byte_array(byte *buffer, byte bufferSize) {
    for (byte i = 0; i < bufferSize; i++) {
        Serial.print(buffer[i] < 0x10 ? "0" : "");
        Serial.print(buffer[i], HEX);
    }
}

/**
 * Helper routine to dump a byte array as hex values to Serial.
 */
void readBlock( byte sector,
                byte blockAddr) {

// Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
    if ( ! mfrc522.PICC_IsNewCardPresent())
        return;

    // Select one of the cards
    if ( ! mfrc522.PICC_ReadCardSerial())
        return;

    // Show some details of the PICC (that is: the tag/card)
    // Serial.println(F("Card UID:"));
    //dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
    Serial.println();
<<<<<<< HEAD
    Serial.print(F("PICC type: "));
    MFRC522::PICC_Type piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
    Serial.println(mfrc522.PICC_GetTypeName(piccType));
=======
    // Serial.print(F("PICC type: "));
    MFRC522::PICC_Type piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
    // Serial.println(mfrc522.PICC_GetTypeName(piccType));
>>>>>>> b394495095ec58ea22107cf80630b09a30a4b7a0

    // Check for compatibility
    if (    piccType != MFRC522::PICC_TYPE_MIFARE_MINI
        &&  piccType != MFRC522::PICC_TYPE_MIFARE_1K
        &&  piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
<<<<<<< HEAD
        Serial.println(F("This sample only works with MIFARE Classic cards."));
=======
        // Serial.println(F("This sample only works with MIFARE Classic cards."));
>>>>>>> b394495095ec58ea22107cf80630b09a30a4b7a0
        return;
    }

    // that is: sector #sector, covering block #blockAddr up to and including block #trailerBlock
    byte trailerBlock   = ((sector+1)*4)-1;
    MFRC522::StatusCode status;
    byte buffer[18];
    byte size = sizeof(buffer);

    // Authenticate using key A
<<<<<<< HEAD
    Serial.println(F("Authenticating using key A..."));
=======
    // Serial.println(F("Authenticating using key A..."));
>>>>>>> b394495095ec58ea22107cf80630b09a30a4b7a0
    status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key1A, &(mfrc522.uid));
    if (status != MFRC522::STATUS_OK) {
        Serial.print(F("PCD_Authenticate() failed for keyA: "));
        Serial.println(mfrc522.GetStatusCodeName(status));
        return;
    }

    // Authenticate using key B
<<<<<<< HEAD
    Serial.println(F("Authenticating using key B..."));
=======
    //  Serial.println(F("Authenticating using key B..."));
>>>>>>> b394495095ec58ea22107cf80630b09a30a4b7a0
      status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B, trailerBlock, &key1B, &(mfrc522.uid));
      if (status != MFRC522::STATUS_OK) {
          Serial.print(F("PCD_Authenticate() failed for keyB: "));
          Serial.println(mfrc522.GetStatusCodeName(status));
          return;
      }

    // Show the whole sector as it currently is
<<<<<<< HEAD
    Serial.print(F("Current data in sector ")); Serial.print(sector); Serial.println(F(" : "));
    mfrc522.PICC_DumpMifareClassicSectorToSerial(&(mfrc522.uid), &key1A, sector);
    Serial.println();
=======
    // Serial.print(F("Current data in sector ")); Serial.print(sector); Serial.println(F(" : "));
    // mfrc522.PICC_DumpMifareClassicSectorToSerial(&(mfrc522.uid), &key1A, sector);
    // Serial.println();
>>>>>>> b394495095ec58ea22107cf80630b09a30a4b7a0

    // Read data from the block
    Serial.print(F("Lecture bloc ")); Serial.print(blockAddr); Serial.println(F(" : "));
    status = (MFRC522::StatusCode) mfrc522.MIFARE_Read(blockAddr, buffer, &size);
    if (status != MFRC522::STATUS_OK) {
        Serial.print(F("MIFARE_Read() failed: "));
        Serial.println(mfrc522.GetStatusCodeName(status));
    }
    dump_byte_array(buffer, 16); Serial.println();
    Serial.println();

    mfrc522.PICC_HaltA(); // Halt PICC
    mfrc522.PCD_StopCrypto1(); // Stop encryption on PCD
}
