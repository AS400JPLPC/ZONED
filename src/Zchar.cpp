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
#ifndef ZCHAR_CPP_INCLUDED
#define ZCHAR_CPP_INCLUDED
#include "Zchar.h"

namespace ZONED
{

Zchar::Zchar()
{
throw std::invalid_argument("msg error : Initialised len = 0 ");
}



Zchar::Zchar(size_t i =0 )
{
    if ( i == 0 ) { throw std::invalid_argument("msg error : Initialised len = 0 "); }
     _length = i;
     _name_ = "Zchar ";
     P_buffer.clear();
     val.clear();
     _name_.clear();
     CPFMSG.clear();
}

Zchar::~Zchar()
{
    return ;
}



/// Zchar to Zchar

 Zchar  Zchar::operator=( const Zchar Z_fld)
{
	CPFERR= false ; CPFMSG = "";
    
    P_buffer = Z_fld.P_buffer;
    if (nbrcar(P_buffer) > _length ) { CPFERR= true ; CPFMSG = "resultat overflow";}
    
	resize();
	
	return *this;
}

Zchar Zchar::operator+=(const Zchar Z_fld)
{
	CPFERR= false ; CPFMSG = "";
    
    P_buffer += Z_fld.P_buffer;
    if (nbrcar(P_buffer) > _length ) { CPFERR= true ; CPFMSG = "resultat overflow";}
    
	resize();
	
	return *this;
}

bool  Zchar::operator==(Zchar Z_fld)
{
	CPFERR= false ; CPFMSG = "";
    
	return P_buffer == Z_fld.P_buffer;
}


bool  Zchar::operator!=(Zchar Z_fld)
{
	CPFERR= false ; CPFMSG = "";
    
	return P_buffer != Z_fld.P_buffer;
}

bool  Zchar::operator<(Zchar Z_fld)
{
	CPFERR= false ; CPFMSG = "";

    return P_buffer < Z_fld.P_buffer;
}

bool  Zchar::operator>(Zchar Z_fld)
{
	CPFERR= false ; CPFMSG = "";

    return P_buffer > Z_fld.P_buffer;
}

bool  Zchar::operator<=(Zchar Z_fld)
{
	CPFERR= false ; CPFMSG = "";
    
	return P_buffer <= Z_fld.P_buffer;
}

bool  Zchar::operator>=(Zchar Z_fld)
{
	CPFERR= false ; CPFMSG = "";

    return P_buffer >= Z_fld.P_buffer;
}

unsigned int  Zchar::cmp(Zchar Z_fld)
{
	CPFERR= false ; CPFMSG = "";
    
	if (P_buffer == Z_fld.P_buffer) CMP = EQ;
	if (P_buffer <  Z_fld.P_buffer) CMP = LT;
	if (P_buffer >  Z_fld.P_buffer) CMP = GT;

	return CMP;
}


/// char * to string

Zchar Zchar::operator=( const char* _C_)
{
	CPFERR= false ; CPFMSG = "";;
	
    P_buffer= _C_;
    if (nbrcar(P_buffer) > _length ) { CPFERR= true ; CPFMSG = "resultat overflow";}
    
    resize();

	return *this;
}

Zchar Zchar::operator+=( const char* _C_)
{
	CPFERR= false ; CPFMSG = "";

    P_buffer+=_C_;
    if (nbrcar(P_buffer) > _length ) { CPFERR= true ; CPFMSG = "resultat overflow";}
    
	resize();
	
	return *this;
}

bool  Zchar::operator==( const char* _C_)
{
	CPFERR= false ; CPFMSG = "";
    
	return P_buffer == std::string(_C_);
}


bool  Zchar::operator!=( const char* _C_)
{
	CPFERR= false ; CPFMSG = "";
    
	return P_buffer != std::string(_C_);
}

bool  Zchar::operator<( const char* _C_)
{
	CPFERR= false ; CPFMSG = "";
    
	return P_buffer < std::string(_C_);
}

bool  Zchar::operator>( const char* _C_)
{
	CPFERR= false ; CPFMSG = "";
    
	return P_buffer > std::string(_C_);
}

bool  Zchar::operator<=( const char* _C_)
{
	CPFERR= false ; CPFMSG = "";
    
	return P_buffer <= std::string(_C_);
}

bool  Zchar::operator>=( const char* _C_)
{
	CPFERR= false ; CPFMSG = "";
    
	return P_buffer >= std::string(_C_);
}


unsigned int  Zchar::cmp( const char* _C_)
{
	CPFERR= false ; CPFMSG = "";
    
	if (P_buffer == std::string(_C_)) CMP = EQ;
	if (P_buffer <  std::string(_C_)) CMP = LT;
	if (P_buffer >  std::string(_C_)) CMP = GT;

	return CMP;
}



/// string * to string

Zchar Zchar::operator=(std::string _S_)
{
	CPFERR= false ; CPFMSG = "";
    
    P_buffer = _S_ ;
	resize();
	
	return *this;
}


Zchar Zchar::operator+=(std::string _S_)
{
	CPFERR= false ; CPFMSG = "";
    
    P_buffer += _S_ ;
	resize();
	
	return *this;
}

bool  Zchar::operator==(std::string _S_)
{
	CPFERR= false ; CPFMSG = "";
    
	return P_buffer == _S_ ;
}


bool  Zchar::operator!=(std::string _S_)
{
	CPFERR= false ; CPFMSG = "";
    
	return P_buffer != _S_ ;
}

bool  Zchar::operator<(std::string _S_)
{
	CPFERR= false ; CPFMSG = "";
    
	return P_buffer <  _S_ ;
}

bool  Zchar::operator>(std::string _S_)
{
	CPFERR= false ; CPFMSG = "";
    
	return P_buffer >  _S_ ;
}

bool  Zchar::operator<=(std::string _S_)
{
	CPFERR= false ; CPFMSG = "";
    
	return P_buffer <=  _S_ ;
}

bool  Zchar::operator>=(std::string _S_)
{
	CPFERR= false ; CPFMSG = "";
	
	return P_buffer >=  _S_ ;;
}


unsigned int  Zchar::cmp(std::string _S_)
{
	CPFERR= false ; CPFMSG = "";
    
	if (P_buffer ==  _S_ ) CMP = EQ;
	if (P_buffer <   _S_ ) CMP = LT;
	if (P_buffer >   _S_ ) CMP = GT;
	
	return CMP;
}



char*   Zchar::ToChar()
{
	CPFERR= false ; CPFMSG = "";
    
    this->strtrim();
 
    return (char *)P_buffer.c_str();
}

const char*   Zchar::ConstChar()
{
	CPFERR= false ; CPFMSG = "";
    
    this->strtrim();
    
    return (const char *)P_buffer.c_str();
}

std::string   Zchar::StringChar()
{
	CPFERR= false ; CPFMSG = "";
	   
    this->strtrim();

    return P_buffer;
}


// FONCTIONS UTILE------------------------------------------------------------
Zchar    Zchar::clear()
{
	CPFERR= false ; CPFMSG = "";
	
	P_buffer.clear() ;
	return *this;
}



///  concaténation








Zchar Zchar::concat(const std::string fmt, ...)									// fonctionne comme prinf
{
	CPFERR= false ; CPFMSG = "";
	
    std::string str , buffer  ;
    va_list ap;
    va_start(ap, fmt);
    int size = vsnprintf(0, 0, (const char*)fmt.c_str(), ap) + sizeof('\0');
    va_end(ap);


	bool stop = false;
    while (!stop) {     // Maximum two passes on a POSIX system...
        str.resize(size);
        va_start(ap, fmt);
        int n = vsnprintf((char *)str.data(), size, fmt.c_str(), ap);
        va_end(ap);
        if (n > -1 && n < size)
        {  // Everything worked
			buffer += str;
			stop = true;
		}
     
        if (n > -1)  // Needed size returned
            size = n + 1;   // For null char
        else
            size *= 2;      // Guess at a larger size (OS specific)
    }

    if (nbrcar(buffer) > _length ){ CPFERR= true ; CPFMSG = "concat : resultat overflow";}
    
    P_buffer = buffer;
	resize();
	
	return *this;
}




/// substring


Zchar Zchar::Replace( const char*  scrut, const char * subst )
{
	CPFERR= false ; CPFMSG = "";
	
	std::wstring x_substr  =  sTows(P_buffer);
	std::wstring x_search  =  sTows(scrut) ;
	std::wstring x_replace =  sTows(subst);
	
    size_t pos = 0;
    while((pos = x_substr.find(x_search, pos)) != std::string::npos)
    {
		x_substr.replace(pos,x_search.length(), x_replace);
		pos += x_replace.length();
		
		if (nbrcar(wsTos(x_substr)) > _length ) { CPFERR= true ; CPFMSG = "Replace : resultat overflow";}
		
		P_buffer =  wsTos(x_substr);
    }

	resize();
	
	return *this;
}
Zchar Zchar::Replace( const char*  scrut, std::string  subst )
{
	CPFERR= false ; CPFMSG = "";
	
	std::wstring x_substr  =  sTows(P_buffer);
	std::wstring x_search  =  sTows(scrut) ;
	std::wstring x_replace =  sTows(subst) ;
	size_t pos = 0;
	while((pos = x_substr.find(x_search, pos)) !=  std::string::npos)
    {
		x_substr.replace(pos,x_search.length(), x_replace);
		pos += x_replace.length();
		
		if (nbrcar(wsTos(x_substr)) > _length ) { CPFERR= true ; CPFMSG = "Replace : resultat overflow";}
		
		P_buffer = wsTos(x_substr);
    }
    
	resize();
	
	return *this;
}



Zchar Zchar::ToUper()
{
	CPFERR= false ; CPFMSG = "";

	std::wstring P_ws = sTows(P_buffer );
	
	std::locale::global(std::locale(""));
	auto& f = std::use_facet<std::ctype<wchar_t>>(std::locale());

	f.toupper(&P_ws[0], &P_ws[0] + P_ws.size());		

	 P_buffer = wsTos(P_ws);
	 
	return *this;
}



Zchar Zchar::ToLower()
{
	CPFERR= false ; CPFMSG = "";
	
	std::wstring P_ws = sTows(P_buffer );
	
	std::locale::global(std::locale(""));
	auto& f = std::use_facet<std::ctype<wchar_t>>(std::locale());

	f.tolower(&P_ws[0], &P_ws[0] + P_ws.size());		

	 P_buffer = wsTos(P_ws);

	return *this;
}



Zchar Zchar::Extrac(const Zchar Z_fld ,size_t start , size_t len  )
{
	CPFERR= false ; CPFMSG = "";
 
	std::wstring s_arg = sTows(Z_fld.P_buffer );
	
	if ( start<= s_arg.length()  && (((start) + len) <= s_arg.length() ))
	{
			s_arg = s_arg.substr(start,len);
			
			P_buffer = wsTos(s_arg);
	}
	else
	{
		_name_ +=  "val :" + wsTos(s_arg);
		_name_ +=  " start :" + std::to_string(start);
		_name_ +=  " len :" + std::to_string(len);
		_name_ +=  " length :" + std::to_string(s_arg.length());
		CPFERR= true ; CPFMSG = "Extrac : Zchar  borne invalide name :" + _name_ ; return *this ;
	}

	if (nbrcar(P_buffer) > _length ) { CPFERR= true ; CPFMSG = "Extrac :  Zchar  resultat overflow";}

	resize();
	
	return *this;

}



Zchar Zchar::Extrac(const char * src  ,size_t start , size_t len )
{
	CPFERR= false ; CPFMSG = "";
	
    std::wstring s_arg = sTows(src) ;
    
	if ( start<= s_arg.length()  && (((start) + len) <= s_arg.length() ))
	{

			s_arg = s_arg.substr(start,len);
			
			P_buffer = wsTos(s_arg);
	
	}
	else
	{
		_name_ +=  "val :" + wsTos(s_arg);
		_name_ +=  " start :" + std::to_string(start);
		_name_ +=  " len :" + std::to_string(len);
		_name_ +=  " length :" + std::to_string(s_arg.length());
		CPFERR= true ; CPFMSG = "Extrac : Zchar  borne invalide name :" + _name_ ; return *this ;
	}

	if (nbrcar(P_buffer) > _length ) { CPFERR= true ; CPFMSG = "Extrac : char*  resultat overflow";}
	
	resize();
	
	return *this;
}



Zchar Zchar::Movel(const char* src  )
{
	CPFERR= false ; CPFMSG = "";

    std::string s_arg  = src;
    unsigned int len   = s_arg.length();
    if ( len> 0 )
    {
		P_buffer += s_arg.substr(0,len);
	}
	if (nbrcar(P_buffer) > _length ) { CPFERR= true ; CPFMSG = "Move : resultat overflow";}
	resize();
	
	return *this;
}



Zchar Zchar::Movel(const Zchar Z_fld )
{
	CPFERR= false ; CPFMSG = "";

    std::string s_arg  = Z_fld.P_buffer ;
    unsigned int len   = s_arg.length();
    if ( len> 0 )
    {
		P_buffer += s_arg.substr(0,len);
	}
	if (nbrcar(P_buffer) > _length ) { CPFERR= true ; CPFMSG = "Move : resultat overflow";}
	resize();
	
	return *this;
}



char * Zchar::ExtracToChar(size_t start , size_t len  )
{
	CPFERR= false ; CPFMSG = "";
	
    std::string s_arg = P_buffer ;

	if ( start<= nbrcar(s_arg)  && (((start) + len) <= nbrcar(s_arg) ))
	{
			s_arg = s_arg.substr(start,len);
	
	}
	else
	{
		_name_ +=  "val :" + s_arg;
		_name_ +=  " start :" + std::to_string(start);
		_name_ +=  " len :" + std::to_string(len);
		_name_ +=  " length :" + std::to_string(nbrcar(s_arg.c_str()));
		CPFERR= true ; CPFMSG = "Extrac : Zchar  borne invalide name :" + _name_ ; return (char*)"" ;
	}
	
	return (char*)s_arg.c_str();
}

Zchar Zchar::strtrim()
{
	CPFERR= false ; CPFMSG = "";
	
    std::string s =  P_buffer;
    std::string::const_iterator it = s.begin();
    while (it != s.end() && isspace(*it))
        it++;

    std::string::const_reverse_iterator rit = s.rbegin();
    while (rit.base() != it && isspace(*rit))
        rit++;
    s = std::string(it, rit.base());
    P_buffer = s ;

    return *this;
}

void   Zchar::name( const char*  name)										/// outil pour debug
{
    _name_ = name;
}

int   Zchar::cfind( const char*  scrut)
{
	CPFERR= false ; CPFMSG = "";

    return   (int) P_buffer.find(scrut);

}

int   Zchar::sfind( std::string _S_)
{
	CPFERR= false ; CPFMSG = "";

	const char* scrut = _S_.c_str();
    return   (int) P_buffer.find(scrut);

}

int   Zchar::deflen()
{
    return (int)_length;
}

int   Zchar::clen()
{
    return  (int) nbrcar(P_buffer);
}


void Zchar::resize()
{
	std::wstring  P_ws = sTows(P_buffer) ;
	std::wstring  P_wval ;

	if ( nbrcar(P_buffer) > _length)
	{
		P_wval = P_ws.substr(0,_length); 
		P_buffer = wsTos(P_wval);
		
	}
	 
}



const char *  Zchar::cerror()
{
    return  CPFMSG.c_str() ;
}



size_t Zchar::nbrcar(const std::string& str)
{
	setlocale (LC_ALL, "");
	const char *_C_ = str.c_str(); 
    const size_t cSize = strlen(_C_)+1;
    
    wchar_t* wc = new wchar_t[cSize];
    mbstowcs (wc, _C_, cSize);
    
    return  wcslen(wc);
}

std::wstring Zchar::sTows(const std::string& str)
{
    //setup converter
    using convert_type = std::codecvt_utf8<wchar_t>;
    std::wstring_convert<convert_type, wchar_t> converter;
    
    return converter.from_bytes(str);
}

std::string Zchar::wsTos(const std::wstring& wstr)
{
    using convert_type = std::codecvt_utf8<wchar_t>;
    std::wstring_convert<convert_type, wchar_t> converter;

    return converter.to_bytes(wstr);
}

}

#endif
