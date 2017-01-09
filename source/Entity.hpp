#pragma once
#include <SFML/Graphics/Drawable.hpp>

namespace cn
{
	class Entity :
		public sf::Drawable
	{
	public:
		Entity() { static std::uint16_t idCounter = 0; id = ++idCounter; position = { 0,0 }; }
		virtual ~Entity() = default;

		auto getID() { return this->id; }
		auto& getPosition() { return this->position; }

		void setPosition(const sf::Vector2f& pos) { this->position = pos; }

	private:
		std::uint16_t id;

	protected:
		sf::Vector2f position;
	};
}