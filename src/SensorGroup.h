#pragma once

#include <WPILib.h>
#include <stdlib.h>

class SensorGroup {
	Encoder* ELeft;
	Encoder* ERight;
public:
	SensorGroup(Encoder* Left, Encoder* Right);
	void PrintValues();
	Encoder* GetELeft();
	Encoder* GetERight();
};
