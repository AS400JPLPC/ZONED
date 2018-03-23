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
#ifndef Zchar_H_INCLUDED
#define Zchar_H_INCLUDED

#include <stdio.h>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
#include <malloc.h>
#include <string>
#include <cstdarg>

#include <cstddef>
#include <cstring>
#include <iostream>


namespace ZONED
{
#define   ZONED_OK	0  	///  OK
#define   ZONED_BAD	22	///  DCML_NUM_BAD_NUMERIC
#define   ZONED_OVR	33	///  DCML_NUM_OVERFLOW
#define   ZONED_UND	66	///  DCML_NUM_UNDERFLOW
#define   ZONED_DIV	99	///  DCML_NUM_DIVIDE_ZERO

#define   LT       05       ///  inferieur
#define   EQ       10       ///  egal
#define   GT       15       ///  superieur

#define   ___max___ 1024    /// maxi length buffer


class Zchar                             /// buffer tampon zone à structure défini
{
private:
    char* P_buffer;                     /// pointer to strorage


protected :
    bool   ___obligatoire___ ;
    unsigned int I_length;                  // I_length
    unsigned int  CMP;                      // 0 Egal  1 Supérieur  -1 Inférieur
//STATUS -----------------------------------------------------------------------
    unsigned int  MSGERR;
    char *        zmsg;
    Zchar   strtrim();
public:
      Zchar(int i);
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


Zchar           concat(const std::string fmt, ...);                                       // Concat from string
Zchar           reset();

///  substring
Zchar           Replace(const char*  scrut ,const char * );
Zchar           Move(const char*   src);
Zchar           Movel(const char*   src);
Zchar           Move(const Zchar);
Zchar           Movel(const Zchar);
Zchar           Extrac(const char*   src   ,unsigned int  , unsigned int  );
Zchar           Extrac(const Zchar         ,unsigned int  , unsigned int  );
Zchar           strtrim(const Zchar );
char *          ExtracToChar(unsigned int  , unsigned int  );
///****************************************************************************
/// FONCTIONS UTILE--------- --------------------------------------------------
///****************************************************************************

unsigned int    locfind( const char*);
unsigned int    sizebuf();
unsigned int    sizeval();

///****************************************************************************
/// FONCTIONS operateur--------------------------------------------------------
///****************************************************************************

bool operator!=( const char* );
bool operator==( const char* );
bool operator<( const char*  );
bool operator>( const char*  );
bool operator<=( const char* );
bool operator>=( const char* );
unsigned   int cmp( const char* );

bool operator!=( Zchar );
bool operator==( Zchar );
bool operator<( Zchar  );
bool operator>=( Zchar );
bool operator<=( Zchar );
bool operator>( Zchar  );
unsigned   int  cmp( Zchar );


///****************************************************************************
/// FONCTIONS status   --------------------------------------------------------
///****************************************************************************
unsigned int   status();
char*          statusmsg();
bool           Msgerr();
};

}
#endif // Zchar_H_INCLUDED
