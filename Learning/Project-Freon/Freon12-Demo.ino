#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>
#include <TridentTD_LineNotify.h>
#define Switch1 D7
#define Switch2 D8
#define LINE_TOKEN  "750rYEeGxbGIcXsRQXt3y87v0rQUALMOJh1UP1Crj8u" //Token

int i;
void setup() {
  Serial.begin(115200);
  WiFiManager wifiManager;
  wifiManager.resetSettings();
  if (!wifiManager.autoConnect("Moo AutoConnectAP"))
  {
    Serial.println("Failed to connect and hit timeout");
    delay(3000);
    ESP.reset();
    delay(5000);
  }
  WiFi.printDiag(Serial);
  Serial.println("connected...OK");
  pinMode(Switch1, INPUT);
  pinMode(Switch2, INPUT);

  LINE.setToken(LINE_TOKEN);
  LINE.notify("System Start Ready");

}
void loop() {
  if (digitalRead(Switch1) == HIGH) {
    LINE.notify("แรงดันFreonต่ำ");
    Serial.println("แรงดันFreonต่ำ");
    for (i = 1000; i > 0; i--) {
      delay(5);
    }
    digitalWrite(Switch1, LOW);
  }
  if (digitalRead(Switch2) == HIGH) {
    LINE.notify("แรงดันFreonสูง");
    Serial.println("แรงดันFreonสูง");
    for (i = 1000; i > 0; i--) {
      delay(5);
    }
    digitalWrite(Switch2, LOW);
  }
}

ICACHE_RAM_ATTR void Alarm1() {
  digitalWrite(Switch1, HIGH);
  i = 0;
}

ICACHE_RAM_ATTR void Alarm2() {
  digitalWrite(Switch2, HIGH);
  i = 0;
}