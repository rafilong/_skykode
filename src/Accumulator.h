#pragma once

#include <WPILib.h>
#include <stdlib.h>

enum LiftStatus { YES, NO };

class Accumulator {
	Victor Lifter, Spinner;
	float LiftPower, SpinPower;
	LiftStatus Status;
public:
	Accumulator(int LiftPort, int SpinPort);
	void SetLiftPower(float Power);
	void SetSpinPower(float Power);
	void AutoLift(float Power, float LiftTime, float RestTime);
	void Execute();
};
