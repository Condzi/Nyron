#pragma once

#include <functional>

#include <SFML/Graphics/Rect.hpp>

namespace cn
{
	class Collider;

	struct CollisionInfo final
	{
		Collider* collider = nullptr;
		enum Side
		{
			Left = 0,
			Right,
			Top,
			Down
		} side = Left;

		CollisionInfo(Collider* p, CollisionInfo::Side s) { collider = p, side = s; }
	};

	class Collider
	{
		friend class CollisionHandler;

	public:
		Collider() :collisionRect(0, 0, 0, 0) {}

		auto& getCollisionRect() { return this->collisionRect; }
		void setCollisionRect(const sf::FloatRect& rect) { this->collisionRect = rect; };

		void setCallback(std::function<void(CollisionInfo)> f) { this->callback = f; }

	protected:
		sf::FloatRect collisionRect;
		std::function<void(CollisionInfo)> callback;
		
	};
}