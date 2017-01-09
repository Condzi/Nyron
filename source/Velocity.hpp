#pragma once

#include "Updatable.hpp"
#include "RequireComponent.hpp"
#include "Entity.hpp"

namespace cn
{
	class Velocity :
		public Updatable,
		public Require<Entity>
	{
	public:
		Velocity(Entity& e) : Require(e) { velocity = { 0,0 }; }

		// something is wrong with entity
		void update(float dt) { /*required.getPosition().x += velocity.x * dt;*/ }

		auto& getVelocity() { return this->velocity; }
		
		void setVelocity(const sf::Vector2f& v) { this->velocity = v; }

	protected:
		sf::Vector2f velocity;
	};
}