#ifndef DEF_COURBESCR_H
#define DEF_COURBESCR_H

/**
 * @file CourbeSCR.h
 * @brief A specialization of Courbe class into a Catmull-Rom curve
 * @author LasceteSohei
 * @version 0.1
 */

#include <iostream>
#include <cmath>

#include "Courbe.h"
#include "Point.h"


class CourbeSCR : public Courbe
{
public:

    /**
    * @brief Default constructor of CourbeSCR class.
    */
    CourbeSCR();

    /**
    * @brief Cloner constructor.
    * @param C the curve you want to clone.
    */
    CourbeSCR(const CourbeSCR& C);

    /**
    * @brief Operator '=' overload.
    */
    CourbeSCR& operator=(const CourbeSCR& C);


    /**
    * @brief Setter for the tension parameter of the curve.
    */
    void setTension(double _tension);


    /**
    * @brief Getter for the tension parameter of the curve.
    */
    double getTension(void) const;


    /**
    * @brief A method to calculate all the points used for the CR approximation of the curve.
    */
    std::vector<Point> calcQ(const double precisionParam) const;


    /**
    * @brief A method to calculate CR matrix product.
    */
    Point calcMatriceCR(int j, double i) const;


    /**
    * @brief Default destructor of CourbeSCR class.
    */
    ~CourbeSCR();

private:
    double m_tension; /*!< 	A low tension parameter will give a loose curve, whereas a high tension parameter will result
				  	in a more rigid curve*/

};




#endif
