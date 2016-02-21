#include <SensorGroup.h>

SensorGroup::SensorGroup(Encoder* Left, Encoder* Right) {
	ELeft = Left;
	ERight = Right;

	ELeft->SetReverseDirection(true);
}

void SensorGroup::PrintValues() {
	std::stringstream s;
	s << ELeft->GetDistance();
	SmartDashboard::PutString("DB/String 0", s.str());
	s << ERight->GetDistance();
	SmartDashboard::PutString("DB/String 1", s.str());
}

Encoder* SensorGroup::GetELeft() {
	return ELeft;
}

Encoder* SensorGroup::GetERight() {
	return ERight;
}
