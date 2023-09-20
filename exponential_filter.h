int pwm_exponential(double alpha ,int current_value ,int wanted_Value){
    return alpha * wanted_Value + (1-alpha) * current_value;
}