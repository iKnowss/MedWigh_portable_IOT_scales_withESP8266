/*
------------------------------------------------------------
-------------------------main function----------------------
------------------------------------------------------------
*/
void setup(){

    /* initialize Serial moitor */
    Serial.begin(115200);
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);

    /* set device as a Wi-Fi satation */
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();

    /* initialize ESP-NOW than check status */
    if (esp_now_init() != 0){
        status_Fail();
        Serial.println("Error initializing ESP-NOW");
        return;
    }

    /* onec ESP-NOW is successfully initialize */
    /* Register callback function of receiving ESPNOW data */
    /* esp_err_t esp_now_register_recv_cb(esp_now_recv_cb_tcb) */
    /* Parameters :: cb : callback function of receiving ESPNOW data */
    esp_now_register_recv_cb(OnDataRecv);

}
void loop(){
  
  /* put your main code here, to run repeadly */
    Serial.printf("\n");
    Serial.printf("Data : %.2f", TotleData);
    Serial.printf("\n");

}
/*
------------------------------------------------------------
-------------------------main function----------------------
------------------------------------------------------------
*/
