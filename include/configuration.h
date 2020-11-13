#ifndef CONFIGURATION_h
#define CONFIGURATION_h

// There are not many reasons to change this
#define MONITOR_BAUDRATE 115200

// Name as it initially pops up in Home Assistant
#define NAME "regalled"

// WiFi Connection information
#define WIFI_SSID "Autonome Tantifa"
#define WIFI_PASSWORD "PSKfuerWPA_AutonomeTantifa!"
#define WIFI_HOSTNAME "regalled"

// OTA setup
const uint16_t OTA_PORT = 8266;
const char *OTA_PASSWORD = "ota password";

// MQTT Server information
#define MQTT_HOST "192.168.0.190"
#define MQTT_USERNAME "zigbee"
#define MQTT_PASSWORD "ApisMellifica"
#define MQTT_PORT 1883

// MQTT topics used by this program
#define MQTT_TOPIC_STATE "ledstrip/state"
#define MQTT_TOPIC_COMMAND "ledstrip/set"
#define MQTT_TOPIC_AVAILABLE "ledstrip/status"

// LED SETUP
#define LED_PIN 33 // PIN number used on the ESP32
#define LED_COUNT 184 // Number of LED your strip has


#endif