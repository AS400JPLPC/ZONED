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

#ifndef ZBOOL_H_INCLUDED
#define ZBOOL_H_INCLUDED


#include <stdio.h>
#include <cstring>
#include <cstdio>

#include <iostream>
#include <exception>
 


namespace ZONED
{

#include <Zcomon.h>




class Zbool {

private:

    bool P_buffer;                  /// pointer to strorage

	std::string	CPFMSG;			/// flag msg error 
protected:

public:
	bool 	CPFERR	= false;	/// flag si erreur

	Zbool();
	~Zbool();


///****************************************************************************
///AFFECTATION BUFFER       ---------------------------------------------------
///****************************************************************************


	char*         Chr();
	const char*   ConstChr();
	std::string   Str();

	Zbool operator=(const bool ) ;
	Zbool operator=(const char * );
	Zbool operator=(std:: string );
	Zbool operator=(const Zbool);
	Zbool operator=(const int);
	    
	bool operator==(bool );
	bool operator!=(bool );    
	bool operator==(const Zbool );
	bool operator!=(const Zbool);
///****************************************************************************
/// FONCTIONS util     --------------------------------------------------------
///****************************************************************************
	const char* cerror();
	friend std::istream& operator>>(std::istream& is,  Zbool& t)
	{
		std::string _var_ ;
		is >> _var_ ;
		t = _var_;
		return is;
	}

	friend std::ostream& operator<<(std::ostream& out, const Zbool& t)
	{
		return out << t.P_buffer;
	}
};
}
#endif
