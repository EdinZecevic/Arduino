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

String string= "sinan"; //texts

void setup () {
 matrix.setIntensity (7); // Adjust the brightness between 0 and 15
 
 // Adjust according to needs
 matrix.setPosition (0, 0, 0); // The first display is in <0, 0>
 matrix.setPosition (1, 1, 0); // The second display is in <1, 0>
 matrix.setPosition (2, 2, 0); // The third display is in <2, 0>
 matrix.setPosition (3, 3, 0); // The fourth display is at <3, 0>
 
 matrix.setRotation (0, 1); // Display position
 matrix.setRotation (1, 1); // Display position
 matrix.setRotation (2, 1); // Display position
 matrix.setRotation (3, 1); // Display position

}

void loop () {
 int n = random (0.10);
 
 for (int i = 0; i <width * string.length () + matrix.width () - 1 - spacer; i ++) {
 
 matrix.fillScreen (LOW);
 
 int letter = i / width;
 int x = (matrix.width () - 1) - i% width;
 int y = (matrix.height () - 8) / 2; // Center the text
 
 while (x + width - spacer>= 0 && letter>= 0) {
 if (letter <string.length ()) {
 matrix.drawChar (x, y, string [letter], HIGH, LOW, 1);
 }
 
 letter--;
 x -= width;
 }
 matrix.write (); // Show the characters
 
 delay (wait);
 }
}
