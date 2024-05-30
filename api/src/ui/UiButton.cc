#include <ui/UiButton.h>

#include <iostream>

#include <SFML/Graphics/RenderTarget.hpp>


UiButton::UiButton(sf::Vector2f position, sf::Color colorBase)
{

	setPosition(position);

	// Declare and load a font
	font_.loadFromFile("../resources/fonts/arial.ttf");
	texture_.loadFromFile("../resources/sprites/yellow_button00.png");

	// Create a text
	text_ = sf::Text("hello", font_);
	text_.setCharacterSize(18);
	text_.setFillColor(sf::Color::Black);
	sf::FloatRect textBounds = text_.getLocalBounds();
	text_.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);

	//sf::FloatRect texSize = sf::FloatRect(texture_.get);
	sprite_.setTexture(texture_);
	sprite_.setOrigin(texture_.getSize().x / 2.0f, texture_.getSize().y / 2.0f);
	sprite_.setColor(sf::Color::White);

	//initialScale_ = sf::Vector2f(0.5f, 0.5f);

}

void UiButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

	states.transform *= getTransform();

	target.draw(sprite_, states);
	target.draw(text_, states);

}

bool UiButton::ContainsMouse(const sf::Event& event)
{
	// Get the position of the mouse click
	float mouseX = static_cast<float>(event.mouseButton.x) - getPosition().x;
	float mouseY = static_cast<float>(event.mouseButton.y) - getPosition().y;

	// Check if the mouse click is inside the drawable shape
	if (sprite_.getGlobalBounds().contains(mouseX, mouseY)) {
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

		setScale(getScale().x / 0.9f, getScale().y / 0.9f);

		if (ContainsMouse(event))
		{
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
			setScale(0.9f * getScale().x, 0.9f * getScale().y);
		}
	}



}

//void UiButton::setScale(float factorX, float factorY)
//{
//	std::cout << "Overide scale" << std::endl;
//	initialScale_.x = factorX;
//	initialScale_.y = factorY;
//
//	sf::Transformable::setScale(factorX, factorY);
//
//}
