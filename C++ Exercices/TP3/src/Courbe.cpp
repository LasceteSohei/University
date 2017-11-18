#include "Courbe.h"

using namespace std;

Courbe::Courbe() : m_pointsCourbe(), m_paramT()
{
}

Courbe::Courbe(const Courbe& C) : m_pointsCourbe(C.getPointCourbe()), m_paramT(C.getParamT())
{
}

Courbe& Courbe::operator=(const Courbe& C)
{
    m_pointsCourbe = C.getPointCourbe();

    m_paramT = C.getParamT();

    return *this;
}


void Courbe::initCourbe()
{
    int nbrePoint;
    cout << "Combien de points dans votre courbe?" << endl;
    cin >> nbrePoint;

    if(m_pointsCourbe.size() != 0)
    {
        m_pointsCourbe.clear();
        m_paramT.clear();
    }

    if(m_pointsCourbe.capacity() == 0)
    {
        m_pointsCourbe.reserve(nbrePoint+5);
        m_paramT.reserve(nbrePoint+5);
    }
    else 	if(m_pointsCourbe.capacity() < nbrePoint)
    {
        m_pointsCourbe.reserve(nbrePoint - m_pointsCourbe.capacity() + 5);
        m_paramT.reserve(nbrePoint - m_paramT.capacity() + 5);
    }

    Point pointTemp;

    for(int i = 0; i < nbrePoint; i++)
    {
        cin >> pointTemp;
        m_pointsCourbe.push_back(pointTemp);
    }

    m_paramT.push_back(0);
    for(int i = 1; i < nbrePoint+1; i++)
        m_paramT.push_back((double)i/(nbrePoint-1));
}

void Courbe::addPoint(const Point& P)
{

    if( (m_pointsCourbe.size() + 1) > (m_pointsCourbe.capacity() ) )
        m_pointsCourbe.reserve(5);

    m_pointsCourbe.push_back(P);

    size_t s(m_pointsCourbe.size());

    m_paramT.clear();

    if(s > m_paramT.capacity() )
        m_paramT.reserve(5);

    m_paramT.push_back(0);
    for(int i = 1; i < s+1; i++)
        m_paramT.push_back((double)i/(s-1));
}

void Courbe::addMPoint()
{
    int nbrePoint;
    cout << "Combien de point à rajouter ?" << endl;
    cin >> nbrePoint;

    Point pointTemp;

    for(int i = 0; i < nbrePoint; i++)
    {
        cin >> pointTemp;
        addPoint(pointTemp);
    }
}

vector<Point> Courbe::getPointCourbe() const
{
    return m_pointsCourbe;
}

vector<double> Courbe::getParamT() const
{
    return m_paramT;
}


double Courbe::calcU(int pos, double t) const
{
    if(m_paramT.size() == 1)
        throw string("Error : Need more points to the curve."); //AMELIORER LE THROW

    double U((double)((t-m_paramT[pos])/(m_paramT[pos+1]-m_paramT[pos])));
    return U;
}


Courbe::~Courbe()
{
}


ostream& operator<<(ostream& flux, const Courbe& C)
{
    size_t s(C.m_pointsCourbe.size());

    flux << "Point de la courbe :"<< endl;
    for(int i = 0; i < s; i++)
        flux << C.m_pointsCourbe[i];

    flux << endl << "Abcisse param de la courbe :"<<endl;
    for(int i = 0; i < s; i++)
        flux <<"t["<<i<<"] :\t"<< C.m_paramT[i] << endl;

    return flux;
}
