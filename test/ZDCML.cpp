#include <stdio.h>
#include <stdlib.h>

#include <stdarg.h>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>


#include <ZONED.hpp>
using namespace std;

///  traitement des nombres l'approche est celle de IBM38 RPGIII
///  34 chiffres maxi pour la gestion c'est confortable
///  conforme au DOUBLE et ODBC  voir alinéa postgesql
///  constructeur (entier,décimale) total lg << (entier + decimale)
///  si lg > 15 pas de constructeur numeric ----> (lol)  longeur maxi 31 digit + le signe + le point decimal;
///  pour les inputs int-->Zdcml  etc...
///  un format est construit ex (5.2)  999.99
///  la valeur  input ne peut pas être plus grande que la définition  pas d'affectation si une valeurs est déjà enregistrée elle est conservé
///

int main(void)
 {
setlocale(LC_ALL,"fr_FR.UTF-8");
Zdcml fra(4,2);
const double frdbl =314.24;
cout<<frdbl<<endl;


fra="3214,14";
cout<<"fra.statusmsg()"<<fra.statusmsg()<<endl;
if ( ! ZONED_OK) cout<<"statusmsg()"<<fra.statusmsg()<<endl;

cout<<"fra.ToChar()"<<fra.ToChar()<<endl;
if ( ! ZONED_OK) cout<<"statusmsg()"<<fra.statusmsg()<<endl;

return 0;

Zdcml KSXCFU(5,0);
Zdcml KSNXBO(4,0);
Zdcml V_QSTKt(10,0);
Zdcml KSNBTE(8,0);



V_QSTKt = 1 ;
KSNBTE =254;
KSNXBO = 4 ;
KSXCFU = 2500 ;

V_QSTKt*=KSNBTE;
cout<<V_QSTKt.ToChar()<<endl;

V_QSTKt*=KSNXBO;

cout<<V_QSTKt.ToChar()<<endl;

V_QSTKt*=KSXCFU;

cout<<V_QSTKt.ToChar()<<endl;
V_QSTKt = 10;
V_QSTKt.mult("%s,%s",KSNXBO.ToChar(),KSXCFU.ToChar());
cout<<V_QSTKt.statusmsg()<<endl;
cout<<V_QSTKt.ToChar()<<endl;

cout<<"KSXCFU = 2500"<<endl;
KSXCFU = 2500 ;
cout<<KSXCFU.ToDec()<<endl;



//return 0;


Zchar NOM(30);
Zdcml dd(19,3); ;
Zdcml a(19,3); Zdcml e(29,2);
Zdcml b(5,0);
Zdcml c(20,5);
Zdcml d(18,2);
Zdcml xx(10,2);
Zdcml f(35,0);
char * x__char ;
double ddd= 0;
 x__char = new char[40];
 Zdcml yy(29,2); /// egal 31 chiffres
                     // 12345678901234
  sprintf(x__char,"%s","34567890.123"); a=x__char;
     // a=34567890.123;
     cout<<a.ToChar()<<" a:"<<a.ToDec()<<endl;

        double _X_ = -99999999999999 ;

        char sign =  '-';
        char * value   = (char*) malloc(256  * sizeof(char*));   sprintf(value,"%c",'\0');
        char * cmd   = (char*) malloc(256  * sizeof(char*));   sprintf(cmd,"%s%c%d.0%d%c","%c",'%',0,5,'f');

        snprintf(value + strlen(value), 16, cmd , sign, fabs(_X_));

        cout<<"char * value "<<value<<endl;

        cout<<"strtod * value "<<strtod (value, NULL)<<endl;
                    // 12345678901234
//sprintf(x__char,"%s","+17976931348623"); dd=x__char;
          //12345678901234
  ddd =99999999999999 ; dd=ddd; sprintf(x__char,"%s","-099999999999999.12345"); dd=x__char;

cout<<" +  dd:"<<dd.ToChar()<<" ToDec:"<<dd.ToDec()<<" Double:"<<dd.ToDouble()<<endl;
//sprintf(x__char,"%s","-17999999999999"); dd=x__char;
        dd=_X_ ;
cout<<" - dd:"<<dd.ToChar()<<" ToDec:"<<dd.ToDec()<<" Double:"<<dd.ToDouble()<<endl;

ddd= ddd *-1;   ddd = dd.ToDouble() ;
cout<<" - dd:"<<dd.ToChar()<<" ToDec:"<<dd.ToDec()<<" Double:"<<dd.ToDouble()<<endl;
       dd*=-1 ;
cout<<" - dd:"<<dd.ToChar()<<" ToDec:"<<dd.ToDec()<<" Double:"<<dd.ToDouble()<<endl;
//sprintf(x__char,"%s","1234567890.12345"); dd=x__char;

 dd=strtod ("1234567890.100", NULL) ;
// cout<<" - dd:"<<dd.ToChar()<<" ToDec:"<<dd.ToDec()<<endl;
 // dd.add("%f",0.001);
  cout<<" - dd: ToDec:"<<dd.ToChar()<<endl; cout<<" - dd: ToDec:"<<dd.ToDec()<<endl; a=dd;
cout<<" - dd:"<<dd.ToChar()<<" ToDec:"<<a.ToDec()<<" Double:"<<dd.ToDouble()<<std::flush;


//return 0;

dd=0; NOM="Jean-pierre"; cout<< NOM.ToChar()<<"--"<< NOM.sizebuf()<<"--"<< NOM.sizeval()<<endl;
sprintf(x__char,"%s","1500.000"); a=x__char;
dd.add("%s","-1234567890.12345");dd.add("%f",-0.0026); cout<<" - dd: ToDec:"<<dd.ToChar()<<endl; cout<<" - dd: ToDec:"<<dd.ToDec()<<std::flush;
std::cout<<" - dd:"<<a.ToChar()<<NOM.ToChar()<<" ToDec:"<<dd.ToDec()<<" Double:"<<dd.ToDouble()<<endl; cout<<" - dd: ToDec:"<<dd.ToDec()<<std::flush;

std::cout<<dd.string_format(" - dd.ToChar(): %s NOM.ToChar() %s dd.ToDec()    %s dd.ToDouble() %f ",dd.ToChar(), NOM.ToChar(), dd.ToDec(), dd.ToDouble()).c_str();


//return 0;






ddd = dd.ToDouble() ; dd=ddd;
cout<<" - dd:"<<dd.ToChar()<<" ToDec:"<<dd.ToDec()<<" Double:"<<dd.ToDouble()<<endl;

 cout<<"\n test value a=0 :"<<endl; a=0; b= 0;  // if(EQ == a.cmp(b)) cout<<"(eq =a.cmp(b))"<<endl;
sprintf(x__char,"%s","1500.000"); a=x__char; cout<<a.ToChar()<<" a:"<<a.ToDec()<<endl;a=0;
a=1234567890.12345986; cout<<a.ToChar()<<" a:"<<a.ToDec()<<" Double:"<<a.ToDouble()<<endl;
double x = a.ToDouble(); a=x; cout<<" Double a:"<<a.ToChar()<<" a:"<<a.ToDec()<<" Double:"<<a.ToDouble()<<endl;
a=0;cout<<"a=0:"<<a.ToChar()<<" a:"<<a.ToDec()<<endl;

a=34567890.123;cout<<a.ToChar()<<" a:"<<a.ToDec()<<endl;

cout<<" printf:"<<a.string_format("%f      %s      %s" ,a.ToDouble(), a.ToChar() , a.ToDec()  )<<endl;


//return 0;



 sprintf(x__char,"%s","1234567890123456789.34");yy=x__char;  cout<<"1234567890123456789098345678901.34   :"<<yy.ToDec()<< endl;



cout<<" yy 29.2 :"<<yy.ToChar()<< endl;
cout<<" yy 29.2 :"<<yy.ToDouble()<< endl;
//return 0;




///Zdcml a(7,2);


sprintf(x__char,"%s","0000012345.12");xx=x__char;
std::cout<< xx.ToChar()<<std::endl;

std::cout<< xx.string_format("%+10.2f",xx.ToDouble())<<std::endl;

std::cout<<"xx.ToDec()" <<xx.ToDec()<<std::endl;
std::cout<<"xx.ToChar()" <<xx.ToChar()<<std::endl;



b= 5; b++;

cout<<b.ToInt()<<endl;
cout<<b.ToChar()<<endl;
cout<<b.ToDouble()<<endl;
//return 0 ;




sprintf(x__char,"%s","1234567890.9019345678901234");a=x__char;

cout<<"1234567890.9019345678901234   "<<a.ToChar()<<endl;

cout<<" Entier:"<<a.ToEntier(); cout<<" Dec:"<<a.ToDec()<<endl;

sprintf(x__char,"%s","1234567890.89012945678901234");a=x__char; cout<<"1234567890.89012945678901234        "<<a.ToChar()<<endl;
//c.ToRound();
cout<<" Entier:"<<a.ToEntier(); cout<<" Dec:"<<a.ToDec()<<endl;





sprintf(x__char,"%s","-1234567890");a=x__char;                           cout<<"-1234567890                         0  "<<a.ToChar()<<" a:"<<a.ToDec()<< endl;a=0;
sprintf(x__char,"%s","-1234567890.999956789012345");a=x__char;           cout<<"-1234567890.999956789012345         x  "<<a.ToChar()<<" a:"<<a.ToDec()<< endl;a=0;
sprintf(x__char,"%s","-123456789012345.6789012345678901");a=x__char;     cout<<"-123456789012345.6789012345678901   y  "<<a.ToChar()<<" a:"<<a.ToDec()<< endl;a=0; cout<<"ERR:"<<a.status();cout<<" ERR:"<<a.statusmsg()<<endl;
sprintf(x__char,"%s","-12345678901234567890983456789.01");e=x__char;     cout<<"-12345678901234567890983456789.01   z  "<<e.ToChar()<<" a:"<<a.ToDec()<< endl;e=0; cout<<"ERR:"<<e.status();cout<<" ERR:"<<e.statusmsg()<<endl;


 /// ****************************************
 /// test
 /// ****************************************


sprintf(x__char,"%s","-1234567890a ");a=x__char;
cout<<"-1234567890a  "; cout<<" ERR:"<<a.status();cout<<" ERR:"<<a.statusmsg()<<endl;


sprintf(x__char,"%s","1234567890.123456789012345678901234");a=x__char;

cout<<"1234567890.123456789012345678901234   "<<a.ToChar()<<endl;
cout<<" Entier:"<<a.ToEntier();cout<<" a: Dec:"<<a.ToDec()<<endl;

cout<<"ERR:"<<a.status()<<endl;
cout<<"ERR:"<<a.statusmsg()<<endl;

cout<<"error test  a<<'toto'"<<endl;
cout<<"ERR:"<<a.status()<<endl;
cout<<"ERR:"<<a.statusmsg()<<endl;


cout<<"Contrôle validité numerique" <<endl;

cout<<"\n test value a=0 :"; a=0;


cout<<"\n \n \n"<<"test value  Zdcml a(10,3);Zdcml c(15,5); Zdcml d(18,2); Zdcml e(29,2);"<<endl;

sprintf(x__char,"%s","-123456");a=x__char;                               cout<<"-123456                                "<<a.ToChar()<<" a:"<<a.ToDec()<<endl;a=0;
sprintf(x__char,"%s","-123456.7");a=x__char;                             cout<<"-123456.7                              "<<a.ToChar()<<" a:"<<a.ToDec()<<endl;a=0;
sprintf(x__char,"%s","-123456.00");a=x__char;                            cout<<"-123456.00                             "<<a.ToChar()<<" a:"<<a.ToDec()<<endl;a=0;
sprintf(x__char,"%s","-1234567890.12345");a=x__char;                     cout<<"-1234567890.12345                      "<<a.ToChar()<<" a:"<<a.ToDec()<<endl;a=0;
sprintf(x__char,"%s","-1234567890.123456789012345");a=x__char;           cout<<"-1234567890.123456789012345            "<<a.ToChar()<<" a:"<<a.ToDec()<<endl;a=0;
sprintf(x__char,"%s","-1234567890.12345678901234567890");a=x__char;      cout<<"-1234567890.123456789012345678901      "<<a.ToChar()<<" a:"<<a.ToDec()<<endl;a=0;
sprintf(x__char,"%s","-12345678901234567890983456789.01");e=x__char;     cout<<"-12345678901234567890983456789.01      "<<e.ToChar()<<" e:"<<e.ToDec()<<endl;e=0;
sprintf(x__char,"%s","-1234567890123456789012345678901");e=x__char;      cout<<"-1234567890123456789012345678901       "<<e.ToChar()<<" e:"<<e.ToDec()<<endl;e=0;
sprintf(x__char,"%s","-123456789012345678.9012345678901");d=x__char;     cout<<"-123456789012345678.9012345678901      "<<d.ToChar()<<" d:"<<d.ToDec()<<endl;d=0;
sprintf(x__char,"%s","-123456789012345678.9012345");d=x__char;           cout<<"-123456789012345678.9012345            "<<d.ToChar()<<" d:"<<d.ToDec()<<endl;d=0;
sprintf(x__char,"%s","-123456789012345");c=x__char;                      cout<<"-123456789012345                       "<<c.ToChar()<<" c:"<<c.ToDec()<<endl;c=0;
sprintf(x__char,"%s","-123456789012345.9012345");c=x__char;              cout<<"-123456789012345.9012345               "<<c.ToChar()<<" c:"<<c.ToDec()<<endl;c=0;
sprintf(x__char,"%s","-123456789012345.9012345678901234");c=x__char;     cout<<"-123456789012345.9012345678901234      "<<c.ToChar()<<" c:"<<c.ToDec()<<endl;c=0;

sprintf(x__char,"%s","123456");a=x__char;                               cout<<"123456                                "<<a.ToChar()<<" a:"<<a.ToDec()<<endl;a=0;
sprintf(x__char,"%s","123456.7");a=x__char;                             cout<<"123456.7                              "<<a.ToChar()<<" a:"<<a.ToDec()<<endl;a=0;
sprintf(x__char,"%s","123456.00");a=x__char;                            cout<<"123456.00                             "<<a.ToChar()<<" a:"<<a.ToDec()<<endl;a=0;
sprintf(x__char,"%s","1234567890.12345");a=x__char;                     cout<<"1234567890.12345                      "<<a.ToChar()<<" a:"<<a.ToDec()<<endl;a=0;
sprintf(x__char,"%s","1234567890.123456789012345");a=x__char;           cout<<"1234567890.123456789012345            "<<a.ToChar()<<" a:"<<a.ToDec()<<endl;a=0;
sprintf(x__char,"%s","1234567890.123456789012345678901234");a=x__char;  cout<<"1234567890.123456789012345678901234   "<<a.ToChar()<<" a:"<<a.ToDec()<<endl;a=0;
sprintf(x__char,"%s","12345678901234567890983456789012.34");e=x__char;  cout<<"12345678901234567890983456789012.34   "<<e.ToChar()<<" e:"<<e.ToDec()<<endl;e=0;
sprintf(x__char,"%s","1234567890123456789012345678901234");e=x__char;   cout<<"1234567890123456789012345678901234    "<<e.ToChar()<<" e:"<<e.ToDec()<<endl;e=0;
sprintf(x__char,"%s","123456789012345678.9012345678901234");d=x__char;  cout<<"123456789012345678.9012345678901234   "<<d.ToChar()<<" d:"<<d.ToDec()<<endl;d=0;
sprintf(x__char,"%s","123456789012345678.9012345");d=x__char;           cout<<"123456789012345678.9012345            "<<d.ToChar()<<" d:"<<d.ToDec()<<endl;d=0;
sprintf(x__char,"%s","123456789012345");c=x__char;                      cout<<"123456789012345                       "<<c.ToChar()<<" c:"<<c.ToDec()<<endl;c=0;
sprintf(x__char,"%s","123456789012345.9012345");c=x__char;              cout<<"123456789012345.9012345               "<<c.ToChar()<<" c:"<<c.ToDec()<<endl;c=0;
sprintf(x__char,"%s","123456789012345.9012345678901234");c=x__char;     cout<<"123456789012345.9012345678901234      "<<c.ToChar()<<" c:"<<c.ToDec()<<endl;c=0;

sprintf(x__char,"%s","123456789012345.90123456789012345");c=x__char;    cout<<"123456789012345.90123456789012345     "<<c.ToChar()<< endl;a=0;
cout<<"ERR:"<<a.status()<<endl;
cout<<"ERR:"<<a.statusmsg()<<endl;

sprintf(x__char,"%s","12345678901234590123456789012345");f=x__char;     cout<<"12345678901234590123456789012345      "<<f.ToChar()<< endl;f=0; cout<<"ERR:"<<f.status();cout<<" ERR:"<<f.statusmsg()<<endl;
if ( f.Msgerr()) cout<<"erreur Zdcml f(35,0);"<<endl;

cout<<"ERR:"<<a.status()<<endl;
cout<<"ERR:"<<a.statusmsg()<<endl;


a=0;        cout<<a.ToChar()<<endl;
b=10;       cout<<b.ToChar()<<endl;
c=20;       cout<<c.ToChar()<<endl;
d=15;       cout<<d.ToChar()<<endl;

cout<<"add"<<endl;
a.add("%s,%s,%s", b.ToChar(),c.ToChar(),d.ToChar()); cout<<a.ToChar()<<endl;

a*=-1;cout<<" a*-1;   "<<a.ToChar()<<endl;

cout<<"sub"<<endl;
a.sub("%s,%s,%s", b.ToChar(),c.ToChar(),d.ToChar()); cout<<a.ToChar()<<endl;

cout<<"mult"<<endl;
a=1;            cout<<a.ToChar()<<endl;
b=10.5;         cout<<b.ToChar()<<endl;
c=2050;         cout<<c.ToChar()<<endl;
d=15000050;     cout<<d.ToChar()<<endl;

a.mult("%s,%s,%s", b.ToChar(),c.ToChar(),d.ToChar()); cout<<a.ToChar()<<endl;


cout<<"div"<<endl;
a=1;            cout<<a.ToChar()<<endl;
b=10.5;         cout<<b.ToChar()<<endl;
c=2050;         cout<<c.ToChar()<<endl;
d=15000050;     cout<<d.ToChar()<<endl;

a.div("%s,%s,%s", b.ToChar(),c.ToChar(),d.ToChar()); cout<<a.ToChar()<<endl;



cout<<"formatage"<<endl;
Zdcml fa(5,0);
Zdcml fb(2,1);
Zdcml fc(4,0);
Zdcml fd(15,4);
fa=1;     fa++;        cout<<fa.ToChar()<<endl;
fb=-10.5;         cout<<fb.ToChar()<<endl;
fc=2050;         cout<<fc.ToChar()<<endl;
fd=15000050;     cout<<fd.ToChar()<<endl;


Zchar nom(10);

/*cout<<"votre nom:";
cin>>test;
cin>>nom;
nom<<test;
cout<<"reponse:"<<nom<<endl;

*/







     return (0);
 }

