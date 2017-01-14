#pragma once

#include <bitset>

#include <SFML/Graphics/RenderTarget.hpp>

#include "Config.hpp"


namespace cn
{
	// Checks if poiter is assigned
	// Returns false if pointer is not assigned
	inline bool IS_ASSIGNED(const void* ptr) { return !(ptr == nullptr); };
	// Checks if given rect is in window bounds
	// Use it if you don't want to try to render things that are not on screen
	inline bool IS_IN_WINDOW_BOUNDS(sf::RenderTarget& t, const sf::FloatRect& r)
	{
		auto& view = t.getView();
		sf::Vector2f offset{ view.getCenter().x - view.getSize().x / 2, view.getCenter().y - view.getSize().y / 2};

		sf::FloatRect windowBounds{ offset, view.getSize() };

		return windowBounds.intersects(r);
	}

	// Contains custom flags such as:
	// Does player have sword?
	// Does player visited locaion X?
	// ... and so on
	static std::bitset<constans::MAX_FLAGS> FLAGS;
}