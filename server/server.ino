/*
!! main file upload to board !!
!! flie adjust parameter !!
Vertion 1.0

esp32 iot with protocol esp-now
refre : https://randomnerdtutorials.com/esp-now-many-to-one-esp32/
ESP-NOW : https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/network/esp_now.html

!! Is receiver or server !!
The code is prepared to receive data from three
different boards.
*/

/*
if your board is esp32 --> include <WiFi.h>
it's not your board is esp8266 --> include <esp8266WiFi.h>
*/
#ifdef ESP32
  #include <WiFi.h>
#else
  #include <ESP8266WiFi.h>
#endif

/* multi sender data to one receiver vai esp-now protocol */
/* import library esp-now */
#include <esp_now.h>

/* import library LCD I2C for show data */
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/*
Create structure to recrive date
must match the sender stuct
*/
typedef struct message
{
  /* must be unique for each sender board */
  int idBoard;
  float dataStruct;
} message;

/* Create a structure called isData */
message isData;

/* Create a structure to hold the reading from each board */
message client_1;
message client_2;
message client_3;

/* Create an array with all the client struct */
message Client[3] = {
  client_1, client_2, client_3
};

/* set address LCD finding with find_LCD.ino */
LiquidCrystal_I2C lcd(0x3F, 20, 4);

/* quality board client */
#define numBoard 3

/* pin led status */
#define pin 2

/* variable for totle data  */
double TotleData = 0;
