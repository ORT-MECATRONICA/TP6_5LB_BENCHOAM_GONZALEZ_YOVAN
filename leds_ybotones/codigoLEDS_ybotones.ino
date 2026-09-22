// GRUPO 7 -- BENCHOAM, GONZALEZ, YOVAN - 5LB
const int PIN_LED_1 = 2;   
const int PIN_LED_2 = 15;  


const int PIN_BOTON_1 = 4; 
const int PIN_BOTON_2 = 5;
void setup() {

  pinMode(PIN_LED_1, OUTPUT);
  pinMode(PIN_LED_2, OUTPUT);
  
 
  pinMode(PIN_BOTON_1, INPUT_PULLUP);
  pinMode(PIN_BOTON_2, INPUT_PULLUP);
}

void loop() {

  int estadoBoton1 = digitalRead(PIN_BOTON_1);
  if (estadoBoton1 == LOW) {
    digitalWrite(PIN_LED_1, HIGH); 
  } else {
    digitalWrite(PIN_LED_1, LOW);  
  }

  int estadoBoton2 = digitalRead(PIN_BOTON_2);
  if (estadoBoton2 == LOW) {
    digitalWrite(PIN_LED_2, HIGH); 
  } else {
    digitalWrite(PIN_LED_2, LOW);  
  }
}

