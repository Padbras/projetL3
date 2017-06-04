#include <SFML/Graphics.hpp>
#include "Case.hpp"
#include "Pays.hpp"
#include "Grille.hpp"
#include "Bateau.hpp"
#include <iostream>
#include "Jeu.hpp"
#include "fenetreAccueil.hpp"
using namespace std;


int main()
{
	 lancerFenetreAccueil();
	
	Pays pays("France");
	cout<<"Pays : "<<pays._nomPays<<endl;
	
	Grille g;
	
	Bateau b1;
	Bateau b2;
	Bateau b3;
	Bateau b4;
	Bateau b5;
	
	g.afficherGrille();
	
	b1.posBateau(g,2);
	g.afficherGrille();
	
	b2.posBateau(g,3);
	g.afficherGrille();
	
	b3.posBateau(g,3);
	g.afficherGrille();
	
	b4.posBateau(g,4);
	g.afficherGrille();
	
	b5.posBateau(g,5);
	g.afficherGrille();
	
	jouerCoup(g);
	jouerCoup(g);
	
	return 0;
}
