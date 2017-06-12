#include "Japon.hpp"
#include <iostream> 

using namespace std;

Japon::Japon(int cooldown):
	Pays(cooldown)
{}

Grille Japon::pouvoir(Grille &g){ //utilisation avec le nombre de parties de bateau touchées = au cooldown -> a vérifier avant 
	int x,y,x1,y1,x2,y2; 
	Event event;
	switch (event.type){				
		case Event::MouseButtonPressed :
			if(	event.mouseButton.x < 933 && event.mouseButton.x >533 && 
				event.mouseButton.y < 600 && event.mouseButton.y > 200){		
				x1 = ptRetourX(event.mouseButton.x);
				y1 = ptRetourY(event.mouseButton.y);
				g._grille[x1][y1]._case_rect.setFillColor(sf::Color(128,128,128,128));
			}
			if(	event.mouseButton.x < 648 && event.mouseButton.x >348 && 
				event.mouseButton.y < 730 && event.mouseButton.y > 670){
					jouerCoup(g,x1,y1); //envoi de paquet a ajouter
			}
		break;
	}			
	
	switch (event.type){				
		case Event::MouseButtonPressed :
			if(	event.mouseButton.x < 933 && event.mouseButton.x >533 && 
				event.mouseButton.y < 600 && event.mouseButton.y > 200){		
				x2 = ptRetourX(event.mouseButton.x);
				y2 = ptRetourY(event.mouseButton.y);
				g._grille[x1][y1]._case_rect.setFillColor(sf::Color(128,128,128,128));
			}
			if(	event.mouseButton.x < 648 && event.mouseButton.x >348 && 
				event.mouseButton.y < 730 && event.mouseButton.y > 670){
					jouerCoup(g,x2,y2); //envoi de paquet a ajouter
			}
		break;
	}	
	
	
	
	return g;
}
