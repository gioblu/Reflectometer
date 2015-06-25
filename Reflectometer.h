/*
  Reflectometer.cpp - General purpose library for reflectometers.
  
  With one photodiode, one LED (better if IR but can be also visible light) and
  Reflectometer you can have a decent distance sensor with up to 5 meters range
  depending on your setup.

  Pass to the constructor the photodiode analog pin and the LED emitter pin
  you are using to get a ISL (Inverse Square Law) distance sensor.
  
  Created by Giovanni Blu Mitolo, November 13, 2014.
  Released into the public domain.
*/

#ifndef Reflectometer_h
  #define Reflectometer_h

  #if defined(ARDUINO) && (ARDUINO >= 100)
    #include "Arduino.h"
  #else
    #include "WProgram.h"
    #include "WConstants.h"
  #endif
#endif

class Reflectometer {

  public:

    Reflectometer(int emitter, int sensor, int readings, int filter);

    void update_ambient_light();        // Update _ambient value
    void update_reading_with_emitter(); // Update _intensity value
    
    double ambient_light(); // Returns _ambient
    double reflex();        // Returns _intensity - _ambient
    double distance();      // Returns distance calculated with inverse square law 

  private:

		double _ambient;
		double _distance;
		double _intensity;
    double _max_intensity; // Maximum _intensity obtained used as distance 0 intensity in ISL
    int _filter;
    int _emitter;
    int _sensor;
    int _readings;

};
