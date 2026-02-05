#include <WiFi.h>
#include <WebServer.h>

const char* ssid     = "Wokwi-GUEST";
const char* password = "";

WebServer server(80);

void raiz() {
  String html =
    "<!doctype html><html><head>"
    "<meta charset='utf-8'>"
    "<meta name='viewport' content='width=device-width, initial-scale=1'>"
    "<title>NodeMCU</title>"
    "<style>body{font-family:Arial;padding:20px;} .card{padding:16px;border:1px solid #ccc;border-radius:12px;max-width:420px;}</style>"
    "</head><body>"
    "<div class='card'>"
    "<h2>Servidor ESP32</h2>"
    "<p>Oi mundo 👋</p>"
    "</div>"
    "</body></html>";
  server.send(200, "text/html; charset=utf-8", html);
}

void NaoEncontrado() {
  server.send(404, "text/plain; charset=utf-8", "404 - Nao encontrado");
}

void estado() {
  server.send(200, "text/plain; charset=utf-8", "OK - Servidor Ativo");
}

void atividade() {
  server.send(200, "text/plain; charset=utf-8", String(millis() / 1000));
}

void api01() {
  String json = "{";
  json += "\"device\":\"NodeMCU\",";
  json += "\"ip\":\"" + WiFi.localIP().toString() + "\",";
  json += "\"rssi\":" + String(WiFi.RSSI()) + ",";
  json += "\"uptime_ms\":" + String(millis() / 1000);
  json += "}";
  server.send(200, "application/json; charset=utf-8", json);
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
  server.on("/status", estado );
  server.on("/uptime", atividade );
  server.on("/api01", api01 );

  server.begin();
  Serial.println("Servidor HTTP iniciado!");
}

void loop() {
  server.handleClient();
}
