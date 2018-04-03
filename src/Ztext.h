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

#ifndef ZTEXT_H_INCLUDED
#define ZTEXT_H_INCLUDED


#include <stdio.h>
#include <cstring>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <exception>

namespace ZONED
{
	
#include <Zcomon.h>



class Ztext 
{
    private :
	std::string P_buffer;
	bool   ___obligatoire___ ;
///****************************************************************************
///AFFECTATION BUFFER       ---------------------------------------------------
///****************************************************************************

    public :
        Ztext();																/// comprendre cela  comme un string 
        ~Ztext();																/// pour travailler avec SQL

char*         ToChar();
const char*   ConstChar();
std::string   StringChar();


 Ztext operator=(const char* );
 Ztext operator=(std::string );

///****************************************************************************
/// FONCTIONS util  --------------------------------------------------------
///****************************************************************************
	int		clen();

	friend std::istream& operator>>(std::istream& is,  Ztext& t)
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
        

	friend std::ostream& operator<<(std::ostream& out, const Ztext& t) {
			return out << t.P_buffer;
	}

    
};
}
#endif
