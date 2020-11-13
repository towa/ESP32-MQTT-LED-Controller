#include <Arduino.h>
#include <ArduinoJson.h>
#include <AsyncMqttClient.h>
#include <EEPROM.h>
#include <Ticker.h>
#include <WiFi.h>
#include <NeoPixelBus.h>

#include "configuration.h"
#include "version.h"
#include "ota.h"

#include <map>
#include <string>

using namespace std;

#ifndef MAIN_h
#define MAIN_h

#define CMD_ON "ON"
#define CMD_DEAD "offline"
#define CMD_ALIVE "online"

struct Color {
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

struct State {
    Color color = { 255, 255, 255 };
    uint8_t brightness = 100;
    string effect = "static";
    uint16_t speed = 1000; 
    bool on = true;
};


AsyncMqttClient mqttClient;
NeoPixelBus<NeoGrbFeature, NeoEsp32I2s1800KbpsMethod> ledstrip(LED_COUNT, LED_PIN);
Ticker mqttReconnectTimer;
Ticker wifiReconnectTimer;
State currentState;

//Connection starters
void connectToWiFi();
void connectToMQTT();

// Event handlers
void onWiFiEvent(WiFiEvent_t event);
void onMQTTConnect(bool sessionPresent);
void onMQTTDisconnect(AsyncMqttClientDisconnectReason reason);
void onMQTTMessage(
    char* topic,
    char* payload,
    AsyncMqttClientMessageProperties properties,
    size_t len,
    size_t index,
    size_t total
);

// Helpers
void announceToHomeAssistant();
void processStateJson(char* payload);
void updateState();

// Main program functions
void setup();
void loop();

#endif
