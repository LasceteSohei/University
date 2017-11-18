#ifndef DEF_COURBEBEZI_H
#define DEF_COURBEBEZI_H

// Courbe de Bézier

#include <iostream>
#include <cmath>

#include "Courbe.h"
#include "Point.h"

class CourbeBezi : public Courbe
{
public:

    /**
    * @brief Default constructor of CourbeBezi class.
    */
    CourbeBezi();

    /**
    * @brief A method to initialize your curve class by giving manually all the points.
    */
    void initCourbe();


    /**
    * @brief A method to calculate all the points used for the Bezier approximation of the curve.
    */
    std::vector<Point> calcQ(const double precisionParam) const;


    /**
    * @brief Default destructor of CourbeSCR class.
    */
    ~CourbeBezi();

};




#endif
