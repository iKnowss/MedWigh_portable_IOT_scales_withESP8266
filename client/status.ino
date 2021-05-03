void status_OK(){
    digitalWrite(pin , HIGH);
    delay(500);
    digitalWrite(pin, LOW);
}

void status_Fail(){
        digitalWrite(pin , HIGH);
        delay(100);
        digitalWrite(pin, LOW);
        delay(100);
        digitalWrite(pin , HIGH);
        delay(100);
        digitalWrite(pin, LOW);
}
