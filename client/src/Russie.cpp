#include "Russie.hpp"
#include <iostream> 

using namespace std;

Russie::Russie(int cooldown):
	Pays(cooldown)
{}

Grille Russie::pouvoir(Grille &g){ //tir en croix avec x et y coordonnées centre récuperées par la souris
	int x,y,x1,y1;
	Event event;
	switch (event.type){				
		case Event::MouseButtonPressed :
			if(	event.mouseButton.x < 933 && event.mouseButton.x >533 && 
				event.mouseButton.y < 600 && event.mouseButton.y > 200){		
				x1 = ptRetourX(event.mouseButton.x);
				y1 = ptRetourY(event.mouseButton.y);	
				g._grille[x1-1][y1]._case_rect.setFillColor(sf::Color(128,128,128,128));		
				g._grille[x1+1][y1]._case_rect.setFillColor(sf::Color(128,128,128,128));		
				g._grille[x1][y1-1]._case_rect.setFillColor(sf::Color(128,128,128,128));		
				g._grille[x1][y1+1]._case_rect.setFillColor(sf::Color(128,128,128,128));		
			}
			if(	event.mouseButton.x < 648 && event.mouseButton.x >348 && 
				event.mouseButton.y < 730 && event.mouseButton.y > 670){
				jouerCoup(g,x1-1,y1); //envoi de paquet a ajouter
				jouerCoup(g,x1+1,y1); //envoi de paquet a ajouter
				jouerCoup(g,x1,y1-1); //envoi de paquet a ajouter
				jouerCoup(g,x1,y1+1); //envoi de paquet a ajouter
			}
		break;
	}
	return g;  //permet de juste renvoyer la grille modifiée , facilite l'affichage et la transmission de paquets
}
