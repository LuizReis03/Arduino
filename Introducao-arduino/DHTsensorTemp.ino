#include <dht.h>
const int pino = 23;
dht DHT;

void setup() {
  Serial.begin(9600);
  delay(200);
}

void loop() {
  DHT.read11(pino);
  Serial.print("Umidade: ");
  Serial.println(DHT.humidity);
  Serial.print("Temperatura: ");
  Serial.println(DHT.temperature, 0);
  Serial.print("\n");
  delay(1000);

}
