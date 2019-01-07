#include <iostream>
#include "window.hpp"


void Window::makeWindow(int const width, int const height)
{
    sf::RenderWindow window(sf::VideoMode(width, height), "Tetris", sf::Style::Titlebar | sf::Style::Close);

    sf::Event event;
    sf::Texture texture1;
    texture1.loadFromFile("images/simple.png");

    sf::Font font;

    if (!font.loadFromFile("Fonts/Adorable.otf"))
    {
        std::cout << "Error loading file" << std::endl;

        system("pause");
    }

    sf::Text text;
    sf::Sprite spritetext;
    text.setFont(font);
    text.setString("TETRIS");
    text.setCharacterSize(75);
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold);
    text.setOutlineColor(sf::Color::Yellow);
    text.setOutlineThickness(5);
    spritetext.setPosition(sf::Vector2f(250, 500));

    sf::Vector2f position = spritetext.getPosition();

    sf::FloatRect textRect = text.getGlobalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,textRect.top  + textRect.height/2.0f);
    text.setPosition(sf::Vector2f(width/2.0f,height - 500));

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
        window.draw(text);
        window.display();
    }
}

void Window::makeTitle()
{

}

