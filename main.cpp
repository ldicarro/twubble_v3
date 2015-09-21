#include <iostream>
#include <SFML/Graphics.hpp>
#include "Bubble.hpp"


using namespace std;
using namespace sf;

int main()
{
	bool fullscreen;

	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::Texture texture;
	if(texture.loadFromFile("resources/background.jpg",sf::IntRect(0,0,1920,1024)) != true)
		return -1;

	sf::Sprite sprite(texture);
	


	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
			{

				if (event.key.code == sf::Keyboard::Escape)
				{
					fullscreen = !fullscreen;
					window.create(sf::VideoMode(200,200), "SFML works!",sf::Style::Close);
				}

				if(event.key.code == sf::Keyboard::F)
				{
					fullscreen = !fullscreen;
					window.create(sf::VideoMode(200,200), "SFML works!",(fullscreen ? sf::Style::Fullscreen : sf::Style::Close));

				}

				if(event.key.code == sf::Keyboard::Q && event.key.control == 1)
				{
						window.close();
				}
			}
		}

		window.clear();
		sprite.setScale(1.5,1.5);
		window.draw(sprite,sf::RenderStates::Default);
		window.draw(shape);
		window.display();
	}

	return 0;
}