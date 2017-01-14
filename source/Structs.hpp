#pragma once

#include <cinttypes>

namespace cn
{
	struct item_t
	{
		const char* name;
		std::uint8_t id;

		constexpr item_t(const char* n, std::uint8_t i) :name(n), id(i) { }
	};
}