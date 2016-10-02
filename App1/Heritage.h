#pragma once
#ifndef HERITAGE_H
#define HERITAGE_H

#include <sstream>

class A
{
	public:
		static std::stringstream str;
		A()
		{
			this->str << "Constructeur class A" << std::endl;
		}
		virtual ~A()
		{
			this->str << "Destructeur class A" << std::endl;
		}
		virtual void affiche()
		{
			this->str << "affiche A" << std::endl;
		}
		void nonvirtualAffiche()
		{
			this->str << "nonvirtualAffiche A" << std::endl;
		}
		static std::string getBuffer()
		{
			std::string ret(A::str.str());
			A::str.str("");
			A::str.clear();
			return ret;
		}
};

class B : public A
{
public:
	B()
	{
		this->str << "Constructeur class B" << std::endl;
	}
	virtual ~B()
	{
		this->str << "Destructeur class B" << std::endl;
	}
	virtual void affiche()
	{
		this->str << "affiche B" << std::endl;
	}
	void nonvirtualAffiche()
	{
		this->str << "nonvirtualAffiche B" << std::endl;
	}
};

void testHeritage(std::stringstream &s);


#endif
