Prime-testing

Inspired by Ralph Bacon

He made a small Arduino-program for testing "find primes 
in 30 seconds" and ran it on different platforms.

I have made a small extension and have "ported" it to c and Python

The result of my testing:
<table>
  <tr>
    <th>Platform<th>Number of primes<th>Factor
  </tr>
  <tr>
    <td>TinyPico<td align="right">2802<td align="right">73
  </tr>
  <tr>
    <td>UNO<td align="right">3850<td align="right">100
  </tr>
  <tr>
    <td>ESP8266<td align="right">28012<td align="right">728
  </tr>
  <tr>
    <td>ESP32<td align="right">180045<td align="right">4676
  </tr>
  <tr>
    <td>RPi ZW<td align="right">185766<td align="right">4825
  </tr>
  <tr>
    <td>RPi	3<td align="right">3246945<td align="right">6414
  </tr>
  </table>
TinyPico: Run on the latest ESP32-based miniboard from unexpected maker

ESP8266 run on a Wemos D1 mini
