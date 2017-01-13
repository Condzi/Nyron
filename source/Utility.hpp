#pragma once

#include <bitset>

#include "Config.hpp"

namespace cn
{
	// Checks if poiter is assigned
	// Returns false if pointer is not assigned
	inline bool IS_ASSIGNED(void* ptr) { return !(ptr == nullptr); }

	static std::bitset<constans::MAX_FLAGS> FLAGS;
}