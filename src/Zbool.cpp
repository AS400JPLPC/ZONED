#ifndef ZBOOL_CPP_INCLUDED
#define ZBOOL_CPP_INCLUDED
#include "Zbool.h"

namespace ZONED
{


Zbool::Zbool()
{
	CPFERR= false ; CPFMSG = "";

	P_buffer = false;
}

Zbool::~Zbool()
{
    return ;
}

Zbool Zbool::operator=(const bool _B_ )
{
	CPFERR= false ; CPFMSG = "";
	
    P_buffer = _B_;
    return *this;
}

Zbool Zbool::operator=(const char * _C_)
{
	CPFERR= false ; CPFMSG = "";
	
	if  (strcmp("false",_C_) ==0)  P_buffer = false ;
	else if (strcmp("true",_C_)==0)  P_buffer = true ;
	else if (strcmp("0",_C_)==0)  P_buffer = false ;
	else if (strcmp("1",_C_)==0)  P_buffer = true ;
	else { CPFERR= true ; CPFMSG = "PGTYPES_CHAR BAD" + std::string(_C_);}
    return *this;
}
Zbool Zbool::operator=(std::string _S_)
{
	CPFERR= false ; CPFMSG = "";
	
	if ( _S_.compare("false") == 0 )  P_buffer = false ;
	else if ( _S_.compare("true") == 0 )  P_buffer = true ;
	else if ( _S_.compare("0") == 0 )  P_buffer = false ;
	else if ( _S_.compare("1") == 0 )  P_buffer = true ;
	else { CPFERR= true ; CPFMSG = "PGTYPES_CHAR BAD" + _S_ ;}
    return *this;
}

Zbool Zbool::operator=(Zbool _B_ )
{
    P_buffer = _B_.P_buffer ;
    return *this;
}


Zbool Zbool::operator=(int _I_ )
{
	CPFERR= false ; CPFMSG = "";
	
	if ( _I_ == 0 )  P_buffer = false ;
	else if ( _I_ == 1 )  P_buffer = true ;
    else { CPFERR= true ; CPFMSG = "PGTYPES_CHAR BAD" + std::to_string(_I_);}
    return *this;
}


bool Zbool::operator==(bool _B_ )
{
    if (P_buffer == _B_ ) return true;
    return false;
}


bool Zbool::operator==(Zbool _B_ )
{
    if (P_buffer == _B_.P_buffer  ) return true;

    return false;
}

bool Zbool::operator!=(bool _B_ )
{
    if (P_buffer != _B_ ) return true;
    return false;
}


bool Zbool::operator!=(Zbool _B_ )
{
    if (P_buffer != _B_.P_buffer ) return true;

    return false;
}

char*   Zbool::Chr()
{
	if (P_buffer == true ) return (char*)"true" ;
     
    return (char*)"false";
}
const char *   Zbool::ConstChr()
{
	if (P_buffer == true ) return (const char *)"true" ;
     
    return (const char *)"false";
}
std::string    Zbool::Str()
{
	if (P_buffer == true ) return std::string("true") ;
     
    return std::string("false");
}



const char *  Zbool::cerror()
{
    return  CPFMSG.c_str() ;
}


}
#endif
