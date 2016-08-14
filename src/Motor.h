#pragma once

#include <WPILib.h>
#include <stdlib.h>

class Motor : public PIDOutput {
   Victor* FVic;
   Victor* BVic;
   float Magnitude;
public:
    Motor(Victor* LVic_, Victor* RVic_, float M);
    void SetPower(float Power);
    void SensPower(float Power);
    void PIDWrite(float Output);
    virtual ~Motor(void) {}
private:
    float SensCurve(float Speed);
};
