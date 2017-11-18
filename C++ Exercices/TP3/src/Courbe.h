#ifndef DEF_COURBE_H
#define DEF_COURBE_H

/**
 * @file Courbe.h
 * @brief A basic curve
 * @author LasceteSohei
 * @version 0.1
 */

#include <iostream>
#include <vector>

#include "Point.h"

/**
* @class Courbe
* @brief A class representing a curve composed of multiple points.
*/
class Courbe
{
public:

    /**
    * @brief Default constructor of curve class.
    */
    Courbe();

    /**
    * @brief Cloner constructor.
    * @param C the curve you want to clone.
    */
    Courbe(const Courbe& C);

    /**
    * @brief Operator '=' overload.
    */
    Courbe& operator=(const Courbe& C);

    /**
    * @brief A method to initialize your curve class by giving manually all the points.
    */
    void initCourbe();

    /**
    * @brief Adding a Point to the curve
    * @param P the Point you want to add to your curve.
    */
    void addPoint(const Point& P);

    /**
    * @brief Adding multiple Point manually to the curve.
    */
    void addMPoint();

    /**
    * @brief Getter of the m_pointsCourbe member.
    * @return A vector containing all the Point of the curve.
    */
    std::vector<Point> getPointCourbe() const;

    /**
    * @brief Getter of the m_paramT member.
    * @return A vector containing all the doubles representing the parametric position for each Point of the curve.
    */
    std::vector<double> getParamT() const;


    /**
    * @brief  A method to calculate the U between two points of a curve (segment).
    */
    double calcU(int pos, double t) const;

    /**
    * @brief A method to calculate all the points for the approximation of the curve.
    * @return std::vector<Point> a vector with all the interpolated points making our curve.
    */
    virtual std::vector<Point> calcQ(const double precisionParam) const = 0; // Fonction virtuelle pure, donc classe abstraite


    /**
    * @brief Default destructor of Courbe.
    */
    virtual ~Courbe();

    /**
    * @brief Operator ' << ' overload.
    */
    friend std::ostream& operator<<(std::ostream& flux, const Courbe& C);

protected:

    std::vector<Point> m_pointsCourbe;  	/*!< A vector containing all the critic points within the curve*/
    std::vector<double> m_paramT;		/*!< A vector containing all the parametric position of the points within the curve*/

};

#endif
