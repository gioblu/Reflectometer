/*
  Reflectometer.cpp - General purpose library for reflectometer sensors.
  Created by Giovanni Blu Mitolo, November 13, 2014.
  Released into the public domain.
*/

#include "WProgram.h"
#include "WConstants.h"
#include "Reflectometer.h"

Reflectometer::Reflectometer(int emitter, int sensor, int readings, int filter) {

  pinMode(sensor, INPUT);
  pinMode(emitter, OUTPUT);

  _emitter = emitter;
  _sensor = sensor;
  _readings = readings;
  _filter = filter;

  (_SFR_BYTE(ADCSRA) |= _BV(ADPS2));
	(_SFR_BYTE(ADCSRA) &= ~_BV(ADPS1));
	(_SFR_BYTE(ADCSRA) |= _BV(ADPS0));

};

double Reflectometer::ambient() {

  _ambient = 0;
  digitalWrite(_emitter, LOW);

  for(int i = 0; i < _readings; i++)
    _ambient = _ambient + analogRead(_sensor);
};

double Reflectometer::reflex() {

  _intensity = 0;
  digitalWrite(_emitter, HIGH);

  for(int i = 0; i < _readings; i++)
    _intensity = _intensity + analogRead(_sensor);

  digitalWrite(_emitter, LOW);
};

double Reflectometer::distance() {
  
  this->ambient();
  this->reflex();

  if(_ambient < _intensity)
  	_intensity = _intensity - _ambient;
  else return 0;

  if(_intensity > _max_intensity)
    _max_intensity = _intensity;

  return _distance = (_distance * _filter) + (sqrt(_max_intensity / _intensity) * (1 - _filter));

};
