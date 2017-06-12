#include "Pirates.hpp"
#include <iostream> 

using namespace std;

Pirates::Pirates(int cooldown):
	Pays(cooldown)
{}

typeCase Pirates::pouvoir(int x,int y,Grille &g){
	if(g._grille[x][y]._type!=touch){
		Pirates::pouvoir(x,y,g);
	}else{
		return g._grille[x][y]._type=boat;
	}	
	
}
