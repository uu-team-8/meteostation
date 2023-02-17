#include <Wire.h>
#include <Adafruit_BMP085.h>
#define DELAY 5000

unsigned long lastMillis = 0;
unsigned long actualMillis = 0;

Adafruit_BMP085 bmp;
  
void setup() {
  Serial.begin(115200);
  if (!bmp.begin()) {
  Serial.println("Could not find a valid BMP180 sensor, check wiring!");
  while (1) {}
  }
}
  
void loop() {
    actualMillis = millis();
    if ((actualMillis - lastMillis) > DELAY) {
    Serial.print("Temperature = ");
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");
    
    Serial.print("Pressure = ");
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");
    lastMillis = actualMillis;
    }
}
