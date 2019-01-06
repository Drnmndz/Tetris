#include <iostream>
#include "window.hpp"

void Window::makeWindow(int const width, int const height)
{
    sf::RenderWindow window(sf::VideoMode(width, height), "Tetris", sf::Style::Titlebar | sf::Style::Close);

    sf::Event event;
    sf::Texture texture1;
    texture1.loadFromFile("images/simple.png");

    sf::Sprite sprite(texture1);

    while(window.isOpen())
    {
        while(window.pollEvent(event)){
            if(event.type == sf::Event::EventType::Closed){
                window.close();
            }
        }
        window.clear();
        window.draw(sprite);
        window.display();
    }
}

void Window::makeTitle()
{

}

