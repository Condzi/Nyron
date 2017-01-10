#pragma once

#include "Updatable.hpp"
#include "RequireComponent.hpp"
#include "Entity.hpp"

namespace cn
{
	class Velocity
	{
	public:
		Velocity() { velocity = { 0,0 }; }

		auto& getVelocity() { return this->velocity; }
		
		void setVelocity(const sf::Vector2f& v) { this->velocity = v; }

	protected:
		sf::Vector2f velocity;
	};
}