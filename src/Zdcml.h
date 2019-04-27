/*
 *
 * M. laroche jean Pierre  12-10-1951    laroche.jeanpierre@gmail.com
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 */

#ifndef ZDCML_HPP_INCLUDED
#define ZDCML_HPP_INCLUDED


#include <cmath>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
#include <malloc.h>

#include <errno.h>
#include <ostream>
#include <iostream>
#include <sstream>
#include <cfloat>
#include <string>
#include <limits.h>
#include <exception>
#include <locale>
#include <limits>
#include <stdarg.h>                 /// For va_start, etc.
 

#define  DECDIGIT 34 				/// work with max 34 digit

#define  DECBUFFER DECDIGIT+2 		/// work with max digit and signe and ponct

#define  DECNUMDIGITS 128


#include <decNumber.h>


/// pas de setlocale please  p_mask[pos] ='.'  compatibilité avec decNumber (IBM)
namespace ZONED
{

#include <Zcomon.h>



class Zdcml
{
private:
    decNumber  *_dcml;       /// Un nombre décimal est un nombre possédant un développement décimal limité 34 chiffres

protected:
///decNumber---------------------------------------------------------------------
    decContext  	T_set;

    unsigned int 	CMP;
    std::string		CPFMSG;				/// flag msg error
///LONGEUR MAXIMUN DU BUFFER ----------------------------------------------------
    unsigned int 	_entier;
    unsigned int 	_dec;

///Zone de travail---------- ----------------------------------------------------
    decNumber  *T_dcml;					/// Zone de travail
    decNumber  *C_dcml;					/// Zone de travail


	std::string		_STRING_ ;			/// string travail
	char * 			T_char ;			/// decNumberToString
    char * 			T_string ;			/// decNumberToString
    char * p_mask, *n_mask ;			/// mask pour contrôle overlay


/// FONCTIONS UTILE--------- ---------------------------------------------------

	void ClearBufferDcml();				/// T_dcml C_dcml

	char* ZDoubleToChar(double _X_ ,unsigned _precision_);
	
	void printformat();					/// formate et tronque selon la definition

	std::string string_format(const std::string fmt, ...);	/// Format String--idem sprintf
///=============================================================================
public:
    bool 		CPFERR ;				/// flag msg error
///CONSTRUCTEURS ----------------------------------------------------------------

Zdcml(unsigned int  ,unsigned int   );

~Zdcml();


	Zdcml& operator=(const int);
	Zdcml& operator=(const long int);
	Zdcml& operator=(const double);
	Zdcml& operator=(const char*);
	Zdcml& operator=(std::string );
	Zdcml& operator=(const Zdcml  X_dcml);

//OPERATEURS ARITHMETIQUES EXTERNES --------------------------------------------
Zdcml& operator+=(const  int);
Zdcml& operator-=(const  int);
Zdcml& operator*=(const  int);
Zdcml& operator/=(const  int);
Zdcml& operator%=(const  int);

Zdcml& operator+=(const long int);
Zdcml& operator-=(const long int);
Zdcml& operator*=(const long int);
Zdcml& operator/=(const long int);
Zdcml& operator%=(const long int);


Zdcml& operator+=(const double);
Zdcml& operator-=(const double);
Zdcml& operator*=(const double);
Zdcml& operator/=(const double);
Zdcml& operator%=(const double);

Zdcml& operator++(int);  /// plus 1
Zdcml& operator--(int);  /// moin 1
Zdcml& operator+=(const Zdcml);
Zdcml& operator-=(const Zdcml);
Zdcml& operator*=(const Zdcml);
Zdcml& operator/=(const Zdcml);
Zdcml& operator%=(const Zdcml);


///OPERATEURS DE COMPARAISON------------------------------
bool operator==(const int);
bool operator<(const int);
bool operator>(const int);
bool operator<=(const int);
bool operator>=(const int);
bool operator!=(const int);
unsigned int cmp(const int);

bool operator==(const long int);
bool operator<(const long int);
bool operator>(const long int);
bool operator<=(const long int);
bool operator>=(const long int);
bool operator!=(const long int);
unsigned int cmp(const long int);

bool operator==(const double);
bool operator<(const double);
bool operator>(const double);
bool operator<=(const double);
bool operator>=(const double);
bool operator!=(const double);
unsigned int cmp(const double);


bool operator==(const Zdcml);
bool operator<(const Zdcml);
bool operator>(const Zdcml);
bool operator<=(const Zdcml);
bool operator>=(const Zdcml);
bool operator!=(const Zdcml);
unsigned int cmp(const Zdcml);


/// FONCTIONS OUTPUT ---return VAL-------------------------
	char*           Chr();							/// format text limit def ex: a(10,5); 1234567890.12345  nbr digit = 15
	const char*     ConstChr();						/// idem Chr
	std::string     Str();							/// idem Chr
	std::string     Edt();							/// edit local punct
/// FONCTION Contrôle Type --------------------------------------
	bool isZeros();      							/// contrôle ZEROS
	bool isNegative();   							/// contrôle IsNegative

	bool CheckOverflow();            				/// contrôle valeur def tampon

///****************************************************************************
/// FONCTIONS util  --------------------------------------------------------
///****************************************************************************
	const char* cerror();							/// text flag error
	int		clen();									/// longueur maxi du champ 
	int		centier();								/// longueur maxi precision 
	int		cdec();									/// longueur maxi scale
	


	friend std::istream& operator>>(std::istream& is,  Zdcml& t)
	{
		std::string _var_ ;
		is >> _var_ ;
		t = _var_;
		return is;
	}

	friend std::ostream& operator<<(std::ostream& out, const Zdcml t)	// out only ponct . use sql or cout 
	{   char *  _C_ = (char*) malloc(DECBUFFER  * sizeof(char*)); decNumberToString(t._dcml, _C_);
		std::string _STRING_ = _C_;
		return out << _STRING_;
	}

};

}


#endif
