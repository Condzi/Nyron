#include "Block.hpp"

namespace cn
{
	void Block::draw(sf::RenderTarget& target, sf::RenderStates state) const
	{
		target.draw(sprite, state);
	}

	Block::Block()
	{
		this->setRequired(*this);
	}

	void Block::setTexture(sf::Texture* t)
	{
		if (!IS_ASSIGNED(t))
		{
			Logger::log("Cannot set Block texture - texture is nullptr", Logger::PREFIX_ERROR);

			return;
		}

		this->sprite.setTexture(*t);
	}

	void Block::update(float)
	{
		this->sprite.setPosition(this->position);
		this->collisionRect.left = this->position.x;
		this->collisionRect.top = this->position.y;
	}
}

