#pragma once

#include "main.h"

namespace ferroni {

constexpr uint8_t LED_SPEED_FAST = 255 * 250_ms  / 2.5_s; // 250ms
constexpr uint8_t LED_SPEED_MED  = 255 * 500_ms  / 2.5_s; // 500ms
constexpr uint8_t LED_SPEED_SLOW = 255 * 1_s     / 2.5_s; // 1000ms

} /* namespace ferroni */

