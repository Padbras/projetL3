#include "Jeu.hpp"
#include "Case.hpp"
#include "Pays.hpp"
#include "Japon.hpp"
#include <iostream>

using namespace std;


void jouerPartie(){
	cout<<"-----JOUEUR 1-----"<<endl;
	Player j1;
	j1.gJoueur=Grille();
	j1.gAdversaire=Grille();
	j1._p=new Japon();
	j1.initGrille(j1.gJoueur);
	cout<<endl;
	cout<<endl;
	
	cout<<"-----JOUEUR 2-----"<<endl;
	Player j2;
	j2.gJoueur=Grille();
	j2.gAdversaire=Grille();
	j2.initGrille(j2.gJoueur);
	cout<<endl;
	cout<<endl;
	
	
	bool gagne=false;
	int cpttouch1=0; //compteur coup touché par j1
	int cpttouch2=0; //compteur coup touché par j2
	int cpttour=0;
	while(!gagne){
		cout<<endl;
		cout<<endl;
		cout<<"------JOUEUR 1------"<<endl;
		cout<<endl;
		cpttouch1=j1.jouerCoup(j2,cpttouch1);
		cout<<"Grille adversaire"<<endl;
		j1.gAdversaire.afficherGrille();
		
		
		if(cpttouch2%j1._p->_cooldown==0 && cpttouch2>0){
			int x,y;
			cin>>x;
			cin>>y;
			j1._p->pouvoir(x,y,j2.gJoueur);
			j2.gJoueur.afficherGrille();
		}
		
		if(win(j2,cpttouch1)){
			gagne=true;
			cout<<"------Joueur 1 gagne la partie ! Bien Joué ;)------"<<endl;
			break;
		}
		cout<<endl;cout<<endl;
		cout<<"------JOUEUR 2------"<<endl;
		cout<<endl;
		cpttouch2=j2.jouerCoup(j1,cpttouch2);
		cout<<"Grille adversaire"<<endl;
		j2.gAdversaire.afficherGrille();
		if(win(j1,cpttouch2)){
			cout<<"------Joueur 2 gagne la partie ! Bien Joué ;)------"<<endl;
			gagne=true;
			break;
		}
		cpttour++;
	}
}

bool win(Player &j,int cpt){
	bool gagne=false;
	if (j.cptBoatPart==cpt){
		gagne = true;
	}else{
		gagne = false;
	}
	return gagne;
}
