/*
Setting LCD 
Is working set home --> clear screen
than set cursor for print text
*/
void setLCD_I2C(int cursorX, int cursorY){
    lcd.home();
    lcd.clear();

    /* set cursor for show text */
    lcd.setCursor(cursorX, cursorY);
    lcd.setBacklight(255);
    lcd.display();
    lcd.blink();
}
