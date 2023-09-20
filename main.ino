
#include "MPU.h"
// #include "PID.h"
// #include <Timer.h>
// #include "USS.h"
// #include "bati5a.h"
#include <Wire.h>
#include "vehicle_movement.h"

#define t_pin 12
#define e_pin 11

float offset = 0.0;
int pins[5] = {9, 8, 7, 5, 4};
// Timer my_timer;
// MPU_6050 mpu;
MPUPU imu;
// UltrasonicSensor USS(t_pin, e_pin);

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

  Wire.begin();
  Serial.begin(9600);
  offset = imu.calibrateGyro();

  for (int i= 0 ; i<5 ;i++){
    pinMode(pins[i] , OUTPUT);
  }
  
  // float current_distance = USS.getDistance() float Yaw =
  // imu.updateYaw() timer.every(1000, timerCallback);
  // imu.setupYaw();
}

void loop() {
  delay(1);
  
  // put your main code here, to run repeatedly:

  // move_l298N(pins, 200, 1 );
  Serial.println(imu.updateYaw(offset));
  // Serial.println(USS.getDistance()); 
}
