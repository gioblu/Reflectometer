### Reflectometer Arduino library
##### Play in a simple way with photodiode / LED based reflectometers / range finders / light sensors
=====
Reflectometer mySensor(**Emitter pin**, **Sensor pin**, **Readings**, **Filter**);
> **Emitter pin**: Arduino pin where you connected the positive of the IR/visible light emitter<br>
> **Sensor pin**: Arduino analog pin where you connected the positive of the photodiode/LED <br>
> **Readings**: Number of analog readings you want to perform in one measurement<br>
> **Filter**: Insert a number from 0 to 1 to filter the output value<br>

mysensor.distance(); 
<br>
> Returns **distance** measurement using ISL (Inverse Square Law), obviously its impossible to determine a correct distance value without knowing the reflectivity of the object in front (could be a mirror 10m away or a black paper sheet at 1m), so in this case is only an estimated value.

mysensor.ambient(); 
<br>
> Returns **ambient light** value that is the sum of all readings done with the LED emitter off

mysensor.reflex(); 
<br>
> Returns **light measurement** value that is the sum of all readings done with the LED emitter on





