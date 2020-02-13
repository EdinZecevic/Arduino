#include "LedControl.h"
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>
#include <DS3231.h>
#include <Wire.h>

DS3231  rtc(SDA, SCL);

Time  t;

int Hor;
int Min;
int Sec;

String s;

LedControl lc=LedControl(8,7,6,5);//pins and number of displays

const int pinCS = 10;
const int numberOfHorizontalDisplays = 4;
const int numberOfVerticalDisplays = 1;

Max72xxPanel matrix = Max72xxPanel (pinCS, numberOfHorizontalDisplays, numberOfVerticalDisplays);

const int wait = 100; // In milliseconds
const int spacer = 1;
const int width = 5 + spacer; // Font width at 5 pixels

void setup() {
  Wire.begin();
rtc.begin();
Serial.begin(9600);
for (int i = 0; i < 5; i++) {
  lc.shutdown(i,false); /*The MAX72XX is in power-saving mode on startup,we have to do a wakeup call*/
  lc.setIntensity(i,8);/* Set the brightness to a medium values */
  lc.clearDisplay(i);/* and clear the display */
}

for (int i = 0; i < 3; i++) { //Prices dispays
  lc.setDigit(0, i, i + 1, false);
  lc.setDigit(1, i, i + 1, false);
  lc.setDigit(2, i, i + 1, false);
  lc.setDigit(3, i, i + 1, false);
  }
  
for (int i = 2; i < 6; i++) {  //Date time 7 seg display
        lc.setDigit(4, 2, 2 + 1, false);
        }
    
matrix.setIntensity (7); // Adjust the brightness between 0 and 15
 // Adjust according to needs
for(int i=0; i<4 ; i++){
   matrix.setPosition (i, i, 0); // The first display is in <0, 0>
   matrix.setRotation (i, 1); // Display position
}  
//rtc.setTime(13, 12, 0);     // Set the time to 12:00:00 (24hr format)
//rtc.setDate(1, 1, 2014);
}

void printPrice(int v, int b) {
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
    lc.setDigit(b,0,(byte)hundreds,true);
    lc.setDigit(b,1,(byte)tens,false);
    lc.setDigit(b,2,(byte)ones,false);
}

void printTime(int s, int b) {
    int time;
    int times;
    time=s%10;
    s=s/10;
    times=s%10;
    bool a=false;
      lc.setDigit(4,b,(byte)time,false);
      lc.setDigit(4,b+1,(byte)times,false);
      
}

void matrixtext(String m){
  for (int i = 0; i <width * m.length () + matrix.width () - 1 - spacer; i ++) {
     matrix.fillScreen (LOW);
     
 int letter = i / width;
 int x = (matrix.width () - 1) - i% width;
 int y = (matrix.height () - 8) / 2; // Center the text
 
 while (x + width - spacer>= 0 && letter>= 0) {
 if (letter <m.length ()) {
 matrix.drawChar (x, y, m [letter], HIGH, LOW, 1);
 }
 letter--;
 x -= width;
 }
 matrix.write (); // Show the characters
 delay (wait);
 }
}
 

void loop() {
  int i=1;
  
  while(Serial.available() > 0 && i==1)
{
  int c= Serial.read();

  if(c==1)
  {
    String b = Serial.readString();
    int a= b.toInt();
    printPrice(a,0);
  }
  else if(c==2)
  {
    String k = Serial.readString();
  int l= k.toInt();
    printPrice(l,1);
  }
  else if(c==3)
  {
    String m = Serial.readString();
  int n= m.toInt();
    printPrice(n,2);
  }
  else if(c==4)
  {
    String t = Serial.readString();
  int r= t.toInt();
    printPrice(r,3);
  }
  else if(c==5)
  {
  s = Serial.readString();
   matrixtext(s);
}}
   
   while(Serial.available() == 0){
        t = rtc.getTime();
        Hor = t.hour;
        Min = t.min;
        Sec = t.sec;
        //printTime(Sec,0);
        printTime(Min,2);
        printTime(Hor,4);
        matrixtext(s);
          }
    i=1;
}
