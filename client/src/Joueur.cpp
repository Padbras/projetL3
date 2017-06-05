#include "Joueur.hpp"
#include "Bateau.hpp"
#include <iostream>

using namespace std;


Joueur::Joueur(){
	string pays;
	cout<<"Choisissez votre nation : France, Allemagne, URSS, Japon, Pirate "<<endl;
	cin>>pays;
	pJoueur=Pays(pays);
	
	Grille gJoueur;
	Grille gAdversaire;
}



int Joueur::jouerCoup(Joueur &jAdv,int &cpt){
	
	int x,y;
	cout<<"Veuillez saisir les coordonnées à viser : "<< endl;
		cout<<"x : ";
		cin>>x;
		cout<<"y : ";
		cin>>y;
	cout<<endl;
	if(jAdv.gJoueur._grille[x][y]._type==boat && this->gAdversaire._grille[x][y]._type==mer){
		cout<<"Touché ! "<<endl;
		this->gAdversaire._grille[x][y]._type=touch;
		cpt++;
		cout<<"cpt = "<<cpt<<endl<<endl;
	}else if(jAdv.gJoueur._grille[x][y]._type==mer){
		cout<<"PLOUF ! Dommage ..."<<endl;
		this->gAdversaire._grille[x][y]._type=miss;
	}
	this->gAdversaire.afficherGrille();
	return cpt;
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
