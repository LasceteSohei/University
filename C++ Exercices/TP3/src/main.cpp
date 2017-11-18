#include <iostream>
#include <algorithm>
#include <fstream>

#include "Courbe.h"
#include "Point.h"
#include "CourbeLin.h"
#include "CourbeSCR.h"
#include "CourbeBezi.h"

using namespace std;


void draw(const Courbe& C, double precision = 0.1, string path = "draw.eps");



int main()
{

    /*!< Marker to loop our programm*/
    bool leave(1);

    while(leave)
    {
        /*!< Menu of choices*/
        cout << "\t\tMENU" << endl;
        cout << "Dessiner une courbe linéaire, tapez 1" << endl;
        cout << "Dessiner une courbe de Catmull-Rom, tapez 2" << endl;
        cout << "Dessiner une courbe de Bézier, tapez 3" << endl;
        cout << "Pour quitter le programme, tapez q" << endl;
        char choix;
        cin >> choix;

        switch(choix)
        {
        case '1':
        {
            CourbeLin C;
            C.initCourbe();
            cout << C;

            double precision;
            cout << "Quelle précision paramétrique?" << endl;
            cin >> precision;

            cout << "Nom par défaut (y/n): " << endl;
            cin >> choix;

            if(choix == 'y')
                draw(C, precision, "drawLin.eps");
            else
            {
                string path;
                cin >> path;
                draw(C, precision, path);
            }

            break;
        }

        case '2':
        {

            CourbeSCR C;
            C.initCourbe();
            cout << C;
            double precision;
            cout << "Quelle précision paramétrique?" << endl;
            cin >> precision;

            cout << "Tension par défaut (y/n): " << endl;
            cin >> choix;


            if(choix == 'n')
	     {
	        double _tension(0);
                cin >> _tension;
		C.setTension(_tension);
	     }
            cout << "Nom par défaut (y/n): " << endl;
            cin >> choix;

            if(choix == 'y')
                draw(C, precision, "drawSCR.eps");
            else
            {
                string path;
                cin >> path;
                draw(C, precision, path);
            }

            break;
        }

        case '3':
        {

            CourbeBezi C;
            C.initCourbe();
            cout << C;
            double precision;
            cout << "Quelle précision paramétrique?" << endl;
            cin >> precision;

            cout << "Nom par défaut (y/n): " << endl;
            cin >> choix;

            if(choix == 'y')
                draw(C, precision, "drawBezier.eps");
            else
            {
                string path;
                cin >> path;
                draw(C, precision, path);
            }

            break;
        }

        case 'q':
        {
            leave = false;
            break;
        }

        default:
            cout << "Ceci n'est pas un choix." << endl;
            break;
        }





    }

    return 0;
}



/**
* @brief Draw a curve.
*
* @param Courbe a reference to the curve you want to draw.
* @param precision the parametrical precision used to interpolate points.
* @param path the destination of the resulting eps file.
*
*/
void draw(const Courbe& C, double precision, string path)
{


    /*!< Calcul de notre courbe*/
    auto pSegQ = C.calcQ(precision);

    /*!< Point max en x*/
    auto max_X = max_element(pSegQ.begin(), pSegQ.end(),[]( const Point &a, const Point &b )
    {
        return  (a.getCoordonneeX() <= b.getCoordonneeX());
    } );
    /*!< Point max en y*/
    auto max_Y = max_element(pSegQ.begin(), pSegQ.end(),[]( const Point &a, const Point &b )
    {
        return (a.getCoordonneeY() <= b.getCoordonneeY()) ;
    } );

    /*!< Point min en x*/
    auto min_X = min_element(pSegQ.begin(), pSegQ.end(),[]( const Point &a, const Point &b )
    {
        return  (a.getCoordonneeX() <= b.getCoordonneeX());
    } );
    /*!< Point min en y*/
    auto min_Y = min_element(pSegQ.begin(), pSegQ.end(),[]( const Point &a, const Point &b )
    {
        return (a.getCoordonneeY() <= b.getCoordonneeY()) ;
    } );

    /*!< Ouverture d'un flux vers fichier*/
    ofstream monFichier(path.c_str(),  ios::trunc | ios::ate);

    /*!< Le fichier est il bien ouvert? */
    if(!monFichier) // Non, erreur
    {
        throw printf("Error : Cannot create .eps file! \n");
    }
    else // Oui, on effectue les manipulations
    {
        /*!< Création de l'entête du fichier .eps*/
        monFichier << "%!PS-Adobe-2.0 EPSF-2.0" << endl;

        monFichier << "%%BoundingBox: "
                   << min_X->getCoordonneeX()-10 << " "
                   << min_Y->getCoordonneeY()-10 << " "
                   << max_X->getCoordonneeX()+10 << " "
                   << max_Y->getCoordonneeY()+10 << endl << endl;

        monFichier << "%%EndComments" << endl ;
        monFichier << "/Times 12 selectfont" << endl;
        monFichier << pSegQ[0].getCoordonneeX() << " " << pSegQ[0].getCoordonneeY() << " moveto" << endl;

        for(auto it : pSegQ)
        {
            monFichier << it.getCoordonneeX() << " " << it.getCoordonneeY() << " lineto" << endl;
            cout << it.getCoordonneeX() << " " << it.getCoordonneeY() << endl;
        }

        monFichier << "stroke" << endl;

    }
    monFichier.close();
}

