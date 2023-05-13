#include <vector>
#ifndef gps.h
#define gps.h

class GPS {
    public:
        GPS();
        void calibrate();
        float getAltitude();
    private:
        double offset;
};
#endif