/**
 * @file main.cpp
 * @brief Main function of our application.
 * @author LasceteSohei
 * @version 0.1
 */
#include <iostream>
#include<string>

#include"Point.h"
#include "Polygone.h"
#include "Vec3.h"


using namespace std;

int main()
{
    Polygone poly(5);

    Point P2(-100,0,0);
    Point P3(-100,-100,0);
    Point P4(0,0,0);
    Point P1(0,100,0);

    poly.ajouterPoint(P1);
    poly.ajouterPoint(P2);
    poly.ajouterPoint(P3);
    poly.ajouterPoint(P4);

    double aire(poly.calculerAire());
    cout << poly << endl;
    cout << aire << endl;
    return 0;
}
