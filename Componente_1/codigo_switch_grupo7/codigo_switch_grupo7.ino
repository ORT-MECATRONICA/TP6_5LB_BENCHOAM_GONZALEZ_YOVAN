// GRUPO 7 5LB_ BENCHOAM, GONZALEZ, YOVAN
#define SWITCH_PIN 4

void setup() {
  Serial.begin(115200);

  pinMode(SWITCH_PIN, INPUT_PULLUP);
}

void loop() {

  if (digitalRead(SWITCH_PIN) == LOW) {
    Serial.println("SWITCH ACTIVADO");
  } 
  else {
    Serial.println("SWITCH DESACTIVADO");
  }

  delay(200);
}