/*
  Reflectometer.h - General purpose library for reflectometer sensors.
  Created by Giovanni Blu Mitolo, November 13, 2014.
  Released into the public domain.
*/

#ifndef Reflectometer_h
#define Reflectometer_h
#include "WProgram.h"
#include "WConstants.h"
#endif

class Reflectometer {

  public:

    Reflectometer(int emitter, int sensor, int readings, int filter);

    double ambient();
    double reflex();
    double distance();

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
