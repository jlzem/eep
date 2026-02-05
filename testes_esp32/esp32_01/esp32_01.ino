#include <WiFi.h>
#include <WebServer.h>

const char* ssid     = "Wokwi-GUEST";
const char* password = "";

WebServer server(80);

void raiz() {
  server.send(200, "text/plain; charset=utf-8", "Oi mundo");
}

void NaoEncontrado() {
  server.send(404, "text/plain; charset=utf-8", "404 - Nao Encontrado");
}

void setup() {
  Serial.begin(115200);
  delay(100);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.print("Conectando ao Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConectado!");
  Serial.print("IP do ESP32: ");
  Serial.println(WiFi.localIP());

  server.on("/", raiz);
  server.onNotFound(NaoEncontrado);

  server.begin();
  Serial.println("Servidor HTTP iniciado!");
}

void loop() {
  server.handleClient();
}
