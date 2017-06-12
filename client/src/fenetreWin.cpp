#include "fenetreWin.hpp"


using namespace sf;
using namespace std;


int fenetreWin(){

////////////////// creation et init de la fenetre //////////////////

	RenderWindow window(sf::VideoMode(1000, 800), "Peaceful Shadow Online : GGWP Cap'tain ",Style::Titlebar);
	window.setPosition(Vector2i(10, 10));


////////////////// creation et init des variables //////////////////

	Event event;
	Clock clock;
	Time time;


////////////////// chargement des fonts et textures /////////////////

	Texture fondEcran_tex;
	if (!fondEcran_tex.loadFromFile("../client/img/win.png")){
	}

	RectangleShape bouton(Vector2f(400, 78));
	bouton.setPosition(300,116);
	bouton.setFillColor(Color(0, 0, 0, 160));
	

//////////// creation des textes, sprites et textures //////////////
	
	Sprite fondEcran_spr(fondEcran_tex);
	
	
//////////// affichage de la fenetre ///////////////////////////////

	while (window.isOpen()){
		
		time = clock.getElapsedTime();
		
		
//////////// gestion de la boule d'evenements///////////////////////
		
		while (window.pollEvent(event)){
			
			switch (event.type){
				
				case Event::MouseButtonPressed : 
				
					//gestion du click sur le bouton
					if(	event.mouseButton.x < 700 && event.mouseButton.x >300 && 
						event.mouseButton.y < 194 && event.mouseButton.y > 116 &&
						time.asSeconds() > 3.0f){
			        	  window.close();
					}
					break;
						
				default:
					break;
			}	
		}


//////////// gestion colorimetrie du bouton  ///////////////////////////

	if (time.asSeconds() > 3.0f ){
		bouton.setFillColor(Color(0, 0, 0, 0));
	}
	
	
////////////////// timer de fermeture automatique //////////////////////

	if (time.asSeconds() > 10.0f){
		window.close();
	}
	

///////////// gestion de l'affichage //////////////////
	
	window.clear(Color::White); 	
	
	window.draw(fondEcran_spr);	
	window.draw(bouton);
        
	window.display();
        
	}

	return 0;
}



