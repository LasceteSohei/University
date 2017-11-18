/**
 * @file Point.cpp
 * @brief A point with 2 coodinates
 * @author LasceteSohei
 * @version 0.1
 */

#include "Point.h"

using namespace std;

Point::Point():m_x(0), m_y(0)
{

}

Point::Point(double x, double y):m_x(x), m_y(y)
{

}

Point::Point(const Point& P):m_x(P.getCoordonneeX()), m_y(P.getCoordonneeY())
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

Point& Point::operator+=(const Point& P)
{
    m_x = ((P.m_x + m_x)/2);

    m_y = ((P.m_y + m_y)/2);

    return *this;
}

Point& Point::operator*=(double const &a)
{
    m_x = (m_x * a);
    m_y = (m_y * a);
    return *this;
}


istream& operator>>(istream& flux, Point& P)
{
    cout << "\n Coordonnée en x ? ";
    flux >> P.m_x;
    cout << "\n Coordonnée en y ? ";
    flux >> P.m_y;
    return flux;
}

ostream& operator<<(ostream& flux, const Point& P)
{
    flux << "x=" << P.m_x << "\t" << "y=" << P.m_y <<  endl;
    return flux;
}

Point::~Point()
{

}

Point operator+(Point const &a, Point const &b)
{
    Point copie(a);
    copie += b;
    return copie;
}

Point operator*(Point const &a, double const &b)
{
    Point copie(a);
    copie *= b;
    return copie;
}

