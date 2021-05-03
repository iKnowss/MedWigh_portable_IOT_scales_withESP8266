/*
!! main file upload to board !!
!! flie adjust parameter !!
Vertion 1.0

esp32 iot with protocol esp-now
refre : https://randomnerdtutorials.com/esp-now-many-to-one-esp32/
ESP-NOW : https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/network/esp_now.html

!! Is sender or client !!
The receiver can identify each sender by its unique MAC address.
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

/* pin led status */
#define pin 2

/*
set your receiver mac address
it's finding in find_macAddress.ion
EX. 0xC4, 0x4F, 0x33, 0x3A, 0x32, 0x35 
*/
uint8_t ReceiverAddress[] = {0xC4, 0x4F, 0x33, 0x3A, 0x32, 0x35};

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
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status){

  /* put code callblack when sented data */
  if (status == ESP_NOW_SEND_SUCCESS)
    status_OK();
  else
    status_Fail();
  return;
 
}
