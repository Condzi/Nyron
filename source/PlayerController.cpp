#include "PlayerController.hpp"

namespace cn
{
	PlayerController::PlayerController(Entity & e, MovementKeys keys, float movementForce, float jumpForce) : RequireEntity(e)
	{
		this->keys = keys;
		this->movementForce = movementForce;
		this->jumpForce = jumpForce;

		canJump = true;
	}

	void PlayerController::update(float dt)
	{
		sf::Vector2f finalForce(0, 0);

		if (sf::Keyboard::isKeyPressed(keys.left))
			finalForce.x -= movementForce * dt;

		if (sf::Keyboard::isKeyPressed(keys.right))
			finalForce.x += movementForce * dt;

		if (sf::Keyboard::isKeyPressed(keys.jump) && canJump)
			finalForce.y += jumpForce * dt;

		this->entity.getPosition() += finalForce;
	}
}

