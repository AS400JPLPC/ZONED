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
#ifndef ZTEXT_CPP_INCLUDED
#define ZTEXT_CPP_INCLUDED
#include "Ztext.h"
namespace ZONED
{

Ztext::Ztext(){ P_buffer ="";}
Ztext::~Ztext(){ return ;}



Ztext Ztext::operator=(const char * _C_)
{
	P_buffer = _C_;
    return *this;
}


Ztext Ztext::operator=(std::string _S_)
{
	P_buffer = _S_;
    return *this;
}


char*   Ztext::ToChar()
{
    return (char*)P_buffer.c_str();
}


const char *   Ztext::ConstChar()
{
    return (const char *)P_buffer.c_str();
}


std::string    Ztext::StringChar()
{ 
    return P_buffer;
}


int   Ztext::clen()
{
    return  (int) nbrcar(P_buffer);
}


size_t Ztext::nbrcar(const std::string& str)
{
	setlocale (LC_ALL, "");
	const char *_C_ = str.c_str(); 
    const size_t cSize = strlen(_C_)+1;
    
    wchar_t* wc = new wchar_t[cSize];
    mbstowcs (wc, _C_, cSize);
    
    return  wcslen(wc);
}


}
#endif
