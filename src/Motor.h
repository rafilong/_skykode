#pragma once

#include <WPILib.h>
#include <stdlib.h>

class Motor : public PIDOutput {
   Victor* FVic;
   Victor* BVic;
   float Direction;
public:
    Motor(Victor* LVic_, Victor* RVic_, float D);
    void SetPower(float Power);
    void PIDWrite(float Output);
    virtual ~Motor(void) {}
};
