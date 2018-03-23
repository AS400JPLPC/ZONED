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

#ifndef ZDATE_H_INCLUDED
#define ZDATE_H_INCLUDED


#include <stdio.h>
#include <sys/time.h>
#include <ctime>
#include <unistd.h>
#include <stdlib.h>     /* atoi */
#include <malloc.h>
#include <string.h>

#include <iostream>


#define   ZONED_OK	0  	///  OK
#define   ZONED_BAD	22	///  DCML_NUM_BAD_NUMERIC
#define   ZONED_OVR	33	///  DCML_NUM_OVERFLOW
#define   ZONED_UND	66	///  DCML_NUM_UNDERFLOW
#define   ZONED_DIV	99	///  DCML_NUM_DIVIDE_ZERO

#define   NE       02       ///  Non egal
#define   LT       05       ///  inferieur
#define   EQ       10       ///  egal
#define   GT       15       ///  superieur



namespace ZONED
{
class Zdate {

private:

    int _YEAR  ;
    int _MOIS  ;
    int _JOUR  ;
    int _DATE  ;

protected:

    int Cyear  ;
    int Cmonth ;
    int Cday   ;
    int Cdate  ;
    void savdate();
    void rstdate();
    void update();
    bool is_Bissextile(int);
    bool isValid();
    int   Paques();
    void next_day();
    void prev_day();
    char* getdays(int);
    char* getmonths(int);

//STATUS -----------------------------------------------------------------------
    unsigned int  MSGERR;
    char *        zmsg;
    unsigned int CMP;

public:
        enum date {eISO,    /// YYYY-MM-DD
                eNUM,  /// YYYYMMDD
                eYMD,   /// YYYY/MM/DD
                eDMY,   /// DD/MM/YYYY
                eMDY,   /// MM/DD/YYYY
                eYM,    /// YYYY/MM
                eMY,    /// MM/YYYY
                elongdate,  /// vendredi 12 octobre 1951
                ntime , /// HH:MM:SC
                sISO,   /// idem date usuel s->system
                sNUM,
                sYMD,
                sDMY,
                sMDY,
                stime ,
                sYM,
                sMY,
                slongdate
                };

    Zdate();             // Le constructeur par défaut.
    ~Zdate() ;             // Le destructeur.

/// la date 0001-01-01 est valide pour ce programme uniquement pour donnée une Valeur "0"

    Zdate operator=(const int  );                       /// 20010101 YYYYMMDD      0 = 00010101
    Zdate operator=(const char*);                       /// "2001-01-01" = 20010101
                                                        /// "0001-01-01" YYYY-MM-DD (POUR Bd ex: Postgresql = 0)
                                                        /// NULL etant possible mais pose des problèmes lors de clef  Non NULL voir le manuel d'ou 00010101
                                                        /// pour faire de la gestion  acceptable Voir IBM  a pris le même raisonnement. Norme SQL
                                                        /// "*SYS"   YYYY-MM-DD  du system

    Zdate& operator++(int);                             /// prefix    + 1
    Zdate& operator--(int);                             /// postfix   + 1
    Zdate&  operator+(const int);                       /// prefix    + n day
    Zdate& operator-(const int);                        /// postfix   - n day

    bool operator == (const Zdate);                     /// opération logique pour comparer des dates entre elles
    bool operator <  (const Zdate);
    bool operator >  (const Zdate);
    bool operator >= (const Zdate);
    bool operator <= (const Zdate);
    bool operator != (const Zdate);
    unsigned int  cmp(const Zdate) ;

/// *************************************************
///---------------------------------------------------
/// YYYYMMDDHHMMSS + 3 quantieme naosecond 9 = 26 char
///---------------------------------------------------
    char* session();        ///  n° unique
    char* sysdattim();      ///  YYYYMMDDHHMMSS
///---------------------------------------------------
/// SYSTEM
///---------------------------------------------------
    char* edtsysNUM();      /// YYYYMMDD
    char* edtsysYMD();      /// YYYY/MM/DD
    char* edtsysDMY();      /// jj/MM/YYYY
    char* edtsysMDY();      /// MM/JJ/YYYY
    char* edttimesys();     /// HH:mn:sec
    char* edtsysYM();       /// YYYY/MM
    char* edtsysMY();       /// MM/YYYY

    char* longdatesys();
    char* D_datesys();      /// Texte
    char* M_datesys();      /// Texte

    int   timehr();         /// heure
    int   timemin();        /// minute
    int   timesec();        /// seconde

    int   sysYM();          /// YYYYMM
    int   sysday();         /// DD
    int   sysmonth();       /// MM
    int   sysyear();        /// YYYY
    int   sysyear2();       /// YY
    int   syssiecle();      /// NN

    int   datesys();        /// YYYYMMDD
    char* edtsysISO();      /// YYYY-MM-DD


    int   Quantiemesys();   /// Quantieme
    int   NumeroJoursys();  /// le Numéro du jour
    int   Semainesys();     /// le numéro de semaine

    int   Decalage_heuresys();  /// 0 =été 1= hiver  -1 pas pris en compte

///---------------------------------------------------
/// Date personnel... table ... attention 00010101 = 0
///---------------------------------------------------
    int   ToInt();          /// YYYYMMDD

    char* edtISO();         /// YYYY-MM-DD  date ISO
    char* edtNUM();         /// YYYYMMDD
    char* edtYMD();         /// YYYY/MM/DD
    char* edtDMY();         /// jj/MM/YYYY
    char* edtMDY();         /// MM/JJ/YYYY
    char* edtYM();          /// YYYY/MM
    char* edtMY();          /// MM/YYYY
    char* longdate();       /// vendredi 12 octobre 1950

    char* ToChar(unsigned int date =0);             /// YYYYMMDD  full format
    const char*   ConstChar(unsigned int date =0);  /// idem ToChar
    std::string   StringChar(unsigned int date =0); /// idem ToChar

    char* D_date();         /// Texte
    char* M_date();         /// Texte

    int   YM();             /// YYYYMM   periode
    int   day();            /// Jour
    int   month();          /// Mois
    int   year();           /// Année
    int   year2();          /// deux dernier chiffre de l'année
    int   siecle();         /// siecle

    bool  isBissextile();   /// ? bisexe tille ;)
    void  Addmonth(int);    /// MOIS + n
    int   PremierJanvier(); /// recupèrer 1 janvier n° du jour
    int   Quantieme();      /// Quantieme
    int   NumeroJour();     /// le Numéro du jour 0 1 2 3 4 5 6
    int   ResteJour();      /// le nombre jour restant dans l'année
    int   Semaine();        /// le numéro de semaine
    int   Ferier();          /// is fête ?? pour construire un calendrier

///****************************************************************************
/// FONCTIONS status   --------------------------------------------------------
///****************************************************************************
unsigned int   status();
char*          statusmsg();
bool  Msgerr();
};
}
#endif
