#include "client.hpp"
#include "aff_elements.hpp"

using namespace sf;
using namespace std;


int main()
{
	string pseudoEntr_s = "";
	RenderWindow window(sf::VideoMode(1000, 800), "Peaceful Shadow Online",Style::Close);
	window.setPosition(Vector2i(10, 10));
	Clock clock; //mise en route de l'horloge


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
		
//////////// creation des textes, sprites et textures /////////////
			
		Sprite spr(tex);
		spr.scale(1.25f, 1.34f);

		Text nomJeu;
		nomJeu.setFont(main_font);
		nomJeu.setString("Peaceful Shadow Online");
		nomJeu.setCharacterSize(70); // exprimée en pixels, pas en points !
		nomJeu.setPosition(180,150);
		
		Text jouer;
		jouer.setFont(main_font);
		jouer.setString("Trouver une partie");
		jouer.setCharacterSize(40);
		jouer.setPosition(380,550);
		
		Text pseudo;
		pseudo.setFont(main_font);
		pseudo.setString("Entrez votre pseudo :");
		pseudo.setCharacterSize(40);
		pseudo.setPosition(380,300);
		
		Text pseudoEntr;
		pseudoEntr.setFont(main_font);
		pseudoEntr.setString(pseudoEntr_s);
		pseudoEntr.setCharacterSize(40);
		pseudoEntr.setPosition(380,380);
		
/////////// gestion de l'entrée pseudo////////////////////

		if (event.type == Event::TextEntered){	
			Time time = clock.getElapsedTime();
			if(time.asMilliseconds() > 250)
			{
				if (((char)event.text.unicode <= 'z' && (char)event.text.unicode >= 'a') // filtrage des caracteres entrés
					|| ((char)event.text.unicode <= 'Z' && (char)event.text.unicode >= 'A') 
					|| ((char)event.text.unicode <= '0' && (char)event.text.unicode >= '9')){
				pseudoEntr_s.push_back((char)event.text.unicode);
				clock.restart();
				}
				
		
			}
		}
		// else if (event.type == Event::KeyPressed){
		  // cout << "rentre dans le if" << endl;
		if (event.key.code == Keyboard::BackSpace){
		  Time time = clock.getElapsedTime();
		  if (time.asMilliseconds() > 250)
		    {
		      if (pseudoEntr_s.size() != 0)
			pseudoEntr_s.pop_back();
		      clock.restart();
		    }
		  

		// }
		}	

	
		
///////////// gestion de l'affichage //////////////////
			
		window.draw(spr);
		window.draw(nomJeu);
		window.draw(jouer);
		window.draw(pseudo);
		window.draw(pseudoEntr);
        
		window.display();
        
	}

	return 0;
}


