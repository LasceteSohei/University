#include "Error.h"
using namespace std;


Error::Error(int numero, string phrase , int niveau ) throw() : 	m_numero(numero),
    m_phrase(phrase),
    m_niveau(niveau)
{}


const char* Error::what() const throw()
{
    return m_phrase.c_str();
}


int Error::getNiveau() const throw()
{
    return m_niveau;
}


Error::~Error() throw() 
{}

