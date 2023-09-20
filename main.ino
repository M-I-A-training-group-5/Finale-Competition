
#include "MPU.h"
// #include "PID.h"
// #include <Timer.h>
#include "USS.h"
#include <Wire.h>
#include "vehicle_movement.h"

#define t_pin 12
#define e_pin 11

int* l298NPins[5];

pins[0] = &;
pins[1] = &in11_pin;
pins[2] = &in21_pin;
pins[3] = &in12_pin;
pins[4] = &in22_pin;
// Timer my_timer;
UltrasonicSensor USS(t_pin, e_pin);
// MPU6050 imu;
// PID pid_controller1(1, 0, 0, 0.01);
// PID pid_controller2(1, 0, 0, 0.01);

// void moveForward(distance) {
//   move_l298N(pinsArr,
//              pid_controller1.calculate(distance, USS.getDistance(), 0));
// }
// void moveBackwards(distance) {
//   move_l298N(pinsArr,
//              pid_controller1.calculate(-distance, USS.getDistance(), 0));
// }
// void rotateRight() {
//     move_l298N(pinsArr, pid_controller2.calculate(90, imu.updateYaw()), 1)) ;
// }
// void rotateLeft() {
//     move_l298N(pinsArr, pid_controller2.calculate(-90, imu.updateYaw()), 1));
// }
// void stop() { move_l298N(pinsArr, 0, 0); }

void setup() {
  Serial.begin(9600);

  for (int i= 0 ; i<5 ;i++){
    pinMode(pins[i] , OUTPUT);
  }
  // float current_distance = USS.getDistance() float Yaw =
  // imu.updateYaw() timer.every(1000, timerCallback);
  // imu.setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  move_l298N( pins, 10, 0);
  Serial.println(USS.getDistance()); 
}
