#include <vector>
#ifndef finpair.h
#define finpair.h

class FinPair {
    public:
        FinPair();
        void calibrate();
        float determineFinAngle(float altitude, float speed, float rollError, float rollVelocity, float directionError, float directionVelocity);
        void setAngle(float angle);
    private:
        double offset;
        float cgToFinY;
        float cgToFinX;
        float momentOfInertia;
        float finArea;
};

#endif