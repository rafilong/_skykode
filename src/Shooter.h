#pragma once

#include <WPILib.h>
#include <stdlib.h>

enum State { EXTENDED, RETRACTED };

class Shooter {
	State HitterState;
	DoubleSolenoid Hitter;
public:
	Shooter(int LPort, int RPort);
	void Switch();
	State GetState();
	void ForceExtend();
	void ForceRetract();
	void AutoShoot();
};
