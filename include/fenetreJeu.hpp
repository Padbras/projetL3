#ifndef FENETREJEU_HPP
#define FENETREJEU_HPP
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "network.hpp"
#include "client.hpp"
#include "Player.hpp"

// return 1 si gagné, -1 si perdu
int fenetreJeu(Player *, sf::TcpSocket *);

#endif
