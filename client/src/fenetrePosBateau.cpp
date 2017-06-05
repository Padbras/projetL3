#include "fenetrePosBateau.hpp"
#include "gestionGrille.hpp"
#include "fenetreJeu.hpp"

using namespace sf;
using namespace std;


int main(){

////////////////// creation et init de la fenetre //////////////////

	RenderWindow window(sf::VideoMode(1000, 800), "Peaceful Shadow Online : Positionnes tes bateaux Matelot !!",Style::Titlebar);
	window.setPosition(Vector2i(10, 10));


////////////////// creation et init des variables //////////////////

	int cpt = 0;
	int x1 , x2 , x3, x4, x5, y1, y2, y3, y4, y5;
	x1 = x2 = x3 = x4 = x5 = y1 = y2 = y3 = y4 = y5 =0;
	Event event;


////////////////// chargement des fonts et textures /////////////////

	Texture fondEcran_tex;
	if (!fondEcran_tex.loadFromFile("../client/img/bateau.png")){
	}
	
	RectangleShape bouton(Vector2f(400, 78));
	bouton.setPosition(300,713);
	bouton.setFillColor(Color(0, 0, 0, 128));


//////////// creation des textes, sprites et textures //////////////
			
	Sprite fondEcran_spr(fondEcran_tex);
	
	
//////////// affichage de la fenetre ///////////////////////////////

	while (window.isOpen()){


//////////// gestion de la boule d'evenements///////////////////////

		while (window.pollEvent(event)){
			
			switch (event.type){
				
				case Event::MouseButtonPressed : // gestion de click dans la grille
					if(	event.mouseButton.x < 700 && event.mouseButton.x >300 && 
						event.mouseButton.y < 700 && event.mouseButton.y > 300 &&
						cpt < 5){	
						x1 = gdRetourX(event.mouseButton.x);
						y1 = gdRetourY(event.mouseButton.y);
						cout << x1 << "  " << y1 << endl;							
					}
					
					//gestion du click sur le bouton
					if(	event.mouseButton.x < 700 && event.mouseButton.x >300 && 
						event.mouseButton.y < 791 && event.mouseButton.y > 713 &&
						cpt == 5){
						window.close();
						fenetreJeu();		
					}
					
					if(	event.mouseButton.x < 650 && event.mouseButton.x > 350 && 
						event.mouseButton.y < 280 && event.mouseButton.y > 221){
						cout << "validation de :"<< x1 << "  " << y1 << endl;
						cpt++;
					}
					break;
						
				default:
					break;
			}	
		}


//////////// gestion colorimetrie du bouton  ///////////////////////////
	
	if (cpt ==5 ){
		bouton.setFillColor(Color(0, 0, 0, 0));
	}


///////////// gestion de l'affichage //////////////////
	
	window.clear(Color::White); 	
		
	window.draw(fondEcran_spr);
	window.draw(bouton);
        
	window.display();
        
	}

	return 0;
}


