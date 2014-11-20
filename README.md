### Reflectometer Arduino library
##### Wire and use in a simple way photodiode / LED based reflectometers / range finders
=====
Reflectometer mySensor(**Emitter pin**, **Sensor pin (analog input)**, **Readings**, **Filter**);
> **Emitter pin**: Arduino pin where you connected the positive of the IR/visible light emitter<br>
> **Sensor pin**: Arduino analog pin where you connected the positive of the photodiode/LED <br>
> **Readings**: Number of analog readings you want to perform in one measurement<br>
> **Filter**: Insert a number from 0 to 1 to filter the output value<br>

mysensor.distance(); 
<br>
> Returns distance measurement using ISL (Inverse Square Law), obviously its impossible to determine a correct distance value without knowing the reflectivity of the object in front (could be a mirror 10m away or a black paper sheet at 1m), so in this case is only an estimated value.



