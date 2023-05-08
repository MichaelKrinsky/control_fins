#include "gyro.h"

Gyro::Gyro(){
    Gyro::calibrate();
}

void Gyro::calibrate(){
    
    offset = 0;
}

double Gyro::getAngle(char direction){
    double reading = 0;
    switch(direction){
        case 'x':
            break;
        case 'y':
            break;
        case 'z':
            break;
    }
    return reading - offset;
}