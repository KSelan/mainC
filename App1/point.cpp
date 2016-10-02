#include "point.h"

void testOperateurs(std::stringstream & s)
{
	point p(4,9);
	s << "operateurs non surchargeables + . :: sizeof typeid" << std::endl;
	s << p << std::endl;
	s << "incrementation point" << std::endl;
	p++;
	s << p << std::endl;
}
