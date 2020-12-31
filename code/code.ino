#include <Servo.h>

#include <Stepper.h>

const int stepsPerRound = 2048;

Servo motor1;

Servo motor2;

Stepper myStepper = Stepper(stepsPerRound, 8, 10, 9, 11);

int stepsPerRevolution = 173;

int pos;

int pushButton = 4; // tähän oikee numero eli se mihin nappula kytketään

int servoPos1 = 40; // yläservon alotuspaikka

const int servoPos2 = 10; // alaservon alotuspaikka

int servo2CurrentPos = servoPos2; //alaservon muuttuja

void setup() {

Serial.begin(9600);

pinMode(pushButton, INPUT);

motor1.write(servoPos1); // servo menee alotuspaikkaan

motor2.write(servoPos2);

motor1.attach(7);

motor2.attach(2);

myStepper.setSpeed(12);

}

void throwCard(){ // heittää kortin

  myStepper.step(stepsPerRound);

}

void turnCaseUp(int steps){ // kääntää korttipakan ylösalaisin, muuttuja steps määrää kuinka monta astetta servo pyörii

  for(pos = steps; pos >= servoPos1; pos -=1) { // steps pitää optimoida

  motor1.write(pos);

  delay (20);

  }

}

void turnCaseUpsidedown(int steps){ // kääntää korttipakan oikein päin, muuttuja steps määrää kuinka monta astetta servo pyörii

  for(pos = servoPos1; pos <= steps; pos += 1) { // steps pitää optimoida

  motor1.write(pos);

  delay (20);

  }

}

void turnBodyReverse(){ // kääntää koko laitetta myötäpäivään, lähtöpisteeseen

  for(pos = servo2CurrentPos; pos >= servoPos2; pos -=1) { // steps pitää optimoida

  motor2.write(pos);

  delay (20);

  }

  servo2CurrentPos = servoPos2;

 

}

void turnBody(int steps) { //kääntää koko laitetta vastapäivään, muuttujana on askelten lukumäärä

  for(pos = servo2CurrentPos; pos <= servo2CurrentPos + steps; pos += 1) { // steps pitää optimoida

  motor2.write(pos);

  delay (20);

  }

  servo2CurrentPos = servo2CurrentPos +  steps;

}

void waitUntilPush() { // ohjelma on pysähdyksissä kunnes painetaan nappulaa

  while (digitalRead(pushButton) == LOW) {

Serial.println(digitalRead(pushButton));

delay(1); //ei tee mitään

  }

}

void deal() { // kääntyy vähän ja jakaa yhen kortin, käytetään kun jaetaan korttei oikein päin

  turnBody(15);

  throwCard();

}

 

void loop() {

  waitUntilPush();

  for(int x = 0; x <= 1; x = x + 1) { // tapahtuu 2 kertaa

throwCard();

turnBody(100);

throwCard();

turnBody(100);

throwCard();    

turnBodyReverse(); // kääntyy lähtöpisteeseen

  }

  //The Flop

  waitUntilPush();

  turnBody(60);

  turnCaseUpsidedown(stepsPerRevolution); //pitää optimoida

  deal();

  deal();

  deal();

  //The Turn

  waitUntilPush();

  deal();

  //The River

  waitUntilPush();

  deal();

  turnCaseUp(stepsPerRevolution);

  turnBodyReverse();

 

}
