#include "fenetreAccueil.hpp"
#include "fenetrePosBateau.hpp"

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
	

//////////// creation des sprites et textures //////////////////////
			
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
						
					break;

				case Event::KeyPressed : 
					if (pseudoEntr_s.size() > 0 && event.key.code == Keyboard::BackSpace )
						pseudoEntr_s.erase();
					break;
				
				case Event::MouseButtonPressed :
					if(	event.mouseButton.x < 700 && event.mouseButton.x >300 && 
						event.mouseButton.y < 700 && event.mouseButton.y > 628 &&
						pseudoEntr_s.size() > 0){	
							window.close();
							fenetrePosBateau();
					}
					break;
				
			//	case Event::KeyPressed :
					
				//	break;
						
				default:
					break;
			}	
		}


//////////// creation des textes ////////////////////////////

	Text pseudoEntr_txt;
	pseudoEntr_txt.setFont(main_font);
	pseudoEntr_txt.setCharacterSize(35);	
	pseudoEntr_txt.setPosition(370,376);
	pseudoEntr_txt.setString(pseudoEntr_s);
	//pseudoEntr_txt.setFillColor(Color::Red);

	
///////////// gestion de l'affichage ////////////////////////////
	
	window.clear(Color::White); 	
	
	window.draw(fondEcran_spr);
	window.draw(pseudoEntr_txt);

        
	window.display();
        
	}

	return 0;
}


