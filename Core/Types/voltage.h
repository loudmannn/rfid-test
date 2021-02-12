#pragma once

namespace ferroni {

using voltage = uint16_t;

constexpr voltage operator"" _V(long double V) {
	return voltage(4096.0 * V / 3.3);
}

} /* namespace ferroni */
