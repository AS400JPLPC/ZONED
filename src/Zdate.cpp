#ifndef ZADTE_CPP_INCLUDED
#define ZDATE_CPP_INCLUDED

#include <Zdate.h>

namespace __ZONED__
{
#define ANNEE_MIN  1582  //Doit etre superieure a 1582 (Calendrier Gregorien)
#define ANNEE_MAX  2501  //Doit etre inferieure a 2501

///$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
///$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

///----------------------------------------------------------------------------
/// constructeur
///----------------------------------------------------------------------------

Zdate::Zdate()
{
    zmsg = new char[80];
     sprintf(zmsg," "); MSGERR=ZONED_OK;
     _YEAR =     1;
     _MOIS =     1;
     _JOUR =     1;
     _DATE =     10101;
    /// zeros c'est possible une date déclaré mais non active
}
Zdate::~Zdate()
{
    return ;
}
///$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
///$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

///----------------------------------------------------------------------------
/// Initialisation
///----------------------------------------------------------------------------

Zdate Zdate::operator=(const int x_DATE )   /// YYYYMMDD
{
    sprintf(zmsg," "); MSGERR=ZONED_OK;

    if (x_DATE==0  or x_DATE == 00010101 ) {
            _YEAR =     1;
            _MOIS =     1;
            _JOUR =     1;
            _DATE =     10101;
            return *this;
          }




    this->savdate();
    char * P_date = (char*) malloc(8  * sizeof(char*));
        sprintf(P_date,"%08d%c",x_DATE,'\0');
        std::string S_arg = P_date;
        S_arg = S_arg.substr(0,4);  _YEAR = atoi(S_arg.c_str());
        S_arg = P_date;
        S_arg = S_arg.substr(4,2);  _MOIS = atoi(S_arg.c_str());
        S_arg = P_date;
        S_arg = S_arg.substr(6,2);  _JOUR = atoi(S_arg.c_str());



    if(_YEAR > ANNEE_MAX || _YEAR < ANNEE_MIN )         /// ANNEE_MIN  1582  ANNEE_MAX  2501
                                        { this->rstdate();
                                        MSGERR = ZONED_BAD;
                                        sprintf(zmsg,"Msgerror -  PGTYPES_NUM_BAD_DATE  -- Msgerror : %d" , ZONED_BAD);
                                        _YEAR =     1;
                                        _MOIS =     1;
                                        _JOUR =     1;
                                        _DATE =     10101;
                                        return *this;}


        if(!this->IsValid())            { this->rstdate();
                                        MSGERR = ZONED_BAD;
                                        sprintf(zmsg,"Msgerror -  PGTYPES_NUM_BAD_DATE  -- Msgerror : %d" , ZONED_BAD);
                                        _YEAR =     1;
                                        _MOIS =     1;
                                        _JOUR =     1;
                                        _DATE =     10101;
                                        return *this;}

        else this->update();
        return *this;
}

///----------------------------------------------------------------------------
/// Initialisation DB Postgresql ..... BD2 .......  fmt YYYY-MM-DD
///----------------------------------------------------------------------------

Zdate Zdate::operator=(const char* P_date )
{
    sprintf(zmsg," "); MSGERR=ZONED_OK;


            if(0==strcmp (P_date,"0001-01-01") or 0==strcmp (P_date,"")  or NULL==P_date or 0==strcmp (P_date,"00010101") or 0==strcmp (P_date,"0") ) {
            _YEAR =     1;
            _MOIS =     1;
            _JOUR =     1;
            _DATE =     10101;
            return      *this;
            }


            if(0==strcmp (P_date,"*SYS")) {
            _YEAR =     sysyear();
            _MOIS =     sysmonth();
            _JOUR =     sysday();
            _DATE =     (_YEAR*10000) + (_MOIS *100) + _JOUR;
            return      *this;
            }


            this->savdate();
            if (strlen(P_date) != 10){
                                        this->rstdate();
                                        MSGERR = ZONED_BAD;
                                        sprintf(zmsg,"Msgerror -  PGTYPES_NUM_BAD_DATE  -- Msgerror : %d" , ZONED_BAD);
                                        return *this;}

            std::string S_arg = P_date;
            if (strlen(P_date) == 10){

            S_arg = S_arg.substr(0,4);  _YEAR = atoi(S_arg.c_str());
            S_arg = (const char*) P_date;
            S_arg = S_arg.substr(5,2);  _MOIS = atoi(S_arg.c_str());
            S_arg = (const char*) P_date;
            S_arg = S_arg.substr(8,2);  _JOUR = atoi(S_arg.c_str());
            _DATE =     (_YEAR*10000) + (_MOIS *100) + _JOUR;
            }
            if (strlen(P_date) == 8){

            S_arg = S_arg.substr(0,4);  _YEAR = atoi(S_arg.c_str());
            S_arg = (const char*) P_date;
            S_arg = S_arg.substr(4,2);  _MOIS = atoi(S_arg.c_str());
            S_arg = (const char*) P_date;
            S_arg = S_arg.substr(6,2);  _JOUR = atoi(S_arg.c_str());
            _DATE =     (_YEAR*10000) + (_MOIS *100) + _JOUR;
            }
            if(!this->IsValid())        { this->rstdate();
                                        MSGERR = ZONED_BAD;
                                        sprintf(zmsg,"Msgerror -  PGTYPES_NUM_BAD_DATE  -- Msgerror : %d" , ZONED_BAD);

                                        _YEAR =     1;
                                        _MOIS =     1;
                                        _JOUR =     1;
                                        _DATE =     10101;
                                        return *this; }

            else this->update();

        return *this;
}

///$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
///$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$


///$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
///                             SYSTEM
///$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

///----------------------------------------------------------------------------
/// Retourne   le jour  de la date system
///----------------------------------------------------------------------------

int Zdate::sysday() {
    time_t rawtime;
    struct tm * timeinfo;
    char * buffer = (char*) malloc( 2   * sizeof(char*));
    time (&rawtime);
    timeinfo = localtime (&rawtime);

    strftime (buffer,80,"%d\0",timeinfo);

 return   atoi(buffer);
}
///----------------------------------------------------------------------------
/// Retourne   le mois  de la date system
///----------------------------------------------------------------------------

int Zdate::sysmonth() {

    time_t rawtime;
    struct tm * timeinfo;
    char * buffer = (char*) malloc( 2   * sizeof(char*));
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime (buffer,80,"%m\0",timeinfo);

 return   atoi(buffer);
}

///----------------------------------------------------------------------------
/// Retourne   l'année sur 4 YYYY  de la date system
///----------------------------------------------------------------------------

int Zdate::sysyear() {

    time_t rawtime;
    struct tm * timeinfo;
    char * buffer = (char*) malloc( 4   * sizeof(char*));
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime (buffer,80,"%Y\0",timeinfo);

 return   atoi(buffer);
}

///----------------------------------------------------------------------------
/// Retourne   l'année sur 2 YY  de la date system
///----------------------------------------------------------------------------

int Zdate::sysyear2() {

    time_t rawtime;
    struct tm * timeinfo;
    char * buffer = (char*) malloc( 2   * sizeof(char*));
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime (buffer,80,"%y\0",timeinfo);

 return   atoi(buffer);
}


int Zdate::syssiecle() {

    time_t rawtime;
    struct tm * timeinfo;
    char * buffer = (char*) malloc( 2   * sizeof(char*));
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime (buffer,80,"%C\0",timeinfo);

 return   atoi(buffer)+1;
}

///----------------------------------------------------------------------------
/// Retourne   le jour  de la date system
///----------------------------------------------------------------------------

int Zdate::sysYM() {
    time_t rawtime;
    struct tm * timeinfo;
    char * buffer = (char*) malloc( 6   * sizeof(char*));
    time (&rawtime);
    timeinfo = localtime (&rawtime);

    strftime (buffer,80,"%Y%d\0",timeinfo);

 return   atoi(buffer);
}
///----------------------------------------------------------------------------
/// Retourne   la date system  format YYYY/MM/DD
///----------------------------------------------------------------------------

char * Zdate::edtsysYMD(){

     char * buffer = (char*) malloc( 10   * sizeof(char*));
     sprintf(buffer,"%4d/%02d/%02d", this->sysyear(), this->sysmonth(),this->sysday());
 return buffer;
}

///----------------------------------------------------------------------------
/// Retourne   la date system  format DD/MM/YYYY
///----------------------------------------------------------------------------

char * Zdate::edtsysDMY(){

     char * buffer = (char*) malloc( 10   * sizeof(char*));
     sprintf(buffer,"%02d/%02d/%4d",this->sysday(), this->sysmonth(), this->sysyear());
 return buffer;
}

///----------------------------------------------------------------------------
/// Retourne   la date system  format MM/DD/YYYY  Americain
///----------------------------------------------------------------------------

char * Zdate::edtsysMDY(){

     char * buffer = (char*) malloc( 10   * sizeof(char*));
     sprintf(buffer,"%02d/%02d/%4d", this->sysmonth(),this->sysday(), this->sysyear());
 return buffer;
}

///----------------------------------------------------------------------------
/// Retourne   la date system  format YYYY/MM
///----------------------------------------------------------------------------

char * Zdate::edtsysYM(){

     char * buffer = (char*) malloc( 7   * sizeof(char*));
     sprintf(buffer,"%04d/%02d", this->sysyear(), this->sysmonth());
 return buffer;
}

///----------------------------------------------------------------------------
/// Retourne   la date system  format MM/YYYY
///----------------------------------------------------------------------------

char * Zdate::edtsysMY(){

     char * buffer = (char*) malloc( 7   * sizeof(char*));
     sprintf(buffer,"%02d/%04d", this->sysmonth(), this->sysyear());
 return buffer;
}

///----------------------------------------------------------------------------
/// Retourne   la date system  YYYYMMJJ
///----------------------------------------------------------------------------

int  Zdate::datesys(){

     char * buffer = (char*) malloc( 8   * sizeof(char*));
     sprintf(buffer,"%4d%02d%02d", this->sysyear(), this->sysmonth(),this->sysday());
 return atoi(buffer);
}

char*   Zdate::edtsysNUM(){

     char * buffer = (char*) malloc( 8   * sizeof(char*));
     sprintf(buffer,"%4d%02d%02d", this->sysyear(), this->sysmonth(),this->sysday());
 return  buffer;
}
///----------------------------------------------------------------------------
/// Retourne   la date system  YYYY-MM-JJ
///----------------------------------------------------------------------------

char*  Zdate::edtsysISO(){

     char * buffer = (char*) malloc( 10   * sizeof(char*));
     sprintf(buffer,"%4d-%02d-%02d", this->sysyear(), this->sysmonth(),this->sysday());
 return buffer;
}

///----------------------------------------------------------------------------
/// Retourne la description  etendue  de la date system
///----------------------------------------------------------------------------

char * Zdate::longdatesys(){  ///  Name_JOUR JJ MOIS YEAR
    time_t rawtime;
    struct tm * timeinfo;
    char * buffer = (char*) malloc(80   * sizeof(char*));
    time (&rawtime);
    timeinfo = localtime (&rawtime);

    sprintf(buffer, "%s %02d %s %4d",
    this->getdays(NumeroJoursys()),
    timeinfo->tm_mday,
    this->getmonths(timeinfo->tm_mon),
        1900 + timeinfo->tm_year);
 return buffer;
}

///----------------------------------------------------------------------------
/// Retourne la description   de l'HEURE
///----------------------------------------------------------------------------

int Zdate::timehr(){
    time_t rawtime;
    struct tm * timeinfo;
    char * buffer = (char*) malloc(2* sizeof(char*));
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    sprintf(buffer, "%02d",timeinfo->tm_hour);

 return     atoi(buffer);
}

///----------------------------------------------------------------------------
/// Retourne la description  de la Minute
///----------------------------------------------------------------------------

int Zdate::timemin(){
    time_t rawtime;
    struct tm * timeinfo;
    char * buffer = (char*) malloc(2 * sizeof(char*));
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    sprintf(buffer, "%02d",timeinfo->tm_min);

 return     atoi(buffer);
}

///----------------------------------------------------------------------------
/// Retourne la description  de la seconde
///----------------------------------------------------------------------------

int Zdate::timesec(){
    time_t rawtime;
    struct tm * timeinfo;
    char * buffer = (char*) malloc(2 * sizeof(char*));
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    sprintf(buffer, "%02d",timeinfo->tm_sec);

 return     atoi(buffer);
}

///----------------------------------------------------------------------------
/// Retourne la description  de l'HEURE MINUTE SECONDE
///----------------------------------------------------------------------------

char * Zdate::edttimesys(){
    time_t rawtime;
    struct tm * timeinfo;
    char * buffer = (char*) malloc(10 * sizeof(char*));
    time (&rawtime);
    timeinfo = localtime (&rawtime);

    sprintf(buffer, "%02d:%02d:%02d",
    timeinfo->tm_hour,
    timeinfo->tm_min, timeinfo->tm_sec);
 return buffer;
}

///----------------------------------------------------------------------------
/// Retourne le nom du jour de la date system
///----------------------------------------------------------------------------

char * Zdate::D_datesys(){
    char * buffer = (char*) malloc(15   * sizeof(char*));
    sprintf(buffer,"%s",this->getdays(NumeroJoursys()));

 return buffer;

}
///----------------------------------------------------------------------------
/// Retourne le nom du mois de la date system
///----------------------------------------------------------------------------

char * Zdate::M_datesys(){
    char * buffer = (char*) malloc(15   * sizeof(char*));

    sprintf(buffer, "%s",this->getmonths(this->sysmonth()));

 return buffer;
}

///----------------------------------------------------------------------------
/// Retourne le Quantieme de la date system
///----------------------------------------------------------------------------

int Zdate::Quantiemesys()
{
    struct tm Temps ;
    char   * buffer =   (char*) malloc(3   * sizeof(char*));

   Temps.tm_year = this->sysyear() - 1900;
   Temps.tm_mon  = this->sysmonth()  - 1;
   Temps.tm_mday = this->sysday();
   Temps.tm_hour =0;
   Temps.tm_min = 0;
   Temps.tm_sec = 0;
   Temps.tm_isdst = -1;  /// heur d'été non disponible
   mktime(&Temps);

    strftime (buffer,80,"%j\0",&Temps );
    return atoi(buffer);
}

///----------------------------------------------------------------------------
/// Retourne le Semaine de la date system
///----------------------------------------------------------------------------

int Zdate::Semainesys()
{
    struct tm Temps ;
    char   * x_date =   (char*) malloc(2   * sizeof(char*));

   Temps.tm_year = this->sysyear() - 1900;
   Temps.tm_mon  = this->sysmonth()  - 1;
   Temps.tm_mday = this->sysday();
   Temps.tm_hour =0;
   Temps.tm_min = 0;
   Temps.tm_sec = 0;
   Temps.tm_isdst = -1;  /// heur d'été non disponible
   mktime(&Temps);
   strftime(x_date, sizeof(x_date), "%V", &Temps );
    return atoi(x_date);
}

///----------------------------------------------------------------------------
/// Retourne le NumeroJour de la date system
///----------------------------------------------------------------------------

int Zdate::NumeroJoursys()
{
    struct tm Temps ;
    char   * x_date =   (char*) malloc(3   * sizeof(char*));

   Temps.tm_year = this->sysyear() - 1900;
   Temps.tm_mon  = this->sysmonth()  - 1;
   Temps.tm_mday = this->sysday();
   Temps.tm_hour =0;
   Temps.tm_min = 0;
   Temps.tm_sec = 0;
   Temps.tm_isdst = -1;  /// heur d'été non disponible
   mktime(&Temps);
   strftime(x_date, sizeof(x_date), "%w", &Temps );
    return atoi(x_date);
}

///----------------------------------------------------------------------------
/// Retourne 1= heure été actif system 0= heure été inactif  -1 non disponible
///----------------------------------------------------------------------------

int Zdate::Decalage_heuresys(){
    time_t rawtime;
    struct tm * timeinfo;
    time (&rawtime);
    timeinfo = localtime (&rawtime);

    switch(timeinfo->tm_isdst)
    {
    case 1 :  return 1;   break;
    case 0 :  return 0;   break;
    default:  return -1;  break;
    }
}



///----------------------------------------------------------------------------
/// Retourne   le timestamp session date aaaammjjhmms-nanoseconde
///----------------------------------------------------------------------------

char * Zdate::session(){
    char * sessiond = (char*) malloc(30  * sizeof(char*));
    char * T_session = (char*) malloc(26  * sizeof(char*));


    time_t now = time(0);
    tm *ltm = localtime(&now);
    strftime(sessiond, 30, "%04Y%02m%02d%02H%02M%02S", ltm);

/*   windows
     struct timeval tp; gettimeofday(&tp, NULL);
     long int  ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
     sprintf(T_session,"%14s%012ld",sessiond,ms);
*/
/// printf("%lld.%.9ld", (long long)ts.tv_sec, ts.tv_nsec)


    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);

    sprintf(T_session,"%14s%03d%09ld",sessiond,this->Quantiemesys(),ts.tv_nsec);
return T_session;
}

///----------------------------------------------------------------------------
/// Retourne   le timestamp session date aaaammjjhmms
///----------------------------------------------------------------------------

char * Zdate::sysdattim(){
    char * T_sysdat    = (char*) malloc(30  * sizeof(char*));
    char * T_sysdattim = (char*) malloc(14  * sizeof(char*));


    time_t now = time(0);
    tm *ltm = localtime(&now);
    strftime(T_sysdat , 30, "%04Y%02m%02d%02H%02M%02S", ltm);

    sprintf(T_sysdattim,"%14s",T_sysdat);
return T_sysdattim;
}
///$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
///   Traitement des valeurs
///$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

///----------------------------------------------------------------------------
/// renvoie date   /// attention 00010101
///----------------------------------------------------------------------------

int     Zdate::day()    { return _JOUR ; }

int     Zdate::month()  { return _MOIS ; }

int     Zdate::year()   { return _YEAR ; }

int     Zdate::year2()  {   int x_year = _YEAR/100;  x_year= x_year* 100;    return (_YEAR- x_year ); }

int     Zdate::ToInt()  { return _DATE ; }

int     Zdate::YM()  { int x_DATE =   _YEAR * 100 + _MOIS; return x_DATE ; }

int     Zdate::siecle() {

        int siecle = (_YEAR / 100 ) ;
    return  siecle +1;
}
///$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
///                 Edition /SQL
///
///---------------------------------------------------------------------------
/// renvoie date *char
///---------------------------------------------------------------------------
char*   Zdate::edtISO() {

 char * P_date = (char*) malloc(10  * sizeof(char*));
 sprintf(P_date,"%04d-%02d-%02d",_YEAR,_MOIS,_JOUR);
    return P_date;
}

///$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
///                 Edition

///---------------------------------------------------------------------------
/// renvoie date *char  YYYYMMJJ
///---------------------------------------------------------------------------

char*   Zdate::edtNUM() {

 char * P_date = (char*) malloc(10  * sizeof(char*));
 sprintf(P_date,"%04d%02d%02d",_YEAR,_MOIS,_JOUR);
    return P_date;
}
///$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
///                 Edition

///---------------------------------------------------------------------------
/// renvoie date *char  YYYY/MM/JJ
///---------------------------------------------------------------------------

char*   Zdate::edtYMD() {

 char * P_date = (char*) malloc(10  * sizeof(char*));
 sprintf(P_date,"%04d/%02d/%02d",_YEAR,_MOIS,_JOUR);
    return P_date;
}
///---------------------------------------------------------------------------
/// renvoie date *char  JJ/MM/YYYY
///---------------------------------------------------------------------------

char*   Zdate::edtDMY() {

 char * P_date = (char*) malloc(10  * sizeof(char*));
 sprintf(P_date,"%02d/%02d/%04d",_JOUR,_MOIS,_YEAR);
    return P_date;
}

///---------------------------------------------------------------------------
/// renvoie date *char  MM/JJ/YYYY
///---------------------------------------------------------------------------

char*   Zdate::edtMDY() {

 char * P_date = (char*) malloc(10  * sizeof(char*));
 sprintf(P_date,"%02d/%02d/%04d",_MOIS,_JOUR,_YEAR);
    return P_date;
}

///---------------------------------------------------------------------------
/// renvoie date *char  YYYY/MM
///---------------------------------------------------------------------------

char*   Zdate::edtYM() {

 char * P_date = (char*) malloc(7  * sizeof(char*));
 sprintf(P_date,"%04d/%02d",_YEAR,_MOIS);
    return P_date;
}

///---------------------------------------------------------------------------
/// renvoie date *char  MM/YYYY
///---------------------------------------------------------------------------

char*   Zdate::edtMY() {

 char * P_date = (char*) malloc(7  * sizeof(char*));
 sprintf(P_date,"%02d/%04d",_MOIS,_YEAR);
    return P_date;
}

///---------------------------------------------------------------------------
/// renvoie date *char  vendrei 12 octobre 1951
///---------------------------------------------------------------------------

char*   Zdate::longdate() {

 char * P_date = (char*) malloc(50  * sizeof(char*));
 sprintf(P_date,"%s %02d %s %04d%c",this->D_date(),_JOUR,M_date(),_YEAR,'\0');
    return P_date;
}

///$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
///$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
///                 Edition /SQL
///
///---------------------------------------------------------------------------
/// renvoie date *char
///---------------------------------------------------------------------------
char*   Zdate::ToChar (unsigned int date) {

switch( date)
  {

     case eISO:         return edtISO(); break ;    /// YYYY-MM-DD
     case eNUM:         return edtNUM(); break ;    /// YYYYMMDD
     case eYMD:         return edtYMD(); break ;    /// YYYY/MM/DD
     case eDMY:         return edtDMY(); break ;    /// DD/MM/YYYY
     case eMDY:         return edtMDY(); break ;    /// MM/DD/YYYY
     case eYM:          return edtYM(); break ;     /// YYYY/MM
     case eMY:          return edtMY(); break ;     /// MM/YYYY
     case elongdate:    return longdate(); break ;  /// vendrei 12 octobre 1951

     case ntime:        return edttimesys(); break ;    /// HH:MM:SC


     case sISO:         return edtsysISO(); break ;    /// YYYY-MM-DD
     case sNUM:         return edtsysNUM();   break ; /// YYYYMMDD
     case sYMD:         return edtsysYMD(); break ;    /// YYYY/MM/DD
     case sDMY:         return edtsysDMY(); break ;    /// DD/MM/YYYY
     case sMDY:         return edtsysMDY(); break ;    /// MM/DD/YYYY
     case sYM:          return edtsysYM();  break ;    /// YYYY/MM
     case sMY:          return edtsysMY();  break ;    /// MM/YYYY
     case slongdate:    return longdatesys(); break ;  /// vendrei 12 octobre 1951

    };

    return edtISO();
}

const char* Zdate::ConstChar(unsigned int date) {

switch( date)
  {

     case eISO:         return (const char *) edtISO(); break ;    /// YYYY-MM-DD
     case eNUM:         return (const char *) edtNUM(); break ;    /// YYYYMMDD
     case eYMD:         return (const char *) edtYMD(); break ;    /// YYYY/MM/DD
     case eDMY:         return (const char *) edtDMY(); break ;    /// DD/MM/YYYY
     case eMDY:         return (const char *) edtMDY(); break ;    /// MM/DD/YYYY
     case eYM:          return (const char *) edtYM(); break ;     /// YYYY/MM
     case eMY:          return (const char *) edtMY(); break ;     /// MM/YYYY
     case elongdate:    return (const char *) longdate(); break ;  /// vendrei 12 octobre 1951

     case ntime:        return (const char *) edttimesys(); break ;   /// HH:MM:SC


     case sISO:         return (const char *) edtsysISO(); break ;    /// YYYY-MM-DD
     case sNUM:         return (const char *) edtsysNUM(); break ;    /// YYYYMMDD
     case sYMD:         return (const char *) edtsysYMD(); break ;    /// YYYY/MM/DD
     case sDMY:         return (const char *) edtsysDMY(); break ;    /// DD/MM/YYYY
     case sMDY:         return (const char *) edtsysMDY(); break ;    /// MM/DD/YYYY
     case sYM:          return (const char *) edtsysYM();  break ;    /// YYYY/MM
     case sMY:          return (const char *) edtsysMY();  break ;    /// MM/YYYY
     case slongdate:    return (const char *) longdatesys(); break ;  /// vendrei 12 octobre 1951

    };
    return (const char *) edtISO();
}

std::string    Zdate::StringChar(unsigned int date) {

switch( date)
  {

     case eISO:         return std::string( edtISO() ); break ;    /// YYYY-MM-DD
     case eNUM:         return std::string( edtNUM() ); break ;    /// YYYYMMDD
     case eYMD:         return std::string( edtYMD() ); break ;    /// YYYY/MM/DD
     case eDMY:         return std::string( edtDMY() ); break ;    /// DD/MM/YYYY
     case eMDY:         return std::string( edtMDY() ); break ;    /// MM/DD/YYYY
     case eYM:          return std::string( edtYM()  ); break ;    /// YYYY/MM
     case eMY:          return std::string( edtMY()  ); break ;    /// MM/YYYY
     case elongdate:    return std::string( longdate() ); break ;  /// vendrei 12 octobre 1951

     case ntime:        return std::string( edttimesys() ); break ;   /// HH:MM:SC


     case sISO:         return std::string( edtsysISO() ); break ;    /// YYYY-MM-DD
     case sNUM:         return std::string( edtsysNUM() ); break ;    /// YYYYMMDD
     case sYMD:         return std::string( edtsysYMD() ); break ;    /// YYYY/MM/DD
     case sDMY:         return std::string( edtsysDMY() ); break ;    /// DD/MM/YYYY
     case sMDY:         return std::string( edtsysMDY() ); break ;    /// MM/DD/YYYY
     case sYM:          return std::string( edtsysYM() );  break ;    /// YYYY/MM
     case sMY:          return std::string( edtsysMY() );  break ;    /// MM/YYYY
     case slongdate:    return std::string( longdatesys() );break ;   /// vendrei 12 octobre 1951

    };
  return std::string( edtISO() );
}
///$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
///$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

///---------------------------------------------------------------------------
/// Opérator
///---------------------------------------------------------------------------


bool Zdate::operator == ( Zdate  x_date)
{
    if ( _DATE == x_date._DATE ) return true;

return false;
}



bool Zdate::operator != (const Zdate  x_date)
{
    if ( _DATE != x_date._DATE) return true ;

return false;
}


bool Zdate::operator < ( const Zdate x_date)
{
    if ( _DATE < x_date._DATE) return true ;

return false;
}



bool Zdate::operator > ( const Zdate x_date)
{
    if ( _DATE > x_date._DATE) return true ;

return false;
}

bool Zdate::operator >= (const Zdate  x_date)
{
    if ( _DATE > x_date._DATE) return false ;

return true;
}

bool Zdate::operator<=(const Zdate x_date)
{
   if ( _DATE < x_date._DATE) return false ;

return true;
}


unsigned int  Zdate::cmp(const Zdate  x_date)
{

    if (_DATE < x_date._DATE) CMP = LT;
    if (_DATE > x_date._DATE) CMP = GT;
    if (_DATE == x_date._DATE) CMP = EQ;


return CMP;
}

///---------------------------------------------------------------------------
///  avance d'un jour
///---------------------------------------------------------------------------

Zdate& Zdate::operator++(int)                               /// prefix operator
{
    if ( _DATE == 00010101) return *this;

    this->next_day();

return *this;
}

///---------------------------------------------------------------------------
///  avance de  n jour(s)
///---------------------------------------------------------------------------
Zdate&  Zdate::operator+(const int _x_ )
{
    if ( _DATE == 00010101) return *this;

    if (_x_ != 0 ) for (int i =0  ; i!= _x_;i++ ) this->next_day();

return *this;
}

///---------------------------------------------------------------------------
///  recule d'un jour
///---------------------------------------------------------------------------

Zdate& Zdate::operator--(int)
{
    if ( _DATE == 00010101) return *this;

    this->prev_day();

return *this;
}

///---------------------------------------------------------------------------
///  recule de  n jour(s)
///---------------------------------------------------------------------------

Zdate& Zdate::operator-(const int _x_  )
{
    if ( _DATE == 00010101) return *this;

    for (int i =0  ; i!= _x_;i++ ) this->prev_day();

return *this;
}

///---------------------------------------------------------------------------
///  Contrôle Date
///---------------------------------------------------------------------------

bool Zdate::IsValid(){

if ( _DATE == 00010101) return true ;


if (_YEAR <ANNEE_MIN) return false; if (_YEAR >ANNEE_MAX) return false;

if (_MOIS >12 || _MOIS <1) return false;

if (_JOUR >31 || _JOUR <1) return false;

if ((_JOUR ==31 && ( _MOIS ==2 || _MOIS ==4 || _MOIS ==6 || _MOIS ==9 || _MOIS ==11) ) ) return false;

if ( _JOUR ==30 && _MOIS ==2) return false;


                if ((_JOUR ==29 && _MOIS ==2) && !( false == isBissextile() )) return false;


return true;
}



///$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
///   date personnel
///$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

///----------------------------------------------------------------------------
/// Retourne le nom du jour
///----------------------------------------------------------------------------

char* Zdate::D_date()
{
    if ( _DATE == 00010101) return NULL ;

    char * buffer = (char*) malloc( 15   * sizeof(char*));

    sprintf (buffer,"%s", this->getdays(this->NumeroJour()));

  return buffer ;
}

///----------------------------------------------------------------------------
/// Retourne le nom du mois
///----------------------------------------------------------------------------

char* Zdate:: M_date()
{
    if ( _DATE == 00010101) return NULL ;

    char * buffer = (char*) malloc( 15   * sizeof(char*));

    sprintf (buffer,"%s",this->getmonths(_MOIS));

  return buffer ;
}


///----------------------------------------------------------------------------
/// Retourne 1 si l'annee est bissextile, sinon 0
///----------------------------------------------------------------------------

bool Zdate::isBissextile()
{
    if ( _DATE == 00010101) return true;

    if ( _YEAR % 400 == 0) return true ;
    if ( _YEAR % 100 == 0) return false ;
    if ( _YEAR % 4   == 0) return true;

   return false;
}

bool Zdate::is_Bissextile(int x_year)    /// interne (protected)
{
    if ( x_year % 400 == 0) return true ;
    if ( x_year % 100 == 0) return false ;
    if ( x_year % 4   == 0) return true;
   return false;
}


///----------------------------------------------------------------------------
///  avance d'un jour
///----------------------------------------------------------------------------

void Zdate::next_day()
{
    if ( _DATE == 00010101) return  ;

   switch(this->_MOIS){
      case 2:

            if(this->isBissextile())
            {if ( this->_JOUR == 29 ){ this->_JOUR=1; this->_MOIS=3;} else this->_JOUR++;}
            else {if ( this->_JOUR == 28 ) { this->_JOUR=1; this->_MOIS=3; } else this->_JOUR++;}

         break;
      case 4:
      case 6:
      case 9:
      case 11:
         if(30==this->_JOUR){
            this->_JOUR=1;
            this->_MOIS++;
         }
         else
            this->_JOUR++;
         break;
      case 1:
      case 3:
      case 5:
      case 7:
      case 8:
      case 10:
         if(31==this->_JOUR){
            this->_JOUR=1;
            this->_MOIS++;
         }
         else
            this->_JOUR++;
         break;
      case 12:
         if(31==this->_JOUR){
            this->_JOUR=1;
            this->_MOIS=1;
            this->_YEAR++;
         }
         else
            this->_JOUR++;
         break;
   }

this->update();
}

///----------------------------------------------------------------------------
///  recule d'un jour
///----------------------------------------------------------------------------

void Zdate::prev_day()
{
    if ( _DATE == 00010101) return ;

   switch(this->_MOIS){
      case 1:
         if(1==this->_MOIS){
            this->_JOUR=31;
            this->_MOIS=12;
            this->_YEAR--;
         }
         else
            this->_JOUR--;
         break;
      case 3:
         if(1==this->_JOUR){
            if(this->isBissextile()) {
               this->_JOUR=29;
               this->_MOIS=2;
            } else
               this->_JOUR=28;
            this->_MOIS=2;
         }
         else
            this->_JOUR--;
         break;
      case 5:
      case 7:
      case 10:
      case 12:
         if(1==this->_JOUR){
            this->_JOUR=30;
            this->_MOIS--;
         }
         else
            this->_JOUR--;
         break;
      default:
         if(1==this->_JOUR){
            this->_JOUR=31;
            this->_MOIS--;
         }
         else
            this->_JOUR--;
         break;
   }
this->update();
}

///----------------------------------------------------------------------------
///  avance de N mois
///----------------------------------------------------------------------------

void Zdate::Addmonth( int n)
{
    if ( _DATE == 00010101) return ;

    if (n < 0) return;
    unsigned int jj ;
    unsigned int mm = this->_MOIS +n  ;
    unsigned int mx = this->_MOIS +1;
    for(register unsigned int cnt=this->_MOIS ;  cnt < mm ; cnt++, mx++)
    {
            if (mx > 12 ) mx = 1;
        	switch (mx)
        	{
                case  4 :   ///Avril, Juin, Septembre, Novembre
                case  6 :
                case  9 :
                case 11 :
                           jj = 30; break ;

                case  2 :   /// FÃ©vrier
                            /// Si Divisible par 400 alors Bisextile
                        if (isBissextile()) jj = 29 ; else jj = 28;
                        break ;
                default : jj = 31 ; break;
            }
            printf("%d jj", jj);
            for(register unsigned int cntj=0; cntj<jj; cntj++) this->next_day();
   }

this->update();

}

///----------------------------------------------------------------------------
/// Retourne le jour du 1er Janvier de l'annee [0 == Dimanche ... 6 == Samedi]
///----------------------------------------------------------------------------

int Zdate::PremierJanvier()
{
    if ( _DATE == 00010101) return 0 ;

    return ((_YEAR / 100) * 5  +
            (_YEAR / 100) / 4  +
            (_YEAR % 100)      +
            (_YEAR % 100) / 4  +
            (this->isBissextile() ? 6 : 0)) % 7;
}

///----------------------------------------------------------------------------
/// Retourne le numero du jour dans l'annee (Quantieme) [1 ... 366]
///----------------------------------------------------------------------------

int Zdate::Quantieme()
{
    if ( _DATE == 00010101) return 0 ;

    if(_MOIS == 1)          return _JOUR;

    if(_MOIS == 2)          return _JOUR + 31;

return _JOUR + (int)((((double)_MOIS) * 30.6) - 32.3) + (this->isBissextile()?1:0);
}

///----------------------------------------------------------------------------
/// Retourne le nombre restant de jours dans l'annee [365 ... 0]
///----------------------------------------------------------------------------

int  Zdate::ResteJour()
{
    if ( _DATE == 00010101) return 0;

    return (365 + (this->isBissextile()? 1 : 0)) - this->Quantieme();
}

///----------------------------------------------------------------------------
/// Retourne le quantieme du dimanche de Paques
///----------------------------------------------------------------------------

int  Zdate::Paques()
{
    if ( _DATE == 00010101) return 0 ;

    int a = _YEAR % 19;
    int b = _YEAR /100;
    int c = _YEAR % 100;
    int d = b / 4;
    int e = b % 4;
    int f = (b + 8) / 25;
    int g = (b + 1 - f) / 3;
    int h = (15 + 19 * a + b - d - g) % 30;
    int i = (32 + 2 * (e + (c / 4)) - h - (c % 4)) % 7;
    int j = (a + 11 * h + 22 * i) / 451;

    _JOUR =21 ; _MOIS=  3;

    int q = this->Quantieme()+ h + i - 7 * j + 1;

return q ;
}

///----------------------------------------------------------------------------
/// Retourne un numero de jour ferie [1 ... 11], sinon 0
///----------------------------------------------------------------------------

int  Zdate::Ferie()
{
        if ( _DATE == 00010101) return 0 ;

    int q, p;

    /// Feries dates fixes -------------------------------------------------------
    if(_JOUR ==  1 && _MOIS ==  1 && _YEAR >= 1811) return 1;   // Nouvel an
    if(_JOUR ==  1 && _MOIS ==  5 && _YEAR >= 1947) return 2;   // Fete du travail
    if(_JOUR ==  8 && _MOIS ==  5 && _YEAR >= 1982) return 3;   // Victoire 1945
    if(_JOUR == 14 && _MOIS ==  7 && _YEAR >= 1880) return 4;   // Fete nationale
    if(_JOUR == 15 && _MOIS ==  8 && _YEAR >= 1802) return 5;   // Assomption
    if(_JOUR ==  1 && _MOIS == 11 && _YEAR >= 1802) return 6;   // Toussaint
    if(_JOUR == 11 && _MOIS == 11 && _YEAR >= 1922) return 7;   // Armistice 1918
    if(_JOUR == 25 && _MOIS == 12 && _YEAR >= 1802) return 8;   // Noel


    /// Feries dates mobiles -----------------------------------------------------
    q = this->Quantieme();
    p = this->Paques();
    if(q == p +  1 && _YEAR >= 1886) return  9;  // Lundi de Paques
    if(q == p + 39 && _YEAR >= 1802) return 10;  // Jeudi de l'Ascension
    if(q == p + 50 && _YEAR >= 1886) return 11;  // Lundi de la Pentecote

return 0;                                    // Non Ferie
}


///----------------------------------------------------------------------------
/// Retourne un numero du jour [1..366]
///----------------------------------------------------------------------------

int Zdate::NumeroJour()
{

    if ( _DATE == 00010101) return 0 ;

    int DM[]={0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};
    int day;
    if(_YEAR<1900)
      day=5*((_YEAR-1860)/4);
    else
      day  = 5*((_YEAR-1900)/4);
      day += _YEAR%4;
      day += DM[_MOIS-1];
      day += _JOUR;
    if(_YEAR%4  == 0 && _MOIS <= 2)
      day += 6;
     day  = (day%7);

return day;
}

///----------------------------------------------------------------------------
/// Retourne le numero de la semaine [1 ... 53]
///----------------------------------------------------------------------------

int Zdate::Semaine()
{

    if ( _DATE == 00010101) return 0;

  int j = PremierJanvier();
  int q = Quantieme();
  int s = (j + q + 5) / 7 - (j / 5);

   if(s== 0)  s =  Semaine();



  if(_MOIS == 12)
  {
    int nj = this->NumeroJour();
    if((nj == 1 && (_JOUR >= 29 && _JOUR<= 31)) ||
       (nj == 2 && (_JOUR == 30 || _JOUR == 31)) ||
       (nj == 3 &&  _JOUR == 31)) s= 1;
  }
  return s;
}




///----------------------------------------------------------------------------
/// code retour
///----------------------------------------------------------------------------

unsigned int Zdate::status() {return this->MSGERR;}
char* Zdate::statusmsg() {return this->zmsg;}
bool  Zdate::Msgerr() { if (this->MSGERR == ZONED_OK ) return false; else return true ;}


///$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
///                             interne
///$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$


///----------------------------------------------------------------------------
/// sauvegarde tampon tampon
///----------------------------------------------------------------------------
void Zdate::savdate() {  Cyear = _YEAR ; Cmonth = _MOIS ; Cday =_JOUR ; Cdate = _DATE;}

///----------------------------------------------------------------------------
/// restaure tampon tampon
///----------------------------------------------------------------------------
void Zdate::rstdate() {
    _YEAR  = this->Cyear;
    _MOIS  = this->Cmonth;
    _JOUR  = this->Cday;
    _DATE  = this->Cdate;
    Cyear = 0 ;Cmonth = 0 ;Cday = 0; Cdate=0;
}


///----------------------------------------------------------------------------
/// Update  zone _DATE
///----------------------------------------------------------------------------
void Zdate::update(){
   if ( _YEAR > 0)  _DATE  = (_YEAR*10000) + (_MOIS *100) + _JOUR;
}

///----------------------------------------------------------------------------
/// Retourne le nom du jour  de la semaine
///----------------------------------------------------------------------------

char * Zdate::getdays(int _numday )
{
    switch(_numday)
   {
       case 0 : return (char*)("Dimanche");     break;
       case 1 : return (char*)("Lundi");        break;
       case 2 : return (char*)("Mardi");        break;
       case 4 : return (char*)("Mercredi");     break;
       case 5 : return (char*)("jeudi");        break;
       case 6 : return (char*)("Vendredi");     break;
       case 7 : return (char*)("Samedi");       break;

   }
   return (char*)("");
}

///----------------------------------------------------------------------------
/// Retourne le nom du mois de l'année
///----------------------------------------------------------------------------

char * Zdate::getmonths(int _nummonth)
{

    switch(_nummonth)
   {
       case 1 : return  (char*)("Janvier");     break;
       case 2 : return  (char*)("Fevrier");     break;
       case 3 : return  (char*)("Mars");        break;
       case 4 : return  (char*)("Avril");       break;
       case 5 : return  (char*)("Mai");         break;
       case 6 : return  (char*)("Juin");        break;
       case 7 : return  (char*)("Juillet");     break;
       case 8 : return  (char*)("Aout");        break;
       case 9 : return  (char*)("Septembre");   break;
       case 10 : return (char*)("Octobre");     break;
       case 11 : return (char*)("Novembre");    break;
       case 12 : return (char*)("Décembre");    break;
   }

  return (char*)("");
}


}

#endif
