#include "main_cpp.h"
#include "Controller/MainController.h"

using namespace ferroni;

void ferroni_loop() {
	MainController controller;

	while (true) {
		controller.update();
	}
}

void ferroni_error_handler() {
	__NOP();
}
