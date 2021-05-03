/*
------------------------------------------------------------
-------------------------main function----------------------
------------------------------------------------------------
*/
void setup() {

  /* initialize Serial moitor */
  Serial.begin(115200);
  pinMode(pin, OUTPUT);

  /* set device as a Wi-Fi satation */
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  /* initialize ESP-NOW than check status */
  if (esp_now_init() != 0)
    status_Fail();
  else
    status_OK();

  /*
  Set the board role. This is a sender board,
  so we’ll set it to ESP_NOW_ROLE_CONTROLLER.
  */
  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);

  /*
  esp_err_tesp_now_register_recv_cb(esp_now_recv_cb_tcb)
  Register callback function of receiving ESPNOW data.
  Parameters :: cb: callback function of receiving ESPNOW data
  */
  esp_now_register_send_cb(OnDataSent);

  /*
  Add peer device
  To send data to another board (the receiver),
  you need to pair it as a peer. The following line registers a new peer.
  The esp_now_add_peer() function accepts the following arguments, in this order: 
  mac address, peer role, wi-fi channel, key, and key length.
  */
  esp_now_add_peer(ReceiverAddress, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);

}

void loop() {
  // put your main code here, to run repeatedly:

  /* set data is your want send */
  isData.idBoard = ID;

  int count = 1;
  while(1){
      CalculatorWeight(count);
      count += 1;
    }
}
/*
------------------------------------------------------------
-------------------------main function----------------------
------------------------------------------------------------
*/
