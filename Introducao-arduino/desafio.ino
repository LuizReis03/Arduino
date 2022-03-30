//LCD
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 14, 27, 26, 25, 33);
#define potPin A0

//FIREBASE
#include <common.h>
#include <FirebaseESP32.h>
#include <FirebaseFS.h>
#include <Utils.h>
FirebaseData firebaseData;
FirebaseJson json;
#define FIREBASE_HOST "https://bosch-aula-ard-default-rtdb.firebaseio.com/" // URL acima do console de dados
#define FIREBASE_AUTH "4cksG9pyqOxTVTmTJ3JVsZiE1BQKoof1u5cybcPb"// Configurações do projeto > Contas de serviço > Chaves secretas do banco de dados > Copiar chave secreta

//WI-FI
#include <WiFi.h>
#define WIFI_SSID "Vivo-Internet-BF17"
#define WIFI_PASSWORD "78814222"

//DHT
#include <DHT.h>
#include <DHT_U.h>
#define DHTPIN 13
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
const int pino = 13;

void setup() {
  Serial.begin(9600);
  pinMode(potPin, OUTPUT);
  pinMode (32, OUTPUT);
  delay(250);
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
  //declara variaveis
  int h = dht.readHumidity();
  int t = dht.readTemperature();
  int valores = analogRead(potPin);
  
  //função map dos valores de luminosidade
  valores = map(valores, 0, 4095, 0, 100);
  
  //valores no lcd
  delay(250);                                                
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(valores);

  //led
  digitalWrite(23, HIGH);
  delay(5000);
  digitalWrite(23, LOW);
  delay(5000);

  //salvando os dados no firebase 
  json.set("/umidade", h);
  json.set("/temperatura", t);
  json.set("/luminosidade", valores);
  Firebase.updateNode(firebaseData, "/sensor", json);

}
