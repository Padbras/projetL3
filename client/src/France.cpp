#include "France.hpp"
#include <iostream> 

using namespace std;

France::France(int cooldown):
	Pays(cooldown)
{}

typeCase France::pouvoir(int x,int y,Grille &g){
	if(g._grille[x][y]._type!=mer && g._grille[x][y]._type!=boat){
		pouvoir(x,y,g);
	}
	return g._grille[x][y]._type;
}
