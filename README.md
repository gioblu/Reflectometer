### Reflectometer Arduino library
##### Wire and use in a simple way photodiode / LED based reflectometers / range finders
=====
<br>
Reflectometer mySensor(<span style="color: red">emitter pin</span>, <span style="color: red">sensor pin (analog input)</span>, <span style="color: red">how many readings</span>, <span style="color: red">filter</span>);
<br>
<br>
mysensor.distance(); 
<br>
<small>Returns some type of distance measurement using ISL (Inverse Square Law), obviously its impossible to determine a correct distance value without knowing the reflectivity of the object in front (could be a mirror 10m away or a black paper sheet at 1m), so in this case is only a estimated value.</small>



