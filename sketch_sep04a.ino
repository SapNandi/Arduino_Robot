#include<Servo.h>
Servo base;
Servo kneck;
Servo arm;
Servo gripper;

int p, q , r, s;

char data = 0;

void setup() {
  Serial.begin(9600);
  base.attach(8);
  kneck.attach(7);
  arm.attach(12);
  gripper.attach(13);

  base.write(90);
  kneck.write(180);
  arm.write(360);
  gripper.write(180);
}

void loop() {
  if (Serial.available() > 0) {
    data = Serial.read();
    Serial.print(data);
    Serial.print("\n");

    if (data == '1') {
      for (p = 90; p >= 0; p--) {
        base.write(p);
        delay(20);
      }
    }
    else if (data == '0') {
      if (p <= 90) {
        for (p = 0; p <= 90; p++) {
          base.write(p);
          delay(20);
        }
      }
      else if (p > 90) {
        for (p = 180; p >= 90; p--) {
          base.write(p);
          delay(20);
        }
      }

    }
    else if (data == 'L') {
      for (p = 90; p <= 180; p++) {
        base.write(p);
        delay(20);
      }
    }
    else if (data == '2') {
      for (q = 90; q <= 180; q++) {
        kneck.write(q);
        delay(20);
      }
    }
    else if (data == '3') {
      for (q = 180; q >= 90; q--) {
        kneck.write(q);
        delay(20);
      }
    }
    else if (data == '4') {
      for (r = 90; r < 270; r++) {
        arm.write(r);
        delay(10);
      }
    }
    else if (data == '5') {
      for (r = 270; r >= 90; r--) {
        arm.write(r);
        delay(10);
      }
    }
    else if (data == '6') {
      for (s = 90; s < 180; s++) {
        gripper.write(s);
        delay(5);
      }
    }
    else if (data == '7') {
      for (s = 180; s >= 90; s--) {
        gripper.write(s);
        delay(5);
      }
    }
  }
}
