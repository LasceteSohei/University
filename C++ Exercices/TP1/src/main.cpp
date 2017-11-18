/**
 * @file main.cpp
 * @brief Main function of our application.
 * @author LasceteSohei
 * @version 0.1
 */
#include <iostream>
#include "Cercle.h"
#include "Point.h"
#include "Error.h"

using namespace std;


int main()
{
    /*!< Creating a circle*/
    Cercle C;
    /*!< Showing defaults settings*/
    cout << endl << "PAR DEFAUT :" << endl << C << endl << endl;
    /*!< Marker to loop our programm*/
    bool leave(1);
while(leave)
{
/*!< Menu of choices*/
cout << "\t\tMENU" << endl;
cout << "Pour calculer pi avec paramètres par défaut, tapez 1" << endl;
cout << "Pour dessiner le calcul avec paramètres par défaut, tapez 2" << endl;
cout << "Pour calculer pi avec vos paramètres, tapez 3" << endl;
cout << "Pour dessiner le calcul avec vos paramètres, tapez 4" << endl;
cout << "Pour voir les paramètres par défaut, tapez d" << endl;
cout << "Pour quitter le programme, tapez q" << endl;
char choix;
cin >> choix;

switch(choix)
{
	case '1':{
    /*!< Creating a circle*/
    Cercle C;
    /*!< Calculating pi with our circle*/
    double pi = C.calcPi();
    /*!< Displaying result*/
    cout << "Pi est : " << pi << endl;
    break;}

	case '2':{
    /*!< Creating a circle*/
    Cercle C;
    /*!< Trying the dangerous section*/
    try
    {
        C.drawPi();
    }
    catch(exception const& e)
    {
       cout << e.what();
    }
    break;}

	case '3':{
	double x,y,rayon;
    /*!< Point ? Radius?*/
    cout << "x : ";
    cin >> x;
    cout << "y : ";
    cin >> y;
    cout << "rayon : ";
    cin >> rayon;
    /*!< Creating a circle*/
    Cercle C(Point(x,y), rayon);
    /*!< Calculating pi with our circle*/
    double pi = C.calcPi();
    /*!< Displaying result*/
    cout << "Pi est : " << pi << endl;
    break;}

	case '4':{
	double x,y,rayon;
    /*!< Point ? Radius?*/
    cout << "x : ";
    cin >> x;
    cout << "y : ";
    cin >> y;
    cout << "rayon : ";
    cin >> rayon;
    /*!< Creating a circle*/
    Cercle C(Point(x,y), rayon);
    /*!< Trying the dangerous section*/
    try
    {
        C.drawPi();
    }
    catch(exception const& e)
    {
       cout << e.what();
    }
    break;}

   	case 'd':{
    /*!< Creating a circle*/
    Cercle C;
    /*!< Showing defaults settings*/
    cout << endl << "PAR DEFAUT :" << endl << C << endl << endl;
    break;
    }

	case 'q':{
    leave = false;
    break;}

	default:
    cout << "Ceci n'est pas un choix." << endl;
    break;
}
}

    return 0;
}

