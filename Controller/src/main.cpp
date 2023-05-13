#include <Arduino.h>
#include <vector>
#include "imu.h"
#include "gyro.h"
#include "gps.h"
#include "finpair.h"
Gyro gyroSensor;
IMU imuSensor;
std::vector<Fin> fins(3);
const float kP = 0.1; // Proportional gain
const float kI = 0.01; // Integral gain
const float kD = 0.5; // Derivative gain
const int MAX_ANGLE = 90;

float angle = 0;
float altitude = 0;
float linear_speed = 0;
float pitch = 0;
float roll = 0;
float yaw = 0;
// float pitch_velocity = 0;
// float roll_velocity = 0;
// float yaw_velocity = 0;
float pitchFinAngle = 0;
float yawFinAngle = 0;

float error = 0; // Current error
float prev_error = 0; // Error from previous iteration
float integral = 0; // Accumulated error
float derivative = 0; // Error rate of change
float output = 0; // Output value

void setup() {
    IMU imuSensor = IMU{};
    Gyro gyroSensor = Gyro{};
    GPS gpsSensor = GPS{};
    FinPair pitchFins;
    FinPair yawFins;
}


void loop() {
    angular_velocity = imuSensor.getRotationalSpeed();
    altitude = gpsSensor.getAltitude();
    linear_speed = imuSensor.getSpeed('y');
    pitch = gyroSensor.getAngle('x');
    yaw = gyroSensor.getAngle('y')
    roll = gyroSensor.getAngle('z');

    pitchFinAngle = pitchFins.determineFinAngle(altitude, linear_speed, roll, 0, pitch, 0);
    yawFinAngle = yawFins.determineFinAngle(altitude, linear_speed, roll, 0, yaw, 0);
    
    // pitch_velocity = imuSensor.getRotationalSpeed("z");
    

    // error = current_angle;
  
    // integral += error;
    // derivative = error - prev_error;
    // output = kP * error + kI * integral + kD * derivative;

    // if (output > MAX_ANGLE) {
    // output = MAX_ANGLE;
    // } else if (output < -MAX_ANGLE) {
    // output = -MAX_ANGLE;
    // }
    
    // for( auto i = 0; i != fins.size(); i++){
    //     fins[i].setAngle(output);
    // }
    
    // Update previous error
    // prev_error = error;
}