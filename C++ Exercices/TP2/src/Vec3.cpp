#include "Vec3.h"

using namespace std;

Vec3::Vec3() : 	m_x(0),
    m_y(0),
    m_z(0)
{
}

Vec3::Vec3(const Point& P1, const Point& P2)
{
    ajouterPtoV3(P1, P2);
}

Vec3::Vec3(const Vec3& V) : 	m_x(V.getCoordonneeX()),
    m_y(V.getCoordonneeY()),
    m_z(V.getCoordonneeZ())
{
}

void Vec3::ajouterPtoV3(const Point& P1, const Point& P2)
{
    m_x = P2.getCoordonneeX() - P1.getCoordonneeX();
    m_y = P2.getCoordonneeY() - P1.getCoordonneeY();
    m_z = P2.getCoordonneeZ() - P1.getCoordonneeZ();
}


Vec3 Vec3::pVec3(const Vec3& v1, const Vec3& v2) const
{

    Vec3 pvec;

    pvec.m_x = (v1.m_y * v2.m_z) - (v1.m_z * v2.m_y);
    pvec.m_y = -(v1.m_x * v2.m_z - v1.m_z * v2.m_x);
    pvec.m_z = (v1.m_x * v2.m_y) - (v1.m_y * v2.m_x);

    return pvec;
}

void Vec3::normVec3()
{
    m_x = sqrt(m_x * m_x);
    m_y = sqrt(m_y * m_y);
    m_z = sqrt(m_z * m_z);

}

double Vec3::getCoordonneeX() const
{
    return m_x;
}

double Vec3::getCoordonneeY() const
{
    return m_y;
}

double Vec3::getCoordonneeZ() const
{
    return m_z;
}

Vec3& Vec3::operator+=(Vec3 const &a)
{

    m_x += a.m_x;
    m_y += a.m_y;
    m_z += a.m_z;

    return *this;
}




ostream& operator<<(ostream& flux, const Vec3& V)
{
    flux << "x=" << V.m_x << "\t" << "y=" << V.m_y << "\t" << "z=" << V.m_z << endl;
    return flux;
}


Vec3 operator*(Vec3 const &v1, Vec3 const &v2)
{
    return v1.pVec3(v1,v2);
}


Vec3::~Vec3()
{
}
