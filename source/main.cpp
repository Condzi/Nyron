#include <iostream>

#include <SFML/Graphics.hpp>

#include "ResourceCache.hpp"
#include "Entity.hpp"

int main()
{
	sf::RenderWindow window({ 800,600 }, "Platformer", sf::Style::Close);
	sf::Event event;
	sf::RectangleShape rectangle({ 100.f,100.f });

	cn::ResourceCache<sf::Texture> cache;
	std::vector<std::string> paths{ "resources/texture.png", "error" };

	cache.load(paths);

	rectangle.setTexture(cache.get("resources/texture.png"));


	while (window.isOpen())
	{
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed ||
				event.key.code == sf::Keyboard::Key::Escape)
				window.close();

		window.clear(sf::Color::Cyan);
		window.draw(rectangle);
		window.display();
	}

	return 0;
}