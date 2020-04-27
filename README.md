# Arduino-Wireless-Temp-Sensor
Upload the Transceiver .ino file to the Arduino you plan to transmit data from.

Ground to Ground

VCC to 5V

Data from DHT11 to Digital Pin 7

Data from 433 MHz Transmitter to Digital Pin 12

Plug the transceiver into its own power source and let it normalize the sensor while you create the receiver

Upload the Receiver .ino file to the Arduino that will receive the data.

The OLED display requires only 3.3 Volts so wire that to the 3.3V pin

Ground to Ground

SCL to the SCL Pin

SDA to the SDA pin

The Transmitter has some extra pins.

Ground to Ground

VCC to 5V

Any of the 2 middle Data Pins go to Digital Pin 11

Plug the receiver into a power source and it should start displaying the temperature in roughly 30 seconds. It will update the Temp and Humidity every 20 seconds until power is disconnected or the data is interrupted. If you are having trouble with range on your 433 MHz module experiment with different types of antenna.
