#include <DHT.h>

#define DHTPIN D1        // указываем номер пина, к которому подключен датчик
#define DHTTYPE DHT11     // указываем тип датчика

#define SensorPin A0

DHT dht(DHTPIN, DHTTYPE);  // создаем объект датчика

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(5000);
  float sensorValue = analogRead(SensorPin);
  float h = dht.readHumidity();     // считываем влажность
  float t = dht.readTemperature();  // считываем температуру
  Serial.print("Влажность воздуха: ");
  Serial.print(h);
  Serial.println("%\t");
  Serial.print("Температура воздуха: ");
  Serial.print(t);
  Serial.println("°C");
  Serial.print("Влажность земли: ");
  Serial.println(sensorValue);
}