#include <SFML/Graphics.hpp>
#include <iostream>

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

        window.clear(sf::Color::White); //RAZ de la fenetre
        
        sf::Texture t_fondAccueil;
        if (!t_fondAccueil.loadFromFile("../img/fond.png"))
			{
			}
		
		sf::Sprite s_fondAccueil;
		s_fondAccueil.setTexture(t_fondAccueil);
		
        window.draw(s_fondAccueil); // execute le "dessin"
       
       
        window.display(); //affichage des objets dessinés
    }

    return 0;
}
