//
// value-parser.hpp
//
// Copyright (C) 2013 Alexander Boldyrev
//

#pragma once

#include <cstdint>

template <typename T>
T parseAsBigEndian(uint8_t *buf) {
	if (!buf) { return 0; } // FIXME

	T retval = 0;

	for (int i = 0; i < sizeof(T); ++i) {
//		retval += buf[sizeof(T) - 1 - i] << (i * 8);
		retval = retval << 8;
		retval += buf[i];
	}

	return retval;
}
template <typename T>
T parseAsLittleEndian(uint8_t *buf) {
	if (!buf) { return 0; } // FIXME

	T retval = 0;

	for (int i = 0; i < sizeof(T); ++i) {
		retval = retval << 8;
		retval += buf[sizeof(T) - i - 1];
	}

	return retval;
}


