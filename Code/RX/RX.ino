#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const byte HC12RxdPin = A2;                  // Recieve Pin on HC12
const byte HC12TxdPin = A3;                  // Transmit Pin on HC12

String val;
float a;
float t;
float lux;

SoftwareSerial hc12(HC12TxdPin, HC12RxdPin); // Create Software Serial Port

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);                       // Open serial port to computer
  hc12.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  startScreen();
  delay(1000);
  display.clearDisplay();
}

void loop()
{
  if (hc12.available())
  {
    val = hc12.readStringUntil('\n');
    val.trim();
    Serial.print("val = ");
    Serial.println(val);
    t = val.substring(0, val.indexOf('*')).toInt();
    a = val.substring(val.indexOf('*') + 1, val.indexOf('#')).toInt();
    lux = val.substring(val.indexOf('#') + 1, val.length()).toInt();
    Serial.print(t);
    Serial.print(a);
    Serial.print(lux);
    MainScreen();
  }


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


void WaitingScreen() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(20, 2);
  display.println(F("Weather Imaging "));
  display.setCursor(30, 18);
  display.println(F("00000000 "));
  display.setCursor(40, 33);
  display.println(F("Telemetry"));
  display.setCursor(30, 50);
  display.println(F("Transmission"));
  display.display();
  delay(1000);
  display.clearDisplay();
  display.setTextSize(1);
}
