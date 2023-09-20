#include <MPU6050_light.h>


// #include "MPU.h"
// #include "PID.h"
// #include <Timer.h>
// #include "USS.h"
// #include "bati5a.h"
#include <Wire.h>
#include "vehicle_movement.h"

#define t_pin 12
#define e_pin 11

MPU6050 mpu(Wire);
unsigned long timer = 0;

// float offset = 0.0;
int pins[5] = {9, 8, 7, 5, 4};
// Timer my_timer;
// MPU_6050 mpu;
// MPUPU imu;
// MPU6050 imu;
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
  
  byte status = mpu.begin();
  Serial.print(F("MPU6050 status: "));
  Serial.println(status);
  while(status!=0){ } // stop everything if could not connect to MPU6050
  
  Serial.println(F("Calculating offsets, do not move MPU6050"));
  delay(1000);
  // mpu.upsideDownMounting = true; // uncomment this line if the MPU6050 is mounted upside-down
  mpu.calcOffsets(); // gyro and accelero
  Serial.println("Done!\n");  // offset = imu.calibrateGyro();

  for (int i= 0 ; i<5 ;i++){
    pinMode(pins[i] , OUTPUT);
  }
  
  // float current_distance = USS.getDistance() float Yaw =
  // imu.updateYaw() timer.every(1000, timerCallback);
  // imu.setupYaw();
}

void loop() {
  // put your main code here, to run repeatedly:

  // move_l298N(pins, 200, 1 );
   mpu.update();
  
  if((millis()-timer)>10){ // print data every 10ms

	Serial.print("\tZ : ");
	Serial.println(mpu.getAngleZ());
	timer = millis();  
  }
  // Serial.println(USS.getDistance()); 
}
