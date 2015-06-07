#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main(){
    sf::RenderWindow window(sf::VideoMode(800,600),"sfml window");
    sf::Clock clock;
    float fps {60};
    sf::Time frameTime = sf::seconds(1.f / fps);

    while(window.isOpen()){
        //event loop
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }

        //frame loop
        sf::Time timeSinceLastFrame{clock.restart()};
        if(timeSinceLastFrame > frameTime){
            //consider using an accumulator to make the fps constant

            window.clear();
            //draw something;
            window.display();
        }
    }


    return 0;
}

