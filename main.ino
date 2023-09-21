#include <MPU6050_light.h>

#include "PID.h"
// #include <Timer.h>
#include "USS.h"
// #include "bati5a.h"
#include <Wire.h>
#include "vehicle_movement.h"

#define t_pin 12
#define e_pin 11
#define alpha 0.4
MPU6050 mpu(Wire);
unsigned long timer = 0;
float error = 0;
float PID_PWM = 0;
// float offset = 0.0;
int pins[5] = {9, 8, 7, 5, 4};
// Timer my_timer;
// MPU_6050 mpu;
// MPUPU imu;
// MPU6050 imu;
UltrasonicSensor USS(t_pin, e_pin, alpha);

PIDController pid_controller1(0.255, 0, 0, 0.01);
PIDController pid_controller2(2.83, 0, 0, 0.01);

float move(int distance) {
  float current_distance = 0;
  error = distance - current_distance;
  while (error != 0){
  float previous_pos = USS.getFilteredDistance(USS.getInitialDistance());
  PID_PWM = pid_controller1.calculate(distance, current_distance);

    move_l298N(pins, PID_PWM, 0);
current_distance += USS.getFilteredDistance(USS.getInitialDistance()) - previous_pos; 
    previous_pos = current_distance;
    error = distance - current_distance;
}
  Serial.println("distance reached");
  stopMotors();
  return PID_PWM;
}

// void moveBackwards(int distance) {
//   move_l298N(pinsArr,
//              pid_controller1.calculate(-distance, USS.getDistance(), 0));
// }
void rotateRight() {

    float current_angle = 0;
  error =  90 - current_angle;
  while (error != 0){
  float previous_pos = mpu.getAngleZ();
  PID_PWM = pid_controller2.calculate(90, current_angle);

    move_l298N(pins, PID_PWM, 1);
    current_angle += mpu.getAngleZ() - previous_pos; 
    previous_pos = current_angle;
    error = 90 - current_angle;
}
  Serial.println("degree of rotation reached");
  stopMotors();
  return PID_PWM;
}
// void rotateLeft() {
//     move_l298N(pinsArr, pid_controller2.calculate(-90, imu.updateYaw()), 1));
// }
void stopMotors() { 
  
  move_l298N(pins, 0, 0);

 }

void setup() {

  Wire.begin();
  Serial.begin(9600);
  Serial.println("test");
  byte status = mpu.begin();
  Serial.print(F("MPU6050 status: "));
  Serial.println(status);

  while(status!=0){ } // stop everything if could not connect to MPU6050
  
  Serial.println(F("Calculating offsets, do not move MPU6050"));
  delay(1000);
  // mpu.upsideDownMounting = true; // uncomment this line if the MPU6050 is mounted upside-down
  mpu.calcOffsets(); // gyro and accelero
  Serial.println("Done!\n");  // offset = imu.calibrateGyro();
  // move(1);
  rotateRight();
  for (int i= 0 ; i<5 ;i++){
    pinMode(pins[i] , OUTPUT);
    
  }
  
  // float current_distance = USS.getDistance() float Yaw =
  // imu.updateYaw() timer.every(1000, timerCallback);
  // imu.setupYaw();
}

void loop() {
  // put your main code here, to run repeatedly:

  // move_l298N(pins, 100, 1 );
   mpu.update();
   

  if((millis()-timer)>10){ // print data every 10ms

	Serial.print("\tZ : ");
	Serial.println(mpu.getAngleZ());
   Serial.println(USS.getFilteredDistance(USS.getInitialDistance()));
	timer = millis();  
  }
  
  }
