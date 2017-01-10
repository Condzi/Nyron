#include <iostream>

#include <SFML/Graphics.hpp>

#include "ResourceCache.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include "CollisionHandler.hpp"

void testCall(cn::CollisionInfo i)
{
	cn::Logger::log("COLLISION! Side:" + std::to_string(i.side), cn::Logger::PREFIX_INFO);
}

int main()
{
	sf::RenderWindow window({ 800,600 }, "Platformer", sf::Style::Close);
	window.setFramerateLimit(60u);
	sf::Event event;

	cn::ResourceCache<sf::Texture> cache;
	std::vector<std::string> paths{ "resources/texture.png"};
	cn::Player p;
	cn::Player p2;
	p2.setPosition({ 0,50 });
	p2.setCallback(testCall);
	p2.setCollisionRect({ 0,0,100,100 });
	p.setCollisionRect({ 0,0,100,100 });
	p.setCallback(testCall);

	cn::CollisionHandler handler;
	handler.registerCollider(&p);
	handler.registerCollider(&p2);

	cache.load(paths);

	p.setTexture(cache.get("resources/texture.png"));


	while (window.isOpen())
	{
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed ||
				event.key.code == sf::Keyboard::Key::Escape)
				window.close();

		p.update(1.f / 60);
		handler.update(1.f / 60);

		window.clear(sf::Color::Cyan);
		window.draw(p);
		window.display();
	}

	return 0;
}
