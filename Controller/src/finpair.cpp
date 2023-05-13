#include "finpair.h"
#include <cmath>
FinPair::FinPair(){
    FinPair::calibrate();
    cgToFinY = 10;
    cgToFinX = 3;
    momentOfInertia = 0;
    finArea = 5;
}

void FinPair::calibrate(){
    
    offset = 0;
}

float FinPair::determineFinAngle(float altitude, float speed, float rollError, float rollVelocity, float directionError, float directionVelocity) { 
    // Torque = inertia * acceleration
    // Xf = X0 + VoT + 1/2AT**2
    // Lift = Clift * density * V**2 * wingArea / 2
    float airDensity = altitude * 0.5; // Some calculation for air density
    float desiredAcceleration = -2 * (directionError + directionVelocity * 2) / 4; // Solve given the directionError and directionVelocity A = -2(X0+VT)/ (T**2)
    float requiredLift = desiredAcceleration * momentOfInertia / cgToFinY; // "lift" is required force in the proper direction to achieve acceleration
    float desiredCoefficientOfLift = requiredLift / ( airDensity * pow(speed, 2) * finArea);
    float newAngle = 5; // ??? Some formula I couldn't find
    //lift = Clist
    FinPair::setAngle(newAngle);
    return 0;
}
void FinPair::setAngle(float angle) {
    //Set angle of fin to angle
}