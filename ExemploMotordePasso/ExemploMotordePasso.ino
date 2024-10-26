#include <Stepper.h>

#define VERT_PIN A0
#define HORZ_PIN A1
#define SEL_PIN  2

#define VERT_PIN A0
#define HORZ_PIN A1
#define SEL_PIN  2

int x = 0;
int y = 0;

int stepsPerRevolution = 5;

Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() {

  pinMode(VERT_PIN, INPUT);
  pinMode(HORZ_PIN, INPUT);
  pinMode(SEL_PIN, INPUT_PULLUP);

  myStepper.setSpeed(30);

  Serial.begin(9600);
}

void loop() {

  int horz = analogRead(HORZ_PIN);
  int vert = analogRead(VERT_PIN);

  //Serial.print("Horinzontal: ");
  //Serial.print(horz);
  //Serial.print(" : ");
  //Serial.print("Vertical: ");
  //Serial.print(vert);
  //Serial.println();

  if (vert < 300) {
    Serial.println("Para Baixo");
    stepsPerRevolution = stepsPerRevolution / 2;
    delay(1000);
  }
  if (vert > 700) {
     Serial.println("Para Cima");    
     stepsPerRevolution = stepsPerRevolution * 2;
     delay(1000);
  }
  if (horz > 700) {
    Serial.println("Para Esquerda");
    myStepper.step(-stepsPerRevolution);
    delay(500);    
  }
  if (horz < 300) {
    Serial.println("Para Direita");
    myStepper.step(stepsPerRevolution);
    delay(500);  
  }

  if (digitalRead(SEL_PIN) == LOW) {
    Serial.println("Sel");
  }  

  //Serial.println("clockwise");
  //myStepper.step(stepsPerRevolution);
  //delay(500);


  //Serial.println("counterclockwise");
  //myStepper.step(-stepsPerRevolution);
  //delay(500);
}