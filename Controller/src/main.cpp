#include <Arduino.h>
#include <vector>
#include "imu.h"
#include "gyro.h"
#include "gps.h"
#include "finpair.h"
const float kP = 0.1; // Proportional gain
const float kI = 0.01; // Integral gain
const float kD = 0.5; // Derivative gain
const int MAX_ANGLE = 90;

float angle = 0;
float altitude = 0;
float linear_speed = 0;
// float pitch_velocity = 0;
// float roll_velocity = 0;
// float yaw_velocity = 0;
float pitchFinAngle = 0;
float yawFinAngle = 0;

float pitchError = 0; // Current error
float prevPitchError = 0; // Error from previous iteration
float pitchIntegral = 0; // Accumulated error
float pitchDerivative = 0; // Error rate of change
float pitchOutput = 0; // Output value
const float pitchkP = 0.1; // Proportional gain
const float pitchkI = 0.01; // Integral gain
const float pitchkD = 0.5; // Derivative gain


float yawError = 0; // Current error
float prevYawError = 0; // Error from previous iteration
float yawIntegral = 0; // Accumulated error
float yawDerivative = 0; // Error rate of change
float yawOutput = 0; // Output value
const float yawkP = 0.1; // Proportional gain
const float yawkI = 0.01; // Integral gain
const float yawkD = 0.5; // Derivative gain

float rollError = 0; // Current error
float prevRollError = 0; // Error from previous iteration
float rollIntegral = 0; // Accumulated error
float rollDerivative = 0; // Error rate of change
float rollOutput = 0; // Output value
const float rollkP = 0.1; // Proportional gain
const float rollkI = 0.01; // Integral gain
const float rollkD = 0.5; // Derivative gain

FinPair pitchFins;
FinPair yawFins;
IMU imuSensor;
GPS gpsSensor;
Gyro gyroSensor;

void setup() {
    imuSensor = IMU{};
    gyroSensor = Gyro{};
    gpsSensor = GPS{};
}


void loop() {
    float angular_velocity = imuSensor.getRotationalSpeed('x');
    float altitude = gpsSensor.getAltitude();
    float linear_speed = imuSensor.getSpeed('y');
    pitchError = gyroSensor.getAngle('x');
    yawError = gyroSensor.getAngle('y');
    rollError = gyroSensor.getAngle('z');

  
    rollIntegral += rollError;
    rollDerivative = rollError - prevRollError;
    rollOutput = rollkP * rollError + rollkI * rollIntegral + rollkD * rollDerivative;

    pitchIntegral += pitchError;
    pitchDerivative = pitchError - prevPitchError;
    pitchOutput = pitchkP * pitchError + pitchkI * pitchIntegral + pitchkD * pitchDerivative;

    yawIntegral += yawError;
    yawDerivative = yawError - prevYawError;
    yawOutput = yawkP * yawError + yawkI * yawIntegral + yawkD * yawDerivative;
    
    pitchFinAngle = pitchFins.determineFinAngle(altitude, linear_speed, rollOutput, 0, pitchOutput, 0);
    yawFinAngle = yawFins.determineFinAngle(altitude, linear_speed, rollOutput, 0, yawOutput, 0);
}