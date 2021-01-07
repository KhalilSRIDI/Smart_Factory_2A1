#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>
#define contrast 8
String data_qt;
int i;

int nb_tours = 0;
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);



LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup() {
  Serial.begin(9600);
  pinMode(contrast, OUTPUT);
  digitalWrite(contrast, LOW);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Welcome!!");

  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
}

void loop() {
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Put your card ");
  lcd.setCursor(5, 1);
  lcd.print("for 3s");
  delay(300);
  if (Serial.available() > 0)
  {
    data_qt = Serial.readString();
    lcd.clear();


    lcd.setCursor(0, 1);
    lcd.print(data_qt);
    delay(800);
    for (int positionCounter = 0; positionCounter < 40; positionCounter++)
    {
      lcd.scrollDisplayLeft();
      delay(250);
      if (positionCounter == 39 && nb_tours != 3)
      {
        positionCounter = 0;
        nb_tours++;
      }

      if (nb_tours == 2)
      {
        lcd.clear();
        positionCounter = 40;
      }
    }

  }

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

  String content = "";
  String msg = "";
  byte letter;

  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    /*Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
      Serial.print(mfrc522.uid.uidByte[i], HEX);*/
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }


  content.toUpperCase();

  msg = content + "#";
  //send data
  //delay (5000);

  for (i = 0; i < msg.length(); i++)
  {
    Serial.write(msg[i]);
    delay (100);
  }
  //delay (1500);
  //recieve qt data
  if (Serial.available() > 0)
  {
    data_qt = Serial.readString();
    lcd.clear();
    lcd.print(data_qt);
  }
}
