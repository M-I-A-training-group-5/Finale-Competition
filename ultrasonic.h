/**
 * @brief remains 5 milliseconds it makes the trigger pin LOW

 * @param t_pin trigger pin
 */
void clear_trigger(int t_pin){
    // ultrasonic to get distance
    //  set trigger to low to ensure that the 10 microsecond pulse is pure
    digitalWrite(t_pin, LOW);
}

/**
 * @brief remains 10 milliseconds it makes the trigger pin HIGH
 * @param t_pin  
 */
void start_ultrared(int t_pin){
    // the ultrasonic sound is triggered only when you pulse a 10 microsecond pulse
    digitalWrite(t_pin, HIGH);
}


/**
 * @brief no remaining time it gives you the distance
 * 
 * @param t_pin trigger pin
 * @param e_pin echo pin 
 * @param ultrasonic_speed in meter per second
 * @return double the distance in centimeter
 */
double end_ultrasonic_and_get_distance_cm(int t_pin, int e_pin , double ultrasonic_speed)
{
    digitalWrite(t_pin, LOW);

    /*velocity  = distance/time
     *"pulsein" function => returns time in microsecond
     *The velocity in air of a sound wave is at 20ºC (68ºF)  = 343m/s
     *distance = velocity * time
     *distance = (343 * time µm)*10^-4 cm
     *distance = time µm * 0.0343
     *distance = puslein / 29.1  (as  .0343 = 1/29.1 nearly and gives you most accurate values in tinkercad)
     *req_disatnce = distance / 2 (as the distance is for 2 - way trip and we want the time consumed of one way (from sound to object))
     */

    double distance = pulseIn(e_pin, HIGH) *ultrasonic_speed / (10000)  / 2;
    return distance;
}