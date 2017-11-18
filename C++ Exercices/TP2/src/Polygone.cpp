/**
 * @file Polygone.cpp
 * @brief A polygon
 * @author LasceteSohei
 * @version 0.1
 */
#include "Polygone.h"

using namespace std;

Polygone::Polygone() : m_pointsPoly()
{
}


Polygone::Polygone(int nbrePoints)
{
    m_pointsPoly.reserve(nbrePoints);
}

void Polygone::ajouterPoint(const Point& P)
{
    m_pointsPoly.push_back(P);
}


void Polygone::ajouterMPoint(int nbrePoints)
{

    Point pointTemp;

    for(int i = 0; i<nbrePoints; i++) /*!< Adding 'nbrePoints' points to the polygon*/
    {
        cout << "Coordonnée du point " << i+1 << ": " ;
        cin >> 	pointTemp;
        cout << endl;

        m_pointsPoly.push_back(pointTemp);
    }
}

double Polygone::calculerAire() const
{

    size_t s(m_pointsPoly.size());	/*!< Size used by the vector containing the polygon*/
    Vec3 v1;
    Vec3 v2;
    Vec3 pVec;
    Vec3 som;

    for (int i = 1; i < s - 1; ++i)
    {
        /*!< Init Vec3 with new points at each loop*/
        v1.ajouterPtoV3(m_pointsPoly[0], m_pointsPoly[i]);
        v2.ajouterPtoV3(m_pointsPoly[0], m_pointsPoly[i+1]);

        /*!< Vector product*/
        pVec = v1 * v2;

        /*!< Normalizing coordinates of vector*/
        pVec.normVec3();

        /*!< Summing all the vector product*/
        som += pVec;
    }

    double aire = 0.5 * sqrt(som.getCoordonneeX() * som.getCoordonneeX()
                        + som.getCoordonneeY() * som.getCoordonneeY()
                        + som.getCoordonneeZ() * som.getCoordonneeZ() );
return aire;
}


ostream& operator<<(ostream& flux, const Polygone& P)
{

    size_t s(P.m_pointsPoly.size()); /*!< Size used by the vector containing the polygon*/

    for(int i = 0; i < s; i++)
    {
        flux << "Point " << i+1 <<" du Polygone : \t" << P.m_pointsPoly[i] << endl;
    }

    return flux;
}



Polygone::~Polygone()
{

}
