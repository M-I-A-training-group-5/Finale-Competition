class UltrasonicSensor {
  private:
    const int trigPin=2;
    const int echoPin=3;

    double distance,duration,kalDist;


  public:
    UltrasonicSensor(int trigPin, int echoPin) :
    trigPin(trigPin), echoPin(echoPin) {
      pinMode(trigPin, OUTPUT);
      pinMode(echoPin, INPUT);
  }

  double getFilteredDistance(double distance){
    static const double R = 40;
    static const double H = 1.00;
    static double Q = 10;
    static double P = 0;
    static double filtered_distance = 0;
    static double K = 0;
    K = P*H/(H*P*H+R);
    filtered_distance += + K*(distance-H*filtered_distance);
    P = (1-K*H)*P+Q;
    return filtered_distance;
  }

  double getInitialDistance() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);    
    unsigned long duration = pulseIn(echoPin, HIGH);
    double distance = duration * 0.034 / 2;
    return distance;
  }
};
