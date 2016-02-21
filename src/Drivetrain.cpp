#include "DriveTrain.h"

Drivetrain::Drivetrain(Motor* MLeft, Motor* MRight, SensorGroup* Sensor, PIDController* Left, PIDController* Right) {
	LeftMotor = MLeft;
	RightMotor = MRight;
	LeftPower = 0;
	RightPower = 0;

	Sensors = Sensor;

	PIDLeft = Left;
	PIDRight = Right;
}

void Drivetrain::DrivePower(float Power) {
	DrivePower(Power, Power);
}

void Drivetrain::DrivePower(float Left, float Right) {
	LeftPower = SensCurve(Left);
	RightPower = SensCurve(Right);
}

void Drivetrain::DrivePower(float Left, float Right, float Multiplier) {
	LeftPower = SensCurve(Left)*Multiplier;
	RightPower = SensCurve(Right)*Multiplier;
}

void Drivetrain::DriveSpeed(float Speed) {
	// not priority
}

void Drivetrain::DriveSpeed(float LSpeed, float RSpeed) {
	// not priority
}

void Drivetrain::DisableAllPID() {
	PIDLeft->Disable();
	PIDRight->Disable();
}

void Drivetrain::DriveDist(float Distance) {
	PIDLeft->SetSetpoint(Distance/WheelCirc);
	PIDRight->SetSetpoint(Distance/WheelCirc);

	PIDLeft->Enable();
	PIDRight->Enable();
}

void Drivetrain::Turn(float Degrees) {
	// needs to be implemented
}

void Drivetrain::Execute() {
	if (!PIDLeft->IsEnabled() && !PIDRight->IsEnabled()) {
		LeftMotor -> SetPower(LeftPower);
		RightMotor -> SetPower(RightPower);
	} else if (PIDLeft->GetSetpoint() < 0.1 && PIDRight->GetSetpoint() < 0.1) {
		PIDLeft->Disable();
		PIDRight->Disable();
	}
}

SensorGroup* Drivetrain::GetSensors() {
	return Sensors;
}

float Drivetrain::SensCurve(float speed) {
	return speed * fabs(speed);
}
