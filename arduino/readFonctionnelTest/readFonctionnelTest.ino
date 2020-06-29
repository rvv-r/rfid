#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9
#define SS_PIN          10

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Créé une instance de MFRC522

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
byte sector;
byte ValueBlock;
byte blockAddr;
byte trailerBlock;
MFRC522::StatusCode status;
byte buffer[18];
byte size = sizeof(buffer);

int32_t itemPrice;
int32_t value;

/**
   Initialisation
*/
void setup() {
  Serial.begin(9600); // Initialise les communications séries avec le PC
  while (!Serial);    // Ne fais rien si aucun port série n'est ouvert
  SPI.begin();        // Initialise le bus SPI
  mfrc522.PCD_Init(); // Initialise la carte MFRC522
}

/**
   Boucle principale
*/
void loop() {

  if(Serial.available()>0){

    userInput=Serial.read(); Serial.println(userInput);

    switch (userInput){

      case 'a':  // porteNiveau1 Secteur 0
      if ( ! mfrc522.PICC_IsNewCardPresent())
        return;

      if ( ! mfrc522.PICC_ReadCardSerial()) // Sélectionne une carte
        return;

      dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size); // Retourne l'UID

      break;

////////////////////////////////////////////////////////////////////////////////////////////

      case 'b':  // porteNiveau2 Secteur 1
        if ( ! mfrc522.PICC_IsNewCardPresent())
          return;

        if ( ! mfrc522.PICC_ReadCardSerial()) // Sélectionne une carte
          return;

        sector = 1;
        blockAddr = 4;
        trailerBlock = ((sector + 1) * 4) - 1;

        status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key1A, &(mfrc522.uid)); // Authentification avec la clé A
        if (status != MFRC522::STATUS_OK)
          return;

        status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B, trailerBlock, &key1B, &(mfrc522.uid)); // Authentification avec la clé B
        if (status != MFRC522::STATUS_OK)
          return;

        /*
        Serial.print(F("Lecture bloc ")); Serial.print(blockAddr); Serial.println(F(" : "));
        */
        status = (MFRC522::StatusCode) mfrc522.MIFARE_Read(blockAddr, buffer, &size); // Lis les données du bloc 4 (Secteur 1)
        if (status != MFRC522::STATUS_OK)
          return;

        dump_byte_array(buffer, 16); Serial.println();
        mfrc522.PCD_StopCrypto1(); // Arrête le chiffrement sur la carte

        break;

////////////////////////////////////////////////////////////////////////////////////////////

      case 'c': // porteNiveau3 Secteur 2
        if ( ! mfrc522.PICC_IsNewCardPresent())
          return;

        if ( ! mfrc522.PICC_ReadCardSerial()) // Sélectionne une carte
          return;

        sector = 2;
        blockAddr = 8;
        trailerBlock = ((sector + 1) * 4) - 1;

        status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key2A, &(mfrc522.uid)); // Authentification avec la clé A
        if (status != MFRC522::STATUS_OK)
          return;

        status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B, trailerBlock, &key2B, &(mfrc522.uid)); // Authentification avec la clé B
        if (status != MFRC522::STATUS_OK)
          return;

        /*
        Serial.print(F("Lecture bloc ")); Serial.print(blockAddr); Serial.println(F(" : "));
        */
        status = (MFRC522::StatusCode) mfrc522.MIFARE_Read(blockAddr, buffer, &size); // Lis les données du bloc 8 (Secteur 2)
        if (status != MFRC522::STATUS_OK)
          return;

        dump_byte_array(buffer, 16); Serial.println();
        mfrc522.PCD_StopCrypto1(); // Arrête le chiffrement sur la carte

        break;

////////////////////////////////////////////////////////////////////////////////////////////

      case 'd': // porteNiveau4 Secteur 3
        if ( ! mfrc522.PICC_IsNewCardPresent())
          return;

        if ( ! mfrc522.PICC_ReadCardSerial()) // Sélectionne une carte
          return;

        sector = 3;
        blockAddr = 12;
        trailerBlock = ((sector + 1) * 4) - 1;

        status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key3A, &(mfrc522.uid)); // Authentification avec la clé A
        if (status != MFRC522::STATUS_OK)
          return;

        status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B, trailerBlock, &key3B, &(mfrc522.uid)); // Authentification avec la clé B
        if (status != MFRC522::STATUS_OK)
          return;
        /*
        Serial.print(F("Lecture bloc ")); Serial.print(blockAddr); Serial.println(F(" : "));
        */
        status = (MFRC522::StatusCode) mfrc522.MIFARE_Read(blockAddr, buffer, &size); // Lis les données du bloc 12 (Secteur 3)
        if (status != MFRC522::STATUS_OK)
          return;

        dump_byte_array(buffer, 16); Serial.println();
        mfrc522.PCD_StopCrypto1(); // Arrête le chiffrement sur la carte

        break;

////////////////////////////////////////////////////////////////////////////////////////////

      case 'e': // hotelNiveau1 Secteur 4
        if ( ! mfrc522.PICC_IsNewCardPresent())
          return;

        if ( ! mfrc522.PICC_ReadCardSerial()) // Sélectionne une carte
          return;

        sector = 4;
        blockAddr = 16;
        trailerBlock   = ((sector + 1) * 4) - 1;

        status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key4A, &(mfrc522.uid)); // Authentification avec la clé A
        if (status != MFRC522::STATUS_OK)
          return;

        status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B, trailerBlock, &key4B, &(mfrc522.uid)); // Authentification avec la clé B
        if (status != MFRC522::STATUS_OK)
          return;

        Serial.print(F("Lecture bloc ")); Serial.print(blockAddr); Serial.println(F(" : "));
        status = (MFRC522::StatusCode) mfrc522.MIFARE_Read(blockAddr, buffer, &size); // Lis les données du bloc 16 (Secteur 4)
        if (status != MFRC522::STATUS_OK)
          return;

        dump_byte_array(buffer, 16); Serial.println();
        mfrc522.PCD_StopCrypto1(); // Arrête le chiffrement sur la carte

        break;

////////////////////////////////////////////////////////////////////////////////////////////

      case 'f': // hotelNiveau2 Secteur 5
        if ( ! mfrc522.PICC_IsNewCardPresent())
          return;

        if ( ! mfrc522.PICC_ReadCardSerial()) // Sélectionne une carte
          return;

        sector = 5;
        blockAddr = 20;
        trailerBlock = ((sector + 1) * 4) - 1;

        status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key5A, &(mfrc522.uid)); // Authentification avec la clé A
        if (status != MFRC522::STATUS_OK)
          return;

        status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B, trailerBlock, &key5B, &(mfrc522.uid)); // Authentification avec la clé B
        if (status != MFRC522::STATUS_OK)
          return;

        /*
        Serial.print(F("Lecture bloc ")); Serial.print(blockAddr); Serial.println(F(" : "));
        */
        status = (MFRC522::StatusCode) mfrc522.MIFARE_Read(blockAddr, buffer, &size); // Lis les données du bloc 20 (Secteur 5)
        if (status != MFRC522::STATUS_OK)
          return;

        dump_byte_array(buffer, 16); Serial.println();
        mfrc522.PCD_StopCrypto1(); // Arrête le chiffrement sur la carte

        break;

////////////////////////////////////////////////////////////////////////////////////////////

      case 'g': // hotelNiveau3 Secteur 6
        if ( ! mfrc522.PICC_IsNewCardPresent())
          return;

        if ( ! mfrc522.PICC_ReadCardSerial()) // Sélectionne une carte
          return;

        sector = 6;
        blockAddr = 24;
        trailerBlock = ((sector + 1) * 4) - 1;

        status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key6A, &(mfrc522.uid)); // Authentification avec la clé A
        if (status != MFRC522::STATUS_OK)
          return;

        status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B, trailerBlock, &key6B, &(mfrc522.uid)); // Authentification avec la clé B
        if (status != MFRC522::STATUS_OK)
          return;

        status = (MFRC522::StatusCode) mfrc522.MIFARE_Read(blockAddr, buffer, &size); // Lis les données du bloc 24 (Secteur 6)
        if (status != MFRC522::STATUS_OK)
          return;

        dump_byte_array(buffer, 16); Serial.println();
        mfrc522.PCD_StopCrypto1(); // Arrête le chiffrement sur la carte

        break;

/////////////////////////////Distributeur1 Coca///////////////////////////////////////////////////////////////

      case 'h': // distributeurNiveau1 Secteur 7
        if ( ! mfrc522.PICC_IsNewCardPresent())
          return;

        if ( ! mfrc522.PICC_ReadCardSerial()) // Sélectionne une carte
          return;

        sector         = 7;
        ValueBlock    = 28;
        trailerBlock   = ((sector + 1) * 4) - 1;
        itemPrice = 3; // Coca = 3€

        status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key7A, &(mfrc522.uid)); // Authentification avec la clé A
        if (status != MFRC522::STATUS_OK)
            return;

        status = mfrc522.MIFARE_GetValue(ValueBlock, &value);
        Serial.print("B"); //B pour before
        Serial.print(value); Serial.println("Y");

        status = mfrc522.MIFARE_Read(trailerBlock, buffer, &size);
        if (status != MFRC522::STATUS_OK)
            return;

        status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B, trailerBlock, &key7B, &(mfrc522.uid)); // Authentification avec la clé B
        if (status != MFRC522::STATUS_OK)
            return;

        if (value>=0 && value>itemPrice){
          Serial.print("P"); Serial.print(itemPrice); Serial.println("X");
          status = mfrc522.MIFARE_Decrement(ValueBlock, itemPrice); // Décrémente itemPrice de ValueBlock et stocke le résultat dans ValueBlock
          if (status != MFRC522::STATUS_OK)
              return;

          status = mfrc522.MIFARE_Transfer(ValueBlock); // Transfère la nouvelle valeur de ValueBock sur la carte
          if (status != MFRC522::STATUS_OK)
              return;

          status = mfrc522.MIFARE_GetValue(ValueBlock, &value); // Récupère la nouvelle valeur du ValueBlock
          if (status != MFRC522::STATUS_OK)
              return;

          Serial.print("A"); Serial.print(value); Serial.println("Z");
          Serial.println("Coca");
          Serial.println();
        }

        else{
          Serial.println("Solde insuffisant");
          Serial.println();
        }

        mfrc522.PCD_StopCrypto1(); // Arrête le chiffrement sur la carte

        break;

/////////////////////////////Distributeur1 Evian///////////////////////////////////////////////////////////////

      case 'i': // distributeurNiveau1 Secteur 7
        if ( ! mfrc522.PICC_IsNewCardPresent())
          return;

        if ( ! mfrc522.PICC_ReadCardSerial()) // Sélectionne une carte
          return;

        sector         = 2;
        ValueBlock    = 8;
        trailerBlock   = ((sector + 1) * 4) - 1;
        itemPrice = 1; // evian = 1€

        status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key7A, &(mfrc522.uid)); // Authentification avec la clé A
        if (status != MFRC522::STATUS_OK)
            return;

        status = mfrc522.MIFARE_GetValue(ValueBlock, &value);
        Serial.print("Solde : "); Serial.print(value); Serial.println("€");

        status = mfrc522.MIFARE_Read(trailerBlock, buffer, &size);
        if (status != MFRC522::STATUS_OK)
            return;

        status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B, trailerBlock, &key7B, &(mfrc522.uid)); // Authentification avec la clé B
        if (status != MFRC522::STATUS_OK)
            return;

        if (value>=0 && value>itemPrice){
          Serial.print("Achat boisson à "); Serial.print(itemPrice); Serial.println("€");
          status = mfrc522.MIFARE_Decrement(ValueBlock, itemPrice); // Décrémente itemPrice de ValueBlock et stocke le résultat dans ValueBlock
          if (status != MFRC522::STATUS_OK)
              return;

          status = mfrc522.MIFARE_Transfer(ValueBlock); // Transfère la nouvelle valeur de ValueBock sur la carte
          if (status != MFRC522::STATUS_OK)
              return;

          status = mfrc522.MIFARE_GetValue(ValueBlock, &value); // Récupère la nouvelle valeur du ValueBlock
          if (status != MFRC522::STATUS_OK)
              return;

          Serial.print(F("Nouveau solde :")); Serial.print(value); Serial.println("€");
          Serial.println("Obtenu : Evian"); Serial.println();
        }

        else{
          Serial.println("Solde insuffisant"); Serial.println();
        }

        mfrc522.PCD_StopCrypto1(); // Arrête le chiffrement sur la carte

        break;

/////////////////////////////Distributeur1 Sprite///////////////////////////////////////////////////////////////

      case 'j': // distributeurNiveau1 Secteur 7
        if ( ! mfrc522.PICC_IsNewCardPresent())
          return;

        if ( ! mfrc522.PICC_ReadCardSerial()) // Sélectionne une carte
          return;

        sector         = 2;
        ValueBlock    = 8;
        trailerBlock   = ((sector + 1) * 4) - 1;
        itemPrice = 2; // Sprite = 2€noi

        status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key7A, &(mfrc522.uid)); // Authentification avec la clé A
        if (status != MFRC522::STATUS_OK)
            return;

        status = mfrc522.MIFARE_GetValue(ValueBlock, &value);
        Serial.print("Solde : "); Serial.print(value); Serial.println("€");

        status = mfrc522.MIFARE_Read(trailerBlock, buffer, &size);
        if (status != MFRC522::STATUS_OK)
            return;

        status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B, trailerBlock, &key7B, &(mfrc522.uid)); // Authentification avec la clé B
        if (status != MFRC522::STATUS_OK)
            return;

        if (value>=0 && value>itemPrice){
          Serial.print("Achat boisson à "); Serial.print(itemPrice); Serial.println("€");
          status = mfrc522.MIFARE_Decrement(ValueBlock, itemPrice); // Decrement 10 from the value of ValueBlock and store the result in ValueBlock.
          if (status != MFRC522::STATUS_OK)
              return;

          status = mfrc522.MIFARE_Transfer(ValueBlock); // Transfère la nouvelle valeur de ValueBock sur la carte
          if (status != MFRC522::STATUS_OK)
              return;

          status = mfrc522.MIFARE_GetValue(ValueBlock, &value); // Récupère la nouvelle valeur du ValueBlock
          if (status != MFRC522::STATUS_OK)
              return;

          Serial.print(F("Nouveau solde :")); Serial.print(value); Serial.println("€");
          Serial.println("Obtenu : Sprite");
          Serial.println();
        }

        else{
          Serial.println("Solde insuffisant");
          Serial.println();
        }

        mfrc522.PCD_StopCrypto1(); // Arrête le chiffrement sur la carte

        break;

/////////////////////////////Distributeur1 Ice Tea///////////////////////////////////////////////////////////////

      case 'k': // distributeurNiveau1 Secteur 7
        if ( ! mfrc522.PICC_IsNewCardPresent())
          return;

        if ( ! mfrc522.PICC_ReadCardSerial()) // Sélectionne une carte
          return;

        sector         = 2;
        ValueBlock    = 8;
        trailerBlock   = ((sector + 1) * 4) - 1;
        itemPrice = 2; // Ice tea = 2€

        status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key7A, &(mfrc522.uid)); // Authentification avec la clé A
        if (status != MFRC522::STATUS_OK)
            return;

        status = mfrc522.MIFARE_GetValue(ValueBlock, &value);
        Serial.print("Solde : "); Serial.print(value); Serial.println("€");

        status = mfrc522.MIFARE_Read(trailerBlock, buffer, &size);
        if (status != MFRC522::STATUS_OK)
            return;

        status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B, trailerBlock, &key7B, &(mfrc522.uid)); // Authentification avec la clé B
        if (status != MFRC522::STATUS_OK)
            return;

        if (value>=0 && value>itemPrice){
          Serial.print("Achat boisson à "); Serial.print(itemPrice); Serial.println("€");
          status = mfrc522.MIFARE_Decrement(ValueBlock, itemPrice); // Decrement 10 from the value of ValueBlock and store the result in ValueBlock.
          if (status != MFRC522::STATUS_OK)
              return;

          status = mfrc522.MIFARE_Transfer(ValueBlock); // Transfère la nouvelle valeur de ValueBock sur la carte
          if (status != MFRC522::STATUS_OK)
              return;

          status = mfrc522.MIFARE_GetValue(ValueBlock, &value); // Récupère la nouvelle valeur du ValueBlock
          if (status != MFRC522::STATUS_OK)
              return;

          Serial.print(F("Nouveau solde :")); Serial.print(value); Serial.println("€");
          Serial.println("Obtenu : Ice tea");
          Serial.println();
        }

        else{
          Serial.println("Solde insuffisant");
          Serial.println();
        }

        mfrc522.PCD_StopCrypto1(); // Arrête le chiffrement sur la carte

        break;

////////////////////////////////Distributeur2////////////////////////////////////////////////////////////

      case 'l': // distributeurNiveau2 Secteur 8
        if ( ! mfrc522.PICC_IsNewCardPresent())
          return;

        if ( ! mfrc522.PICC_ReadCardSerial()) // Sélectionne une carte
          return;

        sector         = 2;
        ValueBlock    = 8;
        trailerBlock   = ((sector + 1) * 4) - 1;
        itemPrice = 1; // Evian = 1€

        status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key8A, &(mfrc522.uid)); // Authentification avec la clé A
        if (status != MFRC522::STATUS_OK)
            return;

        status = mfrc522.MIFARE_GetValue(ValueBlock, &value);
        Serial.print("Solde : "); Serial.print(value); Serial.println("€");

        status = mfrc522.MIFARE_Read(trailerBlock, buffer, &size); // Read the sector trailer as it is currently stored on the PICC
        if (status != MFRC522::STATUS_OK)
            return;

        status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B, trailerBlock, &key8B, &(mfrc522.uid)); // Authentification avec la clé B
        if (status != MFRC522::STATUS_OK) {
            return;
        }

        if (value>=0 && value>itemPrice){
          Serial.print("Achat boisson à "); Serial.print(itemPrice); Serial.println("€");
          Serial.println("Obtenu : evian");
          Serial.print(F("Calcul du nouveau solde : ")); Serial.print(value-itemPrice); Serial.println("€");
          Serial.println();

          delay(200);

          status = mfrc522.MIFARE_Decrement(ValueBlock, itemPrice); // Decrement itemPrice from the value of ValueBlock and store the result in ValueBlock.
          if (status != MFRC522::STATUS_OK)
              return;

          status = mfrc522.MIFARE_Transfer(ValueBlock); // Transfère la nouvelle valeur de ValueBock sur la carte
          if (status != MFRC522::STATUS_OK)
              return;

          status = mfrc522.MIFARE_GetValue(ValueBlock, &value); // Récupère la nouvelle valeur du ValueBlock
          Serial.print(F("Nouveau solde : ")); Serial.print(value); Serial.println("€");
          if (status != MFRC522::STATUS_OK)
              return;
        }

        else{
          Serial.println("Solde insuffisant");
          Serial.println();
        }

        mfrc522.PCD_StopCrypto1(); // Arrête le chiffrement sur la carte

        break;

///////////////////////////////Distributeur3 /////////////////////////////////////////////////////////////

      case 'm': // distributeurNiveau1 sprite
        if ( ! mfrc522.PICC_IsNewCardPresent())
          return;

        if ( ! mfrc522.PICC_ReadCardSerial()) // Sélectionne une carte
          return;

        sector         = 2;
        ValueBlock    = 8;
        trailerBlock   = ((sector + 1) * 4) - 1;
        itemPrice = 2; // Sprite = 2€


        status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key9A, &(mfrc522.uid)); // Authentification avec la clé A
        if (status != MFRC522::STATUS_OK)
            return;

        status = mfrc522.MIFARE_GetValue(ValueBlock, &value);
        Serial.print("Solde : "); Serial.print(value); Serial.println("€");

        status = mfrc522.MIFARE_Read(trailerBlock, buffer, &size);
        if (status != MFRC522::STATUS_OK)
            return;

        status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B, trailerBlock, &key9B, &(mfrc522.uid)); // Authentification avec la clé B
        if (status != MFRC522::STATUS_OK)
            return;

        if (value>=0 && value>itemPrice){
          Serial.print("Achat boisson à "); Serial.print(itemPrice); Serial.println("€");
          delay(300);
          status = mfrc522.MIFARE_SetValue(ValueBlock, value-itemPrice); // Decrement 10 from the value of ValueBlock and store the result in ValueBlock.
          if (status != MFRC522::STATUS_OK)
              return;

          status = mfrc522.MIFARE_GetValue(ValueBlock, &value); // Show the new value of ValueBlock
          if (status != MFRC522::STATUS_OK)
              return;

          Serial.print(F("Nouveau solde : ")); Serial.print(value); Serial.println("€");
          Serial.println("Obtenu : Sprite");
          Serial.println();
        }

        else{
          Serial.println("Solde insuffisant");
          Serial.println();
        }

        mfrc522.PCD_StopCrypto1(); // Arrête le chiffrement sur la carte

        break;

      default:

        return;
    }
  }
}
///////////////////////////////////////////////////////////////////////////////

/**
  Réalise un dump sous forme de valeurs hexadécimales vers le port série
*/
void dump_byte_array(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? "0" : "");
    Serial.print(buffer[i], HEX);
  }
}
