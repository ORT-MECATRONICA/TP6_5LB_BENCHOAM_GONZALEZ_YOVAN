// Grupo 7 5LB, BENCHOAM, GONZALEZ, YOVAN.
#define LDR_PIN 34

void setup() {
  Serial.begin(115200);

  pinMode(LDR_PIN, INPUT);
}

void loop() {
  int valorLDR = analogRead(LDR_PIN);

  Serial.print("Valor del LDR: ");
  Serial.println(valorLDR);

  delay(500);
}