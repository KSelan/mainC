#pragma once

class Expression
{
public:
	virtual int interpret() = 0;
	virtual ~Expression() {}
};

class ExpressionTerminale : public Expression
{
public:
	virtual int interpret() = 0;
	virtual ~ExpressionTerminale() {}
};

class ExpressionEntier : public Expression
{
public:
	int i;
	ExpressionEntier(int i)
	{
		this->i = i;
	}
	virtual int interpret() { return i;}
	virtual ~ExpressionEntier() {}
};

class ExpresionOperateur : public Expression
{
public:
	Expression * gauche;
	Expression * droite;
	virtual int interpret() = 0;
	virtual ~ExpresionOperateur() 
	{
		delete gauche;
		delete droite;
	}
};

class ExpressionPlus : public ExpresionOperateur
{
public:
	virtual int interpret()
	{
		int i, j;
		i = gauche->interpret();
		j = droite->interpret();
		return i + j;

	}
};

class ExpressionMult : public ExpresionOperateur
{
public:
	virtual int interpret()
	{
		int i, j;
		i = gauche->interpret();
		j = droite->interpret();
		return i * j;
	}
};

class Interpreteur
{
public:
	Interpreteur();
	Interpreteur(std::string expression);
	virtual ~Interpreteur();
	Expression * noeud;
	int interpret();
};

void testExpression(std::stringstream & s);



