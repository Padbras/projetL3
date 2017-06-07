#ifndef GESTIONBATEAU_HPP
#define GESTIONBATEAU_HPP
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Grille.hpp"
#include <iostream>
#include <string>



void		placeBateau(Grille *, int, int, int, int);
void		eraseBateau(Grille *, int, int, int, int);

bool		verifTypeNord(Grille *, int, int, int);
bool		verifTypeSud(Grille *, int, int, int);
bool		verifTypeOuest(Grille *, int, int, int);
bool		verifTypeEst(Grille *, int, int, int);

bool		verfMer(Grille *, int, int);

#endif

