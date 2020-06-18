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

MFRC522::MIFARE_Key key1A = {keyByte: {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5}};
MFRC522::MIFARE_Key key1B = {keyByte: {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5}};

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

  	// Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  	if ( ! mfrc522.PICC_IsNewCardPresent()) {
  		return;
  	}

  	// Select one of the cards
  	if ( ! mfrc522.PICC_ReadCardSerial()) {
  		return;
  	}


		switch (userInput){
			case 'a':		//porteNiveau1
				mfrc522.PICC_DumpUIDToSerial(&(mfrc522.uid));

			case 'b': //porteNiveau2
				byte sector         = 1;
				byte blockAddr      = 4;
				byte trailerBlock   = 7;



			case 'c': //porteNiveau3
				byte sector1         = 2;
				byte blockAddr      = 8;
				byte trailerBlock   = 11;
				mfrc522.PICC_DumpMifareClassicSectorToSerial(&(mfrc522.uid), &key2, sector);

			case 'd': //porteNiveau4
				byte sector1         = 3;
				byte blockAddr      = 12;
				byte trailerBlock   = 15;
				mfrc522.PICC_DumpMifareClassicSectorToSerial(&(mfrc522.uid), &key3, sector);

			case 'e': //hotelNiveau1
				byte sector1         = 4;
				byte blockAddr      = 16;
				byte trailerBlock   = 19;
				mfrc522.PICC_DumpMifareClassicSectorToSerial(&(mfrc522.uid), &key4, sector);

			case 'f': //hotelNiveau2
				byte sector1         = 5;
				byte blockAddr      = 20;
				byte trailerBlock   = 23;
				mfrc522.PICC_DumpMifareClassicSectorToSerial(&(mfrc522.uid), &key5, sector);

			case 'g': //hotelNiveau3
				byte sector1         = 5;
				byte blockAddr      = 20;
				byte trailerBlock   = 23;
				mfrc522.PICC_DumpMifareClassicSectorToSerial(&(mfrc522.uid), &key6, sector);

			case 'h': //distributeurNiveau1

			case 'i': //distributeurNiveau2
			dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
			dump_byte_array(dataBlock, 16); Serial.println();
			status = (MFRC522::StatusCode) mfrc522.MIFARE_Write(blockAddr, dataBlock, 16); //on écrit le nouveau solde au lieu de le décrémenter

			case 'j': //distributeurNiveau3

			default: return;
  	}
	}
}
