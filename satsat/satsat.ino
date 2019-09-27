#include <DS3231.h>
#include <Wire.h>
#include "LedControl.h"
DS3231 Clock (SDA, SCL);
bool Century=false;
bool h12;
bool PM;

byte year, month, date, hour, minute, second;

LedControl lc=LedControl(8,7,6,1);
void setup() {
Wire.begin();
lc.shutdown(0,false); /*The MAX72XX is in power-saving mode on startup,we have to do a wakeup call*/
lc.setIntensity(0,8);/* Set the brightness to a medium values */
lc.clearDisplay(0);/* and clear the display */
for (int i = 0; i < 3; i++) {
        lc.setDigit(0, i, i + 1, false);
    }
Serial.begin(9600);
}

void printSeconds(int s) {
    int second;
    int seconds;
    
    second=s%10;
    s=s/10;
    seconds=s%10;
     
    lc.setDigit(0,0,(byte)second,false);
    lc.setDigit(0,1,(byte)seconds,false);
}
void ReadDS3231(){
 int second,minute,hour,date,month,year;
// second=Clock.getSecond();
 //minute=Clock.getMinute();
 //hour=Clock.getHour(h12, PM);
 //date=Clock.getDate();
// month=Clock.getMonth(Century);
// year=Clock.getYear();

}
void loop() {
  ReadDS3231();
  delay(1000);

//int second=Clock.getSecond();
 // int minute=Clock.getMinute();
  //int hour=Clock.getHour(h12, PM);

  printSeconds(12);

}
