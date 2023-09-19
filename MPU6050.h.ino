#include <Wire.h>
class MPU6050{

private:
const int MPU6050Address = 0x68; // MPU6050 address
const int gyroZRegister = 0x47; // Register address for Z-axis

int16_t yawAngle;
float totalYawAngle = 0.0; // variable to store the total yaw angle

unsigned long timeBefore = 0; // time used to subtract from latest time to get the
//time period between each rotation
public:
void setup() {
Wire.begin();
Serial.begin(9600);

// Configuring the MPU6050 sensor
Wire.beginTransmission(MPU6050Address);
Wire.write(0x6B);  // Power management register
Wire.write(0x00);  // waking up the sensor
Wire.endTransmission();

Wire.beginTransmission(MPU6050Address);
Wire.write(0x1B);  // Gyroscope configuration register
Wire.write(0x00);  
Wire.endTransmission();

Wire.beginTransmission(MPU6050Address);
Wire.write(0x1C);  // Accelerometer configuration register
Wire.write(0x00);  
Wire.endTransmission();
}

void updateYaw() {
Wire.beginTransmission(MPU6050Address);
Wire.write(gyroZRegister); // read gyroscope Z-axis input
Wire.endTransmission();

Wire.requestFrom(MPU6050Address, 2); // Takes 2 byte data from the sensor
if (Wire.available() >= 2) {
byte highByte = Wire.read();
byte lowByte = Wire.read();

// combine high and low bytes to obtain the complete yaw angle value by shifting the first 8 bits to the left
yawAngle = (highByte << 8) | lowByte;

unsigned long now = millis(); // returns how long the program has been running in MSs
float time = (now - timeBefore) / 1000.0;  // Converting to seconds

float angularVelocity = yawAngle / 131.0; // conversion to degrees per second (number may vary depending on the sensor)(check datasheet)
                                          // datasheet page 31 since this sensor has a range of +-250 

float deltaYawAngle = angularVelocity * time; // calculate the change in yaw angle over time

totalYawAngle += deltaYawAngle; // add the change in yaw angle to the total yaw angle

Serial.println(totalYawAngle);  // Print the total yaw angle 

timeBefore = now;  // Update the previous time
return totalYawAngle;

}
}



};
