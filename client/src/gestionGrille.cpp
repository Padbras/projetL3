#include "gestionGrille.hpp"

int retGrDroitX(int x)
{
  return (533 + 40 * x);
}

int retGrDroitY(int y)
{
  return (200 + 40 * y);
}

int retGrGauchX(int x)
{
  return (66 + 40 * x);
}

int retGrGauchY(int y)
{
  return (200 + 40 * y);
}

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

int pxX(int x)
{
  return (300 + 40 * x);
}

int pxY(int y)
{
  return (300 + 40 * y);
}


