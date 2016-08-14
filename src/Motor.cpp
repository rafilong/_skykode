#include "Motor.h"

Motor::Motor(Victor* FVic_, Victor* BVic_, float M) {
	FVic = FVic_;
	BVic = BVic_;

    Magnitude = M;
}

void Motor::SetPower(float Power) {
    FVic -> Set(Magnitude*Power);
    BVic -> Set(Magnitude*Power);
}

void Motor::SensPower(float Power) {
	FVic -> Set(Magnitude*SensCurve(Power));
	BVic -> Set(Magnitude*SensCurve(Power));
}

void Motor::PIDWrite(float Output) {
	FVic -> PIDWrite(Magnitude*Output);
	BVic -> PIDWrite(Magnitude*Output);
}

float Motor::SensCurve(float Speed) {
	return Speed * fabs(Speed);
}
