#ifndef __NET_MQTT_H__
#define __NET_MQTT_H__

// include files
#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <pubsubclient.h>
#include <Esp.h>
#include <esp_random.h>
#include <esp_log.h>

// constants

// type definitions
typedef void (*mqtt_callback_t)(char*, byte*, unsigned int);

// shared variables

// public functions
void net_mqtt_init(char *ssid, char *passwd);
void net_mqtt_connect(unsigned int dev_id, char *topic, mqtt_callback_t msg_callback);
void net_mqtt_publish(char *topic, char *payload);
void net_mqtt_loop(void);

#endif // __NET_MQTT_H__