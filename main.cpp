#include<SFML/Graphics.hpp>

int main() {
	sf::RenderWindow window;
	sf::ContextSettings option;
	option.antialiasingLevel = 8;

	window.create(sf::VideoMode{ 800,600 }, "My window", sf::Style::Close, option);

	sf::Event event;

	while (window.isOpen()) {
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}


	return 0;
}