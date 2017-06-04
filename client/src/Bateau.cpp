#include "Bateau.hpp"
#include <iostream>

using namespace std;


Bateau::Bateau(){}


void Bateau::posBateau(Grille &g,int taille){
	int x,y,rotate;
	bool libre = false;
	
	
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
					if((x-i)<0){ //verifie qu'on est dans la grille 
						cout<<"Erreur placement"<<endl;
						posBateau(g,taille);
					}else{
						if(g._grille[x-i][y]._type!=mer){ //permet de gérer les collisions entre bateaux
							libre=false;
							cout<<"Erreur placement"<<endl;
						}
					}
				}
				for(int j=0;j<taille;j++){
					if(libre){
						g._grille[x-j][y]._type=boat;
					}
				}
			break;
			
			case 1: //est
				libre=true;
				for(int i=0;i<taille;i++){
					if((y+i)>9){ //verifie qu'on est dans la grille 
						cout<<"Erreur placement"<<endl;
						posBateau(g,taille);
					}else{
						if(g._grille[x][y+i]._type!=mer){ //permet de gérer les collisions entre bateaux
							libre=false;
							cout<<"Erreur placement"<<endl;
						}
					}
				}
				for(int j=0;j<taille;j++){
					if(libre){
						g._grille[x][y+j]._type=boat;
					}
				}
			break;
				
			case 2: //sud
				libre=true;
				for(int i=0;i<taille;i++){
					if((x+i)>9){ //verifie qu'on est dans la grille 
						cout<<"Erreur placement"<<endl;
						posBateau(g,taille);
					}else{
						if(g._grille[x+i][y]._type!=mer){ //permet de gérer les collisions entre bateaux
							libre=false;
							cout<<"Erreur placement"<<endl;
						}
					}
				}
				for(int j=0;j<taille;j++){
					if(libre){
						g._grille[x+j][y]._type=boat;
					}
				}
					
			break;
			
			case 3: //ouest
				libre=true;
				for(int i=0;i<taille;i++){
					if((y-i)<0){ //verifie qu'on est dans la grille 
						cout<<"Erreur placement"<<endl;
						posBateau(g,taille);
					}else{	
						if(g._grille[x][y-i]._type!=mer){ //permet de gérer les collisions entre bateaux
							libre=false;
							cout<<"Erreur placement"<<endl;
						}
					}
				}
				for(int j=0;j<taille;j++){ 
					if(libre){
						g._grille[x][y-j]._type=boat;
					}
				}
			break;
		}
	}
	
	
}


