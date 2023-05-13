#ifndef imu.h
#define imu.h

class IMU{
    public:
        IMU();
        double getAcceleration(char direction);
        float getRotationalSpeed( char direction);
        float getSpeed( char direction);
    private:
        void calibrate();
        
};
#endif