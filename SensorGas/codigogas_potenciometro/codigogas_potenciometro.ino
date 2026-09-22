// GRUPO 7 -- BENCHOAM, GONZALEZ, YOVAN
#define POT_PIN 34

void setup() {
  Serial.begin(115200);
}

void loop() {
  int valor = analogRead(POT_PIN);

  Serial.println(valor);

  delay(100);
}
