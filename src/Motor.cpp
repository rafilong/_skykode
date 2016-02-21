#include "Motor.h"

Motor::Motor(Victor* FVic_, Victor* BVic_, float D) {
	FVic = FVic_;
	BVic = BVic_;

    Direction = D;
}

void Motor::SetPower(float Power) {
    FVic -> Set(Power*Direction);
    BVic -> Set(Power*Direction);
}

void Motor::PIDWrite(float Output) {
	FVic -> PIDWrite(Output*Direction);
	BVic -> PIDWrite(Output*Direction);
}

