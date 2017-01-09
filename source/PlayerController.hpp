#pragma once

#include <SFML/Window/Keyboard.hpp>

#include "Logger.hpp"
#include "Updatable.hpp"
#include "RequireEntity.hpp"
#include "Entity.hpp"

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
		public RequireEntity
	{
	public:
		PlayerController(Entity& e, MovementKeys keys, float movementForce, float jumpForce);

		void update(float dt);

		// If player is in air then he cannot jump
		void enableJump();
		void disableJump();

	private:
		MovementKeys keys;
		float movementForce;
		float jumpForce;

		bool canJump;
	};
}