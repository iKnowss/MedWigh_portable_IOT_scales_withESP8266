/*

ESP8266 NodeMCU Receiver Code (ESP-NOW)

!! main file upload to board !!
!! flie adjust parameter !!
Vertion 2.0

esp32 iot with protocol esp-now
refre : https://randomnerdtutorials.com/esp-now-many-to-one-esp8266-nodemcu/

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
#define pin D4

/* variable for totle data  */
double TotleData = 0;

/* len of arrary for keep weight data */
#define lenDataWeight 1000

/* variable for caculator data */
float sumWeight = 0.0;
float avgWeight = 0.0; 
float Weight[lenDataWeight]; /* Araay for keep weight */

float randNumber;

/*
Function that will be executed when data is is received
*/
void OnDataRecv(uint8_t * mac_addr, uint8_t *incomingData, uint8_t len)
{
    /* char keep mac address client */ 
    char macSender[18];
    
    Serial.print("recriver from --> ");
    sniprintf(macSender, sizeof(macSender), "%02x:%02x:%02x:%02x:%02x:%02x",
            mac_addr[0], mac_addr[1], mac_addr[2],
            mac_addr[3], mac_addr[4], mac_addr[5]);
    Serial.println(macSender);

    /* copy incomingData to isData */
    memcpy(&isData, incomingData, sizeof(isData));
    Serial.printf("Board ID %u: %u bytes\n", isData.idBoard, len);

    /* Update the struct with the new incoming data */
    Client[isData.idBoard-1].dataStruct = isData.dataStruct;
    Serial.printf("x value: %f \n", Client[isData.idBoard-1].dataStruct);

}
