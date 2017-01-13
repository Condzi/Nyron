#pragma once

#include <vector>
#include <string>

#include "Collider.hpp"
#include "Updatable.hpp"
#include "Logger.hpp"
#include "Utility.hpp"

namespace cn
{
	class CollisionHandler final :
		public Updatable
	{
	private:
		bool collidedLeft(const sf::FloatRect& a, const sf::FloatRect& a_old, const sf::FloatRect& b);
		bool collidedRight(const sf::FloatRect& a, const sf::FloatRect& a_old, const sf::FloatRect& b);
		bool collidedTop(const sf::FloatRect& a, const sf::FloatRect& a_old, const sf::FloatRect& b);
		bool collidedBottom(const sf::FloatRect& a, const sf::FloatRect& a_old, const sf::FloatRect& b);

	public:
		CollisionHandler() {}

		void registerCollider(Collider* coll);
		void unregisterCollider(Collider* coll);

		void update(float deltaTime);

	private:
		std::vector<Collider*> colliders;
	};
}