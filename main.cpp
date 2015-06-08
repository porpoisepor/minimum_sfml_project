#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main(){
    sf::RenderWindow window(sf::VideoMode(800,800),"Test");
    sf::Clock clock;
    float fps {60};
    sf::Time frameTime = sf::seconds(1.f / fps);

    sf::Time timeSinceLastLoop{sf::Time::Zero};
    sf::Time accumulatedTime(sf::Time::Zero);

    while(window.isOpen()){
        //event loop
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }

        //frame loop
        timeSinceLastLoop = clock.restart();
        accumulatedTime += timeSinceLastLoop;
        if(accumulatedTime > frameTime){
            accumulatedTime -= frameTime;
            window.clear();
            //draw something;
            window.display();
        }
    }
    return 0;
}


