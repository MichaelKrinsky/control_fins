#include <vector>
#ifndef gyro.h
#define gyro.h

class Gyro {
    public:
        Gyro();
        void calibrate();
        double getAngle(char direction);
    private:
        double offset;
};
#endif