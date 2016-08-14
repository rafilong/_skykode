#include "Robot.h"

Robot::Robot() :
LFVic((uint32_t) 0),
LBVic((uint32_t) 1),
RFVic((uint32_t) 2),
RBVic((uint32_t) 3),

LMotor(&LFVic, &LBVic, -.96),
RMotor(&RFVic, &RBVic, 1.0),

ELeft((uint32_t) 1, (uint32_t) 0),
ERight((uint32_t) 3, (uint32_t) 2),

Sensors(&ELeft, &ERight),

Left(0.1, 0.0, 0.0, Sensors.GetELeft(), &LMotor, 0.05),
Right(0.1, 0.0, 0.0, Sensors.GetELeft(), &RMotor, 0.05),

RDrivetrain(&LMotor, &RMotor, &Sensors, &Left, &Right),
RShooter(0, 1),
RAccumulator(4, 5),

LeftJoystick((uint32_t) 2),
RightJoystick((uint32_t) 1),
Xbox((uint32_t) 0)
{
}

void Robot::Execute() {
	RDrivetrain.Execute();
	RAccumulator.Execute();
}

void Robot::RobotInit() {
	std::cerr << "setQuality";
	CameraServer::GetInstance()->SetQuality(50);
	// the camera name (ex "cam0") can be found through the roborio web interface
	std::cerr << "startAutomaticCapture";
	CameraServer::GetInstance()->StartAutomaticCapture("cam0");

	// reset smartdashboard
	SmartDashboard::PutString("DB/String 0", "");
	SmartDashboard::PutString("DB/String 1", "");
	SmartDashboard::PutString("DB/String 2", "");
	SmartDashboard::PutString("DB/String 5", "");
	SmartDashboard::PutString("DB/String 6", "");
}

void Robot::DisabledInit() {
	RDrivetrain.DrivePower(0);
	RAccumulator.SetLiftPower(0);
	Execute();
}

void Robot::DisabledPeriodic() {
}

void Robot::AutonomousInit() {
	AutoCycle = 0;
}

void Robot::AutonomousPeriodic() {
	if (AutoCycle >= 25 && AutoCycle <= 525) {
		RDrivetrain.DrivePower(0.5);
	} else {
		RDrivetrain.DrivePower(0);
	}

	if (AutoCycle >= 0 && AutoCycle <= 25) {
		RAccumulator.SetLiftPower(-1);
	} else {
		RAccumulator.SetLiftPower(0);
	}

	Execute();
	AutoCycle++;
}

void Robot::TeleopInit() {
	RDrivetrain.DrivePower(0);
	RDrivetrain.DisableAllPID();
}

void Robot::TeleopPeriodic() {
	// Drive stuff
	RDrivetrain.DrivePower(LeftJoystick.GetY(), RightJoystick.GetY());
	if (RightJoystick.GetTrigger()) RDrivetrain.DrivePower(LeftJoystick.GetY(), RightJoystick.GetY(), 0.7);
	if (LeftJoystick.GetTrigger()) RDrivetrain.DrivePower((LeftJoystick.GetY() + RightJoystick.GetY())/2);

	// Shoot stuff
	if (Xbox.GetRawButton((uint32_t) 6)) RShooter.AutoShoot();
	if (Xbox.GetRawButton((uint32_t) 1)) RShooter.ForceExtend();
	if (Xbox.GetRawButton((uint32_t) 5)) RShooter.ForceRetract();

	// Accumulate stuff
	RAccumulator.SetLiftPower(-Xbox.GetRawAxis((uint32_t) 1));
	RAccumulator.SetSpinPower(Xbox.GetRawAxis((uint32_t) 2) - Xbox.GetRawAxis((uint32_t) 3));

	// Fini
	Execute();

	RDrivetrain.GetSensors() -> PrintValues();
}

void Robot::TestInit() {
}

void Robot::TestPeriodic() {
	if (RightJoystick.GetTrigger()) {
		RDrivetrain.DrivePower(0.5);
	} else if (LeftJoystick.GetTrigger()) {
		RDrivetrain.DrivePower(0.5);
	} else {
		RDrivetrain.DrivePower(0);
	}
	Execute();

	RDrivetrain.GetSensors() -> PrintValues();
}

START_ROBOT_CLASS(Robot);
