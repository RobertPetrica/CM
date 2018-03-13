#include <LiquidCrystal.h>


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


int led = 9;               //pin digital pentru led
const int sensorPin = A0;  //intrare analogica senzor TMP36

// variabila utilizata
float sensorTemperatura; // variabila senzor temperatura

void setup()
{
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  analogReference(INTERNAL); // stabilire referinta tensiune interna de 1.1 volti
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print(" Statie meteo");
  lcd.setCursor(0, 1);
  lcd.print("cu senzor TMP36");
  delay(2000);

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print(" Made by...");
  lcd.setCursor(0, 1);
  lcd.print("Petrica Robert");
  delay(2000);

  lcd.clear();
}

void loop()
{
    sensorTemperatura = analogRead(sensorPin);
    sensorTemperatura = sensorTemperatura/9.31; //conversie valoare temperatura
    Serial.print(sensorTemperatura);
    Serial.print(" grade Celsius\n");
    if (sensorTemperatura < 50) //se seteaza temperatura de reactie ce comanda ledul
    {
      digitalWrite(led, LOW);

      lcd.setCursor(0,0);
      lcd.print(sensorTemperatura);
      lcd.setCursor(5,0);
      lcd.print("'C max=50'C");
      lcd.setCursor(0,1);
      lcd.print("LED=OFF");
     }
     else
     {
       digitalWrite(led,HIGH);

       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print(sensorTemperatura);
       lcd.setCursor(5,0);
       lcd.print("'C max=50'C");
       lcd.setCursor(0,1);
       lcd.print("LED=ON");
      }
    delay(2000); // timp actualizare citiri temperatura
}
