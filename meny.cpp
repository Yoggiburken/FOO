#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200,200), "SFML Window");
    sf::RectangleShape rect;

    rect.setSize(sf::Vector2f(50,50));
    rect.setFillColor(sf::Color::Blue);

    while (window.isOpen()) {

        sf::Event event;

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window.close();
            }

        }

        window.clear();
        window.draw(rect);
        window.display();

    }

    return 0;
}
