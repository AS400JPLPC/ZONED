#ifndef ZDCML_CPP_INCLUDED
#define ZDCML_CPP_INCLUDED



#include <Zdcml.h>
namespace __ZONED__
{
//CONSTRUCTEURS ----------------------------------------------------------------
Zdcml::Zdcml(unsigned int _e_  ,unsigned int _d_  )
  {


     if (_e_ < _d_ ) MSGERR= ZONED_UND ;
     if (_e_ < 1)  MSGERR= ZONED_UND ;
     if (_e_ > 31) MSGERR= ZONED_OVR ;
     if (_d_ > 31) MSGERR= ZONED_OVR ;

     if (MSGERR != ZONED_OK ) { ___obligatoire___ = true;

      sprintf(zmsg,"%s %d","Msgerror - BAD DEFINE  - Max 31 digits code Msgerror: " ,MSGERR  );

       if(___obligatoire___ ) return ;

     }

	 ___obligatoire___ = false ;

    _entier = _e_ - _d_ ; 
    _dec=_d_;

    MSGERR= ZONED_OK; CMP=0;  _round = false;

    
    zmsg= (char*) malloc(128  * sizeof(char*));
    T_string = (char*) malloc(256  * sizeof(char*));
    T_value  = (char*) malloc(256  * sizeof(char*));

    decContextDefault(&T_set, DEC_INIT_DECIMAL128 );    // initialize
    T_set.digits = 128;                                 // initialize
    decContextSetRounding(&T_set,DEC_ROUND_HALF_EVEN);


    _dcml = new decNumber ;     /// Zoned Reel
    T_dcml = new decNumber ;    /// Zoned Travail
    C_dcml = new decNumber ;    /// Zoned Copy
    S_dcml = new decNumber ;    /// Zone Tampon

    decNumberZero( _dcml);
    decNumberZero(T_dcml);
    decNumberZero(C_dcml);


        p_mask = (char*) malloc(36  * sizeof(char*));
        unsigned int pos =0, posd = 0;
        p_mask[pos] ='+';  /// positif
        for ( pos=1 ; pos < _entier+1;pos++ ) p_mask[pos] ='9';
        if (_dec > 0) {
        p_mask[pos] ='.';
        for (pos++, posd=0; posd < _dec;posd++,pos++ ) p_mask[pos] ='9';
        }
        n_mask = (char*) malloc(36  * sizeof(char*));
        pos =0; posd = 0;
        n_mask[pos ] ='-'; /// negatif
        for ( pos=1 ; pos < _entier+1;pos++ ) n_mask[pos] ='9';
        if (_dec > 0) {
        n_mask[pos] ='.';
       for (pos++, posd=0; posd < _dec;posd++,pos++ ) n_mask[pos] ='9';

        }
}


Zdcml::~Zdcml()   { }

void Zdcml::ClearBufferDcml(){
    decContextDefault(&T_set, DEC_INIT_DECIMAL128 );    // initialize
    T_set.digits = 128;                                 // initialize
    decContextSetRounding(&T_set,DEC_ROUND_HALF_EVEN);
     decNumberZero(C_dcml);    decNumberZero(T_dcml);

}

/// operateur
Zdcml& Zdcml::operator=(const int _X_)
{

  if(___obligatoire___ ) return *this;

    sprintf(zmsg," "); MSGERR=ZONED_OK;

    ClearBufferDcml();

    decNumberCopy( S_dcml,_dcml);

   _STRING_ =string_format("%d",_X_);
    if ( _X_ != 0 ) decNumberFromString( _dcml, (char*)_STRING_.c_str(), &T_set);
    else decNumberZero(_dcml);

#ifndef _DEBUG_   /// pour tester les formules
    if ( ZONED_OK != chekoverflow()) {  decNumberCopy( _dcml,S_dcml); ClearBufferDcml(); return *this; }
#endif
    return *this;
}

Zdcml& Zdcml::operator=(const long int _X_)
{

  if(___obligatoire___ ) return *this;

    sprintf(zmsg," "); MSGERR=ZONED_OK;

    ClearBufferDcml();
    decNumberCopy( S_dcml,_dcml);

    _STRING_ =string_format("%ld",_X_);
    if ( _X_ != 0 ) decNumberFromString( _dcml, (char*)_STRING_.c_str(), &T_set);
    else decNumberZero(_dcml);

#ifndef _DEBUG_   /// pour tester les formules
    if ( ZONED_OK != chekoverflow()) {  decNumberCopy( _dcml,S_dcml); ClearBufferDcml(); return *this; }
#endif

  return *this;
}

Zdcml& Zdcml::operator=(const double _X_)
{

  if(___obligatoire___ ) return *this;

    sprintf(zmsg," "); MSGERR=ZONED_OK;

    ClearBufferDcml();

    decNumberCopy( S_dcml,_dcml);



     _STRING_ =string_format("%s", ZDoubleToChar(_X_ ,_dec));
    if ( _X_ !=0 ) decNumberFromString( _dcml, (char*)_STRING_.c_str(), &T_set);
    else decNumberZero(_dcml);

#ifndef _DEBUG_   /// pour tester les formules
    if ( ZONED_OK != chekoverflow()) {  decNumberCopy( _dcml,S_dcml); ClearBufferDcml(); return *this; }
#endif
  return *this;
}



Zdcml& Zdcml::operator=(const char* _X_)
{

  if(___obligatoire___ ) return *this;

    sprintf(zmsg," "); MSGERR=ZONED_OK;

    ClearBufferDcml();

    decNumberCopy( S_dcml,_dcml);

#ifndef _DEBUG_   /// pour tester les formules

    if ( !isnumeric(_X_))  { MSGERR=ZONED_BAD;
                              sprintf(zmsg,"(DCML_NUM_BAD_NUMERIC) - Msgerror : %d",ZONED_BAD);
                              decNumberCopy( _dcml,S_dcml); ClearBufferDcml(); return *this; }
#endif
    rtvchar(_X_);
    decNumberCopy( _dcml,C_dcml);

#ifndef _DEBUG_   /// pour tester les formules
     if ( ZONED_OK != chekoverflow()) {  decNumberCopy( _dcml,S_dcml); ClearBufferDcml(); return *this; }
#endif

    return *this;

}

Zdcml& Zdcml::operator=(const Zdcml X_dcml)
{

  if(___obligatoire___ ) return *this;

    sprintf(zmsg," "); MSGERR=ZONED_OK;

    ClearBufferDcml();

    decNumberCopy( S_dcml,_dcml);

    decNumberCopy( _dcml,X_dcml._dcml);


#ifndef _DEBUG_   /// pour tester les formules
    if ( ZONED_OK != chekoverflow()) {  decNumberCopy( _dcml,S_dcml); ClearBufferDcml(); return *this; }
#endif
    return *this;
}



/// operateur


/// operation arithmetique

Zdcml& Zdcml::operator++(int)
{

  if(___obligatoire___ ) return *this;

    sprintf(zmsg," "); MSGERR=ZONED_OK;

    Zdcml::ClearBufferDcml();

    decNumberCopy( S_dcml,_dcml);

    _STRING_ =string_format("%d",1);
    decNumberFromString( C_dcml, (char*)_STRING_.c_str(), &T_set);

    decNumberAdd(_dcml, _dcml, C_dcml ,&T_set);
    if ( ZONED_OK != chekoverflow()) {  decNumberCopy( _dcml,S_dcml); ClearBufferDcml(); return *this; }

  return *this;
}
Zdcml& Zdcml::operator--(int)
{

  if(___obligatoire___ ) return *this;

    sprintf(zmsg," "); MSGERR=ZONED_OK;

    Zdcml::ClearBufferDcml();

    decNumberCopy( S_dcml,_dcml);

    _STRING_ =string_format("%d",1);
    decNumberFromString( C_dcml, (char*)_STRING_.c_str(), &T_set);

    decNumberSubtract(_dcml, _dcml, C_dcml ,&T_set);
    if ( ZONED_OK != chekoverflow()) {  decNumberCopy( _dcml,S_dcml); ClearBufferDcml(); return *this; }

  return *this;
}


Zdcml& Zdcml::operator+=(const  int _X_)
{

  if(___obligatoire___ ) return *this;

    sprintf(zmsg," "); MSGERR=ZONED_OK;

    Zdcml::ClearBufferDcml();

    decNumberCopy( S_dcml,_dcml);

    _STRING_ =string_format("%d",_X_);
    decNumberFromString( C_dcml, (char*)_STRING_.c_str(), &T_set);

    decNumberAdd(_dcml, _dcml, C_dcml ,&T_set);
    if ( ZONED_OK != chekoverflow()) {  decNumberCopy( _dcml,S_dcml); ClearBufferDcml(); return *this; }

  return *this;
}


Zdcml& Zdcml::operator-=(const  int _X_)
{

  if(___obligatoire___ ) return *this;

    sprintf(zmsg," "); MSGERR=ZONED_OK;

    Zdcml::ClearBufferDcml();

    decNumberCopy( S_dcml,_dcml);

    _STRING_ =string_format("%d",_X_);
    decNumberFromString( C_dcml, (char*)_STRING_.c_str(), &T_set);

    decNumberSubtract(_dcml, _dcml, C_dcml ,&T_set);
    if ( ZONED_OK != chekoverflow()) {  decNumberCopy( _dcml,S_dcml); ClearBufferDcml(); return *this; }

  return *this;
}
 Zdcml& Zdcml::operator*=(const  int _X_)
  {

  if(___obligatoire___ ) return *this;

    sprintf(zmsg," "); MSGERR=ZONED_OK;

    Zdcml::ClearBufferDcml();

    decNumberCopy( S_dcml,_dcml);

    _STRING_ =string_format("%d",_X_);
    decNumberFromString( C_dcml, (char*)_STRING_.c_str(), &T_set);

    decNumberMultiply(_dcml, _dcml, C_dcml ,&T_set);
    if ( ZONED_OK != chekoverflow()) {  decNumberCopy( _dcml,S_dcml); ClearBufferDcml(); return *this; }

  return *this;
}
Zdcml& Zdcml::operator/=(const  int _X_)
{

  if(___obligatoire___ ) return *this;

    sprintf(zmsg," "); MSGERR=ZONED_OK;

    Zdcml::ClearBufferDcml();

    decNumberCopy( S_dcml,_dcml);

    _STRING_ =string_format("%d",_X_);
    decNumberFromString( C_dcml, (char*)_STRING_.c_str(), &T_set);
    if(decNumberIsZero(C_dcml))    { MSGERR= ZONED_DIV; sprintf(zmsg,"(DCML_NUM_DIV ZEROS) - Msgerror : %d",ZONED_DIV);
                                    decNumberCopy( _dcml,S_dcml); ClearBufferDcml(); return *this; }

    decNumberDivide(_dcml, _dcml,C_dcml,&T_set);
    if ( ZONED_OK != chekoverflow()) {  decNumberCopy( _dcml,S_dcml); ClearBufferDcml(); return *this; }

    return *this;
}

Zdcml& Zdcml::operator%=(const int _X_)
{

  if(___obligatoire___ ) return *this;

    sprintf(zmsg," "); MSGERR=ZONED_OK;

    Zdcml::ClearBufferDcml();

    Zdcml::ClearBufferDcml();

    _STRING_ =string_format("%d",_X_);
    decNumberFromString(C_dcml, (char*)_STRING_.c_str(), &T_set);

    decNumberRemainder(_dcml, _dcml ,C_dcml, &T_set);

    return *this;
}



Zdcml& Zdcml::operator+=(const long int _X_)
{

  if(___obligatoire___ ) return *this;

    sprintf(zmsg," "); MSGERR=ZONED_OK;

    Zdcml::ClearBufferDcml();

    decNumberCopy( S_dcml,_dcml);

    _STRING_ =string_format("%ld",_X_);
    decNumberFromString( C_dcml, (char*)_STRING_.c_str(), &T_set);

    decNumberAdd(_dcml, _dcml, C_dcml ,&T_set);
    if ( ZONED_OK != chekoverflow()) {  decNumberCopy( _dcml,S_dcml); ClearBufferDcml(); return *this; }

  return *this;
}
Zdcml& Zdcml::operator-=(const long int _X_)
{

  if(___obligatoire___ ) return *this;

    sprintf(zmsg," "); MSGERR=ZONED_OK;

    Zdcml::ClearBufferDcml();

    decNumberCopy( S_dcml,_dcml);

    _STRING_ =string_format("%ld",_X_);
    decNumberFromString( C_dcml, (char*)_STRING_.c_str(), &T_set);

    decNumberSubtract(_dcml, _dcml, C_dcml ,&T_set);
    if ( ZONED_OK != chekoverflow()) {  decNumberCopy( _dcml,S_dcml); ClearBufferDcml(); return *this; }

  return *this;
}
 Zdcml& Zdcml::operator*=(const long int _X_)
{

  if(___obligatoire___ ) return *this;

    sprintf(zmsg," "); MSGERR=ZONED_OK;

    Zdcml::ClearBufferDcml();

    decNumberCopy( S_dcml,_dcml);

    _STRING_ =string_format("%ld",_X_);
    decNumberFromString( C_dcml, (char*)_STRING_.c_str(), &T_set);

    decNumberMultiply(_dcml, _dcml, C_dcml ,&T_set);
    if ( ZONED_OK != chekoverflow()) {  decNumberCopy( _dcml,S_dcml); ClearBufferDcml(); return *this; }

  return *this;
}
Zdcml& Zdcml::operator/=(const  long int _X_)
{

  if(___obligatoire___ ) return *this;

    sprintf(zmsg," "); MSGERR=ZONED_OK;

    Zdcml::ClearBufferDcml();

    decNumberCopy( S_dcml,_dcml);

    _STRING_ =string_format("%ld",_X_);
    decNumberFromString( C_dcml, (char*)_STRING_.c_str(), &T_set);
    if(decNumberIsZero(C_dcml))    { MSGERR= ZONED_DIV; sprintf(zmsg,"(DCML_NUM_DIV ZEROS) -    Msgerror : %d",ZONED_DIV);
                                    decNumberCopy( _dcml,S_dcml); ClearBufferDcml(); return *this; }

    decNumberDivide(_dcml, _dcml,C_dcml,&T_set);
    if ( ZONED_OK != chekoverflow()) {  decNumberCopy( _dcml,S_dcml); ClearBufferDcml(); return *this; }

    return *this;
}

Zdcml& Zdcml::operator%=(const long int _X_)
{

  if(___obligatoire___ ) return *this;

    sprintf(zmsg," "); MSGERR=ZONED_OK;

    Zdcml::ClearBufferDcml();

    _STRING_ =string_format("%ld",_X_);
    decNumberFromString(C_dcml, (char*)_STRING_.c_str(), &T_set);

    decNumberRemainder(_dcml, _dcml ,C_dcml, &T_set);

    return *this;
}

Zdcml& Zdcml::operator+=(const  double _X_)
{

  if(___obligatoire___ ) return *this;

    sprintf(zmsg," "); MSGERR=ZONED_OK;

    Zdcml::ClearBufferDcml();

    decNumberCopy( S_dcml,_dcml);

    _STRING_ =string_format("%s", ZDoubleToChar(_X_ ,_dec));
    decNumberFromString( C_dcml, (char*)_STRING_.c_str(), &T_set);

    decNumberAdd(_dcml, _dcml, C_dcml ,&T_set);
    if ( ZONED_OK != chekoverflow()) {  decNumberCopy( _dcml,S_dcml); ClearBufferDcml(); return *this; }

  return *this;
}
Zdcml& Zdcml::operator-=(const  double  _X_)
{

  if(___obligatoire___ ) return *this;

    sprintf(zmsg," "); MSGERR=ZONED_OK;

    Zdcml::ClearBufferDcml();

    decNumberCopy( S_dcml,_dcml);

    _STRING_ =string_format("%s", ZDoubleToChar(_X_ ,_dec));
    decNumberFromString( C_dcml, (char*)_STRING_.c_str(), &T_set);

    decNumberSubtract(_dcml, _dcml, C_dcml ,&T_set);
    if ( ZONED_OK != chekoverflow()) {  decNumberCopy( _dcml,S_dcml); ClearBufferDcml(); return *this; }

  return *this;
}
 Zdcml& Zdcml::operator*=(const  double  _X_)
{

  if(___obligatoire___ ) return *this;

    sprintf(zmsg," "); MSGERR=ZONED_OK;

    Zdcml::ClearBufferDcml();

    decNumberCopy( S_dcml,_dcml);

    _STRING_ =string_format("%s", ZDoubleToChar(_X_ ,_dec));
    decNumberFromString( C_dcml, (char*)_STRING_.c_str(), &T_set);

    decNumberMultiply(_dcml, _dcml, C_dcml ,&T_set);
    if ( ZONED_OK != chekoverflow()) {  decNumberCopy( _dcml,S_dcml); ClearBufferDcml(); return *this; }

  return *this;
}
Zdcml& Zdcml::operator/=(const  double  _X_)
{

  if(___obligatoire___ ) return *this;

    sprintf(zmsg," "); MSGERR=ZONED_OK;

    Zdcml::ClearBufferDcml();

    decNumberCopy( S_dcml,_dcml);

    _STRING_ =string_format("%s", ZDoubleToChar(_X_ ,_dec));
    decNumberFromString( C_dcml, (char*)_STRING_.c_str(), &T_set);
    if(decNumberIsZero(C_dcml))    { MSGERR= ZONED_DIV; sprintf(zmsg,"(DCML_NUM_DIV ZEROS) -    Msgerror : %d",ZONED_DIV);
                                    decNumberCopy( _dcml,S_dcml); ClearBufferDcml(); return *this; }

    decNumberDivide(_dcml, _dcml,C_dcml,&T_set);
    if ( ZONED_OK != chekoverflow()) {  decNumberCopy( _dcml,S_dcml); ClearBufferDcml(); return *this; }
    return *this;
}

Zdcml& Zdcml::operator%=(const double  _X_)
{

  if(___obligatoire___ ) return *this;

    sprintf(zmsg," "); MSGERR=ZONED_OK;

    Zdcml::ClearBufferDcml();

    _STRING_ =string_format("%s", ZDoubleToChar(_X_ ,_dec));
    decNumberFromString(C_dcml, (char*)_STRING_.c_str(), &T_set);

    decNumberRemainder(_dcml, _dcml ,C_dcml, &T_set);     // a=a%b

    return *this;
}



Zdcml& Zdcml::operator+=(const Zdcml X_dcml)
{

  if(___obligatoire___ ) return *this;

    sprintf(zmsg," "); MSGERR=ZONED_OK;

    Zdcml::ClearBufferDcml();

    decNumberCopy( S_dcml,_dcml);

    decNumberAdd(_dcml, _dcml, X_dcml._dcml ,&T_set);            // a=a+b
    if ( ZONED_OK != chekoverflow()) {  decNumberCopy( _dcml,S_dcml); ClearBufferDcml(); return *this; }

    return *this;
}

Zdcml& Zdcml::operator-=(const Zdcml  X_dcml)
{

  if(___obligatoire___ ) return *this;

    sprintf(zmsg," "); MSGERR=ZONED_OK;

    Zdcml::ClearBufferDcml();

    decNumberCopy( S_dcml,_dcml);

    decNumberSubtract(_dcml,_dcml,X_dcml._dcml,&T_set);       // a=a-b
    if ( ZONED_OK != chekoverflow()) {  decNumberCopy( _dcml,S_dcml); ClearBufferDcml(); return *this; }

    return *this;
}

Zdcml& Zdcml::operator*=(const Zdcml  X_dcml)
{

  if(___obligatoire___ ) return *this;

    sprintf(zmsg," "); MSGERR=ZONED_OK;

    Zdcml::ClearBufferDcml();

    decNumberCopy( S_dcml,_dcml);

    decNumberMultiply(_dcml, _dcml,X_dcml._dcml,&T_set);       // a=a*b
    if ( ZONED_OK != chekoverflow()) {  decNumberCopy( _dcml,S_dcml); ClearBufferDcml(); return *this; }

    return *this;
}

Zdcml& Zdcml::operator/=(const Zdcml  X_dcml)
{

  if(___obligatoire___ ) return *this;

    sprintf(zmsg," "); MSGERR=ZONED_OK;

    Zdcml::ClearBufferDcml();

    decNumberCopy( S_dcml,_dcml);

    decNumberCopy( C_dcml,X_dcml._dcml);

    if(decNumberIsZero(C_dcml))    { MSGERR= ZONED_DIV; sprintf(zmsg,"(DCML_NUM_DIV ZEROS) -    Msgerror : %d",ZONED_DIV);
                                    decNumberCopy( _dcml,S_dcml); ClearBufferDcml(); return *this; }

    decNumberDivide(_dcml, _dcml,C_dcml,&T_set);
    if ( ZONED_OK != chekoverflow()) {  decNumberCopy( _dcml,S_dcml); ClearBufferDcml(); return *this; }

    return *this;
}

Zdcml& Zdcml::operator%=(const Zdcml  X_dcml)
{
  if(___obligatoire___ ) return *this;

    sprintf(zmsg," "); MSGERR=ZONED_OK;

    decNumberCopy(C_dcml,X_dcml._dcml);

    decNumberRemainder(_dcml, _dcml ,C_dcml, &T_set);

    return *this;
}




Zdcml& Zdcml::add(const std::string fmt, ...)
{

  if(___obligatoire___ ) return *this;


    sprintf(zmsg," "); MSGERR=ZONED_OK;

    decNumberCopy(S_dcml, _dcml);

    char * vParm ;
    ClearBufferDcml();

    std::string str;
    va_list ap;
    va_start(ap, fmt);
    int size = vsnprintf(0, 0, (const char*)fmt.c_str(), ap) + sizeof('\0');
    va_end(ap);
    vParm= (char*) malloc(256  * sizeof(char*));
        _STRING_ =string_format("%d",0);
       decNumberFromString(_dcml, (char*)_STRING_.c_str(), &T_set);

    while (1) {
        str.resize(size);
        va_start(ap, fmt);
        int n = vsnprintf((char *)str.data(), size, fmt.c_str(), ap);

        va_end(ap);
        if (n > -1 && n < size) {
            str.resize(n);
            sprintf(vParm,"%s",str.c_str());
            vParm = strtok (vParm,",");
              while (vParm != NULL)
                {
                     rtvchar(vParm);
                     if (MSGERR == ZONED_BAD)           {MSGERR = ZONED_BAD ;sprintf(zmsg,"(DCML_NUM_BAD_NUMERIC) -  Msgerror : %d",ZONED_BAD);
                                                      decNumberCopy( _dcml,S_dcml);  ClearBufferDcml(); free(vParm) ; return *this; }
                     decNumberAdd(_dcml,_dcml,C_dcml,&T_set);
                     if( decNumberIsNaN(_dcml))      {MSGERR = ZONED_BAD ;sprintf(zmsg,"(DCML_NUM_BAD_NUMERIC) -  Msgerror : %d",ZONED_BAD);
                                                      decNumberCopy( _dcml,S_dcml);  ClearBufferDcml(); free(vParm) ; return *this; }
                     vParm= strtok (NULL, ",");
                }
                if ( ZONED_OK != chekoverflow()) {  decNumberCopy( _dcml,S_dcml); ClearBufferDcml(); free(vParm) ;return *this; }
                free(vParm) ;
                return *this;
        }
        if (n > -1) size = n + 1;
        else size *= 2;

    }
 free(vParm) ;
  return *this;
}


Zdcml& Zdcml::sub(const std::string fmt, ...)
{

  if(___obligatoire___ ) return *this;

    sprintf(zmsg," "); MSGERR=ZONED_OK;

    decNumberCopy(S_dcml, _dcml);
    char * vParm ;
    ClearBufferDcml();

    std::string str;
    va_list ap;
    va_start(ap, fmt);
    int size = vsnprintf(0, 0, (const char*)fmt.c_str(), ap) + sizeof('\0');
    va_end(ap);
    vParm= (char*) malloc(256  * sizeof(char*));

        _STRING_ =string_format("%d",0);
       decNumberFromString(_dcml, (char*)_STRING_.c_str(), &T_set);
    while (1) {
        str.resize(size);
        va_start(ap, fmt);
        int n = vsnprintf((char *)str.data(), size, fmt.c_str(), ap);
        va_end(ap);
        if (n > -1 && n < size) {
            str.resize(n);
            sprintf(vParm,"%s",str.c_str());
            vParm = strtok (vParm,",");
              while (vParm != NULL)
                {
                     rtvchar(vParm);
                     if (MSGERR == ZONED_BAD)           {MSGERR = ZONED_BAD ;sprintf(zmsg,"(DCML_NUM_BAD_NUMERIC) - Msgerror : %d",ZONED_BAD);
                                                      decNumberCopy( _dcml,S_dcml);  ClearBufferDcml(); free(vParm) ; return *this; }
                     decNumberSubtract(_dcml,_dcml,C_dcml,&T_set);
                     if( decNumberIsNaN(_dcml))     {MSGERR =ZONED_BAD  ;sprintf(zmsg,"(DCML_NUM_BAD_NUMERIC) -  Msgerror : %d",ZONED_BAD);
                                                     decNumberCopy( _dcml,S_dcml);  ClearBufferDcml(); free(vParm) ;return *this; }
                     vParm= strtok (NULL, ",");
                }
                if ( ZONED_OK != chekoverflow()) {  decNumberCopy( _dcml,S_dcml); ClearBufferDcml(); free(vParm) ; return *this; }
                free(vParm) ;
                return *this;
        }
        if (n > -1) size = n + 1;
        else size *= 2;

    }
free(vParm) ;
  return *this;
}


Zdcml& Zdcml::mult(const std::string fmt, ...)
{

  if(___obligatoire___ ) return *this;

    sprintf(zmsg," "); MSGERR=ZONED_OK;

    decNumberCopy(S_dcml, _dcml);

    char * vParm ;
    ClearBufferDcml();

    std::string str;
    va_list ap;
    va_start(ap, fmt);
    int size = vsnprintf(0, 0, (const char*)fmt.c_str(), ap) + sizeof('\0');
    va_end(ap);
    vParm= (char*) malloc(256  * sizeof(char*));

        _STRING_ =string_format("%d",1);
    decNumberFromString(_dcml, (char*)_STRING_.c_str(), &T_set);
    while (1) {
        str.resize(size);
        va_start(ap, fmt);
        int n = vsnprintf((char *)str.data(), size, fmt.c_str(), ap);

        va_end(ap);
        if (n > -1 && n < size) {
            str.resize(n);
            sprintf(vParm,"%s",str.c_str());
            vParm = strtok (vParm,",");
              while (vParm != NULL)
                {
                     rtvchar(vParm);
                     if (MSGERR == ZONED_BAD)           {MSGERR = ZONED_BAD ;sprintf(zmsg,"(DCML_NUM_BAD_NUMERIC) -  Msgerror : %d",ZONED_BAD);
                                                      decNumberCopy( _dcml,S_dcml);  ClearBufferDcml();free(vParm); return *this; }
                     decNumberMultiply(_dcml,_dcml,C_dcml,&T_set);
                     if( decNumberIsNaN(_dcml))     {MSGERR = ZONED_BAD ;sprintf(zmsg,"(DCML_NUM_BAD_NUMERIC) -  Msgerror : %d",ZONED_BAD);
                                                     decNumberCopy( _dcml,S_dcml);  ClearBufferDcml();free(vParm);  return *this; }
                     vParm= strtok (NULL, ",");
                }
                if ( ZONED_OK != chekoverflow()) {  decNumberCopy( _dcml,S_dcml); ClearBufferDcml(); return *this; }
                free(vParm) ;
                return *this;
        }
        if (n > -1) size = n + 1;
        else size *= 2;

    }
    free(vParm) ;
  return *this;
}

Zdcml& Zdcml::div(const std::string fmt, ...) {

  if(___obligatoire___ ) return *this;

    sprintf(zmsg," "); MSGERR=ZONED_OK;

    decNumberCopy(S_dcml, _dcml);
    char * vParm ;
    ClearBufferDcml();

    std::string str;
    va_list ap;
    va_start(ap, fmt);
    int size = vsnprintf(0, 0, (const char*)fmt.c_str(), ap) + sizeof('\0');
    va_end(ap);
    vParm= (char*) malloc(256  * sizeof(char*));
    int nx = 0;
        _STRING_ =string_format("%d",0);
       decNumberFromString(_dcml, (char*)_STRING_.c_str(), &T_set);
    while (1) {     // Maximum two passes on a POSIX system...
        str.resize(size);
        va_start(ap, fmt);
        int n = vsnprintf((char *)str.data(), size, fmt.c_str(), ap);

        va_end(ap);
        if (n > -1 && n < size) {
            str.resize(n);
            sprintf(vParm,"%s",str.c_str());
            vParm = strtok (vParm,",");
              while (vParm != NULL)
                {
                     rtvchar(vParm);
                     if (MSGERR == ZONED_BAD)           {MSGERR = ZONED_BAD ;sprintf(zmsg,"(DCML_NUM_BAD_NUMERIC) - Mgserror : %d",ZONED_BAD);
                                                      decNumberCopy( _dcml,S_dcml);  ClearBufferDcml(); free(vParm) ;return *this; }
                      if(decNumberIsZero(C_dcml))    {MSGERR= ZONED_DIV; sprintf(zmsg,"(DCML_NUM_DIV ZEROS) -  Msgerror : %d",ZONED_DIV);
                                                      decNumberCopy( _dcml,S_dcml); ClearBufferDcml(); return *this; }
                     if( nx <1 )   decNumberCopy( _dcml,C_dcml); else  decNumberDivide(_dcml,_dcml,C_dcml,&T_set);
                     if( decNumberIsNaN(_dcml))     {MSGERR = ZONED_BAD  ;sprintf(zmsg,"(DCML_NUM_BAD_NUMERIC) - Msgerror : %d",ZONED_BAD);
                                                     decNumberCopy( _dcml,S_dcml);  ClearBufferDcml();free(vParm) ; return *this; }
                     vParm= strtok (NULL, ",");
                     nx++;
                }
                if ( ZONED_OK != chekoverflow() ) {  decNumberCopy( _dcml,S_dcml); ClearBufferDcml();free(vParm) ; return *this; }
                if ( nx < 2 ) {MSGERR = ZONED_BAD  ;sprintf(zmsg,"(DCML_NUM_BAD_Paramettre) - Msgerror : %d",ZONED_BAD);
                                                     decNumberCopy( _dcml,S_dcml);  ClearBufferDcml();free(vParm) ; return *this; }
                free(vParm) ;
                return *this;
        }
        if (n > -1) size = n + 1;
        else size *= 2;

    }
  free(vParm) ;
  return *this;
}


Zdcml& Zdcml::mod(const Zdcml  X_dcml)
{
  if(___obligatoire___ ) return *this;

    sprintf(zmsg," "); MSGERR=ZONED_OK;

    decNumberCopy(C_dcml,X_dcml._dcml);

    decNumberRemainder(_dcml, _dcml ,C_dcml, &T_set);

    return *this;
}


Zdcml& Zdcml::pcent(const Zdcml X_dcml,const Zdcml Y_dcml)
{

  if(___obligatoire___ ) return *this;

    sprintf(zmsg," "); MSGERR=ZONED_OK;

    decNumberCopy(S_dcml, _dcml);

    _STRING_ =string_format("%d",100);
    decNumberFromString(T_dcml, (char*)_STRING_.c_str(), &T_set);

    decNumberDivide(T_dcml, X_dcml._dcml, T_dcml ,&T_set);

    decNumberMultiply(_dcml, Y_dcml._dcml ,T_dcml, &T_set);
    if ( ZONED_OK != chekoverflow()) {  decNumberCopy( _dcml,S_dcml); ClearBufferDcml(); return *this; }

  return *this;
}



//OPERATEURS DE COMPARAISON-----------------------------------------------------
/// avec un opérateur  INT
bool  Zdcml::operator==(const int _X_)
{
    _STRING_ =string_format("%d",_X_);
    decNumberFromString(T_dcml, (char*)_STRING_.c_str(), &T_set);


    decNumberCompare(C_dcml, _dcml, T_dcml, &T_set);
    decNumberToString(C_dcml, T_string);
    result= atoi(T_string);

    if (result == 0) return true ;
return false ;
}

bool Zdcml::operator<(const int _X_)
{
    _STRING_ =string_format("%d",_X_);
    decNumberFromString(T_dcml, (char*)_STRING_.c_str(), &T_set);


    decNumberCompare(C_dcml, _dcml, T_dcml, &T_set);
    decNumberToString(C_dcml, T_string);
    result= atoi(T_string);

    if (result < 0) return true ;
return false ;
}



bool Zdcml::operator>(const int _X_)
{
    _STRING_ =string_format("%d",_X_);
    decNumberFromString(T_dcml, (char*)_STRING_.c_str(), &T_set);


    decNumberCompare(C_dcml, _dcml, T_dcml, &T_set);
    decNumberToString(C_dcml, T_string);
    result= atoi(T_string);

    if (result > 0) return true ;
return false ;
}

bool  Zdcml::operator!=(const int _X_)
{

    _STRING_ =string_format("%d",_X_);
    decNumberFromString(T_dcml, (char*)_STRING_.c_str(), &T_set);


    decNumberCompare(C_dcml, _dcml, T_dcml, &T_set);
    decNumberToString(C_dcml, T_string);
    result= atoi(T_string);

    if (result != 0) return true ;
return false ;
}

unsigned int  Zdcml::cmp(const int _X_)
{

    _STRING_ =string_format("%d",_X_);
    decNumberFromString(T_dcml, (char*)_STRING_.c_str(), &T_set);

    decNumberCompare(C_dcml, _dcml, T_dcml, &T_set);
    decNumberToString(C_dcml, T_string);
    result= atoi(T_string);

     switch(result){
     case 0  :   CMP = EQ;   break;
     case 1  :   CMP = GT;   break;
     case -1 :   CMP = LT;   break;
     }

return CMP;
}

/// avec un opérateur  long INT
bool  Zdcml::operator==(const long int _X_)
{

    _STRING_ =string_format("%ld",_X_);
    decNumberFromString(T_dcml, (char*)_STRING_.c_str(), &T_set);


    decNumberCompare(C_dcml, _dcml, T_dcml, &T_set);
    decNumberToString(C_dcml, T_string);
    result= atoi(T_string);

    if (result == 0) return true ;
return false ;
}

bool  Zdcml::operator<(const long int _X_)
{

    _STRING_ =string_format("%ld",_X_);
    decNumberFromString(T_dcml, (char*)_STRING_.c_str(), &T_set);


    decNumberCompare(C_dcml, _dcml, T_dcml, &T_set);
    decNumberToString(C_dcml, T_string);
    result= atoi(T_string);

    if (result < 0) return true ;
return false ;
}

bool  Zdcml::operator>(const long int _X_)
{
    _STRING_ =string_format("%ld",_X_);
    decNumberFromString(T_dcml, (char*)_STRING_.c_str(), &T_set);


    decNumberCompare(C_dcml, _dcml, T_dcml, &T_set);
    decNumberToString(C_dcml, T_string);
    result= atoi(T_string);

    if (result > 0) return true ;
return false ;
}


bool  Zdcml::operator!=(const long int _X_)
{
    _STRING_ =string_format("%ld",_X_);
    decNumberFromString(T_dcml, (char*)_STRING_.c_str(), &T_set);


    decNumberCompare(C_dcml, _dcml, T_dcml, &T_set);
    decNumberToString(C_dcml, T_string);
    result= atoi(T_string);

    if (result != 0) return true ;
return false ;
}

unsigned int  Zdcml::cmp(const long int _X_)
{
    _STRING_ =string_format("%ld",_X_);
    decNumberFromString(T_dcml, (char*)_STRING_.c_str(), &T_set);

    decNumberCompare(C_dcml, _dcml, T_dcml, &T_set);
    decNumberToString(C_dcml, T_string);
    result= atoi(T_string);

     switch(result){
     case 0  :   CMP = EQ;   break;
     case 1  :   CMP = GT;   break;
     case -1 :   CMP = LT;   break;
     }
return CMP;

}
/// avec un opérateur  Double
bool  Zdcml::operator==(const double _X_)
{
      _STRING_ =string_format("%s", ZDoubleToChar(_X_ ,_dec));
    decNumberFromString(T_dcml, (char*)_STRING_.c_str(), &T_set);


    decNumberCompare(C_dcml, _dcml, T_dcml, &T_set);
    decNumberToString(C_dcml, T_string);
    result= atoi(T_string);

    if (result == 0) return true ;
return false ;
}

bool Zdcml::operator<(const double _X_)
{
      _STRING_ =string_format("%s", ZDoubleToChar(_X_ ,_dec));
    decNumberFromString(T_dcml, (char*)_STRING_.c_str(), &T_set);


    decNumberCompare(C_dcml, _dcml, T_dcml, &T_set);
    decNumberToString(C_dcml, T_string);
    result= atoi(T_string);

    if (result < 0) return true ;
return false ;
}

bool  Zdcml::operator>(const double _X_)
{
      _STRING_ =string_format("%s", ZDoubleToChar(_X_ ,_dec));
    decNumberFromString(T_dcml, (char*)_STRING_.c_str(), &T_set);


    decNumberCompare(C_dcml, _dcml, T_dcml, &T_set);
    decNumberToString(C_dcml, T_string);
    result= atoi(T_string);

    if (result > 0) return true ;
return false ;
}

bool  Zdcml::operator!=(const double _X_)
{
      _STRING_ =string_format("%s", ZDoubleToChar(_X_ ,_dec));
    decNumberFromString(T_dcml, (char*)_STRING_.c_str(), &T_set);


    decNumberCompare(C_dcml, _dcml, T_dcml, &T_set);
    decNumberToString(C_dcml, T_string);
    result= atoi(T_string);

    if (result != 0) return true ;
return false ;
}

 unsigned int  Zdcml::cmp(const double _X_)
{
    _STRING_ =string_format("%s", ZDoubleToChar(_X_ ,_dec));
    decNumberFromString(T_dcml, (char*)_STRING_.c_str(), &T_set);

    decNumberCompare(C_dcml, _dcml, T_dcml, &T_set);
    decNumberToString(C_dcml, T_string);
    result= atoi(T_string);

     switch(result){
     case 0  :   CMP = EQ;   break;
     case 1  :   CMP = GT;   break;
     case -1 :   CMP = LT;   break;
     }

return CMP;
}
/// avec un opérateur  Zdcml
bool  Zdcml::operator==(const Zdcml  X_dcml)
{
    decNumberCompare(C_dcml, _dcml, X_dcml._dcml, &T_set);
    decNumberToString(C_dcml, T_string);
    result= atoi(T_string);

    if (result == 0) return true ;
return false ;
}

bool  Zdcml::operator<(const Zdcml  X_dcml)
{

    decNumberCompare(C_dcml, _dcml, X_dcml._dcml, &T_set);
    decNumberToString(C_dcml, T_string);
    result= atoi(T_string);

    if (result < 0) return true ;
return false ;
}

bool  Zdcml::operator<=(const Zdcml  X_dcml)
{
    decNumberCompare(C_dcml, _dcml, X_dcml._dcml, &T_set);
    decNumberToString(C_dcml, T_string);
    result= atoi(T_string);

    if (result < 0) return true ;
    if (result == 0) return true ;
return false ;
}

bool  Zdcml::operator>(const Zdcml  X_dcml)
{
    decNumberCompare(C_dcml, _dcml, X_dcml._dcml, &T_set);
    decNumberToString(C_dcml, T_string);
    result= atoi(T_string);

    if (result > 0) return true ;
return false ;
}

bool  Zdcml::operator>=(const Zdcml  X_dcml)
{

    decNumberCompare(C_dcml, _dcml, X_dcml._dcml, &T_set);
    decNumberToString(C_dcml, T_string);
    result= atoi(T_string);

    if (result > 0) return true ;
    if (result == 0) return true ;
return false ;
}


bool  Zdcml::operator!=(const Zdcml  X_dcml)
{
    decNumberCompare(C_dcml, _dcml, X_dcml._dcml, &T_set);
    decNumberToString(C_dcml, T_string);
    result= atoi(T_string);

    if (result != 0) return true ;
return false ;
}
unsigned int  Zdcml::cmp(const Zdcml  X_dcml)
{
    decNumberCompare(C_dcml, _dcml, X_dcml._dcml, &T_set);
    decNumberToString(C_dcml, T_string);
    result= atoi(T_string);

     switch(result){
     case 0  :   CMP = EQ;   break;
     case 1  :   CMP = GT;   break;
     case -1 :   CMP = LT;   break;
     }

return CMP;
}
/// FONCTIONS CHECK  or Is...   -------------------------

unsigned int Zdcml::checkint()
{

    sprintf(zmsg," "); MSGERR=ZONED_OK;

    ClearBufferDcml();

    if( decNumberIsNaN(_dcml))     {MSGERR =ZONED_BAD  ;sprintf(zmsg,"(DCML_NUM_BAD_NUMERIC) -  Msgerror : %d",ZONED_BAD);
                                    decNumberCopy( _dcml,S_dcml);  ClearBufferDcml();      return MSGERR; }

    result=0;
    char* _resultchar_  = (char*) malloc( DECNUMDIGITS+14   * sizeof(char*));
    decNumberToIntegralValue(C_dcml,_dcml,&T_set);

   if (result== 0)   {
    _STRING_ =string_format("%s","+2147483647");
    decNumberFromString(T_dcml, (char*)_STRING_.c_str(), &T_set);
    decNumberCompare(T_dcml, C_dcml , T_dcml, &T_set);
    decNumberToString(T_dcml, _resultchar_ );
    result= atoi(_resultchar_ );
    }
   if (result!= 1)   {
    _STRING_ =string_format("%s","-2147483648");
    decNumberFromString(T_dcml, (char*)_STRING_.c_str(), &T_set);
    decNumberCompare(T_dcml, C_dcml , T_dcml, &T_set);
    decNumberToString(T_dcml, _resultchar_ );
    result= atoi(_resultchar_ );
    if (result == 1) result =0;
    }

    ClearBufferDcml();

      switch(result)
     {
         case 0:
             sprintf(zmsg," "); MSGERR = ZONED_OK;
             break;
         case -1:
             sprintf(zmsg,"(Msgerror == DCML_NUM_OVERFLOW) -  Msgerror : %d",ZONED_OVR); MSGERR = ZONED_OVR ;
             break;
         case 1:
             sprintf(zmsg,"(Msgerror == DCML_NUM_UNDERFLOW) - Msgerror : %d",ZONED_UND); MSGERR = ZONED_UND ;
             break;
     }

    return MSGERR;
}


unsigned  int Zdcml::checklongint()
{
    sprintf(zmsg," "); MSGERR=ZONED_OK;

    if( decNumberIsNaN(_dcml))     {MSGERR =ZONED_BAD  ;sprintf(zmsg,"(DCML_NUM_BAD_NUMERIC) -  Msgerror : %d",ZONED_BAD);
                                    decNumberCopy( _dcml,S_dcml);  ClearBufferDcml();     return MSGERR; }

    ClearBufferDcml();
    result=0;
    char* _resultchar_  = (char*) malloc( DECNUMDIGITS+14   * sizeof(char*));
    decNumberToIntegralValue(C_dcml,_dcml,&T_set);

   if (result== 0)   {
     _STRING_ =string_format("%s","+9223372036854775807 ");

    decNumberFromString(T_dcml, (char*)_STRING_.c_str(), &T_set);
    decNumberFromString(T_dcml, (char*)_STRING_.c_str(), &T_set);
    decNumberCompare(T_dcml, C_dcml , T_dcml, &T_set);
    decNumberToString(T_dcml, _resultchar_ );
    result= atoi(_resultchar_ );
    }
   if (result!= 1)   {
     _STRING_ =string_format("%s","-9223372036854775808");
    decNumberFromString(T_dcml, (char*)_STRING_.c_str(), &T_set);
    decNumberCompare(T_dcml, C_dcml , T_dcml, &T_set);
    decNumberToString(T_dcml, _resultchar_ );
    result= atoi(_resultchar_ );
    if (result == 1) result =0;
    }

    ClearBufferDcml();

      switch(result)
     {
         case 0:
             sprintf(zmsg," "); MSGERR = ZONED_OK;
             break;
         case -1:
             sprintf(zmsg,"(Msgerror == DCML_NUM_OVERFLOW) -  Msgerror : %d",ZONED_OVR); MSGERR = ZONED_OVR ;
             break;
         case 1:
             sprintf(zmsg,"(Msgerror == DCML_NUM_UNDERFLOW) - Msgerror : %d",ZONED_UND); MSGERR = ZONED_UND ;
             break;
     }

    return MSGERR;
}

unsigned  int Zdcml::checkdouble()
{

    sprintf(zmsg," "); MSGERR=ZONED_OK;

    if( decNumberIsNaN(_dcml))     {MSGERR =ZONED_BAD  ;sprintf(zmsg,"(DCML_NUM_BAD_NUMERIC) -  Msgerror : %d",ZONED_BAD);
                                    decNumberCopy( _dcml,S_dcml);  ClearBufferDcml();     return MSGERR; }

    ClearBufferDcml();

    result=0;
    char* _resultchar_  = (char*) malloc( DECNUMDIGITS+14   * sizeof(char*));

    T_set.digits = _entier + _dec;
    decContextSetRounding(&T_set,DEC_ROUND_DOWN);
    if ( _round  )     decContextSetRounding(&T_set,DEC_ROUND_HALF_EVEN);
    decNumberToString(_dcml, T_string);
    decNumberFromString(C_dcml, T_string,&T_set);

   if (result== 0)   {          //15 digit maxi
    _STRING_ =string_format("%s","999999999999999");
    decNumberFromString(T_dcml, (const char*)_STRING_.c_str(), &T_set);
    decNumberCompare(T_dcml,  C_dcml,T_dcml, &T_set);
    decNumberToString(T_dcml, _resultchar_ );
    result= atoi(_resultchar_ );
    }
   if (result== -1)   {          //15 digit maxi
    _STRING_ =string_format("%s","-999999999999999");
    decNumberFromString(T_dcml, (const char*)_STRING_.c_str(), &T_set);
    decNumberCompare(T_dcml,  C_dcml,T_dcml, &T_set);
    decNumberToString(T_dcml, _resultchar_ );
    result= atoi(_resultchar_ );
    if (result == 1) result =0;
    }

    ClearBufferDcml();

      switch(result)
     {
         case 0:
             sprintf(zmsg," " );  MSGERR = ZONED_OK;
             break;
         case -1:
             sprintf(zmsg,"(Msgerror == DCML_NUM_OVERFLOW) -  Msgerror : %d",ZONED_OVR); MSGERR = ZONED_OVR ;
             break;
         case 1:
             sprintf(zmsg,"(Msgerror == DCML_NUM_UNDERFLOW) - Msgerror : %d",ZONED_UND); MSGERR = ZONED_UND ;
             break;
     }
    return MSGERR;
}

unsigned int Zdcml::chekoverflow()
{
    sprintf(zmsg," "); MSGERR=ZONED_OK;

    ClearBufferDcml();

    T_set.digits = _entier + _dec;
    decContextSetRounding(&T_set,DEC_ROUND_DOWN);
    if ( _round  )     decContextSetRounding(&T_set,DEC_ROUND_HALF_EVEN);
    decNumberToString(_dcml, T_string);
    decNumberFromString(C_dcml, T_string,&T_set);


    if (!isnegative()) {
        decNumberFromString(T_dcml, n_mask,&T_set);
        decNumberCompare(C_dcml, C_dcml, T_dcml, &T_set);

        decNumberToString(C_dcml,T_string );
       result= atoi(T_string );


    ClearBufferDcml();

        if (result < 0 ) {
            MSGERR = ZONED_OVR;
            sprintf(zmsg,"Msgerror - entier + dec  != length ?value? DCML_NUM_OVERFLOW  -- Msgerror : %d" , ZONED_OVR );

            return MSGERR;
        }
    }

    if (!isnegative()) {
        decNumberFromString(T_dcml, p_mask,&T_set);
        decNumberCompare(C_dcml, C_dcml, T_dcml, &T_set);

        decNumberToString(C_dcml,T_string );
       result= atoi(T_string );
        if (result >0) {
            MSGERR = ZONED_OVR;
            sprintf(zmsg,"(Msgerror == DCML_NUM_UNDERFLOW) -  Msgerror : %d",ZONED_UND); MSGERR = ZONED_UND ;

            return MSGERR;
        }
    }


    return MSGERR;
}




bool Zdcml::isnumeric(const char *_X_)
{

bool hitDecimal=false;
bool negDecimal=false;
bool posDecimal=false;
  for( size_t  i =0; i < strlen(_X_); i++ )
  {
        if ( _X_[i]=='.' ) { // 2 '.' in string mean invalid
        if ( _X_[i]=='.' && hitDecimal         )  return false;
        if ( _X_[i]=='.')   hitDecimal =  true;
        continue;
    }
    else if ( _X_[i] =='-' ) { // 2 '+' in string mean invalid
         if ( _X_[i] =='-' && negDecimal        )  return false;
         if ( _X_[i] =='-')   negDecimal =  true;
         if ( i   > 0    &&  negDecimal        )   return false;
        continue;
    }
    else if ( _X_[i] =='+' ) { // 2 '+' in string mean invalid
         if ( _X_[i] =='+' && posDecimal == true ) return false;
         if ( _X_[i] =='+')   posDecimal =  true;
         if ( i > 0    &&  posDecimal         )    return false;
        continue;
    }
         if( !isdigit( _X_[i] ) )                  return false; // not ., not
  }


  return true;
}

bool Zdcml::iszeros()
{
    if(decNumberIsZero(_dcml)) return true;
    return false;
}


bool Zdcml::isnegative()
{
    if( decNumberIsNegative(_dcml))  return true;
    return false;
}


bool Zdcml::isdecimale()
{
    ClearBufferDcml();

    decNumberCopy(C_dcml,_dcml);

    decNumberFromString(T_dcml, toentier(),&T_set);
    decNumberSubtract(C_dcml,C_dcml,T_dcml,&T_set);

    if( ! decNumberIsZero(C_dcml)) return false;
    return true;
}


/// FONCTIONS OUTPUT ---return VAL-------------------------


char * Zdcml::toentier()
  {
  if(___obligatoire___ )  return (char*)("0");

    sprintf(zmsg," "); MSGERR=ZONED_OK;

    if( decNumberIsNaN(_dcml))     {MSGERR =ZONED_BAD  ;sprintf(zmsg,"(DCML_NUM_BAD_NUMERIC) -  Msgerror : %d",ZONED_BAD);
                                    decNumberCopy( _dcml,S_dcml);  ClearBufferDcml(); return (char*)("0"); }

#ifndef _DEBUG_   /// pour tester les formules
    if ( ZONED_OK != chekoverflow()) {ClearBufferDcml();  return (char*)("0"); }
#endif

    ClearBufferDcml();  sprintf(T_string,"%c",'\0');

    decNumberCopy(C_dcml,_dcml);

    decNumberToIntegralValue(C_dcml,_dcml,&T_set);
    decNumberToString(C_dcml, T_string);


    ClearBufferDcml();
    return  (char* )T_string;
}

char * Zdcml::todec()
  {

  if(___obligatoire___ )  return (char*)("0");

    sprintf(zmsg," "); MSGERR=ZONED_OK;

    if( decNumberIsNaN(_dcml))     {MSGERR =ZONED_BAD  ;sprintf(zmsg,"(DCML_NUM_BAD_NUMERIC) -  Msgerror : %d",ZONED_BAD);
                                    decNumberCopy( _dcml,S_dcml);  ClearBufferDcml(); return (char*)("0"); }
     decNumber  *X_dcml; X_dcml  = new decNumber ;
     ClearBufferDcml();


    sprintf(T_string,"%c",'\0'); sprintf(T_value,"%c",'\0');
    decNumberToString(_dcml, T_string); T_string=ZLTrim(T_string);
    std::string _test = std::string(T_string);
    std::size_t found; std::string ent ;    found =_test.find_last_of(".");    _test.substr(0,found);
    found=_test.find('.'); // sprintf(T_value,"%ld  %s    %s", found ,T_string, _test.c_str()); return  (char* )T_value;

    ent = _test.substr(0,found);  if(found != _test.rfind(".",0) )  T_set.digits = ent.size() + _dec; else T_set.digits = ent.size() ;
    found=_test.find('-');
    if(found== 0)T_set.digits  --;
    decContextSetRounding(&T_set,DEC_ROUND_DOWN);
    if ( _round  )     decContextSetRounding(&T_set,DEC_ROUND_HALF_EVEN);
    decNumberFromString(X_dcml, T_string,&T_set);
    decNumberToString(X_dcml, T_string);


   sprintf(T_value,"%s",T_string);
    ClearBufferDcml();

    return    T_value;
}


char* Zdcml::tochar(bool signe)
{
if(___obligatoire___ ) {     return (char*)("0"); }

    sprintf(zmsg," "); MSGERR=ZONED_OK;

    if( decNumberIsNaN(_dcml))     {MSGERR =ZONED_BAD  ;sprintf(zmsg,"(DCML_NUM_BAD_NUMERIC) -  Msgerror : %d",ZONED_BAD);
                                    decNumberCopy( _dcml,S_dcml);  ClearBufferDcml(); return (char*)("0");}

#ifndef _DEBUG_   /// pour tester les formules
    if ( ZONED_OK != chekoverflow()) {ClearBufferDcml();  return (char*)("0"); }
#endif


    ClearBufferDcml();


    sprintf(T_string,"%c",'\0'); sprintf(T_value,"%c",'\0');
      decNumber  *X_dcml; X_dcml  = new decNumber ;  decNumberCopy( X_dcml,_dcml);
     if(isnegative()) {
    _STRING_ =string_format("-%ld",1);
    decNumberFromString(T_dcml, (char*)_STRING_.c_str(),&T_set);
    decNumberMultiply(X_dcml, _dcml,T_dcml,&T_set);
    }


    decNumberToString(X_dcml, T_string);
    decContextSetRounding(&T_set,DEC_ROUND_DOWN);
    if ( _round  )     decContextSetRounding(&T_set,DEC_ROUND_HALF_EVEN);


    std::string _test = std::string(T_string);
    std::size_t found; std::string ent ;
    found=_test.find('.');
    ent = _test.substr(0,found);  if(found != _test.rfind(".",0) )  T_set.digits = ent.size() + _dec; else T_set.digits = ent.size() ;

    decNumberFromString(X_dcml, T_string,&T_set);
    decNumberToString(X_dcml, T_string);



    T_string=ZTrim(T_string);

     /// cherche si 0
     if(  decNumberIsZero(X_dcml)  || decNumberIsNaN(X_dcml) ) sprintf(T_value,"0") ;
    else {  if( signe == true)  {      if(isnegative())   sprintf(T_value,"-");else sprintf(T_value,"+"); }
                /// calcul la longueur pour le pading '0'
                for (unsigned  int u= ent.size(); u< _entier; u++) strcat(T_value,"0");
            strcat(T_value,T_string);
    }
       sprintf(T_value,"%s",T_value);
     ClearBufferDcml();

    return   T_value;
}


const char* Zdcml::toconstchar(bool signe) {
if(___obligatoire___ ) {     return (char*)("0"); }
   sprintf(zmsg," "); MSGERR=ZONED_OK;

    if( decNumberIsNaN(_dcml))     {MSGERR =ZONED_BAD  ;sprintf(zmsg,"(DCML_NUM_BAD_NUMERIC) -  Msgerror : %d",ZONED_BAD);
                                    decNumberCopy( _dcml,S_dcml);  ClearBufferDcml(); return (char*)("0");}

#ifndef _DEBUG_   /// pour tester les formules
    if ( ZONED_OK != chekoverflow()) {ClearBufferDcml();  return (char*)("0"); }
#endif


    ClearBufferDcml();


    sprintf(T_string,"%c",'\0'); sprintf(T_value,"%c",'\0');
      decNumber  *X_dcml; X_dcml  = new decNumber ;  decNumberCopy( X_dcml,_dcml);
     if(isnegative()) {
    _STRING_ =string_format("-%ld",1);
    decNumberFromString(T_dcml, (char*)_STRING_.c_str(),&T_set);
    decNumberMultiply(X_dcml, _dcml,T_dcml,&T_set);
    }


    decNumberToString(X_dcml, T_string);
    decContextSetRounding(&T_set,DEC_ROUND_DOWN);
    if ( _round  )     decContextSetRounding(&T_set,DEC_ROUND_HALF_EVEN);


    std::string _test = std::string(T_string);
    std::size_t found; std::string ent ;
    found=_test.find('.');
    ent = _test.substr(0,found);  if(found != _test.rfind(".",0) )  T_set.digits = ent.size() + _dec; else T_set.digits = ent.size() ;

    decNumberFromString(X_dcml, T_string,&T_set);
    decNumberToString(X_dcml, T_string);



    T_string=ZTrim(T_string);

     /// cherche si 0
     if(  decNumberIsZero(X_dcml)  || decNumberIsNaN(X_dcml) ) sprintf(T_value,"0") ;
    else {  if( signe == true)  {      if(isnegative())   sprintf(T_value,"-");else sprintf(T_value,"+"); }
            strcat(T_value,T_string);
    }
       sprintf(T_value,"%s",T_value);
     ClearBufferDcml();
return (const char *) T_value;
}


std::string Zdcml::tostring(bool signe) {
if(___obligatoire___ ) {     return std::string("0"); }
if(___obligatoire___ ) {     return (char*)("0"); }

    sprintf(zmsg," "); MSGERR=ZONED_OK;

    if( decNumberIsNaN(_dcml))     {MSGERR =ZONED_BAD  ;sprintf(zmsg,"(DCML_NUM_BAD_NUMERIC) -  Msgerror : %d",ZONED_BAD);
                                    decNumberCopy( _dcml,S_dcml);  ClearBufferDcml(); return (char*)("0");}

#ifndef _DEBUG_   /// pour tester les formules
    if ( ZONED_OK != chekoverflow()) {ClearBufferDcml();  return (char*)("0"); }
#endif


    ClearBufferDcml();


    sprintf(T_string,"%c",'\0'); sprintf(T_value,"%c",'\0');
      decNumber  *X_dcml; X_dcml  = new decNumber ;  decNumberCopy( X_dcml,_dcml);
     if(isnegative()) {
    _STRING_ =string_format("-%ld",1);
    decNumberFromString(T_dcml, (char*)_STRING_.c_str(),&T_set);
    decNumberMultiply(X_dcml, _dcml,T_dcml,&T_set);
    }


    decNumberToString(X_dcml, T_string);
    decContextSetRounding(&T_set,DEC_ROUND_DOWN);
    if ( _round  )     decContextSetRounding(&T_set,DEC_ROUND_HALF_EVEN);


    std::string _test = std::string(T_string);
    std::size_t found; std::string ent ;
    found=_test.find('.');
    ent = _test.substr(0,found);  if(found != _test.rfind(".",0) )  T_set.digits = ent.size() + _dec; else T_set.digits = ent.size() ;

    decNumberFromString(X_dcml, T_string,&T_set);
    decNumberToString(X_dcml, T_string);



    T_string=ZTrim(T_string);

     /// cherche si 0
     if(  decNumberIsZero(X_dcml)  || decNumberIsNaN(X_dcml) ) sprintf(T_value,"0") ;
    else {  if( signe == true)  {      if(isnegative())   sprintf(T_value,"-");else sprintf(T_value,"+"); }
            strcat(T_value,T_string);
    }
       sprintf(T_value,"%s",T_value);
     ClearBufferDcml();

return std::string(T_value);
}





int Zdcml::toint()
{
if(___obligatoire___ ) return 0;

    sprintf(zmsg," "); MSGERR=ZONED_OK;

   if (ZONED_OK != checkint())  {return 0;}

    ClearBufferDcml();

    decNumberToIntegralValue(C_dcml,_dcml,&T_set);


    decNumberToString(C_dcml, T_value);
    ClearBufferDcml();
    return atoi(T_value);
}


long int Zdcml::tolongint()
{
if(___obligatoire___ ) return 0;

    sprintf(zmsg," "); MSGERR=ZONED_OK;

    if (ZONED_OK != checklongint())  {return 0;}

    ClearBufferDcml();

    _STRING_ =string_format("%ld",1);
    decNumberFromString(T_dcml, (char*)_STRING_.c_str(), &T_set);
    decNumberDivideInteger(C_dcml,_dcml,T_dcml,&T_set);

    decNumberToString(C_dcml,T_value);
    ClearBufferDcml();

    return atol(T_value);
}



double Zdcml::todouble()
{
if(___obligatoire___ ) return 0;

    sprintf(zmsg," "); MSGERR=ZONED_OK;

 if (ZONED_OK != checkdouble())  {return 0;}

    sprintf(T_value,"%s", tochar());
    ClearBufferDcml();

    //15 digit maxi
    return strtod (T_value, NULL);
}



bool Zdcml::istypdbl()
{
    sprintf(zmsg," "); MSGERR=ZONED_OK;

         if (ZONED_OK != checkdouble()  || _dec > 5 ) {
        MSGERR = ZONED_OVR ;
        sprintf(zmsg,"%s %d","Msgerror - entier + dec = Max(15) dec =max(5) DCML_NUM_OVERFLOW  --   code Msgerror: " , ZONED_OVR );
        return false;
         } else return true;
}

bool Zdcml::istypint()
{
    sprintf(zmsg," "); MSGERR=ZONED_OK;

         if ( ZONED_OK != checkint()  ||_dec > 0 ) {
        MSGERR = ZONED_OVR ;
        sprintf(zmsg,"%s %d","Msgerror - entier + dec = Max(10) dec =max(0) DCML_NUM_OVERFLOW  --   -2147483648 à +2147483647   code Msgerror: " , ZONED_OVR );
        return false;
         } else return true;
}

bool Zdcml::istyplongint()
{
    sprintf(zmsg," "); MSGERR=ZONED_OK;

         if (ZONED_OK != checklongint() ||_dec > 0 ) {
        MSGERR = ZONED_OVR ;
        sprintf(zmsg,"%s %d","Msgerror - entier + dec = Max(21) dec =max(0) DCML_NUM_OVERFLOW  --   -9223372036854775808 à +9223372036854775807    code Msgerror: " , ZONED_OVR );
        return false;
         } else return true;
}

char* Zdcml::ZLTrim(char* _X_)
{
    if(' '==_X_[0]) while(' '==(++_X_)[0]);
    return _X_;
}

char* Zdcml::ZRTrim(char* _X_)
{
    int i = strlen(_X_);
    while(' '==_X_[--i]) _X_[i] = 0;
    return _X_;
}

char* Zdcml::ZTrim(char* _X_)
{
    _X_ = ZLTrim(_X_);
    _X_ = ZRTrim(_X_);
    return _X_;
}
char* Zdcml::ZLTrim0(char* _X_)
{
    if('0'==_X_[0]) while('0'==(++_X_)[0]);
    return _X_;
}

char* Zdcml::ZRTrim0(char* _X_)
{
    int i = strlen(_X_);
    while('0'==_X_[--i]) _X_[i] = 0;
    return _X_;
}

char* Zdcml::ZTrim0(char* _X_)
{
    _X_ = ZLTrim0(_X_);
    _X_ = ZRTrim0(_X_);
    return _X_;
}




void Zdcml::toround() { _round = true ;}
void Zdcml::noround() { _round = false ;}
bool Zdcml::isround() { return _round ;}
/// code retour Msgerror or ok------------------------------
unsigned int Zdcml::status() {return MSGERR;}
char* Zdcml::statusmsg() {return zmsg;}
bool  Zdcml::msgerr() { if (MSGERR == ZONED_OK ) return false; else return true ;}

/// Double to char -----------------------------
char* Zdcml::ZDoubleToChar(double _X_ ,unsigned _precision_)
{
        char sign = _X_ >= 0 ? '+' : '-';
        char * X_value   = (char*) malloc(256  * sizeof(char*));   sprintf(X_value,"%c",'\0');
        char * X_cmd     = (char*) malloc(256  * sizeof(char*));   sprintf(X_cmd,"%s%c%d.0%d%c","%c",'%',0,_precision_,'f');

        snprintf(X_value + strlen(X_value), 16, X_cmd , sign, fabs(_X_));

return (char*) X_value;

}
/// Format String--idem sprintf --------------------------
std::string Zdcml::string_format(const std::string fmt, ...)
{
if(___obligatoire___ ) return "" ;

    std::string str;
    va_list ap;
    va_start(ap, fmt);
    int size = vsnprintf(0, 0, (const char*)fmt.c_str(), ap) + sizeof('\0');
    va_end(ap);

    while (1) {     // Maximum two passes on a POSIX system...
        str.resize(size);
        va_start(ap, fmt);
        int n = vsnprintf((char *)str.data(), size, fmt.c_str(), ap);
        va_end(ap);
        if (n > -1 && n < size) {  // Everything worked
            str.resize(n);
            return str;
        }
        if (n > -1)  // Needed size returned
            size = n + 1;   // For null char
        else
            size *= 2;      // Guess at a larger size (OS specific)
    }
    return str;
}







///CONSTRUCTEURS tampon---------avec valeur positive ----------------------------------
void Zdcml::rtvchar(const char* _X_)
{
if(___obligatoire___ ) return ;

    sprintf(zmsg," "); MSGERR=ZONED_OK;

    if ( !isnumeric(_X_))  { MSGERR=ZONED_BAD;
                             sprintf(zmsg,"(DCML_NUM_BAD_NUMERIC) - Msgerror : %d",ZONED_BAD);
                                        return; } ;


    decNumberZero(C_dcml);    decNumberZero(T_dcml);


    decNumberFromString(C_dcml,_X_, &T_set);

#ifndef _DEBUG_   /// pour tester les formules
    std::string _test = std::string(_X_);
    std::size_t found;
    found=_test.find('.');
    if(found != _test.rfind(".",0) ) {
    if(!decNumberIsNegative(C_dcml))
    if( (strlen(_X_) > 33)  ) {
        MSGERR= ZONED_OVR; decNumberZero(C_dcml);
        sprintf(zmsg,"(DCML_NUM_BAD_NUMERIC) - Max 31 digits  Msgerror : %d",ZONED_OVR);  /// +1 signe   +1 .
                                        return; }
    if(decNumberIsNegative(C_dcml))
    if( (strlen(_X_) > 32)  ) {

        MSGERR= ZONED_OVR; decNumberZero(C_dcml);
        sprintf(zmsg,"(DCML_NUM_BAD_NUMERIC) - Max 31 digits  Msgerror : %d",ZONED_OVR);  /// +1 signe
                                        return; }
    } else {
    if(!decNumberIsNegative(C_dcml))
    if( (strlen(_X_) > 32)  ) {
        MSGERR= ZONED_OVR; decNumberZero(C_dcml);
        sprintf(zmsg,"(DCML_NUM_BAD_NUMERIC) - Max 31 digits   Msgerror : %d",ZONED_OVR);  /// +1 signe   +1 .
                                        return; }
    if(decNumberIsNegative(C_dcml))
    if( (strlen(_X_) > 31)  ) {

        MSGERR= ZONED_OVR; decNumberZero(C_dcml);
        sprintf(zmsg,"(DCML_NUM_BAD_NUMERIC) - Max 31 digits  Msgerror : %d",ZONED_OVR);  /// +1 signe
                                        return; }

    }
    std::string ent ;
    found=_test.find('.');
    if(found != _test.rfind(".",0) )
    {           _test = std::string(_X_);
                ent = _test.substr(0,found);
                if( _entier < ent.size()-1 )
                        {
                        MSGERR= ZONED_OVR; decNumberZero(C_dcml);
                        sprintf(zmsg,"(DCML_NUM_BAD_NUMERIC) - Max 31 digits   Msgerror : %d",ZONED_OVR);  /// +1 signe   +1 .
                        return;}
    } else {
                _test = std::string(_X_);
                ent = _test.substr(0,found);
                if( _entier < ent.size()-1 )
                        {
                        MSGERR= ZONED_OVR; decNumberZero(C_dcml);
                        sprintf(zmsg,"(DCML_NUM_BAD_NUMERIC) - Max 31 digits   Msgerror : %d",ZONED_OVR);  /// +1 signe   +1 .
                        return;}
    }




  // std::cout<<"_____________"<< T_string<<"  ent:"<<ent.size()<<"   len:"<<_entier<<"\n"<<std::endl;
#endif
        return ;

}

}
#endif // ZDCML_HPP_INCLUDED
