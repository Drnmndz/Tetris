#include <iostream>
#include "window.hpp"
#include "mainMenu.hpp"


void Window::makeWindow(int const width, int const height)
{
    sf::RenderWindow window(sf::VideoMode(width, height), "Tetris", sf::Style::Titlebar | sf::Style::Close);

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

    sf::FloatRect textRect = text.getGlobalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,textRect.top  + textRect.height/2.0f);
    text.setPosition(sf::Vector2f(width/2.0f,height - 500));

    sf::Sprite sprite(texture1);

    Menu menu(window.getSize().x, window.getSize().y);


    while(window.isOpen())
    {
        sf::Event event;

        while(window.pollEvent(event))
        {
            switch(event.type)
            {
            case sf::Event::KeyReleased:
                switch(event.key.code)
                {
                case sf::Keyboard::Up:
                    menu.MoveUp();
                    break;

                case sf::Keyboard::Down:
                    menu.MoveDown();
                    break;

                case sf::Keyboard::Return:
                    switch(menu.GetPressedItem())
                    {
                    case 0:
                        std::cout << "Play button has been pressed" << std::endl;
                        break;
                    case 1:
                        std::cout << "Highscore button has been pressed" << std::endl;
                        break;
                    case 2:
                        window.close();
                        break;
                    }

                    break;
                }
            }
        }
        window.clear();
        window.draw(sprite);
        window.draw(text);
        menu.draw(window);
        window.display();
    }
}



