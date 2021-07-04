#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
#define BUZZER 8 //buzzer pin
#define ACCESS_DELAY 2000
#define DENIED_DELAY 1000
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

void setup()
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();          // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  pinMode(BUZZER, OUTPUT);
  noTone(BUZZER);
  Serial.println("Put your card to the reader...");
  Serial.println();
  digitalWrite(BUZZER, HIGH);
  delay(50);
  digitalWrite(BUZZER, LOW);
  delay(200);

}
void loop()
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content = "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  if (content.substring(1) == "04 CE 9E 4A 44 70 80") //change here the UID of the card/cards that you want to give access
  {
    digitalWrite(BUZZER, HIGH);
    delay(50);
    digitalWrite(BUZZER, LOW);
    delay(200);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("slot_1.txt=\"Kleine Wohnfläche (< 100qm)");
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("price_1.txt=\"170");
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
  }
  if (content.substring(1) == "04 4B 9E 4A 44 70 80") //change here the UID of the card/cards that you want to give access
  {
    digitalWrite(BUZZER, HIGH);
    delay(50);
    digitalWrite(BUZZER, LOW);
    delay(200);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("slot_2.txt=\"Mittlere Wohnfläche (< 200qm)");
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("price_2.txt=\"930");
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
  }
  if (content.substring(1) == "04 BF 9D 4A 44 70 80") //change here the UID of the card/cards that you want to give access
  {
    digitalWrite(BUZZER, HIGH);
    delay(50);
    digitalWrite(BUZZER, LOW);
    delay(200);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("slot_3.txt=\"Große Wohnfläche (> 200qm)");
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("price_3.txt=\"2000");
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
  }
  if (content.substring(1) == "04 73 8D 02 2B 5E 80") //change here the UID of the card/cards that you want to give access
  {
    digitalWrite(BUZZER, HIGH);
    delay(50);
    digitalWrite(BUZZER, LOW);
    delay(200);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("slot_4.txt=\"Heizen mit Holz");
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("price_4.txt=\"160");
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
  }
  if (content.substring(1) == "04 5B 9E 4A 44 70 80") //change here the UID of the card/cards that you want to give access
  {
    digitalWrite(BUZZER, HIGH);
    delay(50);
    digitalWrite(BUZZER, LOW);
    delay(200);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("slot_5.txt=\"Heizen mit Erdgas");
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("price_5.txt=\"1300");
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
  }
  if (content.substring(1) == "04 8A 41 02 2B 5E 80") //change here the UID of the card/cards that you want to give access
  {
    digitalWrite(BUZZER, HIGH);
    delay(50);
    digitalWrite(BUZZER, LOW);
    delay(200);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("slot_6.txt=\"Heizen mit Erdöl"); //nicht fertig ...
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("price_6.txt=\"1600");
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
  }
  if (content.substring(1) == "04 ED 32 52 44 70 80") //change here the UID of the card/cards that you want to give access
  {
    digitalWrite(BUZZER, HIGH);
    delay(50);
    digitalWrite(BUZZER, LOW);
    delay(200);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("slot_7.txt=\"Milchprodukte");
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("price_7.txt=\"320");
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
  }
  if (content.substring(1) == "04 4F 95 4A 44 70 81") //change here the UID of the card/cards that you want to give access
  {
    digitalWrite(BUZZER, HIGH);
    delay(50);
    digitalWrite(BUZZER, LOW);
    delay(200);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("slot_8.txt=\"Fleischprodukte");
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("price_8.txt=\"1000");
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
  }
  if (content.substring(1) == "04 4B 95 4A 44 70 81") //change here the UID of the card/cards that you want to give access
  {
    digitalWrite(BUZZER, HIGH);
    delay(50);
    digitalWrite(BUZZER, LOW);
    delay(200);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("slot_9.txt=\"Exotische Lebensmittel");
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("price_9.txt=\"350");
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
  }
  if (content.substring(1) == "04 C1 9F 4A 44 70 80") //change here the UID of the card/cards that you want to give access
  {
    digitalWrite(BUZZER, HIGH);
    delay(50);
    digitalWrite(BUZZER, LOW);
    delay(200);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("slot_10.txt=\"Lebensmittel wegwerfen");
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("price_10.txt=\"500");
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
  }
  if (content.substring(1) == "04 FF 22 7 0 45 0") //change here the UID of the card/cards that you want to give access
  {
    digitalWrite(BUZZER, HIGH);
    delay(50);
    digitalWrite(BUZZER, LOW);
    delay(200);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("slot_11.txt=\"Autofahren (< 10000km)");
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("price_11.txt=\"1100");
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
  }
  if (content.substring(1) == "04 9F 1B 8B 0 E4 0") //change here the UID of the card/cards that you want to give access
  {
    digitalWrite(BUZZER, HIGH);
    delay(50);
    digitalWrite(BUZZER, LOW);
    delay(200);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("slot_12.txt=\"Autofahren (< 30000km)");
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("price_12.txt=\"1100");
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
  }
  if (content.substring(1) == "04 67 37 8D 0 FA 0") //change here the UID of the card/cards that you want to give access
  {
    digitalWrite(BUZZER, HIGH);
    delay(50);
    digitalWrite(BUZZER, LOW);
    delay(200);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("slot_13.txt=\"Autofahren (> 30000km)");
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("price_13.txt=\"8000");
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
  }
  if (content.substring(1) == "04 DC E3 4A 44 70 80") //change here the UID of the card/cards that you want to give access
  {
    digitalWrite(BUZZER, HIGH);
    delay(50);
    digitalWrite(BUZZER, LOW);
    delay(200);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("slot_14.txt=\"Öffentliche Verkehrsmittel");
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("price_14.txt=\"1100");
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
  }
  if (content.substring(1) == "04 DC E3 4A 44 70 80") //change here the UID of the card/cards that you want to give access
  {
    digitalWrite(BUZZER, HIGH);
    delay(50);
    digitalWrite(BUZZER, LOW);
    delay(200);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("slot_15.txt=\"Öffentliche Verkehrsmittel");
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("price_15.txt=\"1100");
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
  }
  if (content.substring(1) == "04 C4 E3 4A 44 70 80") //change here the UID of the card/cards that you want to give access
  {
    digitalWrite(BUZZER, HIGH);
    delay(50);
    digitalWrite(BUZZER, LOW);
    delay(200);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("slot_16.txt=\"Flugreise");
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("price_16.txt=\"3600");
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
  }
  if (content.substring(1) == "04 4B 46 52 44 70 81") //change here the UID of the card/cards that you want to give access
  {
    digitalWrite(BUZZER, HIGH);
    delay(50);
    digitalWrite(BUZZER, LOW);
    delay(200);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("slot_17.txt=\"Kreuzfahrt");
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("price_17.txt=\"800");
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
  }
  if (content.substring(1) == "04 89 9E 4A 44 70 80") //change here the UID of the card/cards that you want to give access
  {
    digitalWrite(BUZZER, HIGH);
    delay(50);
    digitalWrite(BUZZER, LOW);
    delay(200);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("slot_18.txt=\"Erneuerbare Energie");
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("price_18.txt=\"250");
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
  }
  if (content.substring(1) == "04 7A CB 02 2B 5E 80") //change here the UID of the card/cards that you want to give access
  {
    digitalWrite(BUZZER, HIGH);
    delay(50);
    digitalWrite(BUZZER, LOW);
    delay(200);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("slot_19.txt=\"Fossile Energie"); //noch nicht fertig...
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("price_19.txt=\"1900");
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
  }
  if (content.substring(1) == "04 57 95 4A 44 70 81") //change here the UID of the card/cards that you want to give access
  {
    digitalWrite(BUZZER, HIGH);
    delay(50);
    digitalWrite(BUZZER, LOW);
    delay(200);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("slot_20.txt=\"Bekleidung (<200€)"); 
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("price_20.txt=\"1900");
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
  }  
  if (content.substring(1) == "04 C 2C 52 44 70 81") //change here the UID of the card/cards that you want to give access
  {
    digitalWrite(BUZZER, HIGH);
    delay(50);
    digitalWrite(BUZZER, LOW);
    delay(200);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("slot_21.txt=\"Bekleidung (>200€)"); 
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("price_21.txt=\"1000");
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
  } 
  if (content.substring(1) == "04 E0 92 4A 44 70 80") //change here the UID of the card/cards that you want to give access
  {
    digitalWrite(BUZZER, HIGH);
    delay(50);
    digitalWrite(BUZZER, LOW);
    delay(200);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("slot_22.txt=\"Unterhaltung (<200€)"); 
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("price_22.txt=\"300");
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
  } 
  if (content.substring(1) == "04 B0 E3 4A 44 70 80") //change here the UID of the card/cards that you want to give access
  {
    digitalWrite(BUZZER, HIGH);
    delay(50);
    digitalWrite(BUZZER, LOW);
    delay(200);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("slot_23.txt=\"Unterhaltung (>200€)"); 
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.print("price_23.txt=\"1000");
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
  } 
}
