#include "France.hpp"
#include <iostream> 

using namespace std;

France::France()
{ 
	_cooldown=4;
}


void France::pouvoir(int x,int y,Grille &g){ //revoie le type d'une case de la grille adverse
	
	if(g._grille[x][y]._type!=mer && g._grille[x][y]._type!=boat){
		pouvoir(x,y,g);
	}else{
		cout<<g.getTypeCase(x,y)<<endl;
	}
}
