// GRUPO 7 -- BENCHOAM, GONZALEZ, YOVAN
#include <MyLD2410.h>

#define RX_PIN 16
#define TX_PIN 17

#define RADAR_BAUD 256000

HardwareSerial radarSerial(1);

MyLD2410 sensor(radarSerial);

void setup() {
  Serial.begin(115200);

  radarSerial.begin(
    RADAR_BAUD,
    SERIAL_8N1,
    RX_PIN,
    TX_PIN
  );

  delay(1000);

  Serial.println("================================");
  Serial.println("     PRUEBA HLK-LD2410C");
  Serial.println("================================");

  if (!sensor.begin()) {
    Serial.println("ERROR: no se pudo conectar con el LD2410C");
    Serial.println("Revisa VCC, GND, TX y RX.");
    
    while (true) {
      delay(1000);
    }
  }

  Serial.println("LD2410C conectado correctamente!");
}

void loop() {

  if (sensor.check()) {

    Serial.println("----------------------------");

    Serial.print("Distancia: ");
    Serial.print(sensor.detectedDistance());
    Serial.println(" cm");
  }

  delay(200);
}