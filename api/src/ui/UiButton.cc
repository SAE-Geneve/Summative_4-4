#include <ui/UiButton.h>

#include <iostream>

#include <SFML/Graphics/RenderTarget.hpp>


UiButton::UiButton(sf::Vector2f size, sf::Vector2f position, sf::Color colorBase)
{

	setPosition(position);

	// Declare and load a font
	font_.loadFromFile("resources/fonts/arial.ttf");

	// Create a text
	text_ = sf::Text("hello", font_);
	text_.setCharacterSize(18);
	text_.setFillColor(sf::Color::Black);
	sf::FloatRect textBounds = text_.getLocalBounds();
	text_.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
	//text_.setPosition(size / 2.0f);

	background_.setSize(size);
	background_.setOrigin(size / 2.0f);
	background_.setFillColor(colorBase);

	

	//background_.setPosition(getPosition());



}

void UiButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

	states.transform *= getTransform();

	target.draw(background_, states);
	target.draw(text_, states);

}

bool UiButton::ContainsMouse(const sf::Event& event)
{
	// Get the position of the mouse click
	float mouseX = static_cast<float>(event.mouseButton.x) - getPosition().x;
	float mouseY = static_cast<float>(event.mouseButton.y) - getPosition().y;

	// Check if the mouse click is inside the drawable shape
	if (background_.getGlobalBounds().contains(mouseX, mouseY)) {
		return true;
	}
	else
	{
		return false;
	}
}

void UiButton::HandleEvent(const sf::Event& event)
{

	// Check for mouse button pressed event
	if (event.type == sf::Event::MouseButtonReleased) {

		if (ContainsMouse(event))
		{

			setScale(1.0f, 1.0f);

			// Check if the left mouse button is pressed
			if (event.mouseButton.button == sf::Mouse::Left) {

				std::cout << "Mouse clicked inside the shape." << std::endl;
			}
		}
	}

	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (ContainsMouse(event))
		{
			setScale(0.9f, 0.9f);
		}
	}



}
