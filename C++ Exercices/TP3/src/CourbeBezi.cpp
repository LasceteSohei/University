#include "CourbeBezi.h"

using namespace std;

CourbeBezi::CourbeBezi() : Courbe()
{}


void CourbeBezi::initCourbe()
{
    try
    {
        Courbe::initCourbe();
        size_t s(m_pointsCourbe.size());
        if(s%4 != 0)
            throw string("Error : Pas assez de point pour jouer avec Bézier, il faut des paquets de 4 points! \n");
    }
    catch(string e)
    {
        cout << e << endl;
        size_t s(m_pointsCourbe.size());
        while(s%4 != 0)
        {
            initCourbe();
            s = m_pointsCourbe.size();
        }
    }

}

vector<Point> CourbeBezi::calcQ(const double precisionParam) const
{

    size_t s(m_pointsCourbe.size());
    vector<Point> pSegQ;

    for(double t = 0 ; t <= 1 ; t += precisionParam)
    {
        int j = floor(t/4. * (s-1));
        double u = calcU(j,t/4.);
        cout << "t=" << t << ", j=" << j << ", u=" << u << endl;
        pSegQ.push_back( 	  m_pointsCourbe[4*j+0] * pow(1-u, 3)
                              + m_pointsCourbe[4*j+1] * 3 * u * pow(1-u, 2)
                              + m_pointsCourbe[4*j+2] * 3 * pow(u, 2) * (1-u)
                              + m_pointsCourbe[4*j+3] * pow(u,3)
                       );
    }
    return pSegQ;
}



CourbeBezi::~CourbeBezi()
{}
