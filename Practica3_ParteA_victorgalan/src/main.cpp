#include <WiFi.h>
#include <WebServer.h>

// ================== DECLARACIÓN ANTICIPADA (¡OBLIGATORIA en PlatformIO!) ==================
void handle_root();        

// SSID & Password (ya puestos con los tuyos)
const char* ssid = "POCO X7 Pro";          
const char* password = "Ian12345";  

WebServer server(80);

// ====================== TU PÁGINA WEB CON JAVASCRIPT ======================
const char HTML[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>🌐 Control de Luz ESP32</title>
    <style>
        body { font-family: Arial, sans-serif; text-align: center; background: #f0f0f0; margin: 0; padding: 20px; }
        .container { max-width: 600px; margin: 50px auto; padding: 30px; background: white; border-radius: 15px; box-shadow: 0 0 15px rgba(0,0,0,0.1); }
        h2 { color: #0066ff; }
    </style>
</head>
<body>
    <div class="container">
        <h2>What Can JavaScript Do?</h2>
        <p>JavaScript can change HTML attribute values.</p>
        <p>In this case JavaScript changes the value of the src (source) attribute of an image.</p>
        
        <button onclick="document.getElementById('myImage').src='https://www.w3schools.com/js/pic_bulbon.gif'">Turn on the light</button>
        
        <img id="myImage" src="https://www.w3schools.com/js/pic_bulboff.gif" style="width:100px">
        
        <button onclick="document.getElementById('myImage').src='https://www.w3schools.com/js/pic_bulboff.gif'">Turn off the light</button>
    </div>
</body>
</html>
)rawliteral";

void setup() {
  Serial.begin(115200);
  Serial.println("\nIntentando conectar a WiFi...");
  Serial.print("SSID: ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("\n✅ WiFi conectado!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  server.on("/", handle_root);
  server.begin();
  Serial.println("🚀 Servidor HTTP iniciado");
}

void loop() {
  server.handleClient();
}

// ====================== FUNCIÓN handle_root ======================
void handle_root() {
  server.send(200, "text/html", HTML);
}


