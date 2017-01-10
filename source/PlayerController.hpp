#pragma once

#include <SFML/Window/Keyboard.hpp>

#include "Logger.hpp"
#include "Updatable.hpp"
#include "RequireComponent.hpp"
#include "Velocity.hpp"

namespace cn
{
	struct MovementKeys
	{
		sf::Keyboard::Key left;
		sf::Keyboard::Key right;
		sf::Keyboard::Key jump;
	};

	class PlayerController :
		public Updatable,
		public Require<Velocity>
	{
		void setRequired(Velocity& vel) { this->velocity_req = &vel; }

	public:
		PlayerController(Velocity& v, MovementKeys keys, float movementForce, float jumpForce);

		void update(float);

		// If player is in air then he cannot jump
		void enableJump() { canJump = true; }
		void disableJump() { canJump = false; }

	private:
		MovementKeys keys;
		float movementForce;
		float jumpForce;

		bool canJump;

		Velocity* velocity_req;
	};
}