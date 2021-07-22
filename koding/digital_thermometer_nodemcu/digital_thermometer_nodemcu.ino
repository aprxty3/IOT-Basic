#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SimpleDHT.h>

const int pinDHT11 = 0;
SimpleDHT11 dht11(pinDHT11);
LiquidCrystal_I2C lcd(0x27, 16, 2); //atau 0x3F

void setup() {
  Serial.begin(115200);

  Wire.begin();
  lcd.init();   // initializing the LCD
  lcd.backlight(); // Enable or Turn On the backlight

  // Pindahkan kursor ke kolom 0 dan baris 0 (baris ke-1)
  lcd.setCursor(0, 0);
  // Cetak ke layar
  lcd.print("IOT PROJECT!");

  // Pindahkan kursor ke kolom 0 dan baris 1 (baris ke-2)
  lcd.setCursor(0, 1);
  lcd.print("AXAR SCHOOL");

  delay(1000);
  //bersihkan layar untuk diganti dengan tulisan lain
  lcd.clear();
}

void loop() {
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);
    return;
  }

  lcd.setCursor(0, 0);
  lcd.print("Temperatur:"); lcd.print((int)temperature); lcd.print("*C");

  lcd.setCursor(0, 1);
  lcd.print("Kelembaban:"); lcd.print((int)humidity); lcd.print(" H");

  delay(1000);
}
