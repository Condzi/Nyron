#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "Collider.hpp"
#include "Logger.hpp"
#include "Entity.hpp"
#include "Updatable.hpp"
#include "Utility.hpp"

namespace cn
{
	class Block :
		public Entity,
		public Collider,
		public Updatable
	{
	private:
		void draw(sf::RenderTarget& target, sf::RenderStates state) const;

	public:
		Block();

		void setTexture(sf::Texture* t);

		void update(float);

	private:
		sf::Sprite sprite;
	};
}