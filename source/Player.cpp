#include "Player.hpp"

namespace cn
{
	void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		if(IS_IN_WINDOW_BOUNDS(target, sprite.getGlobalBounds()))
			target.draw(this->sprite, states);
	}

	cn::Player::Player() :PlayerController(*this, { sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::Up, sf::Keyboard::Down }, 100.f)
	{
		this->Collider::setRequired(*dynamic_cast<Velocity*>(this));
		this->Collider::setRequired(*dynamic_cast<Entity*>(this));
	}

	void Player::setTexture(sf::Texture* t)
	{
		if (!t)
		{
			Logger::log("Cannot set Player texture - texture is nullptr", Logger::PREFIX_ERROR);

			return;
		}

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

