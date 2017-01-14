#pragma once

#include <cinttypes>

#include "Structs.hpp"

namespace cn
{
	namespace constans
	{
		constexpr std::uint8_t MAX_FLAGS = 32;
	}

	namespace flags
	{
		constexpr std::uint8_t TEST_FLAG = 0;
	}

	namespace tilemap
	{
		constexpr auto COLLIDERS_LAYER = "COLLIDERS";
		constexpr auto DRAWABLE_LAYER = "DRAWABLES";
		constexpr auto PLAYER_SPAWN_LAYER = "PLAYER_SPAWN";
		constexpr auto ITEM_LAYER = "ITEM_";
	}

	namespace items
	{
		constexpr item_t SWORD	{ "SWORD", 0 };
	}
}