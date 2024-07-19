EFB1031 Electrical Circuit Analysis Lab May 2024

DC power supply with a fixed 15 V output using a full-wave rectifier (center-tap).

Load: Mega 2560 Arduino with RC255 RFID and Buzzer.


RC522 RFID Module and Buzzer Connection Diagram
|RC522 RFID Pin|Arduino Pin| 
| ------------- | ------------- |
|VCC|N/A|
|GND|GND|
|SDA|53|
|SCK|52|
|MOSI|51|
|MISO|50|
|RST|5|
|IRQ|N/A (optional)|

Buzzer Connection
|Buzzer Pin|Arduino Pin|Resistor (Ω)|
| ------------- | ------------- | ------------- |
|VCC|5V|N/A|
|GND|GND|N/A|
|I/O|8|N/A|
|Cathode (longest pin)|GND|N/A|
|Red pin|9|220Ω|
|Green pin|10|220Ω|
|Blue pin|11|220Ω|
