#pragma once

#include <functional>

#include <SFML/Graphics/Rect.hpp>

#include "Velocity.hpp"
#include "RequireComponent.hpp"

namespace cn
{
	class Collider;

	struct CollisionInfo final
	{
		Collider* collider = nullptr;
		enum Side
		{
			None = -1,
			Left = 0,
			Right,
			Top,
			Down
		} side = Left;

		CollisionInfo(Collider* p, CollisionInfo::Side s) { collider = p, side = s; }
	};

	class Collider :
		public Require<Velocity>
	{
		friend class CollisionHandler;

	public:
		Collider() :collisionRect(0, 0, 0, 0) { velocity_req = nullptr; this->name = "<unnamed collider>"; }

		auto& getCollisionRect() { return this->collisionRect; }
		auto getColliderName() { return this->name; }

		void setColliderName(const std::string& n) { this->name = n; }
		void setCollisionRect(const sf::FloatRect& rect) { this->collisionRect = rect; };
		void setCallback(std::function<void(CollisionInfo)> f) { this->callback = f; }
		void setRequired(Velocity& v) { velocity_req = &v; }

	protected:
		sf::FloatRect collisionRect;
		std::function<void(CollisionInfo)> callback;

		Velocity* velocity_req;
		std::string name;
	};
}