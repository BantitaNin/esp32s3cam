#include "main.h"
#include "hw_camera.h"

// constants
#define TAG "main"

#define BTN_PIN 0

// static variables
static bool press_state = false;

// initialize buffer
uint8_t buffer[20480];

// static variables
static void print_memory(void);

// initialize hardware
void setup()
{
  Serial.begin(115200);
  pinMode(BTN_PIN, INPUT_PULLUP);
  // initialize camera
  hw_camera_init();
  ESP_LOGI(TAG, "Setup complete");
}

// main loop
void loop()
{
  static uint32_t prev_millis = millis();

  if (digitalRead(BTN_PIN) == 0)
  {
    if ((millis() - prev_millis > 500) && (press_state == false))
    {
      // take snapshot
      uint32_t jpg_sz = hw_camera_jpg_snapshot(buffer);
      ESP_LOGI(TAG, "Total img size: %u", jpg_sz);
      print_memory();
      press_state = true;
    }
  }
  else
  {
    if (press_state)
    {
      press_state = false;
    }
  }
  delay(100);
}

// Print memory information
void print_memory()
{
  ESP_LOGI(TAG, "Total heap: %u", ESP.getHeapSize());
  ESP_LOGI(TAG, "Free heap: %u", ESP.getFreeHeap());
  ESP_LOGI(TAG, "Total PSRAM: %u", ESP.getPsramSize());
  ESP_LOGI(TAG, "Free PSRAM: %d", ESP.getFreePsram());
}