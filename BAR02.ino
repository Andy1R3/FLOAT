#include <Wire.h>
#include "MS5837.h"

MS5837 sensor;

bool stopReading = false; // Flag per indicare se la lettura deve essere interrotta

void setup() {
  Serial.begin(9600);
  Serial.println("Starting");
  Wire.begin();
  sensor.setModel(MS5837::MS5837_02BA);
  sensor.init();
  sensor.setFluidDensity(997); // kg/m^3 (997 freshwater, 1029 for seawater)
}

void loop() {
  if (Serial.available() > 0) { // Se c'è un input seriale disponibile
    char command = Serial.read(); // Leggi il carattere dalla seriale
    if (command == 's') { // Se il carattere letto è 's', ferma la lettura
      stopReading = true;
    }
  }
  
  if (!stopReading) { // Se la lettura non è stata interrotta
    sensor.read();
    Serial.print("Pressure: "); 
    Serial.print(sensor.pressure()); 
    Serial.println(" mbar");
  
    Serial.print("Temperature: "); 
    Serial.print(sensor.temperature()); 
    Serial.println(" deg C");
  
    Serial.print("Depth: "); 
    Serial.print(sensor.depth()); 
    Serial.println(" m");
  
    Serial.print("Altitude: "); 
    Serial.print(sensor.altitude()); 
    Serial.println(" m above mean sea level");
  }

  delay(1000);
}
