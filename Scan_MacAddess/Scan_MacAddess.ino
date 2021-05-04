#include <ESP8266WiFi.h>

/* E8:DB:84:E2:BF:73 */
void setup(){
  Serial.begin(115200);
  Serial.println();
  Serial.print("ESP Board MAC Address:  ");
  Serial.println(WiFi.macAddress());
}
 
void loop(){

}
