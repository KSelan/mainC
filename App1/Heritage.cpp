#include "Heritage.h"

std::stringstream A::str;

void testHeritage(std::stringstream &s)
{
	B * b = new B();
	delete(b);
	s << "__ B * b = new B();" << std::endl;
	s << "__ delete(b);" << std::endl;
	s << A::getBuffer();
	s << "__________________________" << std::endl;
	B * b1 = new B();
	b1->affiche();
	b1->nonvirtualAffiche();
	delete(b1);
	s << "__ B * b1 = new B();" << std::endl;
	s << "__ B * b1->affiche();" << std::endl;
	s << "__ b1->nonvirtualAffiche();" << std::endl;
	s << "__ delete(b1);" << std::endl;
	s << A::getBuffer();
	s << "__________________________" << std::endl;
	A * a = new B();
	a->affiche();
	a->nonvirtualAffiche();
	delete(a);
	s << "__ A * a = new B();" << std::endl;
	s << "__ B * a->affiche();" << std::endl;
	s << "__ a->nonvirtualAffiche();" << "*** Utilisation methode mere ***" << std::endl;
	s << "__ delete(a);" << std::endl;
	s << A::getBuffer();
	s << "__________________________" << std::endl;
	B * b2 = new B();
	A * a1 = reinterpret_cast<B*>(b2);
	a1->affiche();
	a1->nonvirtualAffiche();
	delete(a1);
	s << "__ B * b2 = new B();" << std::endl;
	s << "__ A * a1 = reinterpret_cast<B*>(b2);" << std::endl;
	s << "__ a1->affiche();" << std::endl;
	s << "__ a1->nonvirtualAffiche();" << "*** Utilisation methode mere ***" << std::endl;
	s << "__ delete(a1);" << std::endl;
	s << A::getBuffer();
	s << "__________________________" << std::endl;
	B * b3 = new B();
	A * a2 = static_cast<B*>(b3);
	a2->affiche();
	a2->nonvirtualAffiche();
	delete(a2);
	s << "__ B * b3 = new B();" << std::endl;
	s << "__ A * a2 = static_cast<B*>(b3);" << std::endl;
	s << "__ a2->affiche();" << std::endl;
	s << "__ a2->nonvirtualAffiche();" << "*** Utilisation methode mere ***" << std::endl;
	s << "__ delete(a2);" << std::endl;
	s << A::getBuffer();
}