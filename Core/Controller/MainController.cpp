#include "MainController.h"
#include <utils.h>
#include "Config/pins.h"

namespace ferroni {

MainController::MainController()
	: rfidController(rfid)
{
}

void MainController::update() {
	rfid.update();
	rfidController.update();
}


extern "C" void SystemClock_Config();
} /* namespace ferroni */

