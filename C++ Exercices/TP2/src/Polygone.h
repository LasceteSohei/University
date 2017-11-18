#ifndef DEF_POLYGONE
#define DEF_POLYGONE
/**
 * @file Polygone.h
 * @brief A polygon class.
 * @author LasceteSohei
 * @version 0.1
 */

#include <iostream>
#include <vector>
#include "Point.h"
#include "Vec3.h"
#include <cmath>

/**
* @class Polygone
* @brief A polygon and his caracteristics.
*/
class Polygone
{

public:
    /**
    * @brief Default constructor of Polygone class.
    */
    Polygone();
    /**
    * @brief Constructor of Polygone class.
    * @param nbrePoints the number of points in the polygon.
    */
    Polygone(int nbrePoints);

    /**
    * @brief A method to add one point to the polygon.
    * @param P a reference to a Point object.
    */
    void ajouterPoint(const Point& P);

    /**
    * @brief A method to add many points to the polygon through the terminal.
    * @param nbrePoints the number of points you want to add to the polygon.
    */
    void ajouterMPoint(int nbrePoints);

    /**
    * @brief A method to calculate the area of the polygon.
    */
    double calculerAire() const;

    /**
    * @brief Operator ' << ' overload.
    */
    friend std::ostream& operator<<(std::ostream& flux, const Polygone& P);

    /**
    * @brief Default destructor.
    */
    ~Polygone();

private:

    std::vector <Point> m_pointsPoly; /*!< A vector of point representing the polygon*/

};






#endif
