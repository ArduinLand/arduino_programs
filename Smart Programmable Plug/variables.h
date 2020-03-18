/*
 * Ce ficiher contient l'ensemble des variables utilisées 
 * ainsi que les librairies 
 * pour la mise en place de ce projet telle la partie
 * configuration du projet 
 */

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SoftwareSerial.h>
#include <TimeLib.h>
#include <WidgetRTC.h>
#include <ESP8266WiFiMulti.h>
#include <ArduinoJson.h>

ESP8266WiFiMulti wifiMulti;
//SoftwareSerial s(5,6);

const int RESET_BUTTON = D1, APPAREIL = D0, LIGNE_SSID = 0, LIGNE_MDP = 1;
bool paramReceived = false, remote_control = false,
prog_mode = false,paramReceived_progMode = false;
bool putItOn = false;
int parametre_remote = -1,parametre_progMode = -1, wifiStatus = WL_IDLE_STATUS;
char auth[] = "d7f3290a4a5445d5abd2af61c96d7efa";//"yRJu06Lg9Py1JxHobeQmV1n1DK5aAlJ6";

String currentHour = "",
currentMinutes = "", startTimeHour = "", startTimeMinute = "",
stopTimeHour = "", stopTimeMinute = "";
//RTC widget
BlynkTimer timer;
WidgetRTC rtc;
