#ifndef ZCHAR_CPP_INCLUDED
#define ZCHAR_CPP_INCLUDED
#include "Zchar.h"

namespace __ZONED__
{


Zchar::Zchar(int i)
{
          ___obligatoire___ = false ;

     I_length = i;  MSGERR=ZONED_OK; zmsg = new char[80];

     P_buffer = new char[I_length];

        if (I_length >___max___) {

        sprintf(zmsg,"( max lentgh PGTYPES_char_OVERFLOW ): %d",ZONED_OVR); MSGERR = ZONED_OVR ;
          ___obligatoire___ = true ;
        }


}

Zchar::~Zchar(){  }
 
 Zchar  Zchar::operator=( const Zchar Z_fld)
{
     if(___obligatoire___ )  return *this;
    MSGERR =ZONED_OK;

    if ( I_length >= (unsigned)strlen(Z_fld.P_buffer))   strcpy(P_buffer,Z_fld.P_buffer);
    else {sprintf(zmsg,"(MSGERRno == PGTYPES_CHAR_OVERFLOW) -    : %d",ZONED_OVR); MSGERR = ZONED_OVR ;}
    return *this;
}




Zchar Zchar::operator+=(const Zchar Z_fld)
{
     if(___obligatoire___ )  return *this;
    MSGERR= ZONED_OK;

    int n =0 ;
    int l = I_length;

     n = sizeval()+ strlen(Z_fld.P_buffer) ;

    if (n <= l ) strcat(P_buffer,Z_fld.P_buffer);
    else {sprintf(zmsg,"(MSGERRno == PGTYPES_CHAR_OVERFLOW) -    : %d",ZONED_OVR); MSGERR = ZONED_OVR ;}

    return *this;
}

Zchar Zchar::operator=( const char* C_cx)
{
     if(___obligatoire___ )  return *this;
    MSGERR = ZONED_OK;

    if ( I_length < (unsigned) strlen(C_cx)  ) {
            sprintf(zmsg,"(MSGERRno == PGTYPES_CHAR_OVERFLOW) -    : %d",ZONED_OVR); MSGERR = ZONED_OVR ;}
    else  strcpy(P_buffer,C_cx);

    return *this;
}


Zchar Zchar::operator+=( const char* C_cx)
{
     if(___obligatoire___ )  return *this;
    MSGERR= ZONED_OK;

    int n = 0;
    int y = strlen(C_cx);


    n = sizebuf()- sizeval()  ;

    if (n >= y ) strcpy(P_buffer,C_cx);
    else {sprintf(zmsg,"(MSGERRno == PGTYPES_CHAR_OVERFLOW) -    : %d",ZONED_OVR); MSGERR = ZONED_OVR ;}

    return *this;
}

bool  Zchar::operator!=( const char* C_cx)
{
     if(___obligatoire___ )  return  0 ;

int  i= strcmp (P_buffer,C_cx);

if (i != 0) return true;

return false;
}

bool  Zchar::operator==( const char* C_cx)
{
     if(___obligatoire___ )  return  0 ;

int  i= strcmp (P_buffer,C_cx);

if (i == 0) return true;

return false;
}

bool  Zchar::operator<( const char* C_cx)
{
     if(___obligatoire___ )  return  0 ;

int  i= strcmp (P_buffer,C_cx);

if (i < 0) return true;

return false;
}


bool  Zchar::operator<=( const char* C_cx)
{
     if(___obligatoire___ )  return  0 ;


int  i= strcmp (P_buffer,C_cx);

if (i < 0) return true;
if (i == 0) return true;

return false;
}



bool  Zchar::operator>( const char* C_cx)
{
     if(___obligatoire___ )  return  0 ;

int  i= strcmp (P_buffer,C_cx);

if (i > 0) return true;

return false;
}


bool  Zchar::operator>=( const char* C_cx)
{
     if(___obligatoire___ )  return  0 ;


int  i= strcmp (P_buffer,C_cx);

if (i < 0) return true;
if (i == 0) return true;

return false;
}

unsigned int  Zchar::cmp( const char* C_cx)
{
     if(___obligatoire___ )  return  0 ;

char   * a_buffer =   (char*) malloc(___max___   * sizeof(char*));

char   * b_buffer =   (char*) malloc(___max___   * sizeof(char*));



    std::string s =  P_buffer;
    std::string::const_iterator is = s.begin();
    while (is != s.end() && isspace(*is))
        is++;

    std::string::const_reverse_iterator ris = s.rbegin();
    while (ris.base() != is && isspace(*ris))
        ris++;
    s = std::string(is, ris.base());
     sprintf(a_buffer,"%s",s.c_str());


    std::string y =  C_cx;
    std::string::const_iterator iy = y.begin();
    while (iy != y.end() && isspace(*iy))
        iy++;

    std::string::const_reverse_iterator riy = y.rbegin();
    while (riy.base() != iy && isspace(*riy))
        riy++;
    y = std::string(iy, riy.base());
     sprintf(b_buffer,"%s",y.c_str());

int i= strcmp (a_buffer,b_buffer);
free(a_buffer);free(b_buffer);


if (i == 0) CMP = EQ;
if (i <  0) CMP = LT;
if (i  >  0) CMP = GT;

    return CMP;
}

bool  Zchar::operator!=(Zchar Z_fld)
{
    if(___obligatoire___ )  return  0 ;

char   * x_buffer =   (char*) malloc(___max___   * sizeof(char*));
    sprintf(x_buffer,"%s",Z_fld.tochar());

int i= strcmp (P_buffer,x_buffer);

free(x_buffer);
if (i != 0) return true;
return false;
}

bool  Zchar::operator==(Zchar Z_fld)
{
     if(___obligatoire___ )  return  0 ;

char   * x_buffer =   (char*) malloc(___max___   * sizeof(char*));
        sprintf(x_buffer,"%s",Z_fld.tochar());

int i= strcmp (P_buffer,x_buffer);

free(x_buffer);
if (i == 0) return true;
return false;
}


bool  Zchar::operator<(Zchar Z_fld)
{
    if(___obligatoire___ )  return  0 ;

char   * x_buffer =   (char*) malloc(___max___   * sizeof(char*));
        sprintf(x_buffer,"%s",Z_fld.tochar());

int i= strcmp (P_buffer,x_buffer);

free(x_buffer);
if (i < 0) return true;
return false;
}


bool  Zchar::operator<=(Zchar Z_fld)
{
    if(___obligatoire___ )  return  0 ;

char   * x_buffer =   (char*) malloc(___max___   * sizeof(char*));
        sprintf(x_buffer,"%s",Z_fld.tochar());

int i= strcmp (P_buffer,x_buffer);

free(x_buffer);
if (i < 0) return true;
if (i == 0) return true;
return false;
}


bool  Zchar::operator>(Zchar Z_fld)
{
    if(___obligatoire___ )  return  0 ;

char   * x_buffer =   (char*) malloc(___max___   * sizeof(char*));
        sprintf(x_buffer,"%s",Z_fld.tochar());

int i= strcmp (P_buffer,x_buffer);

free(x_buffer);
if (i > 0) return true;
return false;
}

bool  Zchar::operator>=(Zchar Z_fld)
{
    if(___obligatoire___ )  return  0 ;

char   * x_buffer =   (char*) malloc(___max___   * sizeof(char*));
        sprintf(x_buffer,"%s",Z_fld.tochar());

int i= strcmp (P_buffer,x_buffer);

free(x_buffer);
if (i > 0) return true;
if (i == 0) return true;
return false;
}

unsigned int  Zchar::cmp(Zchar Z_fld)
{
    if(___obligatoire___ )  return  0 ;

char   * a_buffer =   (char*) malloc(___max___   * sizeof(char*));

char   * b_buffer =   (char*) malloc(___max___   * sizeof(char*));



    std::string s =  P_buffer;
    std::string::const_iterator is = s.begin();
    while (is != s.end() && isspace(*is))
        is++;

    std::string::const_reverse_iterator ris = s.rbegin();
    while (ris.base() != is && isspace(*ris))
        ris++;
    s = std::string(is, ris.base());
     sprintf(a_buffer,"%s",s.c_str());


    std::string y =  Z_fld.P_buffer;
    std::string::const_iterator iy = y.begin();
    while (iy != y.end() && isspace(*iy))
        iy++;

    std::string::const_reverse_iterator riy = y.rbegin();
    while (riy.base() != iy && isspace(*riy))
        riy++;
    y = std::string(iy, riy.base());
     sprintf(b_buffer,"%s",y.c_str());

int i= strcmp (a_buffer,b_buffer);
free(a_buffer);free(b_buffer);
if (i == 0) CMP = EQ;
if (i <  0) CMP = LT;
if (i >  0) CMP = GT;

return CMP;
}



char*   Zchar::tochar()
{
    if(___obligatoire___ )  return  NULL ;
    this->strtrim();
    return P_buffer;
}

const char*   Zchar::toconstchar()
{
    if(___obligatoire___ )  return  NULL ;
    this->strtrim();
    return (const char *)P_buffer;
}

std::string   Zchar::tostring()
{
    if(___obligatoire___ )  return  NULL ;
    this->strtrim();
    return std::string(P_buffer);
}


// FONCTIONS UTILE------------------------------------------------------------
Zchar    Zchar::reset() { strcpy(P_buffer,"\0");  return *this ;}



///  concaténation








Zchar Zchar::concat(const std::string fmt, ...)
{
if(___obligatoire___ )  return  *this ;
    MSGERR= ZONED_OK;

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


            if( str.length() > I_length || str.length() ==0  ) {
                    sprintf(zmsg,"(MSGERRno == PGTYPES_CHAR_OVERFLOW) -    : %d",ZONED_OVR); MSGERR = ZONED_OVR ;  return *this;
                    } else {
                    MSGERR= ZONED_OK;
                    sprintf(P_buffer,"%s",(char*)str.c_str());
                    return *this;
                    }
        }
        if (n > -1)  // Needed size returned
            size = n + 1;   // For null char
        else
            size *= 2;      // Guess at a larger size (OS specific)
    }

    sprintf(P_buffer,"%s", (char*)str.c_str());
    return *this;
}




/// substring


Zchar Zchar::replace( const char*  scrut, const char * subst )
{
    if(___obligatoire___ )  return  *this ;
    std::string S_arg = std::string(P_buffer) ;
    MSGERR= ZONED_OK;

    std::string x_subject =  std::string(P_buffer);
    std::string x_search  =  std::string(scrut) ;
    std::string x_replace =  std::string(subst) ;
    size_t pos = 0;
    while((pos = x_subject.find(x_search, pos)) != std::string::npos) {
         x_subject.replace(pos,x_search.length(), x_replace);
         pos += x_replace.length();
    }
    if( x_replace.length() > I_length || x_replace.length() ==0  ) {
                    sprintf(zmsg,"(MSGERRno == PGTYPES_CHAR_OVERFLOW) -    : %d",ZONED_OVR); MSGERR = ZONED_OVR ;  return *this;
                    }
                    MSGERR= ZONED_OK;
                    sprintf(P_buffer,"%s",(char*)x_subject.c_str());
    return *this;
}



Zchar Zchar::extrac(const Zchar Z_fld ,unsigned int start , unsigned int len )
{
if(___obligatoire___ )  return   *this ;
    std::string S_arg = std::string(Z_fld.P_buffer) ;
    MSGERR= ZONED_OK;
  if ( len>  I_length) {sprintf(zmsg,"(MSGERRno == PGTYPES_CHAR_OVERFLOW) -    : %d",ZONED_OVR); MSGERR = ZONED_OVR ; return *this ;}



    if ( start<= Z_fld.I_length && start > 0 ) {
        if ( ((start-1) + len) <= Z_fld.I_length ) {
            S_arg = S_arg.substr(start-1,len);
            strcpy (P_buffer, S_arg.c_str()); return *this ;
        } else {
            sprintf(zmsg,"(MSGERRno == PGTYPES_CHAR_OVERFLOW) - 1   : %d",ZONED_OVR); MSGERR = ZONED_OVR ; return *this ;
        }
    }else {
        sprintf(zmsg,"(MSGERRno == PGTYPES_CHAR_OVERFLOW) -    : %d",ZONED_OVR); MSGERR = ZONED_OVR ; return *this ;
    }
}

Zchar Zchar::extrac(const char * src  ,unsigned int start , unsigned int len )
{
if(___obligatoire___ )  return   *this ;
    std::string S_arg = std::string(src) ;
    MSGERR= ZONED_OK;

    if ( start <= I_length && start > 0 ) {
        if ( ((start-1) + len) <= I_length ) {
            S_arg = S_arg.substr(start-1,len);
            strcpy (P_buffer, S_arg.c_str()); return *this ;
        } else {
            sprintf(zmsg,"(MSGERRno == PGTYPES_CHAR_OVERFLOW) -    : %d",ZONED_OVR); MSGERR = ZONED_OVR ; return *this ;
        }
    }else {
        sprintf(zmsg,"(MSGERRno == PGTYPES_CHAR_OVERFLOW) -    : %d",ZONED_OVR); MSGERR = ZONED_OVR ; return *this ;
    }
}

Zchar Zchar::move(const char * src  )
{
if(___obligatoire___ )  return   *this ;
    std::string S_arg = std::string(src) ;
    unsigned int start=0;
    unsigned int len =  S_arg.length();
    if(S_arg.length() > I_length)  start = S_arg.length() - I_length +1;
    MSGERR= ZONED_OK;

    if ( len> 0 && start > 0 )
        {
            S_arg = S_arg.substr(start-1,len);
            strcpy (P_buffer, S_arg.c_str()); return *this ;
        } else {
            sprintf(zmsg,"(MSGERRno == PGTYPES_CHAR_OVERFLOW) -    : %d",ZONED_OVR); MSGERR = ZONED_OVR ; return *this ;
        }

}

Zchar Zchar::movel(const char * src  )
{
if(___obligatoire___ )  return   *this ;
    std::string S_arg = std::string(src) ;
    unsigned int start=1;
    unsigned int len =  S_arg.length();
    if(S_arg.length() > I_length)  len = I_length  ;
    MSGERR= ZONED_OK;

    if ( len> 0 && start > 0 )
        {
            S_arg = S_arg.substr(start-1,len);
            strcpy (P_buffer, S_arg.c_str()); return *this ;
        } else {
            sprintf(zmsg,"(MSGERRno == PGTYPES_CHAR_OVERFLOW) -    : %d",ZONED_OVR); MSGERR = ZONED_OVR ; return *this ;
        }

}
Zchar Zchar::move(const Zchar Z_fld  )
{
if(___obligatoire___ )  return   *this ;
    std::string S_arg = std::string(Z_fld.P_buffer) ;
    unsigned int start=0;
    unsigned int len =  S_arg.length();
    if(S_arg.length() > I_length)  start = S_arg.length() - I_length +1;
    MSGERR= ZONED_OK;

    if ( len> 0 && start > 0 )
        {
            S_arg = S_arg.substr(start-1,len);
            strcpy (P_buffer, S_arg.c_str()); return *this ;
        } else {
            sprintf(zmsg,"(MSGERRno == PGTYPES_CHAR_OVERFLOW) -    : %d",ZONED_OVR); MSGERR = ZONED_OVR ; return *this ;
        }

}

Zchar Zchar::movel(const Zchar Z_fld )
{
if(___obligatoire___ )  return   *this ;
    std::string S_arg = std::string(Z_fld.P_buffer) ;
    unsigned int start=1;
    unsigned int len =  S_arg.length();
    if(S_arg.length() > I_length)  len = I_length  ;
    MSGERR= ZONED_OK;

    if ( len> 0 && start > 0 )
        {
            S_arg = S_arg.substr(start-1,len);
            strcpy (P_buffer, S_arg.c_str()); return *this ;
        } else {
            sprintf(zmsg,"(MSGERRno == PGTYPES_CHAR_OVERFLOW) -    : %d",ZONED_OVR); MSGERR = ZONED_OVR ; return *this ;
        }

}
char * Zchar::extractochar(unsigned int start , unsigned int len )
{
if(___obligatoire___ )  return   NULL ;
    std::string S_arg = std::string(P_buffer) ;
    char   * a_buffer =   (char*) malloc(___max___   * sizeof(char*));
    MSGERR= ZONED_OK;

    if ( start <= I_length && start > 0 ) {
        if ( ((start-1) + len) <= I_length ) {
            S_arg = S_arg.substr(start-1,len);
            sprintf(a_buffer,"%s/0", S_arg.c_str() ); return a_buffer ;
        } else {
            sprintf(zmsg,"(MSGERRno == PGTYPES_CHAR_OVERFLOW) -    : %d",ZONED_OVR); MSGERR = ZONED_OVR ; return NULL ;
        }
    }else {
        sprintf(zmsg,"(MSGERRno == PGTYPES_CHAR_OVERFLOW) -    : %d",ZONED_OVR); MSGERR = ZONED_OVR ; return NULL ;
    }


}

Zchar Zchar::strtrim()
{
if(___obligatoire___ )  return   *this ;
    std::string s =  std::string(P_buffer);
    std::string::const_iterator it = s.begin();
    while (it != s.end() && isspace(*it))
        it++;

    std::string::const_reverse_iterator rit = s.rbegin();
    while (rit.base() != it && isspace(*rit))
        rit++;
    s = std::string(it, rit.base());
     sprintf(P_buffer,"%s",s.c_str());
    return *this;
}



unsigned int   Zchar::locfind( const char*  scrut)
{
      if(___obligatoire___ )  return  -1 ;

    std::string x_subject =  std::string(P_buffer);
    std::string x_search  =  std::string(scrut) ;
    size_t pos = 0;
    return   pos = x_subject.find(x_search, pos);

}

unsigned int   Zchar::sizebuf()
{
    return (int)I_length;
}

unsigned int   Zchar::sizeval()
{
    return  (int)strlen(P_buffer);
}

// code retour _MSGERR_eur or ok
unsigned int Zchar::status() {return MSGERR;}
char* Zchar::statusmsg() {return zmsg;}
bool  Zchar::msgerr() { if (this->MSGERR == ZONED_OK ) return false; else return true ;}


}

#endif
