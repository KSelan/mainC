#include "pch.h"
#include "Interpreteur.h"
#include <sstream>
#include <vector>


Interpreteur::Interpreteur()
{
}

Interpreteur::~Interpreteur()
{
	delete noeud;
}
int Interpreteur::interpret()
{
	return noeud ? noeud->interpret() : 0;
}

int transf(std::string & s)
{
	int ret;
	std::stringstream str;
	str << s;
	str >> ret;
	return ret;
}

Expression * parse(std::string expression)
{
	std::vector<int> positionPlus;
	std::vector<int> positionMult;
	int size = expression.size();
	for (int index = 0; index < size; ++index)
	{
		char c = expression[index];
		if (c == '+')
		{
			positionPlus.push_back(index);
		}
		else if (c == '*')
		{
			positionMult.push_back(index);
		}
	}

	const int nbPlus = positionPlus.size();
	const int nbMult = positionMult.size();
	if (!nbPlus && !nbMult)
	{
		return new ExpressionEntier(transf(expression));
	}
	else if (nbPlus)
	{
		ExpressionPlus * ret = new ExpressionPlus();
		ret->gauche = parse(expression.substr(0, positionPlus[0]));
		ret->droite = parse(expression.substr(positionPlus[0]+1, expression.size() - positionPlus[0]-1));
		return ret;
	}
	else
	{
		ExpressionMult * ret = new ExpressionMult();
		ret->gauche = parse(expression.substr(0, positionMult[0]));
		ret->droite = parse(expression.substr(positionMult[0]+1, expression.size() - positionMult[0]-1));
		return ret;
	}
}

Interpreteur::Interpreteur(std::string expression)
{
	this->noeud = parse(expression);
}

void testExpression(std::stringstream & s)
{
	std::vector < std::string> expressions;
	expressions.push_back("1+2");
	expressions.push_back("2*9");
	expressions.push_back("2*9+1");
	expressions.push_back("2+9+1");
	expressions.push_back("3*9*4");
	expressions.push_back("3+9+4");
	expressions.push_back("1+3*2+4*5");

	for (std::vector<std::string>::iterator it = expressions.begin(); it != expressions.end(); ++it)
	{
		Interpreteur inter(*it);
		int v = inter.interpret();
		s << "l'interpretation de " << *it << " est :\n";
		s << v << std::endl;
	}
}


