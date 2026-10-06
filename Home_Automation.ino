/*
  IoT-Based Home Automation System
  Controller: ESP8266 NodeMCU
  Sensors: DHT11 + LDR
  Outputs: Relay 1 (Light), Relay 2 (Fan)

  IMPORTANT:
  This demo is intended for low-voltage loads or a properly isolated
  relay module. Do not connect mains voltage unless supervised by a
  qualified person.
*/

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <DHT.h>

#define DHT_PIN D4
#define DHT_TYPE DHT11
#define LIGHT_RELAY D1
#define FAN_RELAY D2
#define LDR_PIN A0

const char* WIFI_SSID = "YOUR_WIFI_NAME";
const char* WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";

DHT dht(DHT_PIN, DHT_TYPE);
ESP8266WebServer server(80);

bool lightState = false;
bool fanState = false;

const char PAGE[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width,initial-scale=1">
<title>Smart Home Automation</title>
<style>
body{font-family:Arial;margin:0;background:#f3f6fa;color:#172033}
.wrap{max-width:900px;margin:auto;padding:24px}
h1{text-align:center}.grid{display:grid;grid-template-columns:repeat(auto-fit,minmax(180px,1fr));gap:16px}
.card{background:white;border-radius:16px;padding:20px;box-shadow:0 4px 14px #0001}
button{width:100%;padding:12px;border:0;border-radius:10px;background:#172033;color:white;font-size:16px}
.value{font-size:28px;font-weight:bold;margin-top:10px}
</style>
</head>
<body><div class="wrap">
<h1>🏠 Smart Home Automation</h1>
<div class="grid">
<div class="card"><h3>💡 Light</h3><p id="light">--</p><button onclick="toggle('/light')">Toggle Light</button></div>
<div class="card"><h3>🌀 Fan</h3><p id="fan">--</p><button onclick="toggle('/fan')">Toggle Fan</button></div>
<div class="card"><h3>🌡️ Temperature</h3><div id="temp" class="value">--</div></div>
<div class="card"><h3>💧 Humidity</h3><div id="hum" class="value">--</div></div>
<div class="card"><h3>☀️ Light Level</h3><div id="ldr" class="value">--</div></div>
</div></div>
<script>
async function update(){
 const r=await fetch('/status'); const d=await r.json();
 document.getElementById('light').textContent=d.light?'ON':'OFF';
 document.getElementById('fan').textContent=d.fan?'ON':'OFF';
 document.getElementById('temp').textContent=d.temp+' °C';
 document.getElementById('hum').textContent=d.hum+' %';
 document.getElementById('ldr').textContent=d.ldr;
}
async function toggle(path){await fetch(path);update();}
setInterval(update,2000); update();
</script>
</body></html>
)HTML";

void setRelay(uint8_t pin, bool state) {
  // Most relay modules are active LOW.
  digitalWrite(pin, state ? LOW : HIGH);
}

void handleRoot() { server.send_P(200, "text/html", PAGE); }

void handleLight() {
  lightState = !lightState;
  setRelay(LIGHT_RELAY, lightState);
  server.send(200, "text/plain", lightState ? "ON" : "OFF");
}

void handleFan() {
  fanState = !fanState;
  setRelay(FAN_RELAY, fanState);
  server.send(200, "text/plain", fanState ? "ON" : "OFF");
}

void handleStatus() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  int ldr = analogRead(LDR_PIN);

  if (isnan(t)) t = 0;
  if (isnan(h)) h = 0;

  String json = "{\"light\":" + String(lightState ? "true" : "false") +
                ",\"fan\":" + String(fanState ? "true" : "false") +
                ",\"temp\":" + String(t,1) +
                ",\"hum\":" + String(h,1) +
                ",\"ldr\":" + String(ldr) + "}";
  server.send(200, "application/json", json);
}

void setup() {
  Serial.begin(115200);
  pinMode(LIGHT_RELAY, OUTPUT);
  pinMode(FAN_RELAY, OUTPUT);
  setRelay(LIGHT_RELAY, false);
  setRelay(FAN_RELAY, false);

  dht.begin();

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Open this address in a browser: http://");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/light", handleLight);
  server.on("/fan", handleFan);
  server.on("/status", handleStatus);
  server.begin();
}

void loop() {
  server.handleClient();
}
