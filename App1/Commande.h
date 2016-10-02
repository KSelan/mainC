#pragma once

#ifndef COMMANDE_H
#define COMMANDE_H

#include "utils.h"
#include "pch.h"
using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

#include <sstream>
#include <map>

class Commande
{
public:
	Commande() {}
	Commande(std::string & nom);
	virtual ~Commande() {} //declaration du destructeur virtuel IMPORTANT
	void executer();
	virtual void specifique(std::stringstream & s) {}// = 0;
	std::string getNom() const { return this->nom;}
	void setSortie(TextBox ^ sortie) { this->sortie = sortie;}
protected:
	TextBox ^ sortie;
	std::string nom;
};

class CommandeSimple : public Commande
{
	//SLA comment: par défaut, ce qui n'est pas public est private
public:
	CommandeSimple() {}
	CommandeSimple(std::string & nom) :Commande(nom) {}
protected:
	virtual void specifique(std::stringstream & s);
};

class CommandeHanoi : public CommandeSimple
{
public:
	CommandeHanoi() { this->nom = "Hanoi";}
protected:
	virtual void specifique(std::stringstream & s);
};

class CommandeGraph : public CommandeSimple
{
public:
	CommandeGraph() { this->nom = "Graphe"; }
protected:
	virtual void specifique(std::stringstream & s);
};

class CommandeHeritage : public CommandeSimple
{
public:
	CommandeHeritage() { this->nom = "Heritage"; }
protected:
	virtual void specifique(std::stringstream & s);
};

class CommandeConstTest : public CommandeSimple
{
public:
	CommandeConstTest() { this->nom = "const et mutable"; }
protected:
	virtual void specifique(std::stringstream & s);
};

class CommandeDiamant : public CommandeSimple
{
public:
	CommandeDiamant() { this->nom = "Diamant"; }
};

class CommandeHeritageMultiple : public CommandeSimple
{
public:
	CommandeHeritageMultiple() { this->nom = "Heritage Multiple"; }
};

class CommandeReference : public CommandeSimple
{
public:
	CommandeReference() { this->nom = "reference"; }
};

class CommandeTemplate: public CommandeSimple
{
public:
	CommandeTemplate() { this->nom = "template"; }
};

class CommandeThread : public CommandeSimple
{
public:
	CommandeThread() { this->nom = "Thread"; }
};

class CommandeArbre : public CommandeSimple
{
public:
	CommandeArbre() { this->nom = "arbre binaire"; }
protected:
	virtual void specifique(std::stringstream & s);
};

class CommandeTri : public CommandeSimple
{
public:
	CommandeTri() { this->nom = "Tri"; }
};

class CommandeException : public CommandeSimple
{
public:
	CommandeException() { this->nom = "Exception"; }
};

class CommandeFoncteur : public CommandeSimple
{
public:
	CommandeFoncteur() { this->nom = "foncteur"; }
protected:
	virtual void specifique(std::stringstream & s);
};

class CommandeLambda : public CommandeSimple
{
public:
	CommandeLambda() { this->nom = "lambda expression"; }
};

class CommandePredicat : public CommandeSimple
{
public:
	CommandePredicat() { this->nom = "Predicat"; }
};

class CommandeSharedPointer : public CommandeSimple
{
public:
	CommandeSharedPointer() { this->nom = "Shared Pointer"; }
};

class CommandeAutoPointer : public CommandeSimple
{
public:
	CommandeAutoPointer() { this->nom = "Auto Pointer"; }
};

class CommandeDestructeur : public CommandeSimple
{
public:
	CommandeDestructeur() { this->nom = "Destructeurs"; }
};

class CommandeDeFriend : public CommandeSimple
{
public:
	CommandeDeFriend() { this->nom = "Friend"; }
};

class CommandeTemplateTemplate : public CommandeSimple
{
public:
	CommandeTemplateTemplate() { this->nom = "template de template"; }
};

class CommandeVariaticFunction : public CommandeSimple
{
public:
	CommandeVariaticFunction() { this->nom = "paramètres infinis"; }
};

class CommandeSurchargeOperateur : public CommandeSimple
{
public:
	CommandeSurchargeOperateur() { this->nom = "Surcharge Operateurs"; }
protected:
	void specifique(std::stringstream & s);
};

class CommandeExport : public CommandeSimple
{
public:
	CommandeExport() { this->nom = "Export"; }
};

class CommandeNonCopiable : public CommandeSimple
{
public:
	CommandeNonCopiable() { this->nom = "Non copiable"; }
};

class CommandeSingleton : public CommandeSimple
{
public:
	CommandeSingleton() { this->nom = "Design Pattern _ Singleton"; }
protected:
	virtual void specifique(std::stringstream & s);
};

class CommandeSingletonThreadSafe : public CommandeSimple
{
public:
	CommandeSingletonThreadSafe() { this->nom = "Design Pattern _ Singleton Thread Safe??"; }
};

class CommandeShadok : public CommandeSimple
{
public:
	CommandeShadok() { this->nom = "Shadok"; }
};

class CommandePretImmo : public CommandeSimple
{
public:
	CommandePretImmo() { this->nom = "Pret"; }
//protected:
	//virtual void specifique(std::stringstream & s);
};

class CommandeInterpreteur : public CommandeSimple
{
public:
	CommandeInterpreteur() { this->nom = "Design Pattern _ Interpreteur"; }
protected:
	virtual void specifique(std::stringstream & s);
};

class CommandeCast : public CommandeSimple
{
public:
	CommandeCast() { this->nom = "cast"; }
protected:
	virtual void specifique(std::stringstream & s);
};

class CommandeExplicit : public CommandeSimple
{
public:
	CommandeExplicit() { this->nom = "explicit"; }
protected:
	virtual void specifique(std::stringstream & s);
};

class CommandeMutable : public CommandeSimple
{
public:
	CommandeMutable() { this->nom = "mutable"; }
protected:
	virtual void specifique(std::stringstream & s);
};
class CommandeLister : public CommandeSimple
{
public:
	CommandeLister() { this->nom = "Lister"; }
protected:
	virtual void specifique(std::stringstream & s);
};
















#endif