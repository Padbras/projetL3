#ifndef GESTIONBATEAU_HPP
#define GESTIONBATEAU_HPP
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Grille.hpp"
#include <iostream>
#include <string>



void		setBateau(Grille *, int, int, int, int);
void		eraseBateau(Grille *, int, int, int, int);
bool		verifMer(Grille *, int, int);

bool		verifPlaceNord(Grille *, int, int, int);
bool		verifPlaceSud(Grille *, int, int, int);
bool		verifPlaceOuest(Grille *, int, int, int);
bool		verifPlaceEst(Grille *, int, int, int);

void		posBateauNord(Grille *, int, int, int);
void		posBateauSud(Grille *, int, int, int);
void		posBateauOuest(Grille *, int, int, int);
void		posBateauEst(Grille *, int, int, int);



#endif

