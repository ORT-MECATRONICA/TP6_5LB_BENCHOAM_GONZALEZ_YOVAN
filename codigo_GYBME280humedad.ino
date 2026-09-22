// grupo 7: BENCHOAM, GONZALEZ , YOVAN.
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Adafruit_BMP280.h> 

#define I2C_SDA 21
#define I2C_SCL 22

Adafruit_BME280 bme; 
Adafruit_BMP280 bmp;

bool esBME = false;
bool esBMP = false;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n=== INICIANDO LECTURA DE DATOS ===");

  // Configuramos los pines I2C del ESP32 de forma general
  Wire.begin(I2C_SDA, I2C_SCL);

  // 1. Intentamos iniciar como BME280 (Humedad + Temp + Presión)
  if (bme.begin(0x76, &Wire)) {
    esBME = true;
    Serial.println("-> Sensor identificado como: BME280 (Mide Humedad)");
  } 
  // 2. Si falla el BME, probamos con el método correcto para el BMP280 en 0x76
  else if (bmp.begin(0x76)) {
    esBMP = true;
    Serial.println("-> Sensor identificado como: BMP280 (No mide Humedad)");
  } 
  // 3. Por si las dudas ocurriera otro problema
  else {
    Serial.println("Error crítico: No se pudo comunicar con el chip.");
    while (1) delay(10);
  }
  
  Serial.println("-------------------------------------------------");
}

void loop() {
  float temp = 0.0, pres = 0.0, hum = 0.0, alt = 0.0;

  if (esBME) {
    temp = bme.readTemperature();
    pres = bme.readPressure() / 100.0F; // Convierte a hPa
    hum  = bme.readHumidity();
    alt  = bme.readAltitude(1013.25);   // Altitud basada en presión a nivel del mar
  } 
  else if (esBMP) {
    temp = bmp.readTemperature();
    pres = bmp.readPressure() / 100.0F;
    hum  = -1.0;                        // El chip BMP280 no tiene sensor de humedad
    alt  = bmp.readAltitude(1013.25);
  }

  // --- MOSTRAR DATOS EN EL MONITOR SERIE ---
  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.println(" °C");

  Serial.print("Presión:     ");
  Serial.print(pres);
  Serial.println(" hPa");

  Serial.print("Humedad:     ");
  if (hum >= 0) {
    Serial.print(hum);
    Serial.println(" %");
  } else {
    Serial.println("No disponible");
  }

  Serial.print("Altitud apr: ");
  Serial.print(alt);
  Serial.println(" m");

  Serial.println("-------------------------------------------------");
  
  delay(2000); // Lee datos del ambiente cada 2 segundos
}

