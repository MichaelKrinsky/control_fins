#include "IMU.h"

void IMU::calibrate(){
    //connect to IMU
}
IMU::IMU(){
    IMU::calibrate();
}

double IMU::getRotationalSpeed(){
    return 1;
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