/*   
  A modified verion of the 433 MHz Weather Demo from
  DroneBot Workshop 2018
  https://dronebotworkshop.com
*/

//Include Adafruit libraries to run the OLED display.
//As well as the RadioHead Amplitude Shift Keying (ASK) Library 
//Some of these may be unneccesary.

#include <Adafruit_SPITFT.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>
#include <splash.h>
#include <Adafruit_SSD1306.h>
#include <RH_ASK.h>
#include <SPI.h> 

//defines a pin to reset the OLED if applicable
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

// Define output strings

String str_humid;
String str_temp;
String str_out;

// Create Amplitude Shift Keying Object
RH_ASK rf_driver;

void setup()
{
    // Initialize ASK Object
    rf_driver.init();
    // Setup Serial Monitor
    Serial.begin(9600);

    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.display();
    delay(2000);
    display.clearDisplay();
}

void loop()
{
    // Set buffer to size of expected message
    uint8_t buf[11];
    uint8_t buflen = sizeof(buf);
    // Check if received packet is correct size
    if (rf_driver.recv(buf, &buflen))
    {
      
      // Message received with valid checksum
      // Get values from string
      
      // Convert received data into string
      str_out = String((char*)buf);
      
      // Split string into two values
      for (int i = 0; i < str_out.length(); i++) {
      if (str_out.substring(i, i+1) == ",") {
      str_humid = str_out.substring(0, i);
      str_temp = str_out.substring(i+1);
      break;
      }
    }
      
      // Print values to Serial Monitor
      Serial.print("Humidity: ");
      Serial.print(str_humid);
      Serial.print("  - Temperature: ");
      Serial.println(str_temp);


      // routine for displaying text for temp/hum readout
      display.clearDisplay();
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(0,0);
      display.println(str_temp);
      display.println(str_humid);
      display.setCursor(72,0);
      display.println("Temp");
      display.setCursor(72,16);
      display.println("Hum");
      display.display();
      delay(2000);
               
    }
}
