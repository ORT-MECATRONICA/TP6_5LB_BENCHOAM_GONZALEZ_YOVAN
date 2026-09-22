// GRUPO 7 -- BENCHOAM, GONZALEZ, YOVAN, 5LB
#include <Wire.h>
#include <Adafruit_INA219.h>


Adafruit_INA219 ina219;

void setup(void) {

  Serial.begin(115200);
  while (!Serial) {
    delay(1);
  }

  Serial.println("Inicializando el sensor INA219...");


  if (!ina219.begin()) {
    Serial.println("Error: No se pudo encontrar el sensor INA219. Verifica las conexiones.");
    while (1) { delay(10); }
  }

  Serial.println("Sensor INA219 detectado correctamente. Iniciando lecturas:\n");
}

void loop(void) {
  float shuntvoltage = 0;
  float busvoltage = 0;
  float current_mA = 0;
  float loadvoltage = 0;
  float power_mW = 0;

  shuntvoltage = ina219.getShuntVoltage_mV();
  busvoltage = ina219.getBusVoltage_V();
  current_mA = ina219.getCurrent_mA();
  power_mW = ina219.getPower_mW();
  loadvoltage = busvoltage + (shuntvoltage / 1000);

  Serial.print("Voltaje de Bus (Fuente): ");
  Serial.print(busvoltage);
  Serial.println(" V");
  Serial.print("Voltaje de Shunt:        ");
  Serial.print(shuntvoltage);
  Serial.println(" mV");
  Serial.print("Voltaje en la Carga:     ");
  Serial.print(loadvoltage);
  Serial.println(" V");
  Serial.print("Corriente:               ");
  Serial.print(current_mA);
  Serial.println(" mA");
  Serial.print("Potencia:                ");
  Serial.print(power_mW);
  Serial.println(" mW");
  Serial.println("--------------------------------------------------");

  delay(2000);
}
