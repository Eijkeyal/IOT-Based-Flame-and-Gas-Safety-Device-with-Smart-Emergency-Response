#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define GAS_ANALOG      A0
#define FLAME_ANALOG    A1
#define BUZZER_PIN      7
#define RELAY_PIN       8

#define GAS_THRESHOLD    150
#define FLAME_THRESHOLD  40   

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, HIGH);

  lcd.init();
  lcd.backlight();
  Serial.begin(9600);

  lcd.print("Initializing");
  delay(1500);
  lcd.clear();
}

void loop() {

  int gasValue   = analogRead(GAS_ANALOG);
  int flameValue = analogRead(FLAME_ANALOG);

  bool gasDetected   = gasValue > GAS_THRESHOLD;
  bool flameDetected = flameValue < FLAME_THRESHOLD;  // low = fire

  lcd.setCursor(0, 0);
  lcd.print("G:");
  lcd.print(gasValue);
  lcd.print(" F:");
  lcd.print(flameValue);
  lcd.print("   ");

  lcd.setCursor(0, 1);
  lcd.setCursor(0, 1);
  if (flameDetected && gasDetected) {
    lcd.print("FIRE & GAS   "); 
  } else if (flameDetected) {
    lcd.print("FIRE         "); 
  } else if (gasDetected) {
    lcd.print("GAS          ");  
  } else {
    lcd.print("SAFE         "); 
  }

  if (flameDetected && gasDetected) {
    digitalWrite(BUZZER_PIN, HIGH);
  }
  else if (flameDetected) {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(100);
    digitalWrite(BUZZER_PIN, LOW);
    delay(100);
  }
  else if (gasDetected) {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(200);
    digitalWrite(BUZZER_PIN, LOW);
    delay(200);
  }
  else {
    digitalWrite(BUZZER_PIN, LOW);
    delay(500);
  }

  if (flameDetected && gasDetected) {
    digitalWrite(RELAY_PIN, LOW);
  }
   else if(flameDetected){
    digitalWrite(RELAY_PIN, LOW);
  }
  else {
    digitalWrite(RELAY_PIN, HIGH);
  }
}