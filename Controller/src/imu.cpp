#include "IMU.h"

void IMU::calibrate(){
    //connect to IMU
}
IMU::IMU(){
    IMU::calibrate();
}

float IMU::getRotationalSpeed(char direction){
    switch(direction){
        case 'x':
            break;
        case 'y':
            break;
        case 'z':
            break;
    }
    return 1;
}

float IMU::getSpeed(char direction){
    switch(direction){
        case 'x':
            break;
        case 'y':
            break;
        case 'z':
            break;
    }
    return 1.0;
}
// double IMU::getAcceleration(char direction){
//     switch(direction){
//         case 'x':
//             break;
//         case 'y':
//             break;
//         case 'z':
//             break;
//     }
//     return 1.0;
// }