class UltrasonicSensor {
private:
  const int trigPin;
  const int echoPin;

public:
  UltrasonicSensor(int trigPin, int echoPin) :
trigPin(trigPin), 
echoPin(echoPin) {
    
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
  }

  float getDistance() {
    // Clear the trigger pin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    // Set the trigger pin HIGH for 10 microseconds
     digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
     digitalWrite(trigPin, LOW);
    
    // my_timer.every(.01,call_back(digitalWrite(trigPin, HIGH)));
    

    // Read the echo pin, calculating the duration in microseconds
    unsigned long duration = pulseIn(echoPin, HIGH);

    // Calculate the distance in centimeters
    float distance = duration * 0.034 / 2;

    return distance;
  }
};
