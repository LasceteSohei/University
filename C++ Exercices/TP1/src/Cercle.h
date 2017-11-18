#ifndef DEF_CERCLE
#define DEF_CERCLE

/**
 * @file Cercle.h
 * @brief A circle with a central point and a radius.
 * @author LasceteSohei
 * @version 0.1
 */

#include <chrono>
#include <iostream>
#include <random>
#include <stdio.h>
#include <fstream>

#include "Point.h"
#include "Error.h"

/**
* @class Cercle
* @brief A class representing a simple circle.
*/
class Cercle
{
public:
    /**
    * @brief Default constructor of Cercle class.
    */
    Cercle();

    /**
    * @brief Cloner constructor.
    * @param C the Cercle you want to clone.
    */
    Cercle(const Cercle& C);

    /**
    * @brief Constructor of Cercle class.
    * @param P the center of the circle.
    * @param rayon the radius of the circle
    */
    Cercle(const Point& P, double rayon);

    /**
    * @brief  A getter of the center of the circle.
    * @return Point with the coordinate of the center.
    */
    Point getCentre() const;

    /**
    * @brief  A getter of the radius of the circle.
    * @return Double with the radius of the circle.
    */
    double getRayon() const;


    /**
    * @brief  A method to know if a Point is inside the circle
    * @param  P the point.
    * @return A boolean with the answer.
    */
    bool estDansLeCercle(const Point& P) const;

    /**
    * @brief  A method to calculate pi.
    * @return A double containing the result.
    */
    double calcPi(int n = 100000) const;

    /**
    * @brief  A method to draw pi, our circle and the random generated points into an eps file.
    * @param  path a string containing the path to the file you want to write in. 
    */
    void drawPi(std::string path = "draw.eps", int n = 1000)const;

    /**
    * @brief  Default destructor of the Cercle class.
    */
    ~Cercle();

    /**
    * @brief Operator ' << ' overload.
    */
    friend std::ostream& operator<<(std::ostream& flux, const Cercle& C);

private:
    Point m_centre; /*!< The center of the circle*/
    double m_rayon; /*!< The radius of the circle*/

};

#endif
