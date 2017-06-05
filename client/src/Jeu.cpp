#include "Jeu.hpp"

#include <iostream>

using namespace std;


void jouerPartie(){
	cout<<"-----JOUEUR 1-----"<<endl;
	Joueur j1;
	j1.gJoueur=Grille();
	j1.gAdversaire=Grille();
	j1.initGrille(j1.gJoueur);
	cout<<endl;
	cout<<endl;
	
	cout<<"-----JOUEUR 2-----"<<endl;
	Joueur j2=Joueur();
	j2.gJoueur=Grille();
	j2.gAdversaire=Grille();
	j2.initGrille(j2.gJoueur);
	cout<<endl;
	cout<<endl;
	
	
	bool gagne=false;
	int cpt1=0; //compteur coup touché par j1
	int cpt2=0; //compteur coup touché par j2
	
	while(!gagne){
		
		cout<<"------JOUEUR 1------"<<endl;
		cout<<endl;
		cpt1=j1.jouerCoup(j2,cpt1);
		
		if(win(j2,cpt1)){
			gagne=true;
			cout<<"------Joueur 1 gagne la partie ! Bien Joué ;)------"<<endl;
			break;
		}
		
		cout<<"------JOUEUR 2------"<<endl;
		cout<<endl;
		cpt2=j2.jouerCoup(j1,cpt2);
		
		if(win(j1,cpt2)){
			cout<<"------Joueur 2 gagne la partie ! Bien Joué ;)------"<<endl;
			gagne=true;
			break;
		}
	}
}

bool win(Joueur &j,int cpt){
	bool gagne=false;
	if (j.cptBoatPart==cpt){
		gagne = true;
	}else{
		gagne = false;
	}
	return gagne;
}
