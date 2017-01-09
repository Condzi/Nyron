#include <iostream>

#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window({ 800,600 }, "Platformer", sf::Style::Close);
	sf::Event event;
	sf::RectangleShape rectangle({ 100.f,100.f });

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