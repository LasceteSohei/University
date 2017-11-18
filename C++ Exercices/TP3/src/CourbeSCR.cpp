#include "CourbeSCR.h"

using namespace std;

CourbeSCR::CourbeSCR() : Courbe(), m_tension(0.5)
{
}

CourbeSCR::CourbeSCR(const CourbeSCR& C)
{
    *this = C;
}

CourbeSCR& CourbeSCR::operator=(const CourbeSCR& C)
{
    m_pointsCourbe = C.getPointCourbe();
    m_paramT = C.getParamT();
    m_tension = C.getTension();
    return *this;
}


void CourbeSCR::setTension(double _tension)
{
    m_tension = _tension;
}

double CourbeSCR::getTension(void) const
{
    return m_tension;
}


vector<Point> CourbeSCR::calcQ(const double precisionParam ) const
{

    size_t s(m_pointsCourbe.size());
    vector<Point> pSegQ;


    for(double t = 0 ; t <= 1 ; t += precisionParam)
    {
        int j = floor(t * (s-1));
        pSegQ.push_back(calcMatriceCR(j, t) );
    }

    return pSegQ;
}


Point CourbeSCR::calcMatriceCR(int j, double i) const
{
    Point pOut;

    /*!< On gère le cas du premier point*/
    if( j == 0)
        pOut = m_pointsCourbe[0] * ( -m_tension*calcU(j,i) + 2*m_tension*( pow(calcU(j,i),2)) -m_tension*( pow(calcU(j,i),3)) );
    else
        pOut = m_pointsCourbe[j-1] * ( -m_tension*calcU(j,i) + 2*m_tension*( pow(calcU(j,i),2)) -m_tension*( pow(calcU(j,i),3)) ) ;

    /*!< Cas intermediaires*/
    pOut += m_pointsCourbe[j] * (1 + (m_tension -3 )*( pow(calcU(j,i),2)) + (2-m_tension)*( pow(calcU(j,i),3)));

    pOut += m_pointsCourbe[j+1] * (m_tension*calcU(j,i) + (3-2*m_tension)*( pow(calcU(j,i),2)) + (m_tension - 2)*( pow(calcU(j,i),3)) ) ;

    /*!< On gère le cas des deux derniers points de la courbe*/
    if( j == m_pointsCourbe.size()-2)
        pOut += m_pointsCourbe[j+1] * (-m_tension*( pow(calcU(j,i),2)) + m_tension*( pow(calcU(j,i),3)));
    else
        pOut += m_pointsCourbe[j+2] * (-m_tension*( pow(calcU(j,i),2)) + m_tension*( pow(calcU(j,i),3))) ;

    return pOut;
}


CourbeSCR::~CourbeSCR()
{}
