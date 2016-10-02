#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <sstream>
class point
{
public:
	point() {}
    point(int x, int y):x(x),y(y){}
    int getX() const {return x;}
    int getY() const {return y;}

    friend std::ostream& operator << (std::ostream & stream, const point & p)
    {
        stream << "point d'abscisse " << p.getX() << " et d'ordonnee " << p.getY() << std::endl;
        return stream;
    }

	point operator + (point b)
	{
		point ret;
		ret.x = this->x + b.x;
		ret.y = this->x + b.y;
		return ret;
	}

	point& operator ++()
	{
		this->x++;
		this->y++;
		return *this;
	}

   private:
    int x,y;
};

void testOperateurs(std::stringstream & s);

#endif // POINT_H
