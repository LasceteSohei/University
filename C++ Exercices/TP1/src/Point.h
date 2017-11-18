#ifndef DEF_POINT
#define DEF_POINT

/**
 * @file Point.h
 * @brief A point with 2 coodinates
 * @author LasceteSohei
 * @version 0.1
 */

#include <iostream>
#include <stdio.h>

/**
* @class Point
* @brief A class representing a 2 coordinates point.
*/
class Point
{
public:
    /**
    * @brief Default constructor of Point class.
    */
    Point();

    /**
    * @brief Constructor of Point class.
    * @param x the coordinate in the X-axis.
    * @param y the coordinate in the Y-axis.
    */
    Point(double x, double y);

    /**
    * @brief Cloner constructor.
    * @param P the Point you want to clone.
    */
    Point(const Point& P);

    /**
    * @brief A getter for  the x-coordinate of the point.
    */
    double getCoordonneeX() const;

    /**
    * @brief A getter for  the y-coordinate of the point.
    */
    double getCoordonneeY() const;

    /**
    * @brief Operator ' += ' overload to add a Point to the current Point.
    */
    Point& operator+=(const Point& P);

    /**
    * @brief Operator ' += ' overload to multiply a double to the current Point.
    */
    Point& operator*=(const double& a);


    /**
    * @brief Operator ' >> ' overload.
    */
    friend std::istream& operator>>(std::istream& flux, Point& P);

    /**
    * @brief Operator ' << ' overload.
    */
    friend std::ostream& operator<<(std::ostream& flux, const Point& P);

    /**
    * @brief Default destructor.
    */
    ~Point();


private:

    double m_x; /*!< x coordinate of the point*/
    double m_y; /*!< y coordinate of the point*/

};

/**
* @brief Operator ' + ' overload in order to add easily 2 points.
*/
Point operator+(Point const &a, Point const &b);

/**
* @brief Operator ' * ' overload in order to multiply a double to a Point.
*/
Point operator*(Point const &a, double const &b);

#endif
