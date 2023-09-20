



void move_l298N(int pins[5], int wanted_PWM, int forward ) {
    int COMMON_ENABLE_PIN = pins[0] ,  in11_pin = pins[1] ,  in21_pin = pins[2]  ,  in12_pin  = pins[3] , in22_pin = pins[4];
    int rotate_dir_1 = wanted_PWM > 0, rotate_dir_2;
    if (forward)
        rotate_dir_2 = !rotate_dir_1;
    else
        rotate_dir_2 = rotate_dir_1;
    digitalWrite(pins[1], rotate_dir_1);
    digitalWrite(pins[2], !rotate_dir_1);
    digitalWrite(pins[3], rotate_dir_2);
    digitalWrite(pins[4], !rotate_dir_2);
    analogWrite(pins[0], abs(wanted_PWM));


}