#pragma once

#include <WPILib.h>
#include <stdlib.h>

#include "Motor.h"
#include "SensorGroup.h"

class Drivetrain {
	float LeftPower, RightPower;
	Motor* LeftMotor;
	Motor* RightMotor;
	SensorGroup* Sensors;
	PIDController* PIDLeft;
	PIDController* PIDRight;
	const float WheelCirc = 6 * 3.1415927;
public:
	Drivetrain(Motor* MLeft, Motor* MRight, SensorGroup* Sensor, PIDController* Left, PIDController* Right);
	void DrivePower(float Power);
	void DrivePower(float Left, float Right);
	void DrivePower(float Left, float Right, float Multiplier);
	void DriveSpeed(float Speed);
	void DriveSpeed(float RSpeed, float LSpeed);
	void DisableAllPID();
	void DriveDist(float Distance);
	void PIDDist();
	void Straight();
	void Turn(float Degrees);
	void Execute();
	SensorGroup* GetSensors();
};
