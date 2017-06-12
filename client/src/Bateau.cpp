#include "Bateau.hpp"
#include <iostream>

using namespace std;


Bateau::Bateau(){}


void Bateau::posBateau(Grille &g,int taille){
	int x,y,rotate;
	bool libre=false;
	
	
	while(!libre){ //tant que le bateau ne rencontre pas un autre bateau 
		cout<<"Veuillez saisir les coordonnées de la tête de votre bateau de taille "<<taille<<" cases, ainsi que son orientation (0=nord,1=est,2=sud,3=ouest)"<< endl;
		cout<<"x : ";
		cin>>x;
		cout<<"y : ";
		cin>>y;
		cout<<"Orientation : ";
		cin>>rotate;
		
		switch(rotate){ //en finction de l'orientation voulue
			
			case 0: //nord
				libre=true;
				for(int i=0;i<taille;i++){
					if((x-i)<0 || g._grille[x-i][y]._type!=mer){ //verifie qu'on est dans la grille ou qu'on rencontre pas un bateau
						libre=false;
						cout<<"Erreur placement"<<endl;
					}
				}
				
				if(libre){
					for(int j=0;j<taille;j++){
						g._grille[x-j][y]._type=boat;
					}
				}
				
			break;
			
			case 1: //est
				libre=true;
				for(int i=0;i<taille;i++){
					if((y+i)>9 || g._grille[x][y+i]._type!=mer){ //verifie qu'on est dans la grille ou qu'on rencontre pas un bateau
						libre=false;
						cout<<"Erreur placement"<<endl;
					}
				}
				if(libre){
					for(int j=0;j<taille;j++){
						g._grille[x][y+j]._type=boat;
					}
				}
			break;
				
			case 2: //sud
				libre=true;
				for(int i=0;i<taille;i++){
					if((x+i)>9 || g._grille[x+i][y]._type!=mer){ //verifie qu'on est dans la grille ou qu'on rencontre pas un bateau
						libre=false;
						cout<<"Erreur placement"<<endl;
					}
				}
				if(libre){
					for(int j=0;j<taille;j++){
						g._grille[x+j][y]._type=boat;
					}
				}
					
			break;
			
			case 3: //ouest
				libre=true;
				for(int i=0;i<taille;i++ ){
					if((y-i)<0 || g._grille[x][y-i]._type!=mer){ //verifie qu'on est dans la grille ou qu'on rencontre pas un bateau
						libre=false;
						cout<<"Erreur placement"<<endl;
					}
				}
				if(libre){
					for(int j=0;j<taille;j++){ 
						g._grille[x][y-j]._type=boat;
					}
				}
			break;
		}
	}
}


