#include "gestionGrille.hpp"

// retour X et Y pour une grille centrale
int gdRetourX(int mouseX){
	return (mouseX- 300)/40;
}

int gdRetourY(int mouseY){
	return (mouseY- 300)/40;
}

// retour X et Y pour 2 grilles laterales
int ptRetourX(int mouseX){
	return (mouseX- 533)/40;
}

int ptRetourY(int mouseY){
	return (mouseY- 200)/40;
}

void enrPos(int x, int y, Grille *grille){
	int posx, posy;
	grille->_grille[x][y]._type = boat;
	posx = 300 + 40*x;
	posy = 300 + 40*y;
	grille->_grille[x][y]._case_rect.setPosition(posx,posy);
	grille->_grille[x][y]._case_rect.setFillColor(sf::Color(0, 255, 0, 128));
}


