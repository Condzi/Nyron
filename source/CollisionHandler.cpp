#include "CollisionHandler.hpp"

namespace cn
{
	bool CollisionHandler::collidedLeft(const sf::FloatRect & a, const sf::FloatRect & b)
	{
		return a.left + a.width >= b.left;
	}

	bool CollisionHandler::collidedRight(const sf::FloatRect & a, const sf::FloatRect & b)
	{
		return a.left < b.left + b.width;
	}

	bool CollisionHandler::collidedTop(const sf::FloatRect & a, const sf::FloatRect & b)
	{
		return a.top + a.height >= b.top;
	}

	bool CollisionHandler::collidedBottom(const sf::FloatRect & a, const sf::FloatRect & b)
	{
		return a.top < b.top + b.height;
	}

	void cn::CollisionHandler::registerCollider(Collider * coll)
	{
		for (Collider* c : this->colliders)
			if (c == coll)
			{
				Logger::log("Cannot register collider - found collider with same memory ID (" + std::to_string(reinterpret_cast<std::size_t>(coll)) + ")", Logger::PREFIX_ERROR);
				return;
			}

		this->colliders.push_back(coll);
		
		Logger::log("Registred collider (" + std::to_string((int)&*coll) + "), total colliders registred: " + std::to_string(this->colliders.size()), Logger::PREFIX_INFO);
	}

	void CollisionHandler::unregisterCollider(Collider * coll)
	{
		auto result = std::find(this->colliders.begin(), this->colliders.end(), coll);

		if (result != this->colliders.end())
		{
			this->colliders.erase(result);
			Logger::log("Unregistering collider (" + std::to_string(reinterpret_cast<std::size_t>(coll)) + "), total colliders registred: " + std::to_string(this->colliders.size()), Logger::PREFIX_INFO);
		
			return;
		}

		Logger::log("Cannot unregister collider - cannot find collider (" + std::to_string(reinterpret_cast<std::size_t>(coll)) + ")", Logger::PREFIX_ERROR);
	}

	void CollisionHandler::update(float deltaTime)
	{
		for(unsigned i = 0; i < colliders.size(); ++i)
			for (unsigned j = 0; j < colliders.size(); ++j)
			{
				if (j == i)
					continue;

				sf::FloatRect& collA = colliders[i]->collisionRect;
				sf::FloatRect& collB = colliders[j]->collisionRect;

				if (collA.intersects(collB))
				{
					if (this->collidedLeft(collA, collB))
					{
						colliders[i]->callback(CollisionInfo(colliders[j], CollisionInfo::Left));
						colliders[j]->callback(CollisionInfo(colliders[i], CollisionInfo::Right));
					}
					else if (this->collidedRight(collA, collB))
					{
						colliders[i]->callback(CollisionInfo(colliders[j], CollisionInfo::Right));
						colliders[j]->callback(CollisionInfo(colliders[i], CollisionInfo::Left));
					}
					else if (this->collidedTop(collA, collB))
					{
						colliders[i]->callback(CollisionInfo(colliders[j], CollisionInfo::Top));
						colliders[j]->callback(CollisionInfo(colliders[i], CollisionInfo::Down));
					}
					else if (this->collidedBottom(collA, collB))
					{
						colliders[i]->callback(CollisionInfo(colliders[j], CollisionInfo::Down));
						colliders[j]->callback(CollisionInfo(colliders[i], CollisionInfo::Top));
					}
				}
			}
	}
}
