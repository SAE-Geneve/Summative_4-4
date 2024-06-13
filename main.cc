#include <iostream>
#include <SFML/Graphics.hpp>

#include "gameplay/building_manager.h"
#include "gameplay/change_cursor.h"
#include "ui/UiButton.h"
#include "graphics/Tilemap.h"

//int n = 0;

int main()
{

    BuildingManager building_manager;

    // create the window
    sf::RenderWindow window(sf::VideoMode(1024, 768), "My window");
    ChangeCursor::BasicCursor(window);

    Tilemap map;
    map.Setup(sf::Vector2u(1024 / 18, 768 / 18), sf::Vector2u(18, 18));
    // anyway generate
    map.Generate();

    UiButton btn_generate(sf::Vector2f(50,710), sf::Color::Yellow, "Generate");
    btn_generate.setScale(0.5f, 0.5f);

    // Fix 2 : attach a method or member function can not be directly assigned
    // use a lambda or std::bind
    // Option A : lambda
    btn_generate.callback_ = [&map] (){
        map.Generate();
    };
    // Option B : std::bind
    btn_generate.callback_ = std::bind(&Tilemap::Generate, &map);

    UiButton btn_activate_building(sf::Vector2f(200, 710), sf::Color::Yellow, "Build");
    btn_activate_building.setScale(0.5f, 0.5f);
    btn_activate_building.callback_ = [&building_manager, &window]()
        {
            if (building_manager.GetActive())
            {
                building_manager.SetActive(false);
                ChangeCursor::BasicCursor(window);
            }
            else
            {
                building_manager.SetActive(true);
                ChangeCursor::BuildingCursor(window);
            }
        };

    // Option C : use a lambda which alternates between two callbacks. No real use case, just for fun
    //startButton.callback_ = [&n] () {
    //    n++;
    //    if (n % 2)
    //        std::cout << "callback 1 !!!!!!!!!!!!!!!!" << std::endl;
    //    else
    //        std::cout << "callback 2 !!!!!!!!!!!!!!!!" << std::endl;
    //};

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
            btn_generate.HandleEvent(event);
            btn_activate_building.HandleEvent(event);
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(map);
        window.draw(btn_generate);
        window.draw(btn_activate_building);
        
        // end the current frame
        window.display();
    }

    return 0;
}
