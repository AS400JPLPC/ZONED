
#include <stdio.h>
#include <iostream>
#include "ZONED.hpp"
#include <exception>







int main()
{
try{

Ztime timey;






//timey="94:01:01";
//timey="23:59:59";
//std::cout<<timey<<std::endl;

//timey.chr("24:01:01","24");
//timey.chr("23:01:01","24");
//timey.chr("23:01:01","AX");
//timey.chr("23:01:01","PM");
//timey.chr("13:01:01","AM");
//timey.chr("12:01:01","AM")
//timey.chr("01:01:01","AM");
/* timey.chr("13:51:25","24");
std::cout<<timey.getAmPm()<<std::endl;
std::cout<<timey<<std::endl;
std::cout<<timey.ToChar()<<std::endl;
std::cout<<timey.ConstChar()<<std::endl;
std::cout<<timey.StringChar()<<std::endl;
std::cout<<timey.print()<<std::endl;
timey.chr("01:01:01","AM");
std::cout<<timey.getAmPm()<<std::endl;
std::cout<<timey<<std::endl;
std::cout<<timey.ToChar()<<std::endl;
std::cout<<timey.ConstChar()<<std::endl;
std::cout<<timey.StringChar()<<std::endl;
std::cout<<timey.print()<<std::endl;
timey.chr("11:01:01","PM");
std::cout<<timey.getAmPm()<<std::endl;
std::cout<<timey<<std::endl;
std::cout<<timey.ToChar()<<std::endl;
std::cout<<timey.ConstChar()<<std::endl;
std::cout<<timey.StringChar()<<std::endl;
std::cout<<timey.print()<<std::endl;
timey.chr("11:01:01","24");
std::cout<<timey.getAmPm()<<std::endl;
std::cout<<timey<<std::endl;
std::cout<<timey.ToChar()<<std::endl;;
std::cout<<timey.ConstChar()<<std::endl;
std::cout<<timey.StringChar()<<std::endl;
std::cout<<timey.print()<<std::endl;
*/

/*timey.chr("11:01:01","24");
std::cout<<timey<<std::endl;
timey.add_min(); printf("+1 m:");
std::cout<<timey<<std::endl;
timey.add_min(60); printf("+60 m:");
std::cout<<timey<<std::endl;
timey.sub_min(60); printf("-60 m:");
std::cout<<timey<<std::endl;
timey.sub_min(); printf("-1 m:");
std::cout<<timey<<std::endl;
timey.sub_min(2); printf("-2 m:");
*/
timey.chr("20:01:00","24");
std::cout<<timey<<std::endl;
timey.sub_sec(2); printf("-2 s :");
std::cout<<timey<<std::endl;
timey.sub_sec(120); printf("-120 s :");
std::cout<<timey<<std::endl;
timey.sub_sec(3600); printf("-3600 s :");
std::cout<<timey<<std::endl;
timey.add_sec(3600); printf("+3600 s :");
std::cout<<timey<<std::endl;
timey.add_sec(120); printf("+120 s :");
std::cout<<timey<<std::endl;
timey.add_sec(); printf("+ s :");
timey.add_sec(); printf("+ s :");
std::cout<<timey<<std::endl;
/*timey.add_hr();
std::cout<<timey<<std::endl;
timey.sub_min();
std::cout<<timey<<std::endl;
*/

} catch (const std::exception& e)
{
	  std::cerr<<"Corriger les erreurs"<<e.what()<<std::endl;
	  return EXIT_FAILURE ;
 }


    return EXIT_SUCCESS ; 

}
