# Reflectometer Arduino library
###### Wire and use in a simple way photodiode / LED based reflectometers / range finders
=====
<br>
Reflectometer mySensor(emitter pin, sensor pin (analog input), how many readings, filter);
<br>
mysensor.distance(); 
<br>
Returns some type of distance measurement using ISL (Inverse Square Law), obviously its impossible to determine a correct distance value without knowing the reflectivity of the object in front (could be a mirror 10m away or a black paper sheet at 1m), so in this case is only a estimated value.



