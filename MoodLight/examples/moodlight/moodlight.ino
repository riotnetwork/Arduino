/* MoodLight: Library with MoodLight functions 
   Created by Kasper Kamperman, February 26, 2011.
   http://www.kasperkamperman.com
   Released into the public domain.

   You can find the code without use of the library at:
   http://www.kasperkamperman.com/blog/arduino/arduino-programming-hsb-to-rgb/
*/ 

// Include the MoodLight library.
#include <MoodLight.h>
#include <DmxInterrupt.h>
#include <DmxSimple.h>

// inputs
int sensorPin = 0;

// outputs
int ledPinR = 9;  // pwm pin with red led
int ledPinG = 10; // pwm pin with green led
int ledPinB = 11; // pwm pin with blue led

// other variables
int sensorVal;   // store value from sensorPin

int hue = 0;         // use value between 0 - 359
int saturation;  // use value between 0 - 255
int brightness = 255;  // use value between 0 - 255

// create MoodLight object
MoodLight ml = MoodLight(); 

void setup() {  
    // declare the serial comm at 9600 baud rate
  Serial.begin(9600);

}

void loop() { 
  
  // call the returned value from GetFromSerial() function
  switch(GetFromSerial())
  {
  case 'H':
   hue= GetFromSerial();
    break;
  case 'S':
    saturation=  GetFromSerial();
    break;
    ml.setHSB(hue, saturation , brightness);
    
  DmxSimple.write(1,ml.getRed());
  DmxSimple.write(2,ml.getGreen());
  DmxSimple.write(3,ml.getBlue());
  }
  
  
 
}

int GetFromSerial()
{
  while (Serial.available()<=0) {
  }
  return Serial.read();
}
