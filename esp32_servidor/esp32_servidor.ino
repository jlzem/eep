#include <WiFi.h>
#include <WebServer.h>

const char* ssid     = "Wokwi-GUEST";
const char* password = "";

WebServer server(80);

void handleRoot() {
  server.send(200, "text/plain", "Oi mundo");
}

void setup() {

  Serial.begin(115200);
  delay(1000);

  Serial.println();
  Serial.println("Iniciando conexao Wi-Fi...");
  Serial.print("Conectando em: ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("Wi-Fi conectado!");
  Serial.print("Endereço IP do ESP32: ");
  Serial.println(WiFi.localIP());  // Mostra o IP no Serial Monitor

  // Configura a rota principal ("/")
  server.on("/", handleRoot);

  // Inicia o servidor
  server.begin();
  Serial.println("Servidor web iniciado.");
}

void loop() {
  // Mantém o servidor atendendo as requisições
  server.handleClient();
}