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
#ifndef ZDCML_CPP_INCLUDED
#define ZDCML_CPP_INCLUDED



#include <Zdcml.h>
namespace ZONED
{




	
//CONSTRUCTEURS ----------------------------------------------------------------
Zdcml::Zdcml(unsigned int _e_  ,unsigned int _d_  )
  {
    _entier = _e_; _dec=_d_;    CMP=0;
	CPFERR= false ; CPFMSG = "";



     if (_e_ > 34) CPFERR= true ;
     if (_e_ < 1)  CPFERR= true ;
     if (_d_ > 34) CPFERR= true ;
     if ( (_d_ + _e_ ) > 34  ) CPFERR=true;  
     

     if (CPFERR ) { throw std::invalid_argument("CPFERRor - BAD DEFINE  - Max 31 digits OVERFLOW : init" ); }

    T_char = (char*) malloc(36  * sizeof(char*));

    T_string = (char*) malloc(36  * sizeof(char*));


    decContextDefault(&T_set, DEC_INIT_DECIMAL128 );    // initialize
    T_set.digits = _entier+ _dec;                       // initialize
    decContextSetRounding(&T_set,DEC_ROUND_DOWN);


    _dcml  = new decNumber ;    /// Zoned Reel
    T_dcml = new decNumber ;    /// Zoned Travail
    C_dcml = new decNumber ;    /// Zoned Copy


    decNumberZero( _dcml);  
    decNumberZero(T_dcml);
    decNumberZero(C_dcml);


	/// preparation des mask pour les contrôles

	p_mask = (char*) malloc(36  * sizeof(char*));
        
	unsigned int pos =0, posd = 0;
        
	p_mask[pos] ='+';  /// positif
        
	for ( pos=1 ; pos < _entier+1;pos++ ) p_mask[pos] ='9';
        
	if (_dec > 0)
		{
			p_mask[pos] ='.';
			for (pos++, posd=0; posd < _dec;posd++,pos++ ) p_mask[pos] ='9';
        }
	n_mask = (char*) malloc(36  * sizeof(char*));
        
	pos =0; posd = 0;
        
	n_mask[pos ] ='-'; /// negatif
        
	for ( pos=1 ; pos < _entier+1;pos++ ) n_mask[pos] ='9';
        
	if (_dec > 0)
	{
		n_mask[pos] ='.';
		for (pos++, posd=0; posd < _dec;posd++,pos++ ) n_mask[pos] ='9';

	}

}


Zdcml::~Zdcml()   { }

void Zdcml::ClearBufferDcml()
{
	decContextDefault(&T_set, DEC_INIT_DECIMAL128 );    // initialize
	T_set.digits = 128;                      // initialize
	decContextSetRounding(&T_set,DEC_ROUND_DOWN);
	delete T_dcml ; T_dcml = new decNumber ;    /// Zoned Travail
	delete C_dcml ; C_dcml = new decNumber ;    /// Zoned Travail
	decNumberZero(T_dcml);
	decNumberZero(C_dcml);
}

/// operateur

Zdcml& Zdcml::operator=(const int _I_)
{
	CPFERR= false ; CPFMSG = "";
	
	_STRING_ = std::to_string(_I_);

	const char *  _X_ =	  _STRING_.c_str();

    ClearBufferDcml();
    
    /// contrôle validité
    if (  _I_ != 0 )
    {
		decNumberFromString( T_dcml, _X_ , &T_set);	

		decNumberTrim( T_dcml);
    
		if ( decNumberIsNaN(T_dcml) || CheckOverflow())
		{
			decNumberFromString( _dcml, "" , &T_set);
			CPFERR = true ;  CPFMSG = "DCML numeric  Int invalid :" + _STRING_;  return *this;
		}
	}

    
    if ( _I_ != 0 )
    {
		printformat();
		decNumberToString(T_dcml, T_char);
		decNumberFromString( _dcml, T_char, &T_set);
	}
    else decNumberZero(_dcml);

    ClearBufferDcml();
    return *this;
}



Zdcml& Zdcml::operator=(const long int _I_)
{

	CPFERR= false ; CPFMSG = "";
 
	_STRING_ = std::to_string(_I_);

	const char *  _X_ =   _STRING_.c_str(); 

    ClearBufferDcml();
    
    /// contrôle validité
    if (  _I_ != 0 )
    {
		decNumberFromString( T_dcml, _X_ , &T_set);

		decNumberTrim( T_dcml);
   
		if ( decNumberIsNaN(T_dcml) || CheckOverflow())
		{
			decNumberFromString( _dcml, "" , &T_set);
			CPFERR = true ;  CPFMSG = "DCML numeric  Int invalid :" + std::string(_X_);  return *this;
		}
	}

    
    if ( _I_ != 0 )
    {
		printformat();
		decNumberToString(T_dcml, T_char);
		decNumberFromString( _dcml, T_char, &T_set);
	}
    else decNumberZero(_dcml);
		
    ClearBufferDcml();
    return *this;
}



Zdcml& Zdcml::operator=(const double _D_)
{
	CPFERR= false ; CPFMSG = "";
	
 
	_STRING_ = _STRING_ = ZDoubleToChar(_D_,_dec);
	
	std::string ponct=",";
	int pos = _STRING_.find(ponct);
	if (pos >= 0 ) _STRING_.replace(pos,ponct.length(),".");
	
	const char *  _X_ =   _STRING_.c_str();	

    ClearBufferDcml();
    /// contrôle validité
    if ( _D_ != 0)
    {

		decNumberFromString( T_dcml, _X_ , &T_set);

		decNumberTrim( T_dcml);

		if ( decNumberIsNaN(T_dcml) || CheckOverflow())
		{
			decNumberFromString( _dcml, "" , &T_set);
			CPFERR = true ;  CPFMSG = "DCML numeric  Double invalid :" + std::string(_X_);  return *this;
		}
	}


	/// enregitrement de la valeur
    if ( _D_ != 0 )
    {
		printformat();
		decNumberToString(T_dcml, T_char);
		decNumberFromString( _dcml, T_char, &T_set);
	}
    else decNumberZero(_dcml);

    ClearBufferDcml();
    return *this;
}



Zdcml& Zdcml::operator=(const char* _C_)
{
	CPFERR= false ; CPFMSG = "";

    ClearBufferDcml();

    _STRING_ = _C_;

	std::string ponct=",";
	int pos = _STRING_.find(ponct);            
	if (pos >= 0 ) _STRING_.replace(pos,ponct.length(),".");
	
	const char *  _X_ =   _STRING_.c_str();	
    /// contrôle validité
    if ( _X_ != NULL )
    {
		decNumberFromString( T_dcml, _X_ , &T_set);

		decNumberTrim( T_dcml);

		if ( decNumberIsNaN(T_dcml) || CheckOverflow())
		{
			decNumberFromString( _dcml, "" , &T_set);
			CPFERR = true ;  CPFMSG = "DCML numeric  Double invalid :" + std::string(_X_);  return *this;
		}
	}


    if ( _X_ != NULL )
    {
		printformat();
		decNumberToString(T_dcml, T_char);
		decNumberFromString( _dcml, T_char, &T_set);
	}
    else decNumberZero(_dcml);

    ClearBufferDcml();
    return *this;
}



Zdcml& Zdcml::operator=(std::string _S_)
{
	CPFERR= false ; CPFMSG = "";

    ClearBufferDcml();
    

	_STRING_ = _S_;

	
	std::string ponct=",";
	int pos = _STRING_.find(ponct);            
	if (pos >= 0 ) _STRING_.replace(pos,ponct.length(),".");
	
	const char *  _X_ =   _STRING_.c_str();	
    /// contrôle validité
    if ( _X_ != NULL )
    {
		decNumberFromString( T_dcml, _X_ , &T_set);

		decNumberTrim( T_dcml);
    
		if ( decNumberIsNaN(T_dcml) || CheckOverflow())
		{
			decNumberFromString( _dcml, "" , &T_set);
			CPFERR = true ;  CPFMSG = "DCML numeric  Double invalid :" + std::string(_X_);  return *this;
		}
	}

    if ( _X_ != NULL )
    {
		printformat();
		decNumberToString(T_dcml, T_char);
		decNumberFromString( _dcml, T_char, &T_set);
	}
    else decNumberZero(_dcml);

    ClearBufferDcml();
    return *this;
}



Zdcml& Zdcml::operator=(const Zdcml X_dcml)
{
	CPFERR= false ; CPFMSG = "";

    ClearBufferDcml();

	char *  _X_ =  (char*) malloc(36  * sizeof(char*));
	
	decNumberToString(X_dcml._dcml, _X_);
    /// contrôle validité

	decNumberFromString( T_dcml, _X_ , &T_set);		/// enter val form this

	decNumberTrim( T_dcml);	/// left rigth  trim 0

	if ( decNumberIsNaN(T_dcml) || CheckOverflow())
	{
		decNumberFromString( _dcml, "" , &T_set);
		CPFERR = true ;  CPFMSG = "DCML numeric  Double invalid :" + std::string(_X_);  return *this;
	}
	
    decNumberFromString( _dcml, T_char, &T_set);

    ClearBufferDcml();
    return *this;
}



/// operateur


/// operation arithmetique

Zdcml& Zdcml::operator++(int)
{
    ClearBufferDcml();

    _STRING_ =string_format("%d",1);		std::cout<<_STRING_<<std::endl;
    
    decNumberFromString( T_dcml, (char*)_STRING_.c_str(), &T_set);

	decNumberAdd(_dcml, _dcml, T_dcml ,&T_set);
	
	decNumberTrim(_dcml);
	return *this;
}



Zdcml& Zdcml::operator--(int)
{
    ClearBufferDcml();

    _STRING_ =string_format("%d",1);		std::cout<<_STRING_<<std::endl;
    
    decNumberFromString( T_dcml, (char*)_STRING_.c_str(), &T_set);

	decNumberSubtract(_dcml, _dcml, T_dcml ,&T_set);
	
	return *this;
}



Zdcml& Zdcml::operator+=(const  int _X_)
{
    ClearBufferDcml();

    _STRING_ =std::to_string(_X_);
    
    decNumberFromString( T_dcml, (char*)_STRING_.c_str(), &T_set);

	decNumberAdd(_dcml, _dcml, T_dcml ,&T_set);

	return *this;
}



Zdcml& Zdcml::operator-=(const  int _X_)
{

	ClearBufferDcml();

    _STRING_ =std::to_string(_X_);
    
    decNumberFromString( T_dcml, (char*)_STRING_.c_str(), &T_set);

	decNumberSubtract(_dcml, _dcml, T_dcml ,&T_set);

	return *this;
}



Zdcml& Zdcml::operator*=(const  int _X_)
{
    ClearBufferDcml();

    _STRING_ =std::to_string(_X_);
    
    decNumberFromString( T_dcml, (char*)_STRING_.c_str(), &T_set);

    
    decNumberMultiply(_dcml, _dcml, T_dcml ,&T_set);
    
	return *this;
}



Zdcml& Zdcml::operator/=(const  int _X_)
{
	ClearBufferDcml();

    _STRING_ =std::to_string(_X_);
    
    decNumberFromString( T_dcml, (char*)_STRING_.c_str(), &T_set);
    
    if(decNumberIsZero(T_dcml))    { throw std::invalid_argument("(msg error :DCML numeric ) DIV 0 : /=int"); }

   	decNumberDivide(_dcml, _dcml,T_dcml,&T_set);

    return *this;
}



Zdcml& Zdcml::operator%=(const int _X_)
{
    ClearBufferDcml();

    _STRING_ =std::to_string(_X_);
    
    decNumberFromString(T_dcml, (char*)_STRING_.c_str(), &T_set);

    decNumberRemainder(_dcml, _dcml ,C_dcml, &T_set);

    return *this;
}



Zdcml& Zdcml::operator+=(const long int _X_)
{
    ClearBufferDcml();

    _STRING_ =string_format("%ld",_X_);
    
    decNumberFromString( T_dcml, (char*)_STRING_.c_str(), &T_set);

    decNumberAdd(_dcml, _dcml, T_dcml ,&T_set);   

	return *this;
}



Zdcml& Zdcml::operator-=(const long int _X_)
{
    ClearBufferDcml();

    _STRING_ =string_format("%ld",_X_);
    
    decNumberFromString( T_dcml, (char*)_STRING_.c_str(), &T_set);

    decNumberSubtract(_dcml, _dcml, T_dcml ,&T_set);

	return *this;
}



 Zdcml& Zdcml::operator*=(const long int _X_)
{
    ClearBufferDcml();

    _STRING_ =string_format("%ld",_X_);
    
    decNumberFromString( T_dcml, (char*)_STRING_.c_str(), &T_set);

    decNumberMultiply(_dcml, _dcml, T_dcml ,&T_set);

	return *this;
}



Zdcml& Zdcml::operator/=(const  long int _X_)
{
	ClearBufferDcml();

    _STRING_ =string_format("%ld",_X_);
    
    decNumberFromString( T_dcml, (char*)_STRING_.c_str(), &T_set);
    
    if(decNumberIsZero(T_dcml))    { throw std::invalid_argument("(msg error :DCML numeric ) DIV 0 : /=long int"); }

    decNumberDivide(_dcml, _dcml,T_dcml,&T_set);

    return *this;
}



Zdcml& Zdcml::operator%=(const long int _X_)
{
    Zdcml::ClearBufferDcml();

    _STRING_ =string_format("%ld",_X_);
    
    decNumberFromString(T_dcml, (char*)_STRING_.c_str(), &T_set);

    decNumberRemainder(_dcml, _dcml ,T_dcml, &T_set);

    return *this;
}



Zdcml& Zdcml::operator+=(const  double _X_)
{
    Zdcml::ClearBufferDcml();

    _STRING_ = ZDoubleToChar(_X_,_dec);

	std::string ponct=",";
	int pos = _STRING_.find(ponct);            
	if (pos >= 0 ) _STRING_.replace(pos,ponct.length(),".");

	
    std::cout<<_STRING_<<std::endl;
    
    decNumberFromString( T_dcml, (char*)_STRING_.c_str(), &T_set);

    decNumberAdd(_dcml, _dcml, T_dcml ,&T_set);

	return *this;
}



Zdcml& Zdcml::operator-=(const  double  _X_)
{
    ClearBufferDcml();

    _STRING_ = ZDoubleToChar(_X_,_dec);

	std::string ponct=",";
	int pos = _STRING_.find(ponct);            
	if (pos >= 0 ) _STRING_.replace(pos,ponct.length(),".");;
    
    decNumberFromString( T_dcml, (char*)_STRING_.c_str(), &T_set);

    decNumberSubtract(_dcml, _dcml, T_dcml ,&T_set);

	return *this;
}



 Zdcml& Zdcml::operator*=(const  double  _X_)
{
    ClearBufferDcml();

    _STRING_ = ZDoubleToChar(_X_,_dec);

	std::string ponct=",";
	int pos = _STRING_.find(ponct);            
	if (pos >= 0 ) _STRING_.replace(pos,ponct.length(),".");
    
    decNumberFromString( T_dcml, (char*)_STRING_.c_str(), &T_set);

    decNumberMultiply(_dcml, _dcml, T_dcml ,&T_set);

	return *this;
}



Zdcml& Zdcml::operator/=(const  double  _X_)
{
    Zdcml::ClearBufferDcml();

    _STRING_ = ZDoubleToChar(_X_,_dec);

	std::string ponct=",";
	int pos = _STRING_.find(ponct);            
	if (pos >= 0 ) _STRING_.replace(pos,ponct.length(),".");
    
    decNumberFromString( T_dcml, (char*)_STRING_.c_str(), &T_set);
    
    if(decNumberIsZero(T_dcml))    {  throw std::invalid_argument("(msg error :DCML numeric ) DIV 0 : /= double");}

    decNumberDivide(_dcml, _dcml,T_dcml,&T_set);
    
    return *this;
}




Zdcml& Zdcml::operator%=(const double  _X_)
{
	ClearBufferDcml();

    _STRING_ = ZDoubleToChar(_X_,_dec);

	std::string ponct=",";
	int pos = _STRING_.find(ponct);            
	if (pos >= 0 ) _STRING_.replace(pos,ponct.length(),".");
    
    decNumberFromString(T_dcml, (char*)_STRING_.c_str(), &T_set);

    decNumberRemainder(_dcml, _dcml ,T_dcml, &T_set);     // a=a%b

    return *this;
}



Zdcml& Zdcml::operator+=(const Zdcml X_dcml)
{
    ClearBufferDcml();

    decNumberAdd(_dcml, _dcml, X_dcml._dcml ,&T_set);            // a=a+b

    return *this;
}



Zdcml& Zdcml::operator-=(const Zdcml  X_dcml)
{
    ClearBufferDcml();

    decNumberSubtract(_dcml,_dcml,X_dcml._dcml,&T_set);       // a=a-b

    return *this;
}



Zdcml& Zdcml::operator*=(const Zdcml  X_dcml)
{
    ClearBufferDcml();

    decNumberMultiply(_dcml, _dcml,X_dcml._dcml,&T_set);       // a=a*b

    return *this;
}

Zdcml& Zdcml::operator/=(const Zdcml  X_dcml)
{
    ClearBufferDcml();

    decNumberCopy( T_dcml,X_dcml._dcml);

    if(decNumberIsZero(T_dcml))    {  throw std::invalid_argument("(msg error :DCML numeric ) DIV 0 : /= double"); }

    decNumberDivide(_dcml, _dcml,T_dcml,&T_set);

    return *this;
}

Zdcml& Zdcml::operator%=(const Zdcml  X_dcml)
{
    decNumberCopy(T_dcml,X_dcml._dcml);

    decNumberRemainder(_dcml, _dcml ,T_dcml, &T_set);

    return *this;
}





//OPERATEURS DE COMPARAISON-----------------------------------------------------
/// avec un opérateur  INT
bool  Zdcml::operator==(const int _X_)
{
    _STRING_ =string_format("%d",_X_);
    
     char * T_comp=  (char*) malloc(36  * sizeof(char*));

     
    decNumberFromString(T_dcml, (char*)_STRING_.c_str(), &T_set);


    decNumberCompare(T_dcml, _dcml, T_dcml, &T_set);
    
    decNumberToString(T_dcml, T_comp);
    
    int result = std::stoi(T_comp);

    if (result == 0) return true ;
    
	return false ;
}



bool Zdcml::operator<(const int _X_)
{
    _STRING_ =string_format("%d",_X_);
    
     char * T_comp=  (char*) malloc(36  * sizeof(char*));
    
    decNumberFromString(T_dcml, (char*)_STRING_.c_str(), &T_set);


    decNumberCompare(T_dcml, _dcml, T_dcml, &T_set);
    
    decNumberToString(T_dcml, T_comp);
    
    int result = std::stoi(T_comp);

    if (result < 0) return true ;
    
	return false ;
}



bool Zdcml::operator>(const int _X_)
{
    _STRING_ =string_format("%d",_X_);

    char * T_comp=  (char*) malloc(36  * sizeof(char*));
    
    decNumberFromString(T_dcml, (char*)_STRING_.c_str(), &T_set);


    decNumberCompare(T_dcml, _dcml, T_dcml, &T_set);
    
    decNumberToString(T_dcml, T_comp);
    
    int result = std::stoi(T_comp);

    if (result > 0) return true ;
    
	return false ;
}



bool  Zdcml::operator!=(const int _X_)
{
    _STRING_ =string_format("%d",_X_);

    char * T_comp=  (char*) malloc(36  * sizeof(char*));
        
    decNumberFromString(T_dcml, (char*)_STRING_.c_str(), &T_set);


    decNumberCompare(T_dcml, _dcml, T_dcml, &T_set);
    
    decNumberToString(T_dcml, T_comp);
    
    int result = std::stoi(T_comp);

    if (result != 0) return true ;
    
	return false ;
}

unsigned int  Zdcml::cmp(const int _X_)
{
    _STRING_ =string_format("%d",_X_);

    char * T_comp=  (char*) malloc(36  * sizeof(char*));
    
    decNumberFromString(T_dcml, (char*)_STRING_.c_str(), &T_set);

    decNumberCompare(T_dcml, _dcml, T_dcml, &T_set);
    
    decNumberToString(T_dcml, T_comp);
    
    int result = std::stoi(T_comp);

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
    
    char * T_comp=  (char*) malloc(36  * sizeof(char*));
    
    decNumberFromString(T_dcml, (char*)_STRING_.c_str(), &T_set);


    decNumberCompare(T_dcml, _dcml, T_dcml, &T_set);
    
    decNumberToString(T_dcml, T_comp);
    
    int result = std::stoi(T_comp);

    if (result == 0) return true ;

	return false ;
}



bool  Zdcml::operator<(const long int _X_)
{

    _STRING_ =string_format("%ld",_X_);
    
    char * T_comp=  (char*) malloc(36  * sizeof(char*));
    
    decNumberFromString(T_dcml, (char*)_STRING_.c_str(), &T_set);


    decNumberCompare(T_dcml, _dcml, T_dcml, &T_set);
    
    decNumberToString(T_dcml, T_comp);
    
    int result = std::stoi(T_comp);

    if (result < 0) return true ;
return false ;
}



bool  Zdcml::operator>(const long int _X_)
{
    _STRING_ =string_format("%ld",_X_);
    
    char * T_comp=  (char*) malloc(36  * sizeof(char*));
    
    decNumberFromString(T_dcml, (char*)_STRING_.c_str(), &T_set);


    decNumberCompare(T_dcml, _dcml, T_dcml, &T_set);
    
    decNumberToString(T_dcml, T_comp);
    
    int result = std::stoi(T_comp);

    if (result > 0) return true ;
    
	return false ;
}



bool  Zdcml::operator!=(const long int _X_)
{
    _STRING_ =string_format("%ld",_X_);
    
    char * T_comp=  (char*) malloc(36  * sizeof(char*));
        
    decNumberFromString(T_dcml, (char*)_STRING_.c_str(), &T_set);


    decNumberCompare(T_dcml, _dcml, T_dcml, &T_set);
    
    decNumberToString(T_dcml, T_comp);
    
    int result = std::stoi(T_comp);

    if (result != 0) return true ;

	return false ;
}



unsigned int  Zdcml::cmp(const long int _X_)
{
    _STRING_ =string_format("%ld",_X_);

    char * T_comp=  (char*) malloc(36  * sizeof(char*));
        
    decNumberFromString(T_dcml, (char*)_STRING_.c_str(), &T_set);

    decNumberCompare(T_dcml, _dcml, T_dcml, &T_set);
    
    decNumberToString(T_dcml, T_comp);
    
    int result = std::stoi(T_comp);

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

    char * T_comp=  (char*) malloc(36  * sizeof(char*));
      
    decNumberFromString(T_dcml, (char*)_STRING_.c_str(), &T_set);


    decNumberCompare(T_dcml, _dcml, T_dcml, &T_set);
    
    decNumberToString(T_dcml, T_comp);
    
    int result = std::stoi(T_comp);

    if (result == 0) return true ;
    
	return false ;
}



bool Zdcml::operator<(const double _X_)
{
     _STRING_ =string_format("%s", ZDoubleToChar(_X_ ,_dec));

    char * T_comp=  (char*) malloc(36  * sizeof(char*));
     
    decNumberFromString(T_dcml, (char*)_STRING_.c_str(), &T_set);


    decNumberCompare(T_dcml, _dcml, T_dcml, &T_set);
    
    decNumberToString(T_dcml, T_comp);
    
    int result = std::stoi(T_comp);

    if (result < 0) return true ;
    
	return false ;
}



bool  Zdcml::operator>(const double _X_)
{
	_STRING_ =string_format("%s", ZDoubleToChar(_X_ ,_dec));

    char * T_comp=  (char*) malloc(36  * sizeof(char*));
    
    decNumberFromString(T_dcml, (char*)_STRING_.c_str(), &T_set);


    decNumberCompare(T_dcml, _dcml, T_dcml, &T_set);
    
    decNumberToString(T_dcml, T_comp);
    
    int result = std::stoi(T_comp);

    if (result > 0) return true ;
    
	return false ;
}



bool  Zdcml::operator!=(const double _X_)
{
	_STRING_ =string_format("%s", ZDoubleToChar(_X_ ,_dec));

    char * T_comp=  (char*) malloc(36  * sizeof(char*));
    
    decNumberFromString(T_dcml, (char*)_STRING_.c_str(), &T_set);


    decNumberCompare(T_dcml, _dcml, T_dcml, &T_set);
    
    decNumberToString(T_dcml, T_comp);
    
    int result = std::stoi(T_comp);

    if (result != 0) return true ;
    
	return false ;
}



unsigned int  Zdcml::cmp(const double _X_)
{
    _STRING_ =string_format("%s", ZDoubleToChar(_X_ ,_dec));
 
    char * T_comp=  (char*) malloc(36  * sizeof(char*));
       
    decNumberFromString(T_dcml, (char*)_STRING_.c_str(), &T_set);

    decNumberCompare(T_dcml, _dcml, T_dcml, &T_set);
    
    decNumberToString(T_dcml, T_comp);
    
    int result = std::stoi(T_comp);

	switch(result)
	{
		case 0  :   CMP = EQ;   break;
		case 1  :   CMP = GT;   break;
		case -1 :   CMP = LT;   break;
	}

	return CMP;
}



/// avec un opérateur  Zdcml
bool  Zdcml::operator==(const Zdcml  X_dcml)
{
    char * T_comp=  (char*) malloc(36  * sizeof(char*));
    
    decNumberCompare(T_dcml, _dcml, X_dcml._dcml, &T_set);
    
    decNumberToString(T_dcml, T_comp);
    
    int result = std::stoi(T_comp);

    if (result == 0) return true ;
    
	return false ;
}



bool  Zdcml::operator<(const Zdcml  X_dcml)
{
    char * T_comp=  (char*) malloc(36  * sizeof(char*));
    
    decNumberCompare(T_dcml, _dcml, X_dcml._dcml, &T_set);
    
    decNumberToString(T_dcml, T_comp);
    
    int result = std::stoi(T_comp);

    if (result < 0) return true ;
    
	return false ;
}



bool  Zdcml::operator<=(const Zdcml  X_dcml)
{
    char * T_comp=  (char*) malloc(36  * sizeof(char*));
    
    decNumberCompare(T_dcml, _dcml, X_dcml._dcml, &T_set);
    
    decNumberToString(T_dcml, T_comp);
    
    int result = std::stoi(T_comp);

    if (result < 0) return true ;
    
    if (result == 0) return true ;
    
	return false ;
}



bool  Zdcml::operator>(const Zdcml  X_dcml)
{
	char * T_comp=  (char*) malloc(36  * sizeof(char*));
    
    decNumberCompare(T_dcml, _dcml, X_dcml._dcml, &T_set);
    
    decNumberToString(T_dcml, T_comp);
    
    int result = std::stoi(T_comp);

    if (result > 0) return true ;
    
	return false ;
}



bool  Zdcml::operator>=(const Zdcml  X_dcml)
{
	char * T_comp=  (char*) malloc(36  * sizeof(char*));
    
    decNumberCompare(T_dcml, _dcml, X_dcml._dcml, &T_set);
    
    decNumberToString(T_dcml, T_comp);
    
    int result = std::stoi(T_comp);

    if (result > 0) return true ;
    
    if (result == 0) return true ;
    
	return false ;
}



bool  Zdcml::operator!=(const Zdcml  X_dcml)
{
	char * T_comp=  (char*) malloc(36  * sizeof(char*));
    
    decNumberCompare(T_dcml, _dcml, X_dcml._dcml, &T_set);
    
    decNumberToString(T_dcml, T_comp);
    
    int result = std::stoi(T_comp);

    if (result != 0) return true ;
    
	return false ;
}



unsigned int  Zdcml::cmp(const Zdcml  X_dcml)
{
	char * T_comp=  (char*) malloc(36  * sizeof(char*));
    
    decNumberCompare(T_dcml, _dcml, X_dcml._dcml, &T_set);
    
    decNumberToString(T_dcml, T_comp);
    
    int result = std::stoi(T_comp);

	switch(result)
	{
		case 0  :   CMP = EQ;   break;
		case 1  :   CMP = GT;   break;
		case -1 :   CMP = LT;   break;
	}

	return CMP;
}




/// FONCTIONS CHECK  or Is...   -------------------------

bool Zdcml::CheckOverflow()
{
	
    char * T_chek =  (char*) malloc(36  * sizeof(char*));
    if( decNumberIsNegative(T_dcml))
    {
		decNumberFromString(C_dcml, n_mask,&T_set);
		decNumberCompare(C_dcml, C_dcml, T_dcml, &T_set);

		decNumberToString(C_dcml,T_chek );
		int test = atoi(T_chek );

        if (test > 0) return true;

    }
   else
    {
		decNumberFromString(C_dcml, p_mask,&T_set); 
		decNumberCompare(C_dcml, C_dcml, T_dcml, &T_set);

		decNumberToString(C_dcml,T_chek );
		int test = atoi(T_chek );
		if (test < 0)  return true;

    }

    return false;
}


bool Zdcml::isZeros()
{
	if(decNumberIsZero(_dcml)) return true;
	
    return false;
}


bool Zdcml::isNegative()
{
	if( decNumberIsNegative(_dcml))  return true;
	
    return false;
}



/// FONCTIONS OUTPUT ---return VAL-------------------------


char* Zdcml::ToChar()
{
	if ( decNumberIsNaN(_dcml)  || CheckOverflow())
	{
		CPFERR = true ;  CPFMSG = "DCML numeric  ToChar() ";  return NULL;
	}    
	ClearBufferDcml();
	
	decNumberCopy( T_dcml,_dcml);
	
	printformat();
	
	decNumberToString(T_dcml, T_char);

	ClearBufferDcml();
	
    return   T_char;
}


const char* Zdcml::ConstChar()
{
	if ( decNumberIsNaN(_dcml)  || CheckOverflow())
	{
		CPFERR = true ;  CPFMSG = "DCML numeric   ConstChar() ";  return NULL;
	}  
    
	ClearBufferDcml();
	
	decNumberCopy( T_dcml,_dcml);
	
	printformat();
	
	decNumberToString(T_dcml, T_char);
	
	ClearBufferDcml();
	
	return (const char *) T_char;
}


std::string Zdcml::StringChar()
{
	if ( decNumberIsNaN(_dcml)  || CheckOverflow())
	{
		CPFERR = true ;  CPFMSG = "DCML numeric   StringChar() ";  return NULL;
	}
    
	ClearBufferDcml();
	
	decNumberCopy( T_dcml,_dcml);
	
	printformat();
	
	decNumberToString(T_dcml, T_char);
	
	ClearBufferDcml();
	
	return std::string(T_char);
}




///****************************************************************************
/// FONCTIONS util     --------------------------------------------------------
///****************************************************************************

/// Double to char -----------------------------
char* Zdcml::ZDoubleToChar(double _X_ ,unsigned _precision_)
{

	char * X_value   = (char*) malloc(36  * sizeof(char*));   sprintf(X_value,"%c",'\0');
	char * X_cmd     = (char*) malloc(36  * sizeof(char*));
	char sign = _X_ >= 0 ? '+' : '-';

	if ( sign == '-')
	{
		 sprintf(X_cmd,"%s%c%d.0%d%c","%c",'%',0,_precision_,'f');
		 snprintf(X_value + strlen(X_value), 16, X_cmd , sign, fabs(_X_));
	}
	else
	{
		sprintf(X_cmd,"%c%d.0%d%c",'%',0,_precision_,'f');
		snprintf(X_value + strlen(X_value), 16, X_cmd , fabs(_X_));
	}

	return (char*) X_value;

}



/// Format String--idem sprintf --------------------------
std::string Zdcml::string_format(const std::string fmt, ...)
{
    std::string str;
    va_list ap;
    va_start(ap, fmt);
    int size = vsnprintf(0, 0, (const char*)fmt.c_str(), ap) + sizeof('\0');
    va_end(ap);

    while (1)
    {     // Maximum two passes on a POSIX system...
		str.resize(size);
        va_start(ap, fmt);
        
        int n = vsnprintf((char *)str.data(), size, fmt.c_str(), ap);
        
        va_end(ap);
        
        if (n > -1 && n < size)
        {  // Everything worked
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



/// retaille la zone et tronque --------------------------

void Zdcml::printformat()
{
    decNumberToString(T_dcml, T_string);

    _STRING_ = std::string(T_string);
    
    int found;

    std::string integer ;
    
    found=_STRING_.find('.');
    
    integer = _STRING_.substr(0,found);

    if(found >= 0 ) _STRING_ = _STRING_.substr(0,integer.size() + _dec +1);
    else _STRING_ = integer;

	T_string = (char*)_STRING_.c_str();

    decNumberFromString(T_dcml, T_string,&T_set);


}

/// char length------------------------------
int   Zdcml::clen()
{
	decNumberCopy( T_dcml,_dcml);
	printformat();
    return  (int) strlen(T_string);
}
/// code retour cerror or ok------------------------------
const char * Zdcml::cerror()
{
    return  CPFMSG.c_str() ;
}

}
#endif // ZDCML_HPP_INCLUDED
