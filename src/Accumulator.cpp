#include "Accumulator.h"

Accumulator::Accumulator(int LiftPort, int SpinPort) :
	Lifter((uint32_t) LiftPort),
	Spinner((uint32_t) SpinPort),
	LiftPower(0),
	SpinPower(0),
	Status(LiftStatus::NO)
{
}

void Accumulator::SetLiftPower(float Power) {
	if (Status == LiftStatus::NO) LiftPower = Power * -0.25;
}

void Accumulator::SetSpinPower(float Power) {
	SpinPower = Power;
}

void Accumulator::AutoLift(float Power, float LiftTime, float RestTime) {
	Status = LiftStatus::YES;

	SetLiftPower(Power);
	Execute();
	Wait(LiftTime);
	SetLiftPower(0);
	Execute();
	Wait(RestTime);
	SetLiftPower(-Power);
	Execute();
	Wait(LiftTime);
	SetLiftPower(0);
	Execute();

	Status = LiftStatus::NO;
}

void Accumulator::Execute() {
	Lifter.Set(LiftPower);
	Spinner.Set(SpinPower);
}
