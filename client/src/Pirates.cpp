#include "Pirates.hpp"
#include <iostream> 

using namespace std;

Pirates::Pirates()	
{
	_cooldown=5;
}

void Pirates::pouvoir(int x,int y,Grille &g){ //repare une case de bateau via les coordonnées passées en parametres
	
	if(g.getTypeCase(x,y)==touch){
		g.setTypeCase(x,y,boat);
		g.afficherGrille();
	}else{
		int x1,y1;
		cin>>x1;
		cin>>y1;
		Pirates::pouvoir(x1,y1,g);
	}
}
