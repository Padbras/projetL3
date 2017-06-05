#include "Grille.hpp"

using namespace std;

Grille::Grille(){
	sf::RectangleShape rect(sf::Vector2f(40,40));
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			_grille[i][j]=Case(i,j,mer,rect);
		}
	}
}


void Grille::afficherGrille(){
	cout<<" _ _ _ _ _ _ _ _ _ _"<<endl;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			cout<<"|";
			switch(_grille[i][j]._type){
				case mer:
					cout<<"_";
				break;
				case boat:
					cout<<"B";
				break;
				case touch:
					cout<<"T";
				break;
				case miss:
					cout<<"X";
				break;
			}
		}
		cout<<endl;
	}
}
