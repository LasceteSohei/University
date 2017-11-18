#ifndef DEF_VEC3
#define DEF_VEC3

/**
 * @file Vec3.h
 * @brief A vector with 3 coodinates
 * @author LasceteSohei
 * @version 0.1
 */

#include <iostream>
#include <cmath>
#include "Point.h"

/**
* @class Vec3
* @brief A class representing a 3 coordinates vector.
*/
class Vec3
{

public:
    /**
    * @brief Default constructor of Vec3 class.
    */
    Vec3();

    /**
    * @brief Constructor of Vec3 class.
    * @param P1 a point.
    * @param P2 a point.
    */
    Vec3(const Point& P1, const Point& P2);

    /**
    * @brief Cloner of Vec3 class.
    * @param V the vector you want to clone.
    */
    Vec3(const Vec3& V);

    /**
    * @brief Creating a vector from 2 Point
    * @param P1 a point.
    * @param P2 a point.
    */
    void ajouterPtoV3(const Point& P1, const Point& P2);

    /**
    * @brief Vectorial product between two vectors
    * @param v1 a vector.
    * @param v2 a vector.
    * @return The resulting vector.
    */
    Vec3 pVec3(const Vec3& v1, const Vec3& v2) const;

    /**
    * @brief Norm each coordinate of the Vec3
    */
    void normVec3();

    /**
    * @brief Operator ' += ' overload.
    */
    Vec3& operator+=(Vec3 const &a);

    /**
    * @brief A getter for  the x-coordinate of the vector.
    */
    double getCoordonneeX() const;
    /**
    * @brief A getter for  the y-coordinate of the vector.
    */
    double getCoordonneeY() const;
    /**
    * @brief A getter for  the z-coordinate of the vector.
    */
    double getCoordonneeZ() const;

    /**
    * @brief Operator ' << ' overload.
    */
    friend std::ostream& operator<<(std::ostream& flux, const Vec3& V);

    /**
    * @brief Default destructor.
    */
    ~Vec3();

private:
    double m_x; /*!< x coordinate of the vector*/
    double m_y; /*!< y coordinate of the vector*/
    double m_z; /*!< y coordinate of the vector*/
};


/**
* @brief Operator ' * ' overload (doing a vectorial product).
*/
Vec3 operator*(Vec3 const &v1, Vec3 const &v2);

#endif
