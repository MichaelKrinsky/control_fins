#ifndef imu.h
#define imu.h

class IMU{
    public:
        IMU();
        double getAcceleration(char direction);
        double getRotationalSpeed();
    private:
        void calibrate();
        
};
#endif