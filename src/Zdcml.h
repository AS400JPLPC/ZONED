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



#include <stdarg.h>                 /// For va_start, etc.


#define  DECNUMDIGITS 128   /// work with up to 128 digits

#include <decNumber.h>


/// pas de setlocale please  p_mask[pos] ='.'  compatibilité avec decNumber (IBM)
namespace __ZONED__
{

#define   ZONED_OK	0  	///  OK
#define   ZONED_BAD	22	///  DCML_NUM_BAD_NUMERIC
#define   ZONED_OVR	33	///  DCML_NUM_OVERFLOW
#define   ZONED_UND	66	///  DCML_NUM_UNDERFLOW
#define   ZONED_DIV	99	///  DCML_NUM_DIVIDE_ZERO



#define   LT       05	///  inferieur
#define   EQ       10	///  egal
#define   GT       15	///  superieur





class Zdcml
{
private:
    decNumber  *_dcml;       /// Un nombre décimal est un nombre possédant un développement décimal limité 31 chiffre 29.2 = 31

protected:
///decNumber---------------------------------------------------------------------
    decContext  T_set;
    bool        _round ;
    bool   ___obligatoire___;
///STATUS -----------------------------------------------------------------------
    unsigned int  MSGERR ;
    char * zmsg ;
    unsigned int CMP;

///LONGEUR MAXIMUN DU BUFFER ----------------------------------------------------
    unsigned int _entier;
    unsigned int _dec;

    unsigned int _length;
///Zone de travail---------- ----------------------------------------------------
    decNumber  *T_dcml;       // Zone de travail
    decNumber  *C_dcml;       // Zone de travail
    decNumber  *S_dcml;       // Zone de travail   Copy avant mise en reel

std::string _STRING_ ;
    char * T_string , *T_value;
    char * p_mask, *n_mask ;    /// mask pour contrôle overlay
    int result;

/// FONCTIONS UTILE--------- ---------------------------------------------------
void rtvchar(const char* _X_);
void ClearBufferDcml();       /// T_dcml C_dcml

char* ZLTrim(char* _X_);
char* ZRTrim(char* _X_);
char* ZTrim(char* _X_);
char* ZLTrim0(char* _X_);
char* ZRTrim0(char* _X_);
char* ZTrim0(char* _X_);
char* ZDoubleToChar(double _X_ ,unsigned _precision_);
///=============================================================================
public:

///CONSTRUCTEURS ----------------------------------------------------------------

Zdcml(unsigned int  ,unsigned int   );

~Zdcml();


Zdcml& operator=(const  int);
Zdcml& operator=(const  long int);
Zdcml& operator=(const double);
Zdcml& operator=(const char*);
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



Zdcml& add(const  std::string fmt_str, ...);  /// ex: n.add("%s,%s", a.ToChar(),b.ToChar());
Zdcml& sub(const  std::string fmt_str, ...);
Zdcml& mult(const std::string fmt_str, ...);
Zdcml& div(const  std::string fmt_str, ...);
Zdcml& mod(const Zdcml);

Zdcml& pcent(const Zdcml,const Zdcml);

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
char*           ToChar(bool signe = false);       /// format text limit def ex: a(10,5); 1234567890.12345  nbr digit = def
const char*     ConstChar(bool signe = false);    /// trim zero
std::string     StringChar(bool signe = false);   /// trim zero

int         ToInt();        /// cast par defaut
long int    TolongInt();    /// cast par defaut
double      ToDouble();     /// cast par defaut
/// FONCTION Contrôle Type --------------------------------------
bool        isTypDbl();     /// contrôle typ double
bool        isTypInt();     /// contrôle typ Int
bool        isTyplongInt(); /// contrôle typ long Int
bool        isZeros();      /// contrôle ZEROS
bool        isNegative();   /// contrôle IsNegative
bool        isDecimale();   /// contrôle si valeur Décimale
bool        isNumeric(const char *_X_); /// permet de tester si la valeur répond à un numeric

void        ToRound();      /// DEC_ROUND_HALF_EVEN
void        NoRound();      /// DEC_ROUND_DOWN
bool        isRound();      /// return  ToRound() or NoRound()        default  Noround
unsigned int checkInt();                /// permet de tester si la valeur répond à un int
unsigned int checkDouble();             /// permet de tester si la valeur répond à un double
unsigned int checklongInt();            /// permet de tester si la valeur répond à un long int
unsigned int ChekOverflow();            /// contrôle valeur def tampon
/// FONCTION Utilitaire --------------------------------------
char *     ToEntier();         /// parti entiere
char *     ToDec();            /// partie decimale

/// code retour _ERR_eur or ok ---------------------------------
unsigned int status();
char*        statusmsg();
bool         Msgerr();

/// Format String--idem sprintf --------------------------

std::string string_format(const std::string fmt_str, ...);



};

}


#endif
