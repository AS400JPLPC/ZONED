
#include <stdio.h>
#include <iostream>
#include "ZONED.hpp"








int main()
{

Ztext test;
Ztext tchar;
Ztext tstring;

const char* tchr = "bonjour";
std::string tstr = "bonne nuit";

 test ="jpl";
 std::cout<<test<<std::endl;
 
 tchar = tchr ;
  std::cout<<tchar<<std::endl;
 
 tstring = tstr ;
  std::cout<<tstring<<std::endl;

  
std::cout<<test<<" :"<<tchar.ToChar()<<" :"<<tstring.StringChar()<<std::endl;


    return 0;

}
