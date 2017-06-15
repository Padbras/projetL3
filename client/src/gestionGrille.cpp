#include "gestionGrille.hpp"

int retGrDroitX(int x)
{
	/// \brief Convertit en pixels une abscisse passée en paramêtre de la grille adverse
  return (533 + 40 * x);
}

int retGrDroitY(int y)
{
	/// \brief Convertit en pixels une ordonnée passée en paramêtre de la grille adverse 
  return (200 + 40 * y);
}

int retGrGauchX(int x)
{
	/// \brief Convertit en pixels une abscisse passée en paramêtre de la grille du joueur courant
  return (66 + 40 * x);
}

int retGrGauchY(int y)
{
	/// \brief Convertit en pixels une ordonnée passée en paramêtre de la grille adverse
  return (200 + 40 * y);
}

// retour X et Y pour une grille centrale
int gdRetourX(int mouseX){
	/// \brief Convertit en coordonnées de tableau une abscisse obtenue par la souris pour la grille de placement de bateaux
	return (mouseX- 300)/40;
}

int gdRetourY(int mouseY){
	/// \brief Convertit en coordonnées de tableau une ordonnée obtenue par la souris pour la grille de placement de bateaux
	return (mouseY- 300)/40;
}

// retour X et Y pour 2 grilles laterales
int ptRetourX(int mouseX){
	/// \brief Convertit en coordonnées de tableau une abscisse obtenue par la souris pour une grille de jeu
	return (mouseX- 533)/40;
}

int ptRetourY(int mouseY){
	/// \brief Convertit en coordonnées de tableau une ordonnée obtenue par la souris pour une grille de jeu
	return (mouseY- 200)/40;
}

int pxX(int x)
{
	/// \brief Retourne l'abscisse d'une case d'un grille de jeu
  return (300 + 40 * x);
}

int pxY(int y)
{
	/// \brief Retourne l'ordonnée d'une case d'un grille de jeu
  return (300 + 40 * y);
}


