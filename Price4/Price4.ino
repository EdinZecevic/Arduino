//We always have to include the library
#include "LedControl.h"
LedControl lc=LedControl(8,7,6,4);

void setup() {
  Serial.begin(9600);
lc.shutdown(0,false); /*The MAX72XX is in power-saving mode on startup,we have to do a wakeup call*/
lc.shutdown(1,false);
lc.shutdown(2,false);
lc.shutdown(3,false);

lc.setIntensity(0,8);/* Set the brightness to a medium values */
lc.setIntensity(1,8);
lc.setIntensity(2,8);
lc.setIntensity(3,8);

lc.clearDisplay(0);/* and clear the display */
lc.clearDisplay(1);
lc.clearDisplay(2);
lc.clearDisplay(3);

for (int i = 0; i < 3; i++) {
        lc.setDigit(0, i, i + 1, false);
        lc.setDigit(1, i, i + 1, false);
        lc.setDigit(2, i, i + 1, false);
        lc.setDigit(3, i, i + 1, false);
    }

}

void printNumber1(int v) {
    int ones;
    int tens;
    int hundreds;
    boolean negative;  

    if(v < -999 || v > 999) 
       return;
    if(v<0) {
        negative=true;
        v=v*-1;
    }
    ones=v%10;
    v=v/10;
    tens=v%10;
    v=v/10;
    hundreds=v;     
    //Now print the number digit by digit
    lc.setDigit(0,0,(byte)hundreds,true);
    lc.setDigit(0,1,(byte)tens,false);
    lc.setDigit(0,2,(byte)ones,false);
}

void printNumber2(int b) {
    int ones;
    int tens;
    int hundreds;
    boolean negative;  

    if(b < -999 || b > 999) 
       return;
    if(b<0) {
        negative=true;
        b=b*-1;
    }
    ones=b%10;
    b=b/10;
    tens=b%10;
    b=b/10;
    hundreds=b;     
    //Now print the number digit by digit
    lc.setDigit(1,0,(byte)hundreds,true);
    lc.setDigit(1,1,(byte)tens,false);
    lc.setDigit(1,2,(byte)ones,false);
}

void printNumber3(int v) {
    int ones;
    int tens;
    int hundreds;
    boolean negative;  

    if(v < -999 || v > 999) 
       return;
    if(v<0) {
        negative=true;
        v=v*-1;
    }
    ones=v%10;
    v=v/10;
    tens=v%10;
    v=v/10;
    hundreds=v;     
    //Now print the number digit by digit
    lc.setDigit(2,0,(byte)hundreds,true);
    lc.setDigit(2,1,(byte)tens,false);
    lc.setDigit(2,2,(byte)ones,false);
}

void printNumber4(int v) {
    int ones;
    int tens;
    int hundreds;
    boolean negative;  

    if(v < -999 || v > 999) 
       return;
    if(v<0) {
        negative=true;
        v=v*-1;
    }
    ones=v%10;
    v=v/10;
    tens=v%10;
    v=v/10;
    hundreds=v;     
    //Now print the number digit by digit
    lc.setDigit(3,0,(byte)hundreds,true);
    lc.setDigit(3,1,(byte)tens,false);
    lc.setDigit(3,2,(byte)ones,false);
}




void loop() {

  printNumber1(777); 
  printNumber2(333); 
  printNumber3(444); 
  printNumber4(555); 
}
