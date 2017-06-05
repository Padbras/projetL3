#ifndef CASE_HPP
#define CASE_HPP

enum typeCase{mer=0,boat=1,touch=2,miss=3};


class Case{
	public:
		typeCase _type;
		int _x,_y;
		Case();
		Case(int px, int py, typeCase t);
};

#endif

 
