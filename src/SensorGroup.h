#pragma once

#include <WPILib.h>
#include <stdlib.h>

class SensorGroup {
	Encoder* ELeft;
	Encoder* ERight;
	float LeftSum, RightSum;
public:
	SensorGroup(Encoder* Left, Encoder* Right);
	void PrintValues();
	Encoder* GetELeft();
	Encoder* GetERight();
	void ResetEncoders();
};
