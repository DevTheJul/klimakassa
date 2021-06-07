#include <SPI.h>
#include <MFRC522.h>

#define BUZZER D2 //kann auch 2 sein bzw. 4/3
#define SS_PIN D4
#define RST_PIN D3
MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  mfrc522.PCD_Init();
  mfrc522.PCD_SetAntennaGain(0x07<<4);
}

void loop(){
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial() ) {
    Serial.print("Gelesene UID:");
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      // Abstand zwischen HEX-Zahlen und führende Null bei Byte < 16
      Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    } 
    Serial.println(); 
  }
}


//http://www.makerblog.at/2017/11/rfid-transponder-mit-dem-mfrc-522-card-reader-am-arduino-auslesen/
