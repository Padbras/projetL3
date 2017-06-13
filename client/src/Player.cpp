#include "Player.hpp"
#include "Bateau.hpp"
#include <iostream>

using namespace std;


Player::Player(){}



int Player::jouerCoup(Player &j,int cpt){
	int x,y;
	cout<<"Coordonnées a viser : ";
	cin>>x>>y;
	if(j.gJoueur.getTypeCase(x,y)==boat){
		gAdversaire.setTypeCase(x,y,touch);
		j.gJoueur.setTypeCase(x,y,touch);
		cpt++;
	}else if(j.gJoueur.getTypeCase(x,y)==mer){
		gAdversaire.setTypeCase(x,y,miss);
		j.gJoueur.setTypeCase(x,y,miss);
	}
	return cpt;
}


void Player::initGrille(Grille &g){
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
