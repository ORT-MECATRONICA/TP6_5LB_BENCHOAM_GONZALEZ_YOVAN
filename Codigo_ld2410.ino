// Grupo 7 - Benchoam, gonzalez, yovan - 5LB
#include <ld2410.h>

// Definimos los pines para el puerto Serial2 del ESP32
#define RADAR_RX_PIN 16
#define RADAR_TX_PIN 17

ld2410 radar;

void setup() {
  // Inicializa el monitor serial de la PC
  Serial.begin(115200);
  while(!Serial); 

  // Inicializa el puerto Serial2 del ESP32 a la velocidad del radar (256000)
  // Pasamos los parámetros: velocidad, configuración, pin RX, pin TX
  Serial2.begin(256000, SERIAL_8N1, RADAR_RX_PIN, RADAR_TX_PIN); 

  Serial.println("\n--- Iniciando prueba del HLK-LD2410C con ESP32 ---");
  
  // Asignamos el puerto físico Serial2 al objeto de la librería
  if (radar.begin(Serial2)) {
    Serial.println("¡Sensor LD2410C detectado correctamente por HardwareSerial!");
  } else {
    Serial.println("Error: No se pudo comunicar con el sensor.");
    Serial.println("Revisa que TX esté en GPIO 16, RX en GPIO 17 y que el sensor tenga 5V.");
    while(1); 
  }
}

void loop() {
  // El ESP32 procesa constantemente los paquetes del radar
  radar.read(); 

  // Si el sensor está conectado y detecta cualquier tipo de presencia
  if (radar.isConnected() && radar.presenceDetected()) {
    Serial.println("=========================================");
    Serial.print("👤 ¡Presencia Detectada! -> ");
    
    // El sensor calcula la distancia general combinando ambos estados
    Serial.print("Distancia estimada: ");
    Serial.print(radar.stationaryTargetDistance()); // Puedes usar esta o movingTargetDistance
    Serial.println(" cm");

    // Condición 1: Alguien o algo se está moviendo
    if (radar.movingTargetDetected()) {
      Serial.print("  🏃 En movimiento. Energía/Señal: ");
      Serial.println(radar.movingTargetEnergy());
    }

    // Condición 2: Alguien está completamente quieto (estático)
    if (radar.stationaryTargetDetected()) {
      Serial.print("  🧍 Estático (quieto). Energía/Señal: ");
      Serial.println(radar.stationaryTargetEnergy());
    }
    
    delay(400); // Pausa para que la lectura en pantalla sea legible
  }
}
