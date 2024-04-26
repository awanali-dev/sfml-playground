#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    auto window = sf::RenderWindow{{800u, 600u}, "sfml-playground", sf::Style::None};
    window.setFramerateLimit(60);

    // Calculate the center coordinates of the window
    float centerX = window.getSize().x / 2.0f;
    float centerY = window.getSize().y / 2.0f;

    // Circle
    sf::CircleShape circle(25.f);
    circle.setFillColor(sf::Color::Red);
    circle.setOutlineThickness(5.f);
    circle.setOutlineColor(sf::Color::Green);
    circle.setPosition(centerX - circle.getRadius(), centerY - circle.getRadius());

    // Reactangle
    sf::RectangleShape rectangle(sf::Vector2f(200.0f, 100.0f));
    rectangle.setFillColor(sf::Color(255, 165, 0));
    rectangle.setPosition(centerX - rectangle.getSize().x / 2, (centerY - rectangle.getSize().y / 2) + 150);

    // Line
    sf::Vertex line[] =
        {
            sf::Vertex(sf::Vector2f(0.f, 0.f), sf::Color::Blue),
            sf::Vertex(sf::Vector2f(800.f, 600.f), sf::Color::Blue)};

    // Octagon
    sf::CircleShape octagon(80.f, 8);
    sf::Texture texture;
    if (!texture.loadFromFile("texture_01.png"))
    {
        // error...
    }
    octagon.setTexture(&texture);
    octagon.setTextureRect(sf::IntRect(10, 10, 1024, 1024));

    // Text
    sf::Font font;
    if (!font.loadFromFile("OpenSans-Regular.ttf"))
    {
        // error...
    }
    sf::Text text;
    text.setFont(font);
    text.setString("hello world!");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Magenta);

    // Time
    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Time deltaTime = clock.restart();

        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Clear previous frame
        window.clear(sf::Color::White);

        // Draw everything after clear
        window.draw(circle);
        window.draw(rectangle);
        window.draw(line, 2, sf::Lines);
        window.draw(octagon);
        window.draw(text);

        if (window.hasFocus())
            octagon.rotate(500.f * deltaTime.asSeconds());

        // End current frame
        window.display();
    }
}