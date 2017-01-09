#pragma once

namespace cn
{
	class Entity;

	class RequireEntity
	{
	public:
		RequireEntity(Entity& e): entity(e) {}

	protected:
		Entity& entity;
	};
}