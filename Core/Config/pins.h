#pragma once

#include "main.h"
#include "Driver/Pin.h"
#include "module.h"

namespace ferroni {

using ButtonPin = Pin<GPIOF_BASE, GPIO_PIN_0, true>;
using SensorPin = Pin<GPIOA_BASE, GPIO_PIN_1, true>;

#ifdef FW_MAIN_LITE
using SensorPowerPin = Pin<GPIOA_BASE, GPIO_PIN_0, false>;
using MotorPowerPin  = Pin<GPIOA_BASE, GPIO_PIN_4, false>;
#endif

#ifdef FW_MAIN_FULL
using MainPowerPin        = Pin<GPIOA_BASE, GPIO_PIN_0, false>;
using BatteryDetectionPin = Pin<GPIOF_BASE, GPIO_PIN_1, true>;
#endif

#ifdef TEST_PROTOCOL
using TestInputPin  = Pin<GPIOA_BASE, GPIO_PIN_4, false>;
using TestOutputPin = Pin<GPIOA_BASE, GPIO_PIN_10, false>;
#endif

} /* namespace ferroni */
