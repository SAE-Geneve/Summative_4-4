#include <iostream>
#include <SFML/Graphics.hpp>

#include "ui/UiButton.h"


int main()
{

    int n = 0;
    int captured = 0;

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    UiButton startButton(sf::Vector2f(400,100), sf::Color::Yellow);
    startButton.setScale(0.75f, 0.75f);

    startButton.callback_ = [&n] () {
        n++;
        if (n % 2)
            std::cout << "callback 1 !!!!!!!!!!!!!!!!" << std::endl;
        else
            std::cout << "callback 2 !!!!!!!!!!!!!!!!" << std::endl;

    };

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

            // Handle UI Events
            startButton.HandleEvent(event);
        }



        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(startButton);

        // end the current frame
        window.display();
    }

    return 0;
}
