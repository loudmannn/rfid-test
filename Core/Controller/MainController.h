#pragma once
#include "RfidController.h"
#include "module.h"

namespace ferroni {

class MainController {
public:
	MainController();

	MainController(const MainController&) = delete;
	MainController& operator=(const MainController&) = delete;

	void update();
		
private:
	Rfid rfid;
	RfidController rfidController;
};

} /* namespace ferroni */

