#ifndef DEF_COURBELIN_H
#define DEF_COURBELIN_H

/**
 * @file CourbeLin.h
 * @brief A specialization of Courbe class into a linear curve
 * @author LasceteSohei
 * @version 0.1
 */
#include <iostream>
#include <cmath>

#include "Courbe.h"
#include "Point.h"

/**
* @class CourbeLin
* @brief A class representing a linear curve.
*/
class CourbeLin : public Courbe
{
public:

    /**
    * @brief Default constructor of CourbeLin class.
    */
    CourbeLin();


    /**
    * @brief A method to calculate all the points used for the linear approximation of the curve.
    */
    std::vector<Point> calcQ(const double precisionParam) const;


    /**
    * @brief Default destructor of CourbeLin class.
    */
    ~CourbeLin();


};




#endif
