#pragma once
#ifndef CONSTMUTABLE_H
#define CONSTMUTABLE_H

#include <sstream>

class ConstMut {
private:
	int x;
	mutable int numberofAcces;
public:
	ConstMut(int x) : x(x) { numberofAcces = 0;}
	int getAcces() const { return numberofAcces;}
	int getX() const
	{
		numberofAcces++;
		return x;
	}
};

void testConst(std::stringstream & s)
{
	int i = 2;
	const int IC = 20;
	const int* p;
	ConstMut obj(5);
	s << "mutable permet de modifier l'attribut meme dans une fonction const!" << std::endl;
	s << " x = " << obj.getX() << " acces = " << obj.getAcces() << std::endl;
	s << " x = " << obj.getX() << " acces = " << obj.getAcces() << std::endl;
	s << " x = " << obj.getX() << " acces = " << obj.getAcces() << std::endl;
	s << " x = " << obj.getX() << " acces = " << obj.getAcces() << std::endl;

	p = &IC;
	p = &i;
	//*p = IC; p' : vous ne pouvez pas assigner une variable const
	i = *p;
}

#endif