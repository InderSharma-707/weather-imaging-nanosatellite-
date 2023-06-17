#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306_STM32.h>
#include <BH1750.h>
#include <QMC5883LCompass.h>
#include "DHT.h"

#define DHTPIN PA0
#define DHTTYPE DHT11

#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)

DHT dht(DHTPIN, DHTTYPE);

BH1750 lightMeter;

QMC5883LCompass compass;

Adafruit_SSD1306 display(OLED_RESET);

int a;
float lux;
float t;

void setup() {
  Serial.begin(115200);//SOFTWARE SERIAL BEGIN
  Serial1.begin(9600);

  dht.begin();
  compass.init();
  lightMeter.begin();

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

  startScreen();
  delay(1000);
  display.clearDisplay();

}

void loop() {
  t = dht.readTemperature();

  compass.read();
  a = compass.getAzimuth();

  lux = lightMeter.readLightLevel();

  delay(500);
  MainScreen();
  Serial.println(String(t) + "*" + (String)a + "#" + (String)lux);
  Serial1.println(String(t) + "*" + (String)a + "#" + (String)lux);

}

void startScreen() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(20, 2);
  display.println(F("Weather Imaging "));
  display.setCursor(30, 18);
  display.println(F("CubeSat with "));
  display.setCursor(40, 33);
  display.println(F("Telemetry"));
  display.setCursor(30, 50);
  display.println(F("Transmission"));
  display.display();
  delay(1000);
  display.clearDisplay();
  display.setTextSize(1);
}

void MainScreen()
{
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 6);
  display.println(F("Orientation:"));
  display.setCursor(80, 6);
  display.print(a);
  display.print((char)247);
  display.setCursor(0, 24);
  display.println(F("Temperature:"));
  display.setCursor(80, 24);
  display.print(t);
  display.print((char)247);
  display.print("C");
  display.setCursor(0, 38);
  display.println(F("Infrared \nRadiation:"));
  display.setCursor(80, 43);
  display.print(lux);
  display.display();
  delay(1000);
  display.clearDisplay();
  display.setTextSize(1);
}
