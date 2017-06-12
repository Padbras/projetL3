#ifndef GESTIONGRILLE_HPP
#define GESTIONGRILLE_HPP
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Grille.hpp"
#include <iostream>
#include <string>


int retGrGauchX(int);
int retGrGauchY(int);

int retGrDroitX(int);
int retGrDroitY(int);

int gdRetourX(int mouseX);
int gdRetourY(int mouseY);

int ptRetourX(int mouseX);
int ptRetourY(int mouseY);

int pxX(int x);
int pxY(int y);

#endif

