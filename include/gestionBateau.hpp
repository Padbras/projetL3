#ifndef GESTIONBATEAU_HPP
#define GESTIONBATEAU_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Grille.hpp"
#include "gestionGrille.hpp"
#include <iostream>
#include <string>

bool		verifMer(Grille *, int, int);
bool		verifBoat(Grille *, int, int);
bool 		verifPlace(Grille *grille, int, int, int, int);

bool		posBateau(Grille *, int, int, int, int);
void		eraseBateau(Grille *, int, int, int, int);

void		setBateau(Grille *, int, int);
void 		setMer(Grille *, int, int);
void 		setErreur(Grille *, int, int);

#endif

