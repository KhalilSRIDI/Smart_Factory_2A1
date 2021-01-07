#define PIN_BUZZER 11
#include <Wire.h>
#include <LiquidCrystal_I2C.h> // pour télécharger la librairie: croquis - include library - manage libraries - LiquidCrystal_I2C.h de Frank de Brabander
LiquidCrystal_I2C lcd(0x27,16,2); //écran LCD 0x27 avec 16 colonnes et 2 lignes (ligne 0 et ligne 1)

int inputPin = 4;
// choose the input pin (for PIR sensor)
          int pirState = LOW;             // we start, assuming no motion detected
          int val = 0;  
          #define PIN_LED1 5 //define the LED pins
          #define PIN_LED2 6
          char data;
         
         
         // variable for reading the pin status
           
          void setup() {
            lcd.begin(); //initialisation de l'écran LCD
lcd.cursor_on();
lcd.blink_on();
lcd.backlight();
lcd.cursor_off();
lcd.blink_off();
            pinMode(inputPin, INPUT);     // declare sensor as input

                pinMode(PIN_LED2,OUTPUT);
                pinMode(PIN_LED1,OUTPUT);
           
            Serial.begin(9600);
          }
           
          void loop(){
            val = digitalRead(inputPin);  // read input value
            if (val == HIGH) {            // check if the input is HIGH
              if (pirState == LOW) {
                // we have just turned on
                 noTone(PIN_BUZZER);
                Serial.print("       Pas de Place     ");
                //LCD
                lcd.setCursor(0,0); // écriture du texte sur la ligne 1 colonne 5 (centré)
                lcd.print("pas de place "); // texte "hello" sur ligne 1 colonne 5
            lcd.setCursor(0,1); // écriture du texte sur la ligne 2 colonne 7 (centré)
            lcd.print("pour un materiel");
//Serial.print("1");// texte "ok" sur ligne 2 colonne 7
                // We only want to print on the output change, not state
                pirState = HIGH;
              }
            } else {  
              if (pirState == HIGH){

               
                tone(PIN_BUZZER,1000);
                          delay(200);
                          noTone(PIN_BUZZER);
                          tone(PIN_BUZZER,1000);
                          delay(200);
                          noTone(PIN_BUZZER);
                         
                // we have just turned of
                 Serial.print("      Place libre    ");
                 //LCD
                 lcd.setCursor(0,0); // écriture du texte sur la ligne 1 colonne 5 (centré)
lcd.print(" Place libre"); // texte "hello" sur ligne 1 colonne 5
lcd.setCursor(0,1); // écriture du texte sur la ligne 2 colonne 7 (centré)
lcd.print("pour un materiel"); // texte "ok" sur ligne 2 colonne 7
//Serial.print("0");
                // We only want to print on the output change, not state
                pirState = LOW;
              }
            }
            if(Serial.available())
             
  {data=Serial.read();


  if(data=='1') //ytafi
  { digitalWrite(PIN_LED2,HIGH);
    //Serial.write('1');
   
     
  }
    else if (data=='0') //ycha3el
  {
    digitalWrite(PIN_LED2,LOW);
   //Serial.write('0');
  }
   if(data=='2') //ytafi
  { digitalWrite(PIN_LED1,HIGH);
    //Serial.write('2');
   
     
  }
 
    else if (data=='3')
  {
    digitalWrite(PIN_LED1,LOW);
   // Serial.write('3');
 
  }
 
  }
// Serial.print("      Place occupee    ");
}
