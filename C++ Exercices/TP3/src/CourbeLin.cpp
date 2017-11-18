#include "CourbeLin.h"

using namespace std;

CourbeLin::CourbeLin() : Courbe()
{
}



vector<Point> CourbeLin::calcQ(const double precisionParam) const
{
    size_t s(m_pointsCourbe.size());

    vector<Point> pSegQ;

    for(double t = 0 ; t <= 1 ; t += precisionParam)
    {
        int j = floor(t * (s-1));
        pSegQ.push_back((m_pointsCourbe[j+1] * ( calcU(j,t) )) + (m_pointsCourbe[j] * (1-calcU(j,t))) );
    }

    return pSegQ;
}



CourbeLin::~CourbeLin()
{
}

