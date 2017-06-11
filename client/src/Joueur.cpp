#include "Joueur.hpp"
#include "Bateau.hpp"
#include <iostream>

using namespace std;


Joueur::Joueur(){}



void Joueur::jouerCoup(Grille &g,int x,int y){
	if(g._grille[x][y]._type==boat){
		gAdversaire._grille[x][y]._type=touch;
	}else if(g._grille[x][y]._type==mer){
		g._grille[x][y]._type=miss;
	}
}


void Joueur::initGrille(Grille &g){
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
}
