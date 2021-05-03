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

  /* initialize ESP-NOW than check status */
  if (esp_now_init() != ESP_OK)
    status_Fail();
  else
    status_OK();

  /*
  esp_err_tesp_now_register_recv_cb(esp_now_recv_cb_tcb)
  Register callback function of receiving ESPNOW data.
  Parameters :: cb: callback function of receiving ESPNOW data
  */
  esp_now_register_send_cb(OnDataSent);

  /*
  structures
    structesp_now_peer_info :: ESPNOW peer information parameters.
  */
 static esp_now_peer_info peerInfo;

 /* uint8_t peer_addr[ESP_NOW_ETH_ALEN] */
 /* ESPNOW peer MAC address that is also the MAC address of station or softap */
 memcpy(peerInfo.peer_addr, ReceiverAddress, 6);

 /* uint8_t channel
    Wi-Fi channel that peer uses to send/receive ESPNOW data.
    If the value is 0, use the current channel which station or softap is on.
    Otherwise, it must be set as the channel that station or softap is on. 
*/
  peerInfo.channel = 0;

  /*
  bool encrypt :: ESPNOW data that this peer sends/receives is encrypted or not
  */
  peerInfo.encrypt = false;

  /*
  esp_err_tesp_now_add_peer(constesp_now_peer_info_t *peer)::Add a peer to peer list.
  Parameters :: peer: peer information
  */
  if (esp_now_add_peer(&peerInfo) != ESP_OK)
    status_Fail();
  else
    status_OK();
  

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
