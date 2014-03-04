/*
  MoodLight.h - Library with MoodLight functions 
  Created by Kasper Kamperman, February 26, 2011.
  http://www.kasperkamperman.com
  Released into the public domain.
  
  More info in the .cpp file.
*/


#ifndef MoodLight_h
#define MoodLight_h

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

class MoodLight
{
  public:
    MoodLight();
    void setHSB(uint16_t,uint8_t,uint8_t);
    uint8_t getRed();
    uint8_t getGreen();
    uint8_t getBlue();
    uint8_t getDc(uint8_t);
    uint8_t* _dim_curve;    
    
  private:
    
    uint8_t  _red;
    uint8_t  _green;
    uint8_t  _blue;
};

#endif