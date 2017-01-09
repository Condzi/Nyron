#include <iostream>

#include <SFML/Graphics.hpp>

#include "ResourceCache.hpp"
#include "Entity.hpp"
#include "Player.hpp"

int main()
{
	sf::RenderWindow window({ 800,600 }, "Platformer", sf::Style::Close);
	window.setFramerateLimit(60u);
	sf::Event event;

	cn::ResourceCache<sf::Texture> cache;
	std::vector<std::string> paths{ "resources/texture.png"};
	cn::Player p;

	cache.load(paths);

	p.setTexture(cache.get("resources/texture.png"));


	while (window.isOpen())
	{
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed ||
				event.key.code == sf::Keyboard::Key::Escape)
				window.close();

		p.update(1.f / 60);

		window.clear(sf::Color::Cyan);
		window.draw(p);
		window.display();
	}

	return 0;
}