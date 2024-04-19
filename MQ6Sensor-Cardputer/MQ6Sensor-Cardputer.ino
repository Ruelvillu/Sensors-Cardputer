#include "M5Cardputer.h"
#include <M5Unified.h>
#include <M5GFX.h>
// Built By RuelVillo+GPt3 20/04/2024 0245
// Define the analog pin connected to the sensor
#define SENSOR_PIN G1

void setup() {
    // Initialize M5Cardputer and display
    auto cfg = M5.config();
    M5Cardputer.begin(cfg);
    M5Cardputer.Display.fillScreen(TFT_BLACK); // Clear the screen
    M5Cardputer.Display.setTextSize(1);       // Set smaller text size
    
    // Set up the sensor
    pinMode(SENSOR_PIN, INPUT);

    // Adjust display orientation by 180 degrees
    M5Cardputer.Display.setRotation(1);
}

void loop() {
    // Read sensor value
    int sensorValue = analogRead(SENSOR_PIN);
    float voltage = sensorValue * (5.0 / 1023.0); // Convert analog value to voltage (assuming 5V reference voltage)

    // Clear previous sensor reading
    M5Cardputer.Display.fillScreen(TFT_BLACK);

    // Display new sensor reading
    M5Cardputer.Display.setCursor(20, M5Cardputer.Display.height() / 2 - 20);
    M5Cardputer.Display.setTextColor(TFT_WHITE);
    M5Cardputer.Display.print("CO "); // Carbon monoxide symbol
    M5Cardputer.Display.println("ppm: "); // Parts per million (ppm)
    M5Cardputer.Display.println(sensorValue); // Sensor reading

    M5Cardputer.Display.setCursor(20, M5Cardputer.Display.height() / 2 + 20); // Move voltage text down
    M5Cardputer.Display.print("Voltage: ");
    M5Cardputer.Display.println(voltage, 2); // Print voltage with 2 decimal places

    // Adjust the position of "Al3" text
    M5Cardputer.Display.setCursor(M5Cardputer.Display.width() / 2 - 20, M5Cardputer.Display.height() - 20);
    M5Cardputer.Display.print("Al3");

    delay(1000); // Update every second
}
