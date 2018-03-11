#include <stdio.h>
#include <stdlib.h>

#include <stdarg.h>
#include <cstddef>
#include <cstring>
#include <iostream>
#include "ZONED.hpp"
using namespace std;



int main()
{

Zchar v_KART(30);
Zchar CGIM(1);
Zdcml CDPO(2,0);
Zchar CSTD(8);
Zchar TCZLBQ(15) ;
Zchar xSTRING(4);
char * _val="";
xSTRING ="----";
CGIM ="S";
CDPO=21;
CSTD="RDS50x69";
 v_KART.concat("%s%s%s%s",CGIM.ToChar(),"---" ,CDPO.ToChar(),CSTD.ToChar() );
    cout<<v_KART.ToChar()<<endl;

  //      return (0);
CGIM="";
CDPO=0;
CSTD="";
    CGIM.Extrac(v_KART,1,1);
    CDPO = atoi(v_KART.ExtracToChar(2,2));
    CSTD.Extrac(v_KART,4,8);
    cout<<CGIM.ToChar()<<"--"<<CDPO.ToChar()<<"--"<<CSTD.ToChar()<<endl;



    TCZLBQ.concat("%s%s%s",CGIM.ToChar(),CDPO.ToChar(),CSTD.ToChar() );
    cout<<TCZLBQ.ToChar()<<"--"<<TCZLBQ.sizebuf()<<"--"<<TCZLBQ.sizeval()<<endl;

 //        return (0);

   Zchar TCCPAY (2)  ;
    Zchar TCZLBL(15) ;
    Zchar test(7);
    Zchar TEST15(15) ;
    Zchar TEST10(10) ;  TEST10 ="1234567890";
    TCCPAY =="fr";
    cout<<TCCPAY.ToChar()<<"--"<<TCCPAY.sizebuf()<<"--"<<TCCPAY.sizeval()<<endl;
    TCCPAY ="ABCDEF";
    cout<<TCCPAY.ToChar()<<"--"<<TCCPAY.sizebuf()<<"--"<<TCCPAY.sizeval()<<endl;


    test ="BO12345";
    cout<<test.ToChar()<<"--"<<test.sizebuf()<<"--"<<test.sizeval()<<endl;
    test.Move("0123456789");
    cout<<test.ToChar()<<"--"<<test.sizebuf()<<"--"<<test.sizeval()<<endl;
    test.Movel("0123456789");
    cout<<test.ToChar()<<"--"<<test.sizebuf()<<"--"<<test.sizeval()<<endl;
        test.Move(TEST10);
    cout<<test.ToChar()<<"--"<<test.sizebuf()<<"--"<<test.sizeval()<<endl;
    test.Movel(TEST10);
    cout<<test.ToChar()<<"--"<<test.sizebuf()<<"--"<<test.sizeval()<<endl;
 //  return true;
cout<<"\n--01--------TCZLBL------------------------"<<endl;
     TCZLBL ="BONJOUR";
     cout<<TCZLBL.ToChar()<<"--"<<TCZLBL.sizebuf()<<"--"<<TCZLBL.sizeval()<<endl;
     cout<<TCZLBL.ToChar()<<endl;
cout<<"\n--02--------TCZLBL = test-----------------------"<<endl;
    TCZLBL = test;
    cout<<TCZLBL.ToChar()<<"--"<<TCZLBL.sizebuf()<<"--"<<TCZLBL.sizeval()<<endl;
cout<<"\n--03--------TCZLBL +=test;-----------------------"<<endl;
       TCZLBL ="xx";
        TCZLBL +=test;
       cout<<TCZLBL.ToChar()<<"--"<<TCZLBL.sizebuf()<<"--"<<TCZLBL.sizeval()<<endl;
cout<<"\n-04--TEST15 ='123456789012345';--TCZLBL +TEST15;---"<<endl;
    TEST15 ="123456789012345";
    TCZLBL +=TEST15;
    cout<<TCZLBL.ToChar()<<"--"<<TCZLBL.sizebuf()<<"--"<<TCZLBL.sizeval()<<endl;
cout<<"\n------------TCZLBL.concat('00001' ,'yyyyyssssx', NULL)-----------------------"<<endl;
    TCZLBL.concat("00001" ,"yyyyyssssx", NULL);
    cout<<TCZLBL.ToChar()<<"--"<<TCZLBL.sizebuf()<<"--"<<TCZLBL.sizeval()<<endl;
cout<<"\n-05--TCZLBL.concat('000002' ,'yyyyyssssss' ,'yyyyw' , '3333', NULL)---"<<endl;
    TCZLBL.concat("000002" ,"yyyyyssssss" ,"yyyyw" , "3333", NULL);
    cout<<TCZLBL.ToChar()<<"--"<<TCZLBL.sizebuf()<<"--"<<TCZLBL.sizeval()<<endl;
cout<<"\n------------TCZLBL.concat('2002' , NULL);-----------------------"<<endl;
    TCZLBL.concat("2002" , NULL);
    cout<<TCZLBL.ToChar()<<"--"<<TCZLBL.sizebuf()<<"--"<<TCZLBL.sizeval()<<endl;
cout<<"\n--06--------TCZLBL.concat('2002' , NULL);-----------------------"<<endl;
    TCZLBL.concat("2002" , NULL);
    cout<<TCZLBL.ToChar()<<"--"<<TCZLBL.sizebuf()<<"--"<<TCZLBL.sizeval()<<endl;
cout<<"\n------------TCZLBL.concat('' , NULL);-----------------------"<<endl;
    TCZLBL.concat("" , NULL);
    cout<<TCZLBL.ToChar()<<"--"<<TCZLBL.sizebuf()<<"--"<<TCZLBL.sizeval()<<endl;
cout<<"\n--07---TCZLBL.concat(TCZLBL.ToChar(),'12345' NULL);----------"<<endl;
    TCZLBL.concat("2002" , NULL);
    TCZLBL.concat(TCZLBL.ToChar(),"12345", NULL);
       cout<<TCZLBL.ToChar()<<"--"<<TCZLBL.sizebuf()<<"--"<<TCZLBL.sizeval()<<endl;
cout<<"\n--08-TCZLBL = '2013-';-------TCZLBL.+=(TEST10 , NULL);----------"<<endl;
    TCZLBL = "2013-";
    TCZLBL+=TEST10;
    cout<<TCZLBL.ToChar()<<"--"<<TCZLBL.sizebuf()<<"--"<<TCZLBL.sizeval()<<endl;
cout<<"\n--09----------------------------------------"<<endl;
    TCZLBL = test;      cout<<TCZLBL.ToChar()<<"--"<<TCZLBL.sizebuf()<<"--"<<TCZLBL.sizeval()<<endl;
    string xx =TCZLBL.ToChar();
    cout<<xx<<endl;
cout<<"\n--10------- substr Zchar----------------"<<endl;



//    TCZLBQ(15);  //test redeclaration beug   a la compile
    TCZLBQ ="1----.....----9";

    cout<<TCZLBQ.ToChar()<<"--"<<TCZLBQ.sizebuf()<<"--"<<TCZLBQ.sizeval()<<endl;
cout<<"\n---11------ +=-------------------"<<endl;
    TCZLBQ ="xxx";
    TCZLBQ +="12345";
    cout<<TCZLBQ.ToChar()<<"--"<<TCZLBQ.sizebuf()<<"--"<<TCZLBQ.sizeval()<<endl;
cout<<"\n--12------- concat----------------"<<endl;
    TCZLBQ ="yyy";
    TCZLBQ.concat("12345","YYY",NULL);
    cout<<TCZLBQ.ToChar()<<"--"<<TCZLBQ.sizebuf()<<"--"<<TCZLBQ.sizeval()<<endl;
cout<<"\n--13-------TCZLBQ.xsubstr('12345',2,3)----------------"<<endl;
    TCZLBQ ="yyy";
    TCZLBQ.Extrac("12345",2,3);
    cout<<TCZLBQ.ToChar()<<"--"<<TCZLBQ.sizebuf()<<"--"<<TCZLBQ.sizeval()<<endl;
cout<<"\n---14--------TCZLBQ.Extrac('1234512345678901234567890',2,25);-"<<endl;
    TCZLBQ ="yyy";
    TCZLBQ.Extrac("1234512345678901234567890",2,25);
    cout<<TCZLBQ.ToChar()<<"--"<<TCZLBQ.sizebuf()<<"--"<<TCZLBQ.sizeval()<<endl;
cout<<"\n---15--------TCZLBL = TCZLBQ.xsubstr(3,12)----------"<<endl;
    TCZLBQ ="123456789012345";
    TCZLBL.Extrac(TCZLBQ,1,12);
    cout<<TCZLBL.ToChar()<<"--"<<TCZLBL.sizebuf()<<"--"<<TCZLBL.sizeval()<<endl;
    cout<<TCZLBQ.ToChar()<<"--"<<TCZLBQ.sizebuf()<<"--"<<TCZLBQ.sizeval()<<endl;
cout<<"\n----16------------TCZLBQ ='yyy';----- TCZLBQ cmp'xxx'-------"<<endl;
    TCZLBQ ="yyy";

    if(EQ == TCZLBQ.cmp("xxx")) cout<<"ok"<<endl;else cout<<" not ok"<<endl;
cout<<"\n---17-------------TCZLBQ ='yyy';----- TCZLBQ cmp'yyy'--"<<endl;

     if(EQ == TCZLBQ.cmp("yyy")) cout<<"ok"<<endl;else cout<<" not ok"<<endl;
cout<<"\n--18---------- TCZLBQ ='yyy';TCZLBQ ='xxx'; TCZLBQ cmpTCZLBL; ---"<<endl;
    TCZLBQ ="yyy";
    TCZLBL = "xxx";

    if(EQ == TCZLBQ.cmp(TCZLBL)) cout<<"ok"<<endl;else cout<<" not ok"<<endl;
cout<<"\n--19----------- TCZLBQ ='yyy'; TCZLBQ cmpTCZLBL; ----------------"<<endl;
    TCZLBL = "yyy";

    if(EQ == TCZLBQ.cmp(TCZLBL)) cout<<"ok"<<endl;else cout<<" not ok"<<endl;
    printf("%s\n",TCZLBQ.ToChar());
cout<<"\n--20------------ TCZLBQ ='yyy'; TCZLBQ += TCZLBL; ----------------"<<endl;
    TCZLBL = "yyy";
    TCZLBQ += TCZLBL;
    printf("%s\n",TCZLBQ.ToChar());
cout<<"\n--21------------------------cout<<TCZLBL<<endl;-------------------"<<endl;
    cout<<TCZLBL.ToChar()<<endl;
cout<<"\n--30------------TCZLBL = 'yyy';--------TCZLBL.xfind('0')----------------------"<<endl;
    if ( TCZLBL.locfind("0")) {cout<<"coucou"<<endl;} else  {cout<<" pas coucou"<<endl;}  ;
cout<<"\n--31-------------TCZLBL = 'yyy';--------TCZLBL.xfind('y')----------------------"<<endl;
    if ( TCZLBL.locfind("y")) {cout<<"coucou"<<endl;} ;



Zchar    X_DEB(2);
Zchar    X_FIN(2);
Zchar    X_KEY(4);
Zchar    H_KEY(10);

 H_KEY = "1007992801";

    X_DEB.Extrac(H_KEY,1,2);
    X_FIN.Extrac(H_KEY,9,2);
 //    X_KEY.concat( X_DEB.ToChar(),X_FIN.ToChar(), NULL );
 // X_KEY.concat("%s%s",X_DEB.ToChar(),X_FIN.ToChar(), NULL);
     X_KEY.concat("%d%d",X_DEB.ToChar(),X_FIN.ToChar(), NULL );
cout<<"\n--32--- ----------------"<<endl;
    cout<<"X_KEY.concat( X_DEB.ToChar() )"<<endl;
    cout<<X_KEY.ToChar()<<"--"<<X_KEY.sizebuf()<<"--"<<X_KEY.sizeval()<<endl;


 //        return (0);



    TCZLBQ ="yyy";
cout<<"TCZLBQ = yyy   :"<<TCZLBQ.ToChar()<<endl;

    TCZLBL ="yyy";
cout<<"TCZLBL =    :"<<TCZLBL.ToChar()<<":"<<endl;


cout<<"\n--42-----------NE == TCZLBQ.cmpNE(TCZLBL)----------------"<<endl;
cout<<"TCZLBL = yyy   :"<<TCZLBL.ToChar()<<endl;
    if(TCZLBQ!=(TCZLBL)) cout<<"NE"<<endl;else cout<<"ERRBAD"<<endl;

cout<<"\n--43-----------EQ == TCZLBQ.cmpEQ(TCZLBL)----------------"<<endl;
cout<<"TCZLBL = yyy   :"<<TCZLBL.ToChar()<<endl;
    if(TCZLBQ==(TCZLBL)) cout<<"EQ"<<endl;else cout<<"ERRBAD"<<endl;

cout<<"\n--44-----------LT == TCZLBQ.cmpLT(TCZLBL)----------------"<<endl;
cout<<"TCZLBL = yyy   :"<<TCZLBL.ToChar()<<endl;
    if(TCZLBQ<(TCZLBL)) cout<<"LT"<<endl;else cout<<"ERRBAD"<<endl;

cout<<"\n--44-----------GT == TCZLBQ.cmpGT(TCZLBL)----------------"<<endl;
cout<<"TCZLBL = yyy   :"<<TCZLBL.ToChar()<<endl;
    if(TCZLBQ>(TCZLBL)) cout<<"GT"<<endl;else cout<<"ERRBAD"<<endl;

cout<<"\n--45-----------GT == TCZLBQ.cmpGT(TCZLBL)----------------"<<endl;
cout<<"TCZLBL = yyy   :"<<TCZLBL.ToChar()<<endl;
    if(EQ == TCZLBQ.cmp(TCZLBL)) cout<<"EQ"<<endl;else cout<<"ERRBAD"<<endl;
    if(LT == TCZLBQ.cmp(TCZLBL)) cout<<"LT"<<endl;else cout<<"ERRBAD"<<endl;
    if(GT == TCZLBQ.cmp(TCZLBL)) cout<<"GT"<<endl;else cout<<"ERRBAD"<<endl;



cout<<"\n--52-----------NE == TCZLBQ.cmpNE(TCZLBL)----------------"<<endl;

    if(TCZLBQ!=("yya")) cout<<"NE"<<endl;else cout<<"ERRBAD"<<endl;

cout<<"\n--53-----------EQ == TCZLBQ.cmpEQ(TCZLBL)----------------"<<endl;

    if(TCZLBQ==("yya")) cout<<"EQ"<<endl;else cout<<"ERRBAD"<<endl;

cout<<"\n--54-----------LT == TCZLBQ.cmpLT(TCZLBL)----------------"<<endl;

    if(TCZLBQ<("yya")) cout<<"LT"<<endl;else cout<<"ERRBAD"<<endl;

cout<<"\n--54-----------GT == TCZLBQ.cmpGT(TCZLBL)----------------"<<endl;

    if(TCZLBQ>("yya")) cout<<"GT"<<endl;else cout<<"ERRBAD"<<endl;

cout<<"\n--55-----------GT == TCZLBQ.cmpGT(TCZLBL)----------------"<<endl;
cout<<"TCZLBL = yyy   :"<<TCZLBL.ToChar()<<endl;
    if(EQ == TCZLBQ.cmp("yya")) cout<<"EQ"<<endl;else cout<<"ERRBAD"<<endl;
    if(LT == TCZLBQ.cmp("yya")) cout<<"LT"<<endl;else cout<<"ERRBAD"<<endl;
    if(GT == TCZLBQ.cmp("yya")) cout<<"GT"<<endl;else cout<<"ERRBAD"<<endl;





     return (0);

}
