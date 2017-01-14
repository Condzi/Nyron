#include <iostream>

#include <SFML/Graphics.hpp>

#include "ResourceCache.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include "Block.hpp"
#include "CollisionHandler.hpp"

void testCall(cn::CollisionInfo i)
{
	cn::Logger::log(i.collider->getColliderName(), cn::Logger::PREFIX_INFO);
	cn::Logger::log(std::to_string(i.entity->getID()), cn::Logger::PREFIX_INFO);
}

int main()
{
	sf::RenderWindow window({ 1280, 720 }, "Platformer", sf::Style::Close);
	window.setFramerateLimit(60u);
	sf::Event event;

	cn::ResourceCache<sf::Texture> cache;
	std::vector<std::string> paths{ "resources/texture.png"};
	cn::Player p;
	p.setCollisionRect({ 0,0,25,25 });
	p.setCallback(testCall);
	cn::Block b;
	b.setCollisionRect({ 0,0,25,25 });

	cn::CollisionHandler handler;
	handler.registerCollider(&p);
	handler.registerCollider(&b);

	cache.load(paths);

	b.setTexture(cache.get("resources/texture.png"));
	p.setTexture(cache.get("resources/texture.png"));
	p.setColliderName("Player");
	b.setColliderName("Box");
	b.setCallback(testCall);

	b.setPosition({ 200,200 });
	
	// it is that simple to use flags
	cn::FLAGS.set(cn::flags::TEST_FLAG);
	sf::View v = window.getDefaultView();
	v.setCenter(200, 200);

	while (window.isOpen())
	{
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed ||
				event.key.code == sf::Keyboard::Key::Escape)
				window.close();

		handler.update(1.f / 60);
		p.update(1.f / 60);
		b.update(1.f / 60);

		window.setView(v);
		window.clear({ 250,200,150 });
		window.draw(p);
		window.draw(b);
		window.display();
	}

	return 0;
}


