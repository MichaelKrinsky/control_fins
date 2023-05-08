#include <Arduino.h>
#include <vector>
#include "imu.h"
#include "gyro.h"
#include "fin.h"
Gyro gyroSensor;
IMU imuSensor;
std::vector<Fin> fins(3);
const float kP = 0.1; // Proportional gain
const float kI = 0.01; // Integral gain
const float kD = 0.5; // Derivative gain
const int MAX_ANGLE = 90;

float current_angle = 0;
float error = 0; // Current error
float prev_error = 0; // Error from previous iteration
float integral = 0; // Accumulated error
float derivative = 0; // Error rate of change
float output = 0; // Output value

void setup() {
    IMU imuSensor = IMU{};
    Gyro gyroSensor = Gyro{};
    Fin fin1;
    Fin fin2;
    Fin fin3;
}


void loop() {
    current_angle = imuSensor.getRotationalSpeed();
    error = current_angle;
  
    integral += error;
    derivative = error - prev_error;
    output = kP * error + kI * integral + kD * derivative;

    if (output > MAX_ANGLE) {
    output = MAX_ANGLE;
    } else if (output < -MAX_ANGLE) {
    output = -MAX_ANGLE;
    }
    
    for( auto i = 0; i != fins.size(); i++){
        fins[i].setAngle(output);
    }
    
    // Update previous error
    prev_error = error;
}