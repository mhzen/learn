#include <ESP32Servo.h>

Servo myservo;

#define TRIG_PIN 14
#define ECHO_PIN 12
#define SERVO_PIN 22

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  myservo.attach(SERVO_PIN);
}

void loop() {
  // put your main code here, to run repeatedly:
  // delay(1); // this speeds up the simulation
  long duration, distance;

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.print(" cm");

  if (distance < 300){
    myservo.write(90);
    delay(500);
  }else{
    myservo.write(0);
  }

  delay(5);
}
