#include "Drivestation.h"

Drivestation::Drivestation() {
	std::cerr << "setQuality";
	CameraServer::GetInstance()->SetQuality(50);
	//the camera name (ex "cam0") can be found through the roborio web interface
	std::cerr << "startAutomaticCapture";
	CameraServer::GetInstance()->StartAutomaticCapture("cam0");
}
