#pragma once

#include <SFML/Window/Keyboard.hpp>

#include "Logger.hpp"
#include "Updatable.hpp"
#include "RequireComponent.hpp"
#include "Velocity.hpp"
#include "Utility.hpp"

namespace cn
{
	struct MovementKeys
	{
		sf::Keyboard::Key left;
		sf::Keyboard::Key right;
		sf::Keyboard::Key up;
		sf::Keyboard::Key down;
	};

	class PlayerController :
		public Updatable,
		public Require<Velocity>
	{
		void setRequired(Velocity& vel) { this->velocity_req = &vel; }

	public:
		PlayerController(Velocity& v, MovementKeys keys, float movementForce);

		void update(float);

	private:
		MovementKeys keys;
		float movementForce;

		bool canJump;

		Velocity* velocity_req;
	};
}