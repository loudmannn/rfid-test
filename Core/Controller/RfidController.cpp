#include "RfidController.h"
#include "utils.h"

namespace ferroni {

RfidController::RfidController(Rfid& rfid)
: rfid(rfid)
{
}

void RfidController::update() {
	WAIT_UNTIL(rfid.done());
	// SWITCH_STATE(state, RFID_CONTROLLER_STATES);
}
}