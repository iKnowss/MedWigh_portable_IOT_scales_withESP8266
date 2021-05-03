# weight-machine
<div align="left">
(Block
Thai language)
</div>
<a href="https://i-knowss11.medium.com/weight-machine-91fa638db621" target="_blank"> 
    <code><img height="25" alt="medium"
    src="https://www.graphicdesignforum.com/uploads/default/original/2X/0/0e58f26a6dd982e7f04d1286defd4320e6d6153b.jpeg"/></code></a>


## Overview
weight machine with ESP32 vai ESP-now Protocol

To send messages via ESP-NOW, you need to know the receiver board’s MAC address.

Each board has a unique MAC address.

<img alt="Overview"
    src="https://cdn-images-1.medium.com/max/600/1*6k0O8asJAqNXdJb4QhK_WA.png">

``` c++
/* Upload code to your server board to get is mac address */
/* it's find_macAddress.ino */

#ifdef ESP32
  #include <WiFi.h>
#else
  #include <ESP8266WiFi.h>
#endif


void setup() {
  
  Serial.begin(112500);
  Serial.println();
  Serial.print("ESP Board MAC Address:  ");
  //Show your mac address
  Serial.println(WiFi.macAddress());

}

void loop(){
  
}

```

Uploading the code, then the Mac address should be displayed on the Seial Monitor.

After uploading, press the EN/RST button.

<img alt="show macAddress"
    src="https://cdn-images-1.medium.com/max/600/1*HRfdFOj7QqAqjJ96UZF_Iw.jpeg" />


