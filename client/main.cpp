#include <SFML/Graphics.hpp>

int main()
{	//creation de la fenetre
    sf::RenderWindow window(sf::VideoMode(800, 600), "Peaceful Shadow Online"
    ,sf::Style::Default);

	// tant que la fenetre est ouverte ...
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }

    return 0;
}
