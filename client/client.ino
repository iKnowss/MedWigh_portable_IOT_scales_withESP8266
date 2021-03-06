/*

ESP8266 NodeMCU Sender Code (ESP-NOW)

!! main file upload to board !!
!! flie adjust parameter !!
Vertion 2.0

esp8266 iot with protocol esp-now
refre : https://randomnerdtutorials.com/esp-now-many-to-one-esp8266-nodemcu/

The receiver can identify each sender by its unique MAC address.
*/

/*
Include the ESP8266WiFi and espnow libraries.
*/
#include <ESP8266WiFi.h>
#include <espnow.h>

/*
set your receiver mac address
it's finding in find_macAddress.ion
EX. 0xC4, 0x4F, 0x33, 0x3A, 0x32, 0x35 
*/
uint8_t ReceiverAddress[] = {0xE8, 0xDB, 0x84, 0xE2, 0xBF, 0x73};

/* pin led status */
#define pin D4

/* set ID board must be unique for each sender board */
#define ID 1

/* len of arrary for keep weight data */
#define lenDataWeight 1000

/* variable for caculator data */
float sumWeight = 0.0;
float avgWeight = 0.0; 
float Weight[lenDataWeight]; /* Araay for keep weight */

float randNumber;

/*
create struct to send data
must match the receiver stuct
*/
typedef struct message
{
  /* must be unique for each sender board */
  int idBoard;
  float dataStruct;
} message;

/* Create a structure called isData */
message isData;

/*
function this callblack when data is sented
*/
void OnDataSent(uint8_t *mac_addr, uint8_t sendStatus){

//  /* put code callblack when sented data */
//  if (sendStatus == 0)
//    status_OK();
//  else
//    status_Fail();
   Serial.print("\r\nLast Packet Send Status: ");
  if (sendStatus == 0){
    Serial.println("Delivery success");
    status_OK();
  }
  else{
    Serial.println("Delivery fail");
    status_Fail();
  }
}
