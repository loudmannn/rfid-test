#pragma once

namespace ferroni {

using millis = uint16_t;

constexpr millis operator"" _s(long double s) {
	return millis(s * 1000);
}

constexpr millis operator"" _s(unsigned long long s) {
	return millis(s * 1000);
}

constexpr millis operator"" _s2(long double s) {
	return millis(s * 1024);
}

constexpr millis operator"" _s2(unsigned long long s) {
	return millis(s * 1024);
}

constexpr millis operator"" _ms(unsigned long long ms) {
	return millis(ms);
}

} /* namespace ferroni */
