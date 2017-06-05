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

//void posBateau(int numeroBateau,int x, int y){

//}
