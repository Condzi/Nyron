#include "PlayerController.hpp"

namespace cn
{
	PlayerController::PlayerController(Velocity& v, MovementKeys keys, float movementForce)
	{
		this->keys = keys;
		this->movementForce = movementForce;
		this->setRequired(v);

		canJump = true;
	}

	void PlayerController::update(float)
	{
		static bool error_informated = false;

		if (!IS_ASSIGNED(this->velocity_req))
		{
			Logger::log("Cannot updata PlayerController - velocity_req is not assigned", Logger::PREFIX_ERROR);

			error_informated = true;
			return;
		}

		error_informated = false;

		this->velocity_req->setVelocity({ 0,0 });
		sf::Vector2f finalForce(0, 0);

		if (sf::Keyboard::isKeyPressed(keys.left))
			finalForce.x -= movementForce;

		if (sf::Keyboard::isKeyPressed(keys.right))
			finalForce.x += movementForce;

		if (sf::Keyboard::isKeyPressed(keys.up))
			finalForce.y -= movementForce;
		if (sf::Keyboard::isKeyPressed(keys.down))
			finalForce.y += movementForce;

		this->velocity_req->getVelocity() += finalForce;
	}
}

