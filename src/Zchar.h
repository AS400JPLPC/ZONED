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
#ifndef ZCHAR_H_INCLUDED
#define ZCHAR_H_INCLUDED

#include <stdio.h>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
#include <malloc.h>
#include <string>
 
#include <algorithm>

#include <cstddef>
#include <cstring>
#include <iostream>
#include <exception>
#include <typeinfo>
#include <stdarg.h>                 /// For va_start, etc.

namespace ZONED
{
	
#include <Zcomon.h>


class Zchar                             /// buffer tampon zone à structure défini
{
private:
    std::string P_buffer="";            /// pointer to strorage
    std::string val = "";            	/// pointer to strorage
    size_t _length =0;                  /// _length
	void resize();
	std::string _name_ ;				/// name of vairable
    std::string	CPFMSG="";				/// flag msg error 
//STATUS -----------------------------------------------------------------------
    unsigned int  CMP;               	/// EQ -- LT -- GT 	

protected :
    Zchar   strtrim();


public:

	bool 	CPFERR	= false;	/// flag si erreur
	Zchar();
    Zchar(size_t i);
    ~Zchar();

///****************************************************************************
///AFFECTATION BUFFER       ---------------------------------------------------
///**************************************************************************** 

	char*         ToChar();
	const char*   ConstChar();
	std::string   StringChar();

	Zchar operator=(const Zchar);
	Zchar operator+=(const Zchar);

	Zchar operator=(const char*);
	Zchar operator+=(const char*);

	Zchar operator=(std::string);
	Zchar operator+=(std::string);

	Zchar           concat(const std::string fmt, ...);                                       // Concat from string
	Zchar           clear();

///  substring
	Zchar           Replace(const char*  scrut ,const char * );
	Zchar           Replace(const char*  scrut ,std::string  );
	Zchar           Movel(const char*   src);
	Zchar           Movel(const Zchar);
	Zchar			ToUper();
	Zchar			ToLower();
	Zchar           Extrac(const char*   src   ,size_t , size_t );
	Zchar           Extrac(const Zchar         ,size_t , size_t );
	Zchar           strtrim(const Zchar );
	char *          ExtracToChar(size_t , size_t );
///****************************************************************************
/// FONCTIONS UTILE--------- --------------------------------------------------
///****************************************************************************
	void 	name( const char*);
	int		cfind( const char*);
	int		sfind( std::string);
	int		deflen();
	int		clen();

///****************************************************************************
/// FONCTIONS operateur--------------------------------------------------------
///****************************************************************************

	bool operator!=( const char* );
	bool operator==( const char* );

	bool operator<(  const char*  );
	bool operator>(  const char*  );
	bool operator<=( const char*  );
	bool operator>=( const char*  );
	unsigned   int cmp( const char* );



	bool operator!=( std::string );
	bool operator==( std::string );

	bool operator<(  std::string  );
	bool operator>(  std::string  );
	bool operator<=( std::string  );
	bool operator>=( std::string  );

	unsigned   int cmp( std::string );

	bool operator!=( Zchar );
	bool operator==( Zchar );

	bool operator<(  Zchar  );
	bool operator>(  Zchar  );
	bool operator<=( Zchar  );
	bool operator>=( Zchar  );

	unsigned   int  cmp( Zchar );


///****************************************************************************
/// FONCTIONS util     --------------------------------------------------------
///****************************************************************************
	const char* cerror();
	
	friend std::istream& operator>>(std::istream& is,  Zchar& t)
	{
		std::string _var_ ;
		is >> _var_ ;
		for (size_t i = 0; i < _var_.size(); ++i)
			{
				if (_var_[i] == DeLiMiTaTioN)
				{
				_var_[i] = ' ';
				}
			}
		t = _var_;
		return is;
	}
	
	friend std::ostream& operator<<(std::ostream& out, const Zchar& t)
	{
		return out << t.P_buffer;
	}
};



}
#endif // Zchar_H_INCLUDED
