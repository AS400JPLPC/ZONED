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


namespace __ZONED__
{
#define   ZONED_OK     0       ///  OK
#define   ZONED_BAD   22       ///  PGTYPES_CHAR_BAD
#define   ZONED_OVR   33       ///  PGTYPES_CHAR_OVERFLOW

#define   LT          05       ///  inferieur
#define   EQ          10       ///  egal
#define   GT          15       ///  superieur

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


char*         tochar();
const char*   toconstchar();
std::string   tostring();

Zchar operator=(const Zchar);
Zchar operator+=(const Zchar);
Zchar operator=(const char*);
Zchar operator+=( const char*);


Zchar           concat(const std::string fmt, ...);                                       // Concat from string
Zchar           reset();

///  substring
Zchar           replace(const char*  scrut ,const char * );
Zchar           move(const char*   src);
Zchar           movel(const char*   src);
Zchar           move(const Zchar);
Zchar           movel(const Zchar);
Zchar           extrac(const char*   src   ,unsigned int  , unsigned int  );
Zchar           extrac(const Zchar         ,unsigned int  , unsigned int  );
Zchar           strtrim(const Zchar );
char *          extractochar(unsigned int  , unsigned int  );
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
bool           msgerr();
};

}
#endif // Zchar_H_INCLUDED