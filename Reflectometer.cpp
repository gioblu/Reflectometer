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

void Reflectometer::update_ambient_light() {
  _ambient = 0;
  digitalWrite(_emitter, LOW);

  for(int i = 0; i < _readings; i++)
    _ambient = _ambient + analogRead(_sensor);
};

void Reflectometer::update_reading_with_emitter() {
  _intensity = 0;
  digitalWrite(_emitter, HIGH);

  for(int i = 0; i < _readings; i++)
    _intensity = _intensity + analogRead(_sensor);

  digitalWrite(_emitter, LOW);
};

double Reflectometer::ambient_light() {
  return _ambient;
};

double Reflectometer::reflex() {
  this->update_ambient_light();
  this->update_reading_with_emitter();
  return _intensity - _ambient;
};

double Reflectometer::distance() {
  this->update_ambient_light();
  this->update_reading_with_emitter();

  if(_ambient < _intensity)
    _intensity = _intensity - _ambient;
  else 
    return 0;

  if(_intensity > _max_intensity)
    _max_intensity = _intensity;

  return _distance = (_distance * _filter) + (sqrt(_max_intensity / _intensity) * (1 - _filter));
};


