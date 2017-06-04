#include "fenetrePosBateau.hpp"
#include "gestionGrille.hpp"

using namespace sf;
using namespace std;


int fenetrePosBateau()
{

////////////////// creation et init de la fenetre //////////////////

	RenderWindow window(sf::VideoMode(1000, 800), "Peaceful Shadow Online : Positionne tes bateaux Matelot !!",Style::None);
	window.setPosition(Vector2i(10, 10));


////////////////// creation et init des variables //////////////////

	string pseudoEntr_s = "";
	int cpt = 0;
	int btx , bty;
	Event event;


////////////////// chargement des fonts et textures /////////////////

	Texture fondEcran_tex;
	if (!fondEcran_tex.loadFromFile("../client/img/bateau.png")){
	}
	

//////////// creation des textes, sprites et textures //////////////
			
	Sprite fondEcran_spr(fondEcran_tex);
	
	
//////////// affichage de la fenetre ///////////////////////////////

	while (window.isOpen()){


//////////// gestion de la boule d'evenements///////////////////////

		while (window.pollEvent(event)){
			
			switch (event.type){
				
				case Event::KeyPressed : 
					if (pseudoEntr_s.size() > 0 && event.key.code == Keyboard::BackSpace )
						pseudoEntr_s.erase();
					break;
				
				case Event::MouseButtonPressed : // gestion de click dans la grille
					if(	event.mouseButton.x < 700 && event.mouseButton.x >300 && 
						event.mouseButton.y < 700 && event.mouseButton.y > 300 &&
						cpt < 5){		
						btx = event.mouseButton.x - 300; // -300 pour etre en 0,0 sur le
						bty = event.mouseButton.y - 300; // coin sup gche de la grille
						cpt++;		
						std::cout << "btx: " << retourX(btx) << "bty: " << retourY(bty) << std::endl;
					}
					
					//gestion du click sur le bouton
					if(	event.mouseButton.x < 700 && event.mouseButton.x >300 && 
						event.mouseButton.y < 791 && event.mouseButton.y > 713 &&
						cpt = 5){		
						std::cout << "the button was pressed" << std::endl;
						
					}
					
					
					break;
						
				default:
					break;
			}	
		}


//////////// creation du texte avec le pseudo //////////////////////
/*
	Text pseudoEntr_txt;
	pseudoEntr_txt.setFont(main_font);
	pseudoEntr_txt.setCharacterSize(35);	
	pseudoEntr_txt.setPosition(370,376);
	//pseudoEntr_txt.setFillColor(Color::Red);
	pseudoEntr_txt.setString(pseudoEntr_s);
*/
///////////// gestion de l'affichage //////////////////
	
	window.clear(Color::White); 	
		
	window.draw(fondEcran_spr);
	//window.draw(pseudoEntr_txt);
        
	window.display();
        
	}

	return 0;
}


