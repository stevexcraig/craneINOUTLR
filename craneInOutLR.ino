const int switchPin = 11;    // Left Right
const int switch2Pin = 12;
const int motor1Pin = 5;
const int motor2Pin = 4;
const int enablePin = 3;
int potPin = A0;
int motorSpeed = 0;

const int switchBPin = 9;    // IN OUT
const int switchB2Pin = 10;
const int motor1BPin = 7;
const int motor2BPin = 8;
const int enableBPin = 6;
int potPinB = A1;
int motorSpeedB = 0;


void setup() {
  // set the switch as an input:
  pinMode(switchPin, INPUT_PULLUP);
  pinMode(switch2Pin, INPUT_PULLUP);

  // set all the other pins you're using as outputs:
  pinMode(motor1Pin, OUTPUT);
  pinMode(motor2Pin, OUTPUT);
  pinMode(enablePin, OUTPUT);

  // set the switch as an input:
  pinMode(switchBPin, INPUT_PULLUP);
  pinMode(switchB2Pin, INPUT_PULLUP);

  // set all the other pins you're using as outputs:
  pinMode(motor1BPin, OUTPUT);
  pinMode(motor2BPin, OUTPUT);
  pinMode(enableBPin, OUTPUT);


  // set enablePin high so that motor can turn on:
  digitalWrite(enablePin, HIGH);
  digitalWrite(enableBPin, HIGH);
}

void loop() {
  // if the switch is high, motor will turn on one direction:
  if (digitalRead(switchPin) == LOW) {
    digitalWrite(motor1Pin, LOW);   // set leg 1 of the H-bridge low
    digitalWrite(motor2Pin, HIGH);  // set leg 2 of the H-bridge high
    motorSpeed = analogRead(potPin) / 4;
    analogWrite(enablePin, motorSpeed);
  }
  // if the switch is high, motor will turn on one direction:
  else if (digitalRead(switch2Pin) == LOW) {
    digitalWrite(motor1Pin, HIGH);   // set leg 1 of the H-bridge low
    digitalWrite(motor2Pin, LOW);  // set leg 2 of the H-bridge high
    motorSpeed = analogRead(potPin) / 4;
    analogWrite(enablePin, motorSpeed);
  }
  // if the switch is low, motor will turn in the other direction:
  else {
    digitalWrite(motor1Pin, LOW);  // set leg 1 of the H-bridge high
    digitalWrite(motor2Pin, LOW);   // set leg 2 of the H-bridge low

  }

  // if the switch is high, motor will turn on one direction:
  if (digitalRead(switchBPin) == LOW) {
    digitalWrite(motor1BPin, LOW);   // set leg 1 of the H-bridge low
    digitalWrite(motor2BPin, HIGH);  // set leg 2 of the H-bridge high
    motorSpeedB = analogRead(potPinB) / 4;
    analogWrite(enableBPin, motorSpeedB);
  }
  // if the switch is high, motor will turn on one direction:
  else if (digitalRead(switchB2Pin) == LOW) {
    digitalWrite(motor1BPin, HIGH);   // set leg 1 of the H-bridge low
    digitalWrite(motor2BPin, LOW);  // set leg 2 of the H-bridge high
    motorSpeedB = analogRead(potPinB) / 4;
    analogWrite(enableBPin, motorSpeedB);
  }
  // if the switch is low, motor will turn in the other direction:
  else {
    digitalWrite(motor1BPin, LOW);  // set leg 1 of the H-bridge high
    digitalWrite(motor2BPin, LOW);   // set leg 2 of the H-bridge low

  }
}
