#include <DS3231.h>
#include "LedControl.h"
LedControl lc=LedControl(8,7,6,1);

DS3231  rtc(SDA, SCL);
 
void setup() { 

  Serial.begin(9600);
lc.shutdown(0,false); /*The MAX72XX is in power-saving mode on startup,we have to do a wakeup call*/
lc.setIntensity(0,8);/* Set the brightness to a medium values */
lc.clearDisplay(0);/* and clear the display */
for (int i = 0; i < 3; i++) {
        lc.setDigit(0, i, i + 1, false);
    }
  
 rtc.begin(); // Initialize the rtc object
 
}

void printTime(int v) {
    int ones;
    int tens;
    int hundreds;
    int tousents;
    boolean negative;  

    if(v < -9999 || v > 9999) 
       return;
    if(v<0) {
        negative=true;
        v=v*-1;
    }
    ones=v%10;
    v=v/10;
    tens=v%10;
    v=v/10;
    hundreds=v%10;
    v=v/10;
    tousents =v%10;
    v=v/10;
    tousents1 =v%10;
    v=v/10;
    tousents2 =v%10;    
    //Now print the number digit by digit
    lc.setDigit(0,0,(byte)tousents2,false);
    lc.setDigit(0,1,(byte)tousents1,false);
    lc.setDigit(0,2,(byte)tousents,false);
    lc.setDigit(0,3,(byte)hundreds,false);
    lc.setDigit(0,4,(byte)tens,false);
    lc.setDigit(0,5,(byte)ones,false);
}

void printDate(int v) {
    int ones;
    int tens;
    int hundreds;
    int tousents;
    int tousents1;
    int tousents2;
    int tousents3;
    int tousents4;
    boolean negative;  

    if(v < -9999 || v > 9999) 
       return;
    if(v<0) {
        negative=true;
        v=v*-1;
    }
    ones=v%10;
    v=v/10;
    tens=v%10;
    v=v/10;
    hundreds=v%10;
    v=v/10;
    tousents =v%10;
    v=v/10;
    tousents1 =v%10;
    v=v/10;
    tousents2 =v%10;
    v=v/10;
    tousents3 =v%10;
    v=v/10;
    tousents4 =v%10;    
    //Now print the number digit by digit
    lc.setDigit(0,0,(byte)tousents4,false);
    lc.setDigit(0,1,(byte)tousents3,false);
    lc.setDigit(0,2,(byte)tousents2,false);
    lc.setDigit(0,3,(byte)tousents1,false);
    lc.setDigit(0,4,(byte)tousents,true);
    lc.setDigit(0,5,(byte)hundreds,false);
    lc.setDigit(0,6,(byte)tens,true);
    lc.setDigit(0,7,(byte)ones,false);
}
void loop() { 
 
 //String t=rtc.getTimeStr();
  //int tt=t.toInt();
  //printTime(tt);
 
 String d=rtc.getDateStr();
  int dd=d.toInt();
  printDate(dd);
 
}
