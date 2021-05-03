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

    /* Update the struct with the new incoming data */
    Client[isData.idBoard-1].dataStruct = isData.dataStruct;

    WeightClient();

}

/*
------------------------------------------------------------
-------------------------main function----------------------
------------------------------------------------------------
*/
void setup(){

    /* initialize Serial moitor */
    Serial.begin(115200);

    /* set device as a Wi-Fi satation */
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();

    /* initialize ESP-NOW than check status */
    if (esp_now_init() != ESP_OK){
        tatus_Fail();
    }

    /* onec ESP-NOW is successfully initialize */
    /* Register callback function of receiving ESPNOW data */
    /* esp_err_t esp_now_register_recv_cb(esp_now_recv_cb_tcb) */
    /* Parameters :: cb : callback function of receiving ESPNOW data */
    esp_now_register_recv_cb(OnDataRecv);

}
void loop(){
  
  /* put your main code here, to run repeadly */
  Serial.print(TotleData);

}
/*
------------------------------------------------------------
-------------------------main function----------------------
------------------------------------------------------------
*/
