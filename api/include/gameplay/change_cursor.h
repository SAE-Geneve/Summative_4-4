#ifndef CURSOR_H
#define CURSOR_H

#include <SFML/Graphics/Image.hpp>
#include <SFML/Window/Cursor.hpp>
#include <SFML/Window/Window.hpp>

class ChangeCursor
{

public:
	static void BasicCursor(sf::Window& window)
	{
		// TO DO : Move cursor to ressource manager
		sf::Image image;
		image.loadFromFile("../resources/sprites/pointer_scifi_a.png");

		sf::Cursor cursor;
		cursor.loadFromPixels(image.getPixelsPtr(), image.getSize(), sf::Vector2u(0,0));

		window.setMouseCursor(cursor);

	}

	static void BuildingCursor(sf::Window& window)
	{
		// TO DO : Move cursor to ressource manager
		sf::Image image;
		image.loadFromFile("../resources/sprites/tool_hammer.png");

		sf::Cursor cursor;
		cursor.loadFromPixels(image.getPixelsPtr(), image.getSize(), sf::Vector2u(0,0));

		window.setMouseCursor(cursor);

	}

};
#endif // CURSOR_H
