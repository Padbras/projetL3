#include "Pays.hpp"
#include "Bateau.hpp"

void jouerCoup(Grille &g){
	int x,y;
	cout<<"Veuillez saisir les coordonnées à viser : "<< endl;
		cout<<"x : ";
		cin>>x;
		cout<<"y : ";
		cin>>y;
	
	if(g._grille[x][y]._type==boat){
		cout<<"Touché ! "<<endl;
		g._grille[x][y]._type=touch;
	}else if(g._grille[x][y]._type==mer){
		cout<<"PLOUF ! Dommage ..."<<endl;
		g._grille[x][y]._type=miss;
	}
	g.afficherGrille();
}
