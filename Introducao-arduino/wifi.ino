#include <common.h>
#include <FirebaseESP32.h>
#include <FirebaseFS.h>
#include <Utils.h>

#include <DHT.h>
#define DHTPIN 4
#define DHTTYPE DHT11

#define FIREBASE_HOST "https://enviadadoswifi-default-rtdb.firebaseio.com/" // URL acima do console de dados
#define FIREBASE_AUTH "iQgqmDqY55DMOAsFholDZ8YeYFOm2gXpUPP7iBVq"// Configurações do projeto > Contas de serviço > Chaves secretas do banco de dados > Copiar chave secreta

FirebaseData firebaseData;
FirebaseJson json;

DHT dht(DHTPIN, DHTTYPE);

#include <WiFi.h>
#define WIFI_SSID "Vivo-Internet-BF17"
#define WIFI_PASSWORD "78814222"

void setup() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.begin(9600);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.print("Connected with IP: ");
  delay(1000);
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
  Firebase.setReadTimeout(firebaseData, 1000 * 60);
  Firebase.setwriteSizeLimit(firebaseData, "tiny");
  dht.begin();

}
void loop() {
  int h = dht.readHumidity();
  int t = dht.readTemperature();
  json.set("/temperatura", t);
  json.set("/umidade", h);
  Firebase.updateNode(firebaseData, "/sensor", json);

}
