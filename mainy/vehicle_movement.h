#include <math.h>

/**
 * @brief rotate the vehicle of two motors using L298N
 * 
 * @param pins = {COMMON_ENABLE_PIN  ,  in11_pin ,  in21_pin  ,  in12_pin  , in22_pin } 
 * in11_pin is input 1 of motor1 and so on
 * @param rotation if 1 the vehicle will rotate and if 0 the vehicle will move forward
 * @param PWM is the PWM value of the common enable pin of the two motors
 */
void move_l298N( int pins[5] , int PWM  ,int rotate){
    int COMMON_ENABLE_PIN = pins[0] ,  in11_pin = pins[1] ,  in21_pin = pins[2]  ,  in12_pin  = pins[3] , in22_pin = pins[4];

    int rotate_dir_1 = PWM > 0 , rotate_dir_2;
    if (rotate) rotate_dir_2 =  ! rotate_dir_1;
    else rotate_dir_2 =  rotate_dir_1;
    digitalWrite(in11_pin , rotate_dir_1);
    digitalWrite(in21_pin , !rotate_dir_1);
    digitalWrite(in12_pin , rotate_dir_2);
    digitalWrite(in22_pin , !rotate_dir_2);
    analogWrite(COMMON_ENABLE_PIN, abs(PWM));
}