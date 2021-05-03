/*
    Function sum weight all client
*/
void WeightClient(){
    /* 
        create variable "sumSim" for sum data t
        hen end for loop reset to zero
    */
    float sumSim = 0.0;

    /* sum data is sented by client */
    for (int i=0; i<numBoard; i++){
        /* add data to sumSim for sum data */
        sumSim += Client[i].dataStruct;
    }
    TotleData = sumSim;
}
