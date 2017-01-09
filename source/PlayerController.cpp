#include "PlayerController.hpp"

namespace cn
{
	PlayerController::PlayerController(Velocity& v, MovementKeys keys, float movementForce, float jumpForce) : Require(v)
	{
		this->keys = keys;
		this->movementForce = movementForce;
		this->jumpForce = jumpForce;

		canJump = true;
	}

	void PlayerController::update(float)
	{
		sf::Vector2f finalForce(0, 0);

		if (sf::Keyboard::isKeyPressed(keys.left))
			finalForce.x -= movementForce;

		if (sf::Keyboard::isKeyPressed(keys.right))
			finalForce.x += movementForce;

		if (sf::Keyboard::isKeyPressed(keys.jump) && canJump)
			finalForce.y -= jumpForce;

		this->required.getVelocity() += finalForce;
	}
}

