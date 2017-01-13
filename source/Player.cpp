#include "Player.hpp"

namespace cn
{
	void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		target.draw(this->sprite, states);
	}

	cn::Player::Player() :PlayerController(*this, { sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::Up, sf::Keyboard::Down }, 100.f)
	{
		this->Collider::setRequired(*this);
	}

	void Player::setTexture(sf::Texture* t)
	{
		if (!IS_ASSIGNED(t))
			Logger::log("Assigning nullptr texture to player", Logger::PREFIX_WARNING);

		this->sprite.setTexture(*t);
	}

	void Player::update(float dt)
	{
		this->PlayerController::update(dt);
		// this should be in Velocity::update but it crashes for no reason so it is here
		this->position += velocity * dt;
		
		this->sprite.setPosition(this->position);
		this->collisionRect.left = this->position.x;
		this->collisionRect.top = this->position.y;
	}
}

