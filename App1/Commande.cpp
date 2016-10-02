#include "Commande.h"
#include "hanoi.h"
#include "graph_test.h"
#include "arbre.h"
#include "foncteur.h"
#include "Singleton.h"
#include "Interpreteur.h"
#include "Heritage.h"
#include "point.h"
#include "constmutable.h"

Platform::String^ convertToWinString3(std::stringstream & s)
{
	std::string s_str(s.str());
	std::wstring wid_str = std::wstring(s_str.begin(), s_str.end());
	const wchar_t* w_char = wid_str.c_str();
	return ref new Platform::String(w_char);
}

Platform::String^ convertToWinString4(std::string & s)
{
	std::wstring wid_str = std::wstring(s.begin(), s.end());
	const wchar_t* w_char = wid_str.c_str();
	return ref new Platform::String(w_char);
}

Commande::Commande(std::string  & nom) : nom(nom){}

void Commande::executer()
{
	std::stringstream s;
	specifique(s);
	this->sortie->Text = convertToWinString3(s);
}

void CommandeSimple::specifique(std::stringstream & s)
{
	s << "error" << std::endl;
}

void CommandeHanoi::specifique(std::stringstream & s)
{
	hanoitest(s);
}

void CommandeGraph::specifique(std::stringstream & s)
{
	run_test(s);
}

void CommandeArbre::specifique(std::stringstream & s)
{
	testNode(s);
}

void CommandeFoncteur::specifique(std::stringstream & s)
{
	testFoncteur(s);
}

void  CommandeSingleton::specifique(std::stringstream & s)
{
	//singletonTest(s);
	s << "************lancement test Singleton ************" << std::endl;
	s << "recuperation du singleton à l'addresse : " << std::hex << Singleton::GetInstance() << std::endl;
	s << "recuperation du singleton à l'addresse : " << std::hex << Singleton::GetInstance() << std::endl;
	s << "recuperation du singleton à l'addresse : " << std::hex << Singleton::GetInstance() << std::endl;
	s << "destruction du singleton" << std::endl;
	Singleton::resetSingleton();
	s << "recuperation du singleton à l'addresse : " << std::hex << Singleton::GetInstance() << std::endl;
	s << "recuperation du singleton à l'addresse : " << std::hex << Singleton::GetInstance() << std::endl;
	s << "recuperation du singleton à l'addresse : " << std::hex << Singleton::GetInstance() << std::endl;
	Singleton::resetSingleton();
}

void CommandeInterpreteur::specifique(std::stringstream & s)
{
	testExpression(s);
}

void CommandeHeritage::specifique(std::stringstream & s)
{
	testHeritage(s);
}

void CommandeSurchargeOperateur::specifique(std::stringstream & s)
{
	testOperateurs(s);
}

void CommandeConstTest::specifique(std::stringstream & s)
{
	testConst(s);
}

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>



void CommandeLister::specifique(std::stringstream & s)
{
	char buffer[MAX_PATH];
	LPWSTR buf = (WCHAR*) &buffer;
	GetModuleFileName(NULL, buf, MAX_PATH);
	//std::string::size_type pos = std::string(buf).find_last_of("\\/");
	//std::string sf =  std::string(buffer).substr(0, pos);

}


