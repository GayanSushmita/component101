// Humidity and Temperature Sensor DHT11

#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
    Serial.begin(9600);
    dht.begin(); // initialize the sensor
}

void loop()
{
    // wait a few seconds between measurements.
    delay(2000);
    // read humidity
    float humi = dht.readHumidit();
    // read temperature as Celsius
    float tempC = dht.readTemperature();
    // read temperature as Fahrenheit
    float tempF = dht.readTemperature(true);

    // check if any reads failed
    if (isnan(humi) || isnan(tempC) || isnan(tempF))
    {
        Serial.println("Failed to read from DHT sensor!");
    }
    else
    {
        Serial.print("Humidity: ");
        Serial.print(humi);
        Serial.print("%");

        Serial.print(" | ");

        Serial.print("Tempurature: ");
        Serial.print(tempC);
        Serial.print("C ~ ");
        Serial.print(tempF);
        Serial.print(" F ");
    }
}