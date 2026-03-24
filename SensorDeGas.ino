#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int pinMQ2 = 34;      
const int pinBuzzer = 5;    

int valorGas = 0;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();

  pinMode(pinMQ2, INPUT);
  pinMode(pinBuzzer, OUTPUT);

  lcd.setCursor(0, 0);
  lcd.print("Monitor de Gas");
  delay(1500);
  lcd.clear();
}

void loop() {
  valorGas = analogRead(pinMQ2);
  Serial.print("Leitura MQ-2: ");
  Serial.println(valorGas);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Qualidade:");

  if (valorGas > 2700) {
    lcd.setCursor(0, 1);
    lcd.print("PERIGO!");
    digitalWrite(pinBuzzer, HIGH); 
  }
  else if (valorGas > 2200 && valorGas <= 2700) {
    lcd.setCursor(0, 1);
    lcd.print("RUIM");
    digitalWrite(pinBuzzer, LOW);
  }
  else if (valorGas > 1500) {
    lcd.setCursor(0, 1);
    lcd.print("BOM");
    digitalWrite(pinBuzzer, LOW);   
  } 
  else {
    lcd.setCursor(0, 1);
    lcd.print("MUITO BOM");
    digitalWrite(pinBuzzer, LOW); 
  }

  delay(1000); 
}
