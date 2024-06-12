#include <iostream>
#include <SFML/Graphics.hpp>

#include "ui/UiButton.h"
#include "graphics/Tilemap.h"

//int n = 0;

int main()
{

    Tilemap map;
    map.Setup(sf::Vector2u(25, 25), sf::Vector2u(18, 18));
    
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    UiButton startButton(sf::Vector2f(400,100), sf::Color::Yellow);
    startButton.setScale(0.75f, 0.75f);

    // Fix 2 : attach a method or member function can not be directly assigned
    // use a lambda or std::bind
    // Option A : lambda
    startButton.callback_ = [&map] (){
        map.Generate();
    };
    // Option B : std::bind
    startButton.callback_ = std::bind(&Tilemap::Generate, &map);

    // Option C : use a lambda which alternates between two callbacks. No real use case, just for fun
    //startButton.callback_ = [&n] () {
    //    n++;
    //    if (n % 2)
    //        std::cout << "callback 1 !!!!!!!!!!!!!!!!" << std::endl;
    //    else
    //        std::cout << "callback 2 !!!!!!!!!!!!!!!!" << std::endl;
    //};

    // anyway generate
    map.Generate();


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
        window.draw(map);
        window.draw(startButton);
        
        // end the current frame
        window.display();
    }

    return 0;
}
