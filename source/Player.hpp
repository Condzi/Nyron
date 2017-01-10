#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Logger.hpp"
#include "Entity.hpp"
#include "Velocity.hpp"
#include "PlayerController.hpp"
#include "Collider.hpp"

namespace cn
{
	class Player final:
		public Entity,
		public Velocity, 
		public PlayerController,
		public Collider
	{
	private:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	public:
		Player();

		void setTexture(sf::Texture* t);

		void update(float dt);
	
	private:
		sf::Sprite sprite;
	};
}