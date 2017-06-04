#include <SFML/Graphics.hpp>
#include "Case.hpp"
#include "Pays.hpp"
#include "Grille.hpp"
#include "Bateau.hpp"
#include <iostream>
#include "Jeu.hpp"
#include "fenetreAccueil.hpp"
#include "network.hpp"
using namespace std;


int main()
{
	
	Grille g;
	int verif;
	sf::TcpSocket socketToServer;
	
	Bateau b1;
	Bateau b2;
	Bateau b3;
	Bateau b4;
	Bateau b5;
	
	g.afficherGrille();
	
	b1.posBateau(g,2);	
	b2.posBateau(g,3);	
	b3.posBateau(g,3);	
	b4.posBateau(g,4);	
	b5.posBateau(g,5);

	g.afficherGrille();

	verif = connectToServer(&socketToServer, "127.0.0.1", 8888);

	return 0;
}
