#include <ui/UiButton.h>

#include <iostream>

#include <SFML/Graphics/RenderTarget.hpp>


UiButton::UiButton()
{

	background_.setSize(sf::Vector2f(50, 50));
	background_.setFillColor(sf::Color::Yellow);

}

void UiButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

	target.draw(background_, states);

}

void UiButton::HandleEvent(const sf::Event& event)
{

    // Check for mouse button pressed event
    if (event.type == sf::Event::MouseButtonReleased) {

        // Check if the left mouse button is pressed
        if (event.mouseButton.button == sf::Mouse::Left) {

            // Get the position of the mouse click
            float mouseX = static_cast<float>(event.mouseButton.x);
            float mouseY = static_cast<float>(event.mouseButton.y);

            // Check if the mouse click is inside the drawable shape
            if (background_.getGlobalBounds().contains(mouseX, mouseY)) {
                std::cout << "Mouse clicked inside the shape." << std::endl;
            }
        }
    }


}
