#define sensorDigital A0
#define sensorTrigger 10
#define sensorEcho 11
#define Motor 9
#define buzzer 8

void setup() {
  pinMode(sensorDigital, INPUT);
  pinMode(sensorTrigger, OUTPUT);
  pinMode(sensorEcho, INPUT);
  pinMode(Motor, OUTPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(Motor, HIGH);
  digitalWrite(buzzer, LOW);
  Serial.begin(9600);
}

void loop() {
  bool alcoholDetected = digitalRead(sensorDigital);
  Serial.print("Alcohol Sensor Value: ");
  Serial.println(alcoholDetected);

  long duration, distance;
  digitalWrite(sensorTrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(sensorTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensorTrigger, LOW);

  duration = pulseIn(sensorEcho, HIGH);
  distance = (duration / 2) / 29.1;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (alcoholDetected == LOW || (distance > 0 && distance < 15)) {
    digitalWrite(Motor, LOW);
    digitalWrite(buzzer, HIGH);
  } 
  else {
    digitalWrite(Motor, HIGH);
    digitalWrite(buzzer, LOW);
  }

  delay(100);
}
