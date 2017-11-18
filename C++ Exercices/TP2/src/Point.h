#ifndef DEF_POINT
#define DEF_POINT

/**
 * @file Point.h
 * @brief A point with 3 coodinates
 * @author LasceteSohei
 * @version 0.1
 */

#include <iostream>
#include <stdio.h>

/**
* @class Point
* @brief A class representing a 3 coordinates point.
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
    * @param z the coordinate in the Z-axis.
    */
    Point(double x, double y, double z);

    /**
    * @brief A getter for  the x-coordinate of the point.
    */
    double getCoordonneeX() const;

    /**
    * @brief A getter for  the y-coordinate of the point.
    */
    double getCoordonneeY() const;

    /**
    * @brief A getter for  the z-coordinate of the point.
    */
    double getCoordonneeZ() const;

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
    double m_z; /*!< z coordinate of the point*/
};


#endif
