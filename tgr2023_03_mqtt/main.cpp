#include "main.h"
#include "net_mqtt.h"

// constants
#define TAG             "main"
#define BTN_PIN         0 
#define WIFI_SSID       "WIFI SSID"
#define WIFI_PASSWORD   "WIFI PASSWORD"
#define MQTT_EVT_TOPIC  "tgr2023/YOUR TEAM NAME/btn_evt"
#define MQTT_CMD_TOPIC  "tgr2023/YOUR TEAM NAME/cmd"
#define MQTT_DEV_ID     "H20"

// static function prototypes
void print_memory(void);
static void mqtt_callback(char* topic, byte* payload, unsigned int length);

// static variables
static bool enable_flag = true;
// declare ArduinoJson objects for cmd_buf and evt_buf

static char buf[128];

// Setup hardware
void setup() {
  Serial.begin(115200);
  print_memory();
  pinMode(BTN_PIN, INPUT_PULLUP);
  // connect to WiFi

  // connect to MQTT broker
  
}

// Main loop
void loop() {
  static uint32_t prev_millis = 0;

  if (enable_flag) {
    // check button status

    // check button bounce

    // publish button event

  }
  // loop MQTT interval

  delay(100);
}

// Print memory information
void print_memory() {
  ESP_LOGI(TAG, "Total heap: %u", ESP.getHeapSize());
  ESP_LOGI(TAG, "Free heap: %u", ESP.getFreeHeap());
  ESP_LOGI(TAG, "Total PSRAM: %u", ESP.getPsramSize());
  ESP_LOGI(TAG, "Free PSRAM: %d", ESP.getFreePsram());
}

// callback function to handle MQTT message
 void mqtt_callback(char* topic, byte* payload, unsigned int length) {
  ESP_LOGI(TAG, "Message arrived on topic %s", topic);
  ESP_LOGI(TAG, "Payload: %.*s", length, payload);
  // extract data from payload

  // check if the message is for this device

  // configure enable/disable status

 }