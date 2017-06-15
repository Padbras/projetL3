#ifndef CASE_HPP
#define CASE_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

enum typeCase{mer,boat,touch,miss};


class Case{
	
	public:
		typeCase _type;
		int _x,_y;
		sf::RectangleShape _case_rect;
		
		
		Case(int, int, typeCase, sf::RectangleShape);
		Case();

};

#endif
