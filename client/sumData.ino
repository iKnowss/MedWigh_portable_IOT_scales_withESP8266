/*
function for average data of array
*/
void average(float Weight[lenDataWeight], int count, int Division){
    /* 
        create variable "sumSim" for sum data t
        hen end for loop reset to zero
    */
    float sumSim = 0.0;

    /* 
        for loop sum data all element
    */
   for (int i=0; i<lenDataWeight; i++){
       /* sumSim add weight element i  */
       sumSim += Weight[i];

   }
   sumWeight = sumSim;
   /* calculator average weight */
   if (count == 1)
      avgWeight = sumWeight/Division;
   else
      avgWeight = sumWeight/lenDataWeight;
}

/* 
function add weight data to element array
*/
void CalculatorWeight(int count){
    /* for loop add data to array */
    for (int i=0; i<lenDataWeight; i++){
        randNumber = random(100);

        /* add data to array */
        Weight[i] = randNumber;
        average(Weight, count, i);
        isData.dataStruct = avgWeight;
        
        /* send data vai ESP-NOW */
        esp_now_send(0, (uint8_t *) &isData, sizeof(isData));

        delay(100);
    }
}
