#include <DS3231.h>
#include <Wire.h>
#include "LedControl.h"
DS3231  rtc(SDA, SCL);
LedControl lc=LedControl(8,7,6,1);
Time  t;

int Hor;
int Min;
int Sec;

void setup(){  
  Wire.begin();
  rtc.begin();
  Serial.begin(9600);
  for (int i = 0; i < 8; i++) {
lc.shutdown(i,false); /*The MAX72XX is in power-saving mode on startup,we have to do a wakeup call*/
lc.setIntensity(i,8);/* Set the brightness to a medium values */
lc.clearDisplay(i);/* and clear the display */
  }
  
  for (int j = 0; j < 8; j++) {
for (int i = 0; i < 3; i++) {
        lc.setDigit(j, i, i + 1, false);
    }
  }
  delay(2000);
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
void printMinutes(int m) {
    int minute;
    int minutes;
    minute=m%10;
    m=m/10;
    minutes=m%10;
    lc.setDigit(0,2,(byte)minute,true);
    lc.setDigit(0,3,(byte)minutes,false);
}
void printHours(int h) {
    int hour;
    int hours;
    hour=h%10;
    h=h/10;
    hours=h%10;
    lc.setDigit(0,4,(byte)hour,true);
    lc.setDigit(0,5,(byte)hours,false);
}
void loop(){
  t = rtc.getTime();
  Hor = t.hour;
  Min = t.min;
  Sec = t.sec;
  
    printSeconds(Sec);
    printMinutes(Min);
    printHours(Hor);
    
delay(1000); 
    
// d=rtc.getDateStr();

  //int day=d.day;
  //int month=d.month;
  //int year=d.year;
  
 //delay(1000); 
}
