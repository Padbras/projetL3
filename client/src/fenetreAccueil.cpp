#include "fenetreAccueil.hpp"

using namespace sf;
using namespace std;


int main()
{

////////////////// creation et init de la fenetre //////////////////

	RenderWindow window(sf::VideoMode(1000, 800), "Peaceful Shadow Online",Style::Close);
	window.setPosition(Vector2i(10, 10));


////////////////// creation et init des variables //////////////////

	string pseudoEntr_s = "";
	Event event;


////////////////// chargement des fonts et textures /////////////////

	Texture fondEcran_tex;
	if (!fondEcran_tex.loadFromFile("../img/accueil.png")){
	}
	Font main_font;
	main_font.loadFromFile("../fonts/main_font.ttf");
	

//////////// creation des textes, sprites et textures //////////////
			
	Sprite fondEcran_spr(fondEcran_tex);
	
	
//////////// affichage de la fenetre ///////////////////////////////

	while (window.isOpen()){


//////////// gestion de la boule d'evenements///////////////////////

		while (window.pollEvent(event)){
			
			switch (event.type){
				
				case Event::Closed :
					window.close();
					break;
				
				case Event::TextEntered :
					pseudoEntr_s.push_back((char)event.text.unicode);
					cout << pseudoEntr_s << endl ;
						
					break;

				case Event::KeyPressed : 
					if (pseudoEntr_s.size() > 0 && event.key.code == Keyboard::BackSpace ){
						cout << pseudoEntr_s << endl ;
						cout << "taille de la string "<< pseudoEntr_s.size() << endl;
						pseudoEntr_s.erase();
						cout << "nvlle taille "<< pseudoEntr_s.size() << endl;
					}
					break;
				
				case Event::MouseButtonPressed :
					std::cout << "the right button was pressed" << std::endl;
					std::cout << "mouse x: " << event.mouseButton.x << std::endl;
					std::cout << "mouse y: " << event.mouseButton.y << std::endl;
					break;
						
				default:
					break;
			}	
		}


//////////// creation du texte avec le pseudo //////////////////////

	Text pseudoEntr_txt;
	pseudoEntr_txt.setFont(main_font);
	pseudoEntr_txt.setCharacterSize(40);	
	pseudoEntr_txt.setPosition(380,380);
	pseudoEntr_txt.setString(pseudoEntr_s);

///////////// gestion de l'affichage //////////////////
	
	window.clear(Color::White); 	
		
	window.draw(fondEcran_spr);
	window.draw(pseudoEntr_txt);
        
	window.display();
        
	}

	return 0;
}


