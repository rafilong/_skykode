#pragma once

#include <WPILib.h>
#include <stdlib.h>

#include "Drivetrain.h"
#include "Shooter.h"
#include "Accumulator.h"
#include "SensorGroup.h"

class Robot : public IterativeRobot {
	Victor LFVic, LBVic, RFVic, RBVic;
	Motor LMotor, RMotor;
	Encoder ELeft, ERight;
	SensorGroup Sensors;
	PIDController Left, Right;
	Drivetrain RDrivetrain;
	Shooter RShooter;
	Accumulator RAccumulator;
	Joystick LeftJoystick, RightJoystick, Xbox;
public:
	Robot();

	void Execute();
    void RobotInit();
    void DisabledInit();
    void DisabledPeriodic();
    void AutonomousInit();
    void AutonomousPeriodic();
    void TeleopInit();
    void TeleopPeriodic();
    void TestInit();
    void TestPeriodic();
};
