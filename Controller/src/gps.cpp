#include "gps.h"

GPS::GPS(){
    GPS::calibrate();
}

void GPS::calibrate(){
    
    offset = 0;
}

float GPS::getAltitude(){
    float reading = 0; // Do something to get data from GPS 
    return reading - offset;
}