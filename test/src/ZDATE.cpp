
#include <stdio.h>
#include <iostream>
#include "ZONED.hpp"

using namespace std;






int main()
{





 Zdate  dats  ;
 Zdate  daty  ;

 int DATESYS = dats.datesys();
 
cout<<DATESYS<<endl; 
 
if (10101 != dats.ToInt()  )cout<<"date 00010101"<<endl;

cout<<"dats.ToInt()"<<dats.ToInt()<<endl;
cout<<"dats.edtNUM())"<<dats.edtNUM()<<endl;  
 

dats= DATESYS;   
cout<<dats.edtISO()<<endl;  


cout<<"Date  test :"<<endl;
 dats= "";


cout<<"Date  test :"<<dats.ToChar(dats.enull)<<"   int: "<< dats.ToInt()<<endl;  


 dats= "2016-12-24"; 


cout<<"Date  test :"<<dats.ToChar( dats.eISO)<<":int: "<< dats.ToInt()<<endl;


 dats= "24001224"; 


cout<<"Date  test :"<<dats.ToChar( dats.eISO)<<":int: "<< dats.ToInt()<<endl; 


dats= "9999-07-24"; 
if (dats.CPFERR) std::cout<<dats.cerror()<<std::endl;

dats= "bonjour"; 
if (dats.CPFERR) std::cout<<dats.cerror()<<std::endl;





std::string test= "2300-12-24";
dats= test; 
cout<<"Date  test :"<<dats.ToChar( dats.eISO)<<":int: "<< dats.ToInt()<<endl;


test= "9999-07-24";
dats= test;  
if (dats.CPFERR) std::cout<<dats.cerror()<<std::endl;
test= "0724";
dats= test;  
if (dats.CPFERR) std::cout<<dats.cerror()<<std::endl;

test= "bonjour";
dats= test;   
if (dats.CPFERR) std::cout<<dats.cerror()<<std::endl;


int i= 99990724;
dats= i;  
if (dats.CPFERR) std::cout<<dats.cerror()<<std::endl;
i= 724;
dats= i;  
if (dats.CPFERR) std::cout<<dats.cerror()<<std::endl;

i= -1;
dats= i;  
if (dats.CPFERR) std::cout<<dats.cerror()<<std::endl;

i= 0;
dats= i;  
if (dats.CPFERR) std::cout<<dats.cerror()<<std::endl;
i= 10101;
dats= i;  
if (dats.CPFERR) std::cout<<dats.cerror()<<std::endl;
cout<<"Date  test :"<<dats.ToChar( dats.eISO)<<":int: "<< dats.ToInt()<<endl;

test= "20181224";
 dats= test; 


cout<<"Date  test :"<<dats.ToChar( dats.eISO)<<":int: "<< dats.ToInt()<<endl;


dats++;  cout<<"Date  test :"<<dats.ToChar( dats.eISO)<<":int: "<< dats.ToInt()<<endl;

dats+(5);  cout<<"Date  test :"<<dats.ToChar( dats.eISO)<<":int: "<< dats.ToInt()<<endl;

 std::cout<<"  --  **************************"<<std::endl;


 dats= "20181224";
 daty= "20181225";

 std::cout<<dats.ToInt()<< "  --  "<<daty.ToInt()<<std::endl;
 if (dats== daty ) std::cout<<"if (dats== daty )"<<std::endl; else std::cout<<"if (dats== daty )  *NO " <<std::endl;

 if (dats!= daty ) std::cout<<"if (dats!= daty )"<<std::endl; else std::cout<<"if (dats!= daty )  *NO " <<std::endl;

 if (dats<= daty ) std::cout<<"if (dats<= daty )"<<std::endl; else std::cout<<"if (dats<= daty )  *NO " <<std::endl;

 if (dats>= daty ) std::cout<<"if (dats>= daty )"<<std::endl; else std::cout<<"if (dats>= daty )  *NO " <<std::endl;

 if (dats> daty ) std::cout<<"if (dats> daty )"<<std::endl; else std::cout<<"if (dats> daty )  *NO " <<std::endl;

 if (dats< daty ) std::cout<<"if (dats< daty )"<<std::endl; else std::cout<<"if (dats< daty )  *NO " <<std::endl;


 std::cout<<"  --  **************************"<<std::endl; 
 
cout<<"Date  edtsysYMD()   :"<<dats.edtsysYMD()<<"  --  "<<dats.edtYMD()<<endl;

cout<<"Date  edtsysDMY()   :"<<dats.edtsysDMY()<<"  --  "<<dats.edtDMY()<<endl;

cout<<"Date  edtsysMDY()   :"<<dats.edtsysMDY()<<"  --  "<<dats.edtMDY()<<endl;

cout<<"Date  edtsysYM()    :"<<dats.edtsysYM()<<"  --  "<<dats.edtYM()<<endl;

cout<<"Date  edtsysMY()    :"<<dats.edtsysMY()<<"  --  "<<dats.edtMY()<<endl;

cout<<"Date  edttimesys()  :"<<dats.edttimesys()<<endl;

cout<<"Date  longdatesys() :"<<dats.longdatesys()<<"  --  "<<dats.longdate()<<endl;

cout<<"Date  D_datesys()   :"<<dats.D_datesys()<<"  --  "<<dats.D_date()<<endl;

cout<<"Date  M_datesys()   :"<<dats.M_datesys()<<"  --  "<<dats.M_date()<<endl;

cout<<"Date  edtsysISO()   :"<<dats.edtsysISO()<<"  --  "<<dats.ToChar(dats.sISO)<<endl;

cout<<"Date  edtsysNUM()   :"<<dats.edtsysNUM()<<"  --  "<<dats.ToChar(dats.sNUM)<<endl;



cout<<"Date  sysYM()       :"<<dats.sysYM()<<"  --  "<<dats.YM()<<endl;

cout<<"Date  sysday()      :"<<dats.sysday()<<"  --  "<<dats.day()<<endl;

cout<<"Date  sysmonth()    :"<<dats.sysmonth()<<"  --  "<<dats.month()<<endl;

cout<<"Date  sysyear()     :"<<dats.sysyear()<<"  --  "<<dats.year()<<endl;

cout<<"Date  sysyear2()    :"<<dats.sysyear2()<<"  --  "<<dats.year2()<<endl;

cout<<"Date  syssiecle()   :"<<dats.syssiecle()<<"  --  "<<dats.siecle()<<endl;

cout<<"Date  datesys()     :"<<dats.datesys()<<"  --  "<<dats.ToInt()<<endl;

cout<<"Date  Quantiemesys  :"<<dats.Quantiemesys()<<"  --  "<<dats.Quantieme()<<endl;

cout<<"Date  NumeroJoursys :"<<dats.NumeroJoursys()<<"  --  "<<dats.NumeroJour()<<endl;

cout<<"Date  Semainesys()  :"<<dats.Semainesys()<<"  --  "<<dats.Semaine()<<endl;


cout<<"Date  ResteJousys()   :"<<dats.ResteJoursys()<<"  --  "<<dats.ResteJour()<<endl;

cout<<"Date  edtISO()   :"<<dats.edtISO()<<"  --  "<<dats.ToChar(dats.eISO)<<endl;

cout<<"Date  edtNUM()   :"<<dats.edtNUM()<<"  --  "<<dats.ToChar(dats.eNUM)<<endl;

cout<<"Date  Decalage_heuresys()   :"<<dats.Decalage_heuresys()<<endl;


    return 0;

}
