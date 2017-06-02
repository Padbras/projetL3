#include "client.hpp"
#include "aff_elements.hpp"

using namespace sf;
using namespace std;


int main()
{
	RenderWindow window(sf::VideoMode(1000, 800), "Peaceful Shadow Online",Style::Close);
	window.setPosition(Vector2i(10, 10));

	// tant que la fenetre est ouverte ...
	while (window.isOpen()){
		// gestion des evenements depuis la derniere maj de la fenetre
		Event event;
		while (window.pollEvent(event)){
			// fermeture de la fenetre
			if (event.type == Event::Closed)
				window.close();
		}
        
		window.clear(Color::White); //effacement en blanc de la frame preced.
		
		//chargement des fonts et textures
		Texture tex;
		if (!tex.loadFromFile("../img/fond.png")){}
		Font main_font;
		main_font.loadFromFile("../fonts/main_font.ttf");
		
			
		Sprite spr(tex);
		spr.scale(1.25f, 1.34f);

		Text nomJeu;
		nomJeu.setFont(main_font);
		nomJeu.setString("Peaceful Shadow Online");
		nomJeu.setCharacterSize(70); // exprimée en pixels, pas en points !
		nomJeu.setPosition(180,150);
		
		Text jouer;
		jouer.setFont(main_font);
		jouer.setString("Trouvez une partie");
		jouer.setCharacterSize(40);
		jouer.setPosition(380,550);
		
		Text pseudo;
		pseudo.setFont(main_font);
		pseudo.setString("Entrez votre pseudo");
		pseudo.setCharacterSize(40);
		pseudo.setPosition(380,300);
		
		
		
		window.draw(spr);
		window.draw(nomJeu);
		window.draw(jouer);
		window.draw(pseudo);
        
		window.display(); // affichage des elements créés/déssinés...
        
	}

	return 0;
}


