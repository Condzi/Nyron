#pragma once

namespace cn
{
	// Checks if poiter is assigned
	// Returns false if pointer is not assigned
	inline bool IS_ASSIGNED(void* ptr) { return !(ptr == nullptr); }
}