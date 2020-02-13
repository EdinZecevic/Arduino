#include "LedControl.h"
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

const int pinCS = 10;
const int numberOfHorizontalDisplays = 4;
const int numberOfVerticalDisplays = 1;

Max72xxPanel matrix = Max72xxPanel (pinCS, numberOfHorizontalDisplays, numberOfVerticalDisplays);

const int wait = 100; // In milliseconds
const int spacer = 1;
const int width = 5 + spacer; // Font width at 5 pixels

void setup() {
  
Serial.begin(9600);

    
matrix.setIntensity (7); // Adjust the brightness between 0 and 15
 // Adjust according to needs
for(int i=0; i<4 ; i++){
   matrix.setPosition (i, i, 0); // The first display is in <0, 0>
   matrix.setRotation (i, 1); // Display position
}  

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
  String m="Edin";
        matrixtext(m);
}
