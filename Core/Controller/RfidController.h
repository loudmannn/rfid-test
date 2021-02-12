#pragma once
#include "Driver/Rfid/Rfid.h"

namespace ferroni {

#define RFID_CONTROLLER_STATES(X) \
	X(Start) \
	X(Idle) \
	X(GetUID) \

class RfidController {
public:
	RfidController(Rfid& rfid);

	RfidController(const RfidController&) = delete;
	RfidController& operator=(const RfidController&) = delete;

	void update();

private:
	ENUM_STATE(RFID_CONTROLLER_STATES);
	State state;
    UPDATE_STATE(RFID_CONTROLLER_STATES);
    Rfid& rfid;
};

} /* namespace ferroni */

