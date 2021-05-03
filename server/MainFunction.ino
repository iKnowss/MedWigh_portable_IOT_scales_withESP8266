/*
Function that will be executed when data is is received
*/
void OnDataRecv(const uint8_t * mac_addr, const uint8_t *incomingData, int len)
{
    /* char keep mac address client */ 
    char macSender[18];
    Serial.print("recriver from --> ");
    sniprintf(macSender, sizeof(macSender), "%02x:%02x:%02x:%02x:%02x:%02x",
            mac_addr[0], mac_addr[1], mac_addr[2],
            mac_addr[3], mac_addr[4], mac_addr[5]);
    Serial.println(macSender);

//    setLCD_I2C(0, 0);
    /* copy incomingData to isData */
    memcpy(&isData, incomingData, sizeof(isData));
//    lcd.printf("Board ID %u: %u bytes", isData.idBoard, len);

    /* Update the struct with the new incoming data */
    Client[isData.idBoard-1].dataStruct = isData.dataStruct;

//    int myDATA = Client[isData.idBoard-1].dataStruct;

//    lcd.setCursor(0, 1);
//    lcd.printf("Data : %d", myDATA);
//    delay(2000);
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

    /* initialize wire for lcd i2c */
    Wire.begin();

    /* initialize LCD */
    lcd.begin();

    /* set device as a Wi-Fi satation */
    WiFi.mode(WIFI_STA);

    /* initialize ESP-NOW than check status */
    if (esp_now_init() != ESP_OK){
        setLCD_I2C(0,0);
        lcd.println("Error initializing ESP-NOW");
    }

    /* onec ESP-NOW is successfully initialize */
    /* Register callback function of receiving ESPNOW data */
    /* esp_err_t esp_now_register_recv_cb(esp_now_recv_cb_tcb) */
    /* Parameters :: cb : callback function of receiving ESPNOW data */
    esp_now_register_recv_cb(OnDataRecv);

}
void loop(){
  
  /* put your main code here, to run repeadly */

  lcd.setBacklight(255);
  lcd.display();
  lcd.blink();
  lcd.setCursor(0, 1);
  lcd.printf("Data : %.2f", TotleData);


}
/*
------------------------------------------------------------
-------------------------main function----------------------
------------------------------------------------------------
*/
