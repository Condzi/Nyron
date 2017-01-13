#pragma once

#include <functional>

#include <SFML/Graphics/Rect.hpp>

#include "Velocity.hpp"
#include "RequireComponent.hpp"

namespace cn
{
	class Collider;
	class Entity;

	struct CollisionInfo final
	{
		Collider* collider = nullptr;
		Entity* entity = nullptr;
		enum Side
		{
			None = -1,
			Left = 0,
			Right,
			Top,
			Down
		} side = None;

		CollisionInfo(Collider* p, Entity* e, CollisionInfo::Side s) { collider = p; entity = e; side = s; }
	};

	class Collider :
		public Require<Velocity>,
		public Require<Entity>
	{
		friend class CollisionHandler;

	public:
		Collider() :collisionRect(0, 0, 0, 0) { velocity_req = nullptr; this->name = "<unnamed collider>"; }

		auto& getCollisionRect() { return this->collisionRect; }
		auto getColliderName() { return this->name; }

		void setColliderName(const std::string& n) { this->name = n; }
		void setCollisionRect(const sf::FloatRect& rect) { this->collisionRect = rect; };
		void setCallback(std::function<void(CollisionInfo)> f) { this->callback = f; }
		void setRequired(Velocity& v) { this->velocity_req = &v; }
		void setRequired(Entity& e) { this->entity_req = &e; }

	protected:
		sf::FloatRect collisionRect;
		std::function<void(CollisionInfo)> callback;

		Velocity* velocity_req;
		Entity* entity_req;
		std::string name;
	};
}