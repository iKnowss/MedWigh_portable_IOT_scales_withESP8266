/*

ESP8266 NodeMCU Receiver Code (ESP-NOW)

!! main file upload to board !!
!! flie adjust parameter !!
Vertion 2.0

esp32 iot with protocol esp-now
refre : https://randomnerdtutorials.com/esp-now-many-to-one-esp32/

The code is prepared to receive data from three
different boards.
*/

/*
Include the ESP8266WiFi and espnow libraries.
*/
#include <ESP8266WiFi.h>
#include <espnow.h>

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

/* quality board client */
#define numBoard 3

/* pin led status */
#define pin 2

/* variable for totle data  */
double TotleData = 0;
