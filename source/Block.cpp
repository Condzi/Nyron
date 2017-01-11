#include "Block.hpp"

namespace cn
{
	void Block::draw(sf::RenderTarget& target, sf::RenderStates state) const
	{
		target.draw(sprite, state);
	}

	Block::Block()
	{
	}

	void Block::setTexture(sf::Texture* t)
	{
		this->sprite.setTexture(*t);
	}

	void Block::update(float)
	{
		this->sprite.setPosition(this->position);
		this->collisionRect.left = this->position.x;
		this->collisionRect.top = this->position.y;
	}
}

