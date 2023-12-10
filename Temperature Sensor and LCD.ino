#include "DHT.h"
#define DHTPIN 7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#include <LiquidCrystal.h>
byte degree[8] = {
  // Array of bytes
  B11100,  // B stands for binary formatter and the 5 numbers are the pixels
  B10100,
  B11100,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};

// Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7)
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);

  dht.begin();

  lcd.begin(16, 2);  // Initializes the interface to the LCD screen, and specifies the dimensions(width and height) of the display

  lcd.createChar(1, degree);  // Create a custom character for use on the LCD. Up to eight characters of 5x8 pixels are supported
}

void loop() {
  int h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  int t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  int f = dht.readTemperature(true);

  lcd.setCursor(0, 0);
  lcd.print("Temp.......:");
  lcd.print(t);
  lcd.write(1);
  lcd.print("C");
  lcd.setCursor(0, 1);
  lcd.print("Humidity...:");
  lcd.print(h);
  lcd.print("RH");
  delay(2000);  // 2 second delay

  lcd.setCursor(0, 0);  
  lcd.print("Temp.......:");
  lcd.print(f);
  lcd.write(1);
  lcd.print("F");
  lcd.setCursor(0, 1);
  lcd.print("Humidity...:");
  lcd.print(h);
  lcd.print("RH");
  delay(2000);  // 2 second delay

  lcd.clear();  // Write a character to the LCD
}
