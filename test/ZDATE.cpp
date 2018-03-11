
#include <stdio.h>
#include <iostream>
#include "ZONED.hpp"
using namespace __ZONED__;
using namespace std;






int main()
{





 Zdate  dats  ;


 int DATESYS = dats.datesys();



if (10101 == dats.ToInt()  )cout<<"date 00010101"<<endl;
cout<<dats.edtNUM()<<endl;
//dats= DATESYS;  cout<<"err"<<dats.statusmsg()<<dats.status()<<endl;
cout<<DATESYS<<endl;
 dats= "2016-07-24";


cout<<"Date  test :"<<dats.ToChar(0)<<":int: "<< dats.ToInt()<<endl;
 //   return 0;
 dats= "9999-07-24";



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


cout<<"Date  ResteJour()   :"<<dats.ResteJour()<<endl;

cout<<"Date  edtISO()   :"<<dats.edtISO()<<"  --  "<<dats.ToChar(dats.eISO)<<endl;

cout<<"Date  edtNUM()   :"<<dats.edtNUM()<<"  --  "<<dats.ToChar(dats.eNUM)<<endl;

cout<<"Date  Decalage_heuresys()   :"<<dats.Decalage_heuresys()<<endl;


    return 0;

}
