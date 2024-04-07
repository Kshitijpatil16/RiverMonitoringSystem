# River Monitoring System Project Log

### Phase -1: ESP32, Sensors, LoRaWAN Publisher

`7/04/24`
**K -** Hey team, today's progress report:

So, today I made sensor connections to the ESP32 as follows:

| Component         | ESP32 Pin |
|-------------------|-----------|
| **DS18B20 (Temperature Sensor)** | **GPIO 13** |
| **TDS Sensor v1.0**   | **Pin 34**    |
| **OLED Display**      | **SDA: GPIO 21, SCL: GPIO 22** |

Next, I wrote a [code](./Codes/Esp32_SensorIntergation_&_DisplayingReadings_on_OLED_code.ino) which will display both the sensor readings on the OLED display and flashed it to our ESP32.

The issues I figured out were: 
- The DS18B20 output pin given to the GPIO 13 needs to be connected to a pull-up resistor which is connected to a 5V supply.
- For the OLED display, I had to use the *u8g2 library* and `U8G2_SH1106_128X64_NONAME_F_SW_I2C` object.

Rest all was the same as you are imagining right now! Following this process, we can easily display both the readings on the OLED display.

![image](https://github.com/Kshitijpatil16/RiverMonitoringSystem/assets/104309685/95fd7b61-b315-46d5-85a0-d834433a2cb1)

Cheers

