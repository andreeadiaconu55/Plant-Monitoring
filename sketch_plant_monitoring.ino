#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define DHTTYPE DHT11
#define DHTPIN 2
#define LIGHTPIN 8
#define SOILHUMIDITYPIN A0
#define LEDPIN 13
#define MAXDARKTIME 36000000

class PlantMonitor {
public:
  PlantMonitor(int lcdAddress, int lcdCols, int lcdRows) : lcd(lcdAddress, lcdCols, lcdRows), dht(DHTPIN, DHTTYPE) {}

  void init() {
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
  }

  void readSensors() {
    air_humidity = dht.readHumidity();
    air_temperature = dht.readTemperature();

    light_intensity = digitalRead(LIGHTPIN);

    float sum = 0;
    for (int i = 0; i < 500; ++i) {
      sum += analogRead(SOILHUMIDITYPIN);
    }
    soil_humidity = sum / 500;
  }

  void printDetailsOnLCD(bool good_temp, bool good_light, bool good_soil, bool plant_mood) {
    lcd.setCursor(1, 0);

    // Air temperature details
    lcd.print(good_temp ? "t-yey  " : "t->cold  ");

    // Light presence details
    lcd.print(good_light ? "l-yey  " : "l->bad  ");

    lcd.setCursor(0, 1);

    // Soil humidity details
    lcd.print(good_soil ? "s-yey  " : "s->dry  ");

    // Plant mood details
    lcd.print(plant_mood ? "plant-:)" : "plant-:(");
  }

  void monitorPlant() {
    readSensors();

    if (air_temperature < 18.0 || air_temperature > 28.0)
      good_temp = false;
    else
      good_temp = true;

    int current_time = millis();
  if (light_intensity != 1 && dark_start_time + MAXDARKTIME >= current_time) {
    good_light = false;
  }
  else {
    good_light = true;
    dark_start_time = millis();
  }

  if (soil_humidity < 150)
      good_soil = true;
  else
    good_soil = false;

    plant_mood = good_temp && good_light && good_soil;

    printDetailsOnLCD(good_temp, good_light, good_soil, plant_mood);

  if (!plant_mood) {
      digitalWrite(LEDPIN, HIGH);
  } else {
      digitalWrite(LEDPIN, LOW);
  }  
}

private:
  LiquidCrystal_I2C lcd;
  DHT dht;

  float air_humidity, air_temperature, light_intensity, soil_humidity;
  bool good_temp, good_light, good_soil, plant_mood;
  unsigned long dark_start_time = 0;
};

PlantMonitor plantMonitor(0x3F, 20, 4);

void setup() {
  plantMonitor.init();
  Serial.begin(9600);
}

void loop() {
  plantMonitor.monitorPlant();
//masuratori realizate la 30 de minute
  delay(1800000);
}
