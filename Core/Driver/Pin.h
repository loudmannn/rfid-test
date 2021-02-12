#pragma once

#include <utils.h>
#include "main.h"

namespace ferroni {

template<uint32_t GPIO, uint16_t PinID, bool Inverted>
class Pin {
public:
	Pin() = delete;

	INLINE static GPIO_TypeDef* gpio() {
		return (GPIO_TypeDef*)GPIO;
	}

	INLINE static bool read() {
		return Inverted ^ (HAL_GPIO_ReadPin(gpio(), PinID) == GPIO_PIN_SET);
	}

	INLINE static void write(bool enabled) {
		HAL_GPIO_WritePin(gpio(), PinID, (Inverted ^ enabled) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	}

	INLINE static void enable() {
		write(true);
	}

	INLINE static void disable() {
		write(false);
	}
};

} /* namespace ferroni */
