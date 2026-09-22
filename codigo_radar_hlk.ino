#define RXD2 16  // Conectado al pin TX del HLK-LD2410C
#define TXD2 17  // Conectado al pin RX del HLK-LD2410C

void setup() {
  // Inicializa el monitor serie de la PC
  Serial.begin(115200);
  while (!Serial) {
    ; // Espera a que se abra el puerto serie (solo necesario en algunas placas)
  }
  
  Serial.println("--- Prueba de Comunicación HLK-LD2410C ---");
  Serial.println("Inicializando puerto Serial2 a 256000 baudios...");

  // Inicializa la comunicación con el sensor radar
  // Configuración: 256000 baudios, modo 8N1, RX=GPIO16, TX=GPIO17
  Serial2.begin(256000, SERIAL_8N1, RXD2, TXD2);
  
  Serial.println("Esperando datos del sensor... Muévete frente a él.");
}

void loop() {
  // Si el sensor envía datos, los lee y los reenvía directamente al monitor serie de la PC
  if (Serial2.available()) {
    char c = Serial2.read();
    
    // Mostramos los datos en formato Hexadecimal para ver las tramas del radar
    if ((uint8_t)c < 0x10) Serial.print("0");
    Serial.print((uint8_t)c, HEX);
    Serial.print(" ");
  }

  // Pequeña ayuda visual en el monitor de la PC si tú escribes algo
  if (Serial.available()) {
    Serial2.write(Serial.read());
  }
}
