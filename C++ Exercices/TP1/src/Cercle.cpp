/**
 * @file Cercle.cpp
 * @brief A circle with a central point and a radius.
 * @author LasceteSohei
 * @version 0.1
 */
#include "Cercle.h"

using namespace std;


Cercle::Cercle(): 	m_centre(Point(0,0)),
    m_rayon(150)
{
}

Cercle::Cercle(const Cercle& C) :	m_centre(C.getCentre()),
    m_rayon(C.getRayon())
{
}

Cercle::Cercle(const Point& P, double rayon):	m_centre(P),
    m_rayon(rayon)
{
}


Point Cercle::getCentre() const
{
    return m_centre;
}


double Cercle::getRayon() const
{
    return m_rayon;
}


bool Cercle::estDansLeCercle(const Point& P) const
{
    if (sqrt(P.getCoordonneeX() * P.getCoordonneeX() + P.getCoordonneeY() * P.getCoordonneeY()) < m_rayon )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


double Cercle::calcPi( int n) const
{
    double pi(0);

    int count(0);   /*!< Compteur*/

    unsigned int germe = chrono::system_clock::now().time_since_epoch().count(); /*!< Germe pour initialiser le générateur*/
    mt19937_64 gen(germe); /*!< Générateur de Mersenne initialiser avec notre germe*/

    uniform_real_distribution<double> distrib;


    for (int i=0; i<n; i++) /*!< Pour n nbre itérations, on vérifie si le point générée aléatoirement est dans le cercle*/
    {
        Point P((distrib(gen)-0.5)*2*getRayon() + getCentre().getCoordonneeX(),
 		(distrib(gen)-0.5)*2*getRayon() + getCentre().getCoordonneeY());

        if (estDansLeCercle(P))
        {
            count++;  /*!< S'il est dans le cercle, incrémentation du compteur*/
        }
    }

    pi = (double)((4.0 * count) / n); /*!< Calcul de pi: nbre de point à l'intérieur du cercle sur total du nbre de point générée, le tout fois 4*/
    return pi;
}


void Cercle::drawPi(string path, int n) const
{


    /*!< Ouverture d'un flux vers fichier*/
    ofstream monFichier(path.c_str(),  ios::trunc | ios::ate);

    /*!< Le fichier est il bien ouvert? */
    if(!monFichier) // Non, erreur
    {
        throw Error(1, "Error : Cannot create .eps file! \n");
    }
    else // Oui, on effectue les manipulations
    {
        /*!< Création de l'entête du fichier .eps*/
        monFichier << "%!PS-Adobe-2.0 EPSF-2.0" << endl;

        monFichier << "%%BoundingBox: " 	<< getCentre().getCoordonneeX() - getRayon() - getRayon()/5 << " "
                   << getCentre().getCoordonneeY() - getRayon() - getRayon()/5 << " "
                   << getCentre().getCoordonneeX() + getRayon() + getRayon()/5 << " "
                   << getCentre().getCoordonneeY() + getRayon() + getRayon()/5 << endl << endl;

        monFichier << "%%EndComments" << endl ;

        /*!< Une croix, description*/
        monFichier << "/cross { moveto -2 -2 rmoveto 4 4 rlineto -4 0 rmoveto 4 -4 rlineto stroke } def" << endl << endl ;

        /*!< Tracé du carré*/
        monFichier 	<< getCentre().getCoordonneeX() << " " << getCentre().getCoordonneeY() << " translate "
                    << -getRayon() << " "
                    << -getRayon() << " "
                    << getRayon()*2 << " " << getRayon()*2  << " rectstroke" << endl << endl ;

        /*!< Tracé du cercle*/
        monFichier << "1 1 0 setrgbcolor" << endl ;
        monFichier << "0 0 " << getRayon() << " 0 360 arc stroke" << endl  ;

        double pi(0);

        int count(0);   /*!< Compteur*/

        unsigned int germe = chrono::system_clock::now().time_since_epoch().count(); /*!< Germe pour initialiser le générateur*/
        mt19937_64 gen(germe); /*!< Générateur de Mersenne initialiser avec notre germe*/

        uniform_real_distribution<double> distrib;


        for (int i=0; i<n; i++) /*!< Pour n nbre itérations, on vérifie si le point générée aléatoirement est dans le cercle*/
        {
		/*!< Génération d'un point aléatoirement*/
            Point P( (distrib(gen)-0.5)*2*getRayon() + getCentre().getCoordonneeX(),
                     (distrib(gen)-0.5)*2*getRayon() + getCentre().getCoordonneeY() );

            if (estDansLeCercle(P))
            {
		/*!< S'il est dans le cercle, incrémentation du compteur + coloration*/
                count++;  
                monFichier << "1 1 0 setrgbcolor" << endl;
            }
            else
            {
                monFichier << "0 0 0 setrgbcolor" << endl;
            }
            monFichier << P.getCoordonneeX() << " " << P.getCoordonneeY();
            monFichier << " cross" << endl;
        }


        monFichier << "0 setgray /Symbol " << getRayon()/5 << " selectfont " << getCentre().getCoordonneeX() << " " << getCentre().getCoordonneeY() << " moveto (p " << "\\" << "273 ) show" << endl;

        monFichier << "(" << (double)((4.0 * count) / n) << ") show" << endl;
    }
    monFichier.close(); //Fermeture du fichier

}



Cercle::~Cercle()
{
}

ostream& operator<<(ostream& flux, const Cercle& C)
{

    flux << "Le centre du cercle est localisé au point (x,y) :\t" << C.m_centre;
    flux << "Le rayon du cercle est de :\t" << C.m_rayon << endl;
    return flux;
}
