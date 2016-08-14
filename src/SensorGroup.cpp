#include <SensorGroup.h>

SensorGroup::SensorGroup(Encoder* Left, Encoder* Right) {
	ELeft = Left;
	ERight = Right;
	LeftSum = 0;
	RightSum = 0;

	ELeft->SetReverseDirection(true);
}

void SensorGroup::PrintValues() {
	LeftSum += ELeft->GetDistance();
	RightSum += ERight->GetDistance();

	SmartDashboard::PutString("DB/String 0", std::to_string(LeftSum));
	SmartDashboard::PutString("DB/String 1", std::to_string(RightSum));
	SmartDashboard::PutString("DB/String 5", std::to_string(ELeft->GetDistance()));
	SmartDashboard::PutString("DB/String 6", std::to_string(ERight->GetDistance()));
}

Encoder* SensorGroup::GetELeft() {
	return ELeft;
}

Encoder* SensorGroup::GetERight() {
	return ERight;
}

void SensorGroup::ResetEncoders() {
	ELeft->Reset();
	ERight->Reset();
}
