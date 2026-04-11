//Internal Headers
#include <GUI/GUI.hpp>

//External Headers
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

void GUI::initGUI() {
	sf::RenderWindow window(sf::VideoMode({ 1600u, 900u }), "ProfitLens Debug Test");

	window.setFramerateLimit(60);

	while (window.isOpen()) {
		// Event processing
		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>())
				window.close();
		}

		// 1. Clear the window
		window.clear(sf::Color::White);

		// 2. Draw your objects here (see below)
		// window.draw(shape);

		// 3. Display what was drawn
		window.display();
	}
}
