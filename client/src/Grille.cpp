#include "Grille.hpp"

using namespace std;

Grille::Grille(){
	sf::RectangleShape rect(sf::Vector2f(40,40));
	for(int j=0;j<10;j++){
		for(int i=0;i<10;i++){
			_grille[i][j]=Case(i,j,mer,rect);
		}
	}
}


void Grille::afficherGrille(){
	cout<<" _ _ _ _ _ _ _ _ _ _"<<endl;
	for(int j=0;j<10;j++){
		for(int i=0;i<10;i++){
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


/////////////////////////// Getters et Setters /////////////////////////

void Grille::setPosCase(int x, int y, int pixX, int pixY){
	_grille[x][y]._case_rect.setPosition(pixX,pixY);
}

void Grille::setColorCase(int x, int y, int r, int g, int b, int alpha){
	_grille[x][y]._case_rect.setFillColor(sf::Color(r,g,b,alpha));
}

void Grille::setTypeCase(int x, int y, typeCase type){
	_grille[x][y]._type = type;
}

typeCase Grille::getTypeCase(int x, int y){
	return _grille[x][y]._type;
}

sf::RectangleShape Grille::getRect(int x, int y)
{
  return _grille[x][y]._case_rect;
}
