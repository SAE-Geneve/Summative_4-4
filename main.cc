#include <iostream>
#include <SFML/Graphics.hpp>

#include "gameplay/building_manager.h"
#include "gameplay/change_cursor.h"
#include "gameplay/woods_man.h"
#include "ui/ui_button.h"
#include "graphics/tilemap.h"
#include "pathfinding/path_finder.h"

//int n = 0;

int main()
{

    BuildingManager building_manager;
    
    // create the window
    sf::RenderWindow window(sf::VideoMode(1024, 768), "My window");
    ChangeCursor::BasicCursor(window);

    Tilemap map;
    map.Setup(sf::Vector2u(1024 / 64, 768 / 64), sf::Vector2u(64, 64));
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
    //btn_generate.callback_ = std::bind(&Tilemap::Generate, &map);

    UiButton bt_add_house(sf::Vector2f(200, 710), sf::Color::Yellow, "House");
    bt_add_house.setScale(0.5f, 0.5f);
    bt_add_house.callback_ = [&building_manager, &window, &map]()
        {
            if (building_manager.GetActive())
            {
                building_manager.SetActive(false);
            }
            else
            {
                building_manager.SetActive(true);
                map.ClickedTile = std::bind(&BuildingManager::AddHouse, &building_manager, std::placeholders::_1);
            }
        };

    UiButton bt_add_mill(sf::Vector2f(300, 710), sf::Color::Yellow, "Mill");
    bt_add_mill.setScale(0.5f, 0.5f);
    bt_add_mill.callback_ = [&building_manager, &window, &map]()
        {
            if (building_manager.GetActive())
            {
                building_manager.SetActive(false);
            }
            else
            {
                building_manager.SetActive(true);
                map.ClickedTile = std::bind(&BuildingManager::AddMill, &building_manager, std::placeholders::_1);
            }
        };

    Woodsman woodsman(window.getSize().x / 2 , window.getSize().y / 2, 100, map);
    //woodsman.InitiateBehaviours();

    Woodsman woodsman2(window.getSize().x / 2 , window.getSize().y / 2, 100, map);
    woodsman2.InitiateBehaviours();


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

        // -- -- -- -- -- ---
        woodsman.Tick();
        woodsman2.Tick();

        // - - - - - - - - - -
        building_manager.GetActive() ? ChangeCursor::BuildingCursor(window) : ChangeCursor::BasicCursor(window);

    	// check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

            //if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Right)
            //{
            //    sf::Vector2f destination(event.mouseButton.x, event.mouseButton.y);
            //    Path p = Pathfinder::CalculatePath(map.GetWalkables(), woodsman.LastDestination(), destination, 64);

            //	woodsman.set_path(p);

            //    // Set Destination -----------------------------------------------------------------------------
            //	//woodsman.set_destination(event.mouseButton.x, event.mouseButton.y);

            //}
               

            // Handle UI Events
            btn_generate.HandleEvent(event);
            bt_add_house.HandleEvent(event);
            bt_add_mill.HandleEvent(event);
            map.HandleEvent(event);
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(map);
    	window.draw(woodsman);
    	window.draw(woodsman2);
    	window.draw(building_manager);

        window.draw(btn_generate);
    	window.draw(bt_add_house);
    	window.draw(bt_add_mill);
        
        // end the current frame
        window.display();
    }

    return 0;
}
