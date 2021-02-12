#pragma once

#include "main.h"

#define CASE_UPDATE(x) case State::x: update ## x (); break

#define STATE_T State

#define SWITCH_STATE_ENTRY(x)                                  \
	case STATE_T::x: update ## x (); break;

#define SWITCH_STATE(STATE, LIST)                              \
	switch(STATE) {                                            \
		LIST(SWITCH_STATE_ENTRY)                               \
	}


#define ENUM_STATE_ENTRY(x)                                    \
	x,

#define ENUM_STATE(LIST)                                       \
	enum class STATE_T : uint8_t {                             \
		LIST(ENUM_STATE_ENTRY)                                 \
	}


#define UPDATE_STATE_ENTRY(x)                                  \
	void update ## x();

#define UPDATE_STATE(LIST)                                     \
	LIST(UPDATE_STATE_ENTRY)


#define GOTO_STATE_ENTRY(x)                                  \
	void goto ## x();

#define GOTO_STATE(LIST)                                     \
	LIST(GOTO_STATE_ENTRY)


#define WAIT_UNTIL(CONDITION)                           \
	if (!(CONDITION)) {                                 \
		return;                                         \
	}

#define WAIT(TIMER, TIME) WAIT_UNTIL(TIMER.time() >= millis(TIME))

#define INLINE __attribute__((always_inline)) inline

#define FILL_int8_tS_INIT(var)                                                   \
	uint8_t* p = packet.data + 1

#define FILL_int8_tS(var)                                                        \
	fillint8_ts(var, p);                                                         \
	p += sizeof(var);

INLINE void fillint8_ts(uint8_t& val, uint8_t* data) {
	val = *data;
}

INLINE void fillint8_ts(uint16_t& val, uint8_t* data) {
	val = (uint16_t)(
		(uint16_t)(data[0] << 8) |
		(uint16_t)(data[1] << 0)
	);
}

INLINE void fillint8_ts(uint32_t& val, uint8_t* data) {
	val = (uint32_t)(
		(uint32_t)(data[0] << 24) |
		(uint32_t)(data[1] << 16) |
		(uint32_t)(data[2] << 8)  |
		(uint32_t)(data[3] << 0)
	);
}

INLINE uint32_t map(uint32_t x, uint32_t in_min, uint32_t in_max, uint32_t out_min, uint32_t out_max) {
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
