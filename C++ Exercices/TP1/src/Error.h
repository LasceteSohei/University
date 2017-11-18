#ifndef DEF_ERROR_H
#define DEF_ERROR_H

/**
 * @file Error.h
 * @brief An error.
 * @author LasceteSohei
 * @version 0.1
 */

#include <exception>
#include <string>

/**
* @class Error
* @brief A customized class which goal is to report problems.
*/
class Error : public std::exception
{

public:

    /**
    * @brief Default constructor of Error class.
    */
    Error(int numero=0, std::string phrase = "", int niveau = 0) throw() ;

    /**
    * @brief Overload of what() method.
    * @return A string with the issue inside.
    */
    virtual const char* what() const throw();

    /**
    * @brief Getter of m_niveau.
    * @return An integer with the value inside.
    */
    int getNiveau() const throw();

    /**
    * @brief Default destructor of Error class.
    */
    ~Error() throw();


private:
    int m_numero;		/*!< Numéro de l'erreur*/
    std::string m_phrase;	/*!< Description de l'erreur*/
    int m_niveau; 		/*!< Niveau de l'erreur*/


};











#endif
