#pragma once
#include "i2c.h"
#include "main.h"
#include "utils.h"
#include "Adafruit_MFRC630.h"

#define RFID_STATES(X) \
	X(Start) \
	X(Idle)

namespace ferroni {

class Rfid {
	static constexpr I2C_HandleTypeDef& i2c = hi2c1;
public:
	static Rfid* instance;
	Rfid();
	Rfid(const Rfid&) = delete;
	Rfid& operator=(const Rfid&) = delete;

	void update();

    bool done();
private:
	ENUM_STATE(RFID_STATES);
	State state;
    UPDATE_STATE(RFID_STATES);

	Adafruit_MFRC630 _rfid_dev;
};
}