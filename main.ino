
#include "MPU6050.h"
#include "PID.h"
#include <Timer.h>
#include <Ultrasonicpos>
#include <Wire.h>
#include <vehicle_movement.h>

#define t_pin 11
#define pinsArr                                                                \
  { 9, 8, 7, 5, 4 }
Timer my_timer;
UltrasonicSensor USS;
MPU6050 imu;
PID pid_controller1(1, 0, 0, 0.01);
PID pid_controller2(1, 0, 0, 0.01);

void moveForward(distance) { move_l298N(pinsArr, pid_controller1.calculate(distance, USS.getDistance(), 0));
}
void moveBackwards(distance) {
   move_l298N(pinsArr, pid_controller1.calculate(-distance, USS.getDistance(), 0));
}
void rotateRight() {
    move_l298N(pinsArr, pid_controller2.calculate(90, imu.updateYaw()), 1)) ;
}
void rotateLeft() {
    move_l298N(pinsArr, pid_controller2.calculate(-90, imu.updateYaw()), 1));
}
void stop() { move_l298N(pinsArr, 0, 0); }

void setup() {
  float current_distance = USS.getDistance()
  float Yaw = imu.updateYaw()
  timer.every(1000, timerCallback);
  imu.setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  timer.update();
}



// loop(){
//   currtime
//   if (time - currtime > 10){
//     ultra
//   }
//   move_l298N
  
// }