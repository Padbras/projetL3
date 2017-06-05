#ifndef GESTIONGRILLE_HPP
#define GESTIONGRILLE_HPP
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Grille.hpp"
#include <iostream>
#include <string>


int gdRetourX(int mouseX);
int gdRetourY(int mouseY);

int ptRetourX(int mouseX);
int ptRetourY(int mouseY);

void enrPos(int x, int y, Grille *grille);
#endif
