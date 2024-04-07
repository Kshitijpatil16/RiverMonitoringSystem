#include <Wire.h>
#include <U8g2lib.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is connected to GPIO 13 for DS18B20
#define ONE_WIRE_BUS 13

// Analog pin connected to TDS sensor
#define TDS_SENSOR_PIN 34

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// Define the OLED display object
U8G2_SH1106_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ 22, /* data=*/ 21, /* reset=*/ U8X8_PIN_NONE);

void setup() {
  Serial.begin(9600);
  sensors.begin();

  // Initialize the OLED display
  u8g2.begin();
}

void loop() {
  // Read temperature from DS18B20 sensor
  sensors.requestTemperatures();
  float temperatureC = sensors.getTempCByIndex(0);

  // Read TDS sensor value
  int tdsValue = analogRead(TDS_SENSOR_PIN);

  // Display readings on OLED display
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr); // Set font size to 8 pixels
  u8g2.setFontPosTop(); // Set font position to top

  // Calculate text widths
  int temperatureTextWidth = u8g2.getStrWidth("Temperature:");
  int tdsTextWidth = u8g2.getStrWidth("TDS Value:");

  // Calculate center positions
  int centerX = (128 - temperatureTextWidth) / 2;
  int centerY = 0;
  int temperatureValueX = (128 - u8g2.getStrWidth("100.00C")) / 2;
  int tdsValueX = (128 - u8g2.getStrWidth("1023")) / 2;

  // Display temperature
  u8g2.setCursor(centerX, centerY);
  u8g2.print("Temperature:");
  u8g2.setCursor(temperatureValueX, centerY + 15);
  u8g2.print(temperatureC);
  u8g2.print("C");

  // Display TDS value
  u8g2.setCursor(centerX, centerY + 30);
  u8g2.print("TDS Value:");
  u8g2.setCursor(tdsValueX, centerY + 45);
  u8g2.print(tdsValue);

  u8g2.sendBuffer();

  // Display readings on serial monitor
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");
  Serial.print("TDS Value: ");
  Serial.println(tdsValue);

  // Delay before taking the next reading
  delay(1000);
}
