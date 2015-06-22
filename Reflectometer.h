/*
  Reflectometer.h - General purpose library for reflectometer sensors.
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

    void compute_ambient_light();
    void compute_reflex();
    double distance();
    double ambient_light();

  private:

		double _ambient;
		double _distance;
		double _intensity;
    double _max_intensity;
    int _filter;
    int _emitter;
    int _sensor;
    int _readings;

};
