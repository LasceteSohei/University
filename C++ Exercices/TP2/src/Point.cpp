/**
 * @file Point.cpp
 * @brief A point with 3 coodinates
 * @author LasceteSohei
 * @version 0.1
 */

#include "Point.h"

using namespace std;

Point::Point():m_x(0), m_y(0), m_z(0)
{

}

Point::Point(double x, double y, double z):m_x(x), m_y(y), m_z(z)
{

}


double Point::getCoordonneeX() const
{
    return m_x;
}

double Point::getCoordonneeY() const
{
    return m_y;
}

double Point::getCoordonneeZ() const
{
    return m_z;
}


istream& operator>>(istream& flux, Point& P)
{
    cout << "\n Coordonnée en x ? ";
    flux >> P.m_x;
    cout << "\n Coordonnée en y ? ";
    flux >> P.m_y;
    cout << "\n Coordonnée en z ? ";
    flux >> P.m_z;
    return flux;
}

ostream& operator<<(ostream& flux, const Point& P)
{
    flux << "x=" << P.m_x << "\t" << "y=" << P.m_y << "\t" << "z=" << P.m_z << endl;
    return flux;
}

Point::~Point()
{

}
