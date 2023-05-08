#include <vector>
#ifndef fin.h
#define fin.h

class Fin {
    public:
        Fin();
        void calibrate();
        void setAngle(float angle);
    private:
        double offset;
};
#endif