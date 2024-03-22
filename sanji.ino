#include <ESP8266WiFi>
#include "wifi.h"
#include "cmdParser.h"
#include "execCmd.h"

#define SANJI_PORT 3020

WiFiServer server(SANJI_PORT); // setup server to accept command from client

void setup() {
    Serial.begin(9600);

    // server begin
    server.begin();
    
    // connect to wifi
    WiFi.begin(SSID, PASSWORD);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("WiFi connected");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    Serial.print("Server running on port: ");
    Serial.println(SANJI_PORT);

}

static uint8_t line[256]; // buffer of the received data
static Cmd cmd;

void loop() {
    WiFiClient client = server.available();

    if (!client) return;

    bool lineIsEmpty = true;
    uint8_t i = 0;

    while (client.connected()) {
        if (client.available()) {
            uint8_t c = client.read();

            line[i++] = c;
            if (c != '\n') {
                lineIsEmpty = false;
            } else {
                if (!lineIsEmpty) {
                    line[i] = '\n';
                    parseCmd(&cmd, line, i);

                    execCmd(&cmd);
                }
            }
        }
    }
}