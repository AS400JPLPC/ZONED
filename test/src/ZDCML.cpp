#include <stdio.h>
#include <stdlib.h>

#include <stdarg.h>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>
#include <limits>

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

std::cout<<"-----double--------"<<std::endl;


Zdcml test_dbl0(5,0);
 std::cout<<"init   "<<test_dbl0<<std::endl;

test_dbl0=33.00;    std::cout<<test_dbl0.clen()<<std::endl;

printf(" test_dbl0.ToChar() >>>    %s\n",test_dbl0.ToChar());
printf(" test_dbl0.ConstChar() >>>    %s\n",test_dbl0.ConstChar());

std::string xstring0 = test_dbl0.String();
std::cout<<"test_dbl0.String()  >>>"<<   xstring0<<std::endl;


if(test_dbl0.CPFERR) std::cout<<"test_dbl0=33.20;  "<<test_dbl0.cerror()<<std::endl;
std::cout<<"test_dbl0=33.20;  >>"<<test_dbl0<<std::endl;

 





Zdcml test_dbl(5,2);
//std::cout<<"init   "<<test_dbl<<std::endl;

test_dbl=33.20;    std::cout<<test_dbl.clen()<<std::endl;

printf(" test_dbl.ToChar() >>>    %s\n",test_dbl.ToChar());
printf(" test_dbl.ConstChar() >>>    %s\n",test_dbl.ConstChar());

std::string xstring = test_dbl.String();
std::cout<<"test_dbl.String()  >>>"<<   xstring<<std::endl;


if(test_dbl.CPFERR) std::cout<<"test_dbl=33.20;  "<<test_dbl.cerror()<<std::endl;
std::cout<<"test_dbl=33.20;  >>"<<test_dbl<<std::endl;

 

std::cout<<"-----int--------"<<std::endl;
Zdcml test_int(2,0);

std::cout<<"init   "<<test_int<<std::endl;

 
test_int=33.2;

if(test_int.CPFERR) std::cout<<"test_int=33.2; err  "<<test_int.cerror()<<std::endl;
std::cout<<"test_int=33.2;  "<<test_int<<std::endl;


test_int="aa";
if(test_int.CPFERR) std::cout<<"test_int=\"aa\"; err "<<test_int.cerror()<<std::endl;
std::cout<<"test_int=\"aa\";  "<<test_int<<std::endl;



test_int=33;
if(test_int.CPFERR) std::cout<<"test_int=33; err  "<<test_int.cerror()<<std::endl;
std::cout<<"test_int=33;  "<<test_int<<std::endl;



test_int=-33;
if(test_int.CPFERR) std::cout<<"test_int=-33;  err "<<test_int.cerror()<<std::endl;
std::cout<<"test_int=-33;  "<<test_int<<std::endl;
 

test_int=123456;
if(test_int.CPFERR) std::cout<<"test_int=123456; err  "<<test_int.cerror()<<std::endl;
std::cout<<"test_int=123456;  "<<test_int<<std::endl;


std::cout<<"-----int-LONG-------"<<std::endl;

Zdcml test_int_lon(17,0);
std::cout<<"init   "<<test_int_lon<<std::endl;


test_int_lon=33.2;
if(test_int_lon.CPFERR) std::cout<<"test_int_lon=33.2;  "<<test_int_lon.cerror()<<std::endl;
std::cout<<"test_int_lon=33.2;  "<<test_int_lon<<std::endl;


test_int_lon="aa";
if(test_int_lon.CPFERR) std::cout<<"test_int_lon=\"aa\";  "<<test_int_lon.cerror()<<std::endl;
std::cout<<"test_int_lon=\"aa\";  "<<test_int_lon<<std::endl;

test_int_lon=33;
if(test_int_lon.CPFERR) std::cout<<"test_int_lon=33;  "<<test_int_lon.cerror()<<std::endl;
std::cout<<"test_int_lon=33;  "<<test_int_lon<<std::endl;
test_int_lon=-33;
if(test_int_lon.CPFERR) std::cout<<"test_int_lon=-33;  "<<test_int_lon.cerror()<<std::endl;
std::cout<<"test_int_lon=-33;  "<<test_int_lon<<std::endl;
 

test_int_lon=12345678901234567;
if(test_int_lon.CPFERR) std::cout<<"test_int_lon=\"12345678901234567\"  "<<test_int_lon.cerror()<<std::endl;
std::cout<<"test_int_lon=\"12345678901234567\"  "<<test_int_lon<<std::endl;


test_int_lon=1234567890123456789;
if(test_int_lon.CPFERR) std::cout<<"test_int_lon=\"1234567890123456789\"  "<<test_int_lon.cerror()<<std::endl;
std::cout<<"test_int_lon=\"1234567890123456789\"  "<<test_int_lon<<std::endl;



std::cout<<"-----double--------"<<std::endl;

/*
Zdcml test_dbl(5,2);
//std::cout<<"init   "<<test_dbl<<std::endl;

test_dbl=33.20; printf("33.20   >>> %s",test_dbl.ToChar());
if(test_dbl.CPFERR) std::cout<<"test_dbl=33.02;  "<<test_dbl.cerror()<<std::endl;
std::cout<<"test_dbl=33.02;  >>"<<test_dbl.ToChar()<<std::endl;
*/

test_dbl=123456.99;
if(test_dbl.CPFERR) std::cout<<"test_chr=\"12456.99\"  "<<test_dbl.cerror()<<std::endl;
std::cout<<"test_chr=\"123456.99\"  "<<test_dbl<<std::endl;

Zdcml test_dblx(30,4);

//test_dblx=9999999999999999.08L;    error
//          123456789012345678 
  test_dblx=999999999999999999;	// ou  
//test_dblx=99999999999.99;		// reducteur 
if(test_dblx.CPFERR) std::cout<<"test_dblx=\"123456789012345x.02L\"  "<<test_dblx.cerror()<<std::endl;
std::cout<<"test_dblx=\"123456789012345x.02L\"  "<<test_dblx<<std::endl;

test_dblx="-123456789012345567890.02";
if(test_dblx.CPFERR) std::cout<<"test_dblx=\"12345678901234567890.02\"  "<<test_dblx.cerror()<<std::endl;
std::cout<<"test_dblx=\"12345678901234567890.02\"  "<<test_dblx<<std::endl;
 
std::cout<<"------char*--------"<<std::endl;

Zdcml test_chr(5,2);
std::cout<<"init   "<<test_chr<<std::endl;
test_chr=33.02;
if(test_chr.CPFERR) std::cout<<"test_chr=33.02;   "<<test_chr.cerror()<<std::endl;
std::cout<<"test_chr=33.02;   "<<test_chr<<std::endl;

test_chr="33,02";
if(test_chr.CPFERR) std::cout<<"test_chr=\"33,02\"  "<<test_chr.cerror()<<std::endl;
std::cout<<"test_chr=\"33,02\"  "<<test_chr<<std::endl;


test_chr="33,,02";
if(test_chr.CPFERR) std::cout<<"test_chr=\"33,,02\"  "<<test_chr.cerror()<<std::endl;
std::cout<<"test_chr=\"33,,02\"  "<<test_chr<<std::endl;

test_chr="";
test_chr="33ab02";
if(test_chr.CPFERR) std::cout<<"test_chr=\"33ab02\"  "<<test_chr.cerror()<<std::endl;
std::cout<<"test_chr=\"33ab02\"  "<<test_chr<<std::endl;


test_chr="123456.99";
if(test_chr.CPFERR) std::cout<<"test_chr=\"12456.99\"  "<<test_chr.cerror()<<std::endl;
std::cout<<"test_chr=\"123456.99\"  "<<test_chr<<std::endl;






std::cout<<"-----string-----"<<std::endl;

Zdcml test_str(3,2);
std::cout<<"init   "<<test_str<<std::endl;

string str ="33.02";
test_str=str;
if(test_str.CPFERR) std::cout<<"test_str=33.02;   "<<test_str.cerror()<<std::endl;
std::cout<<"test_str=33.02;   "<<test_str<<std::endl;


str ="33,02";
test_str=str;
if(test_str.CPFERR) std::cout<<"test_str=\"33,02\"  "<<test_str.cerror()<<std::endl;
std::cout<<"test_str=\"33,02\"  "<<test_str<<std::endl;


str ="33,,02";
test_str=str;
if(test_str.CPFERR) std::cout<<"test_str=\"33,,02\"  "<<test_str.cerror()<<std::endl;
std::cout<<"test_str=\"33,,02\"  "<<test_str<<std::endl;

test_str="";
str ="33ab02";
test_str=str;
if(test_str.CPFERR) std::cout<<"test_str=\"33ab02\"  "<<test_str.cerror()<<std::endl;
std::cout<<"test_str=\"33ab02\"  "<<test_str<<std::endl;


test_str="123456.99";
if(test_str.CPFERR) std::cout<<"test_str=\"12456.99\"  "<<test_str.cerror()<<std::endl;
std::cout<<"test_chr=\"123456.99\"  "<<test_str<<std::endl;


std::cout<<"-----Zdcml-----"<<std::endl;
//Zdcml test_str(3,2);
//Zdcml test_dblx(30,4);

test_str ="-1,123";
if(test_str.CPFERR) std::cout<<"test_str =\"1,123\";  ici la valeur est tronqué (3,2)"<<test_str.cerror()<<std::endl;


test_dblx = -99.9945 ;
std::cout<<"init   "<<test_str<<std::endl;
std::cout<<"init   "<<test_dblx<<std::endl;
test_dblx = 99.9945 ;
test_str=test_dblx;

if(test_str.CPFERR) std::cout<<"test_str=test_dblx;  "<<test_str.cerror()<<std::endl;
std::cout<<"test_str=test_dblx; "<<test_str<<std::endl;


test_dblx = 9999.99 ;
test_str=test_dblx;

if(test_str.CPFERR) std::cout<<"test_str=test_dblx;  "<<test_str.cerror()<<std::endl;
std::cout<<"test_str=test_dblx; "<<test_str<<std::endl;

test_dblx = 999.99 ;
test_str=test_dblx;

if(test_str.CPFERR) std::cout<<"test_str=test_dblx;  "<<test_str.cerror()<<std::endl;
std::cout<<"test_str=test_dblx; "<<test_str<<std::endl;

test_str++;

if(test_str.CPFERR) std::cout<<"test_str=test_dblx;  "<<test_str.cerror()<<std::endl;
std::cout<<"test_str=test_dblx; "<<test_str<<std::endl;
test_str--;
if(test_str.CPFERR) std::cout<<"test_str=test_dblx;  "<<test_str.cerror()<<std::endl;
std::cout<<"test_str=test_dblx; "<<test_str<<std::endl;

test_str++;
std::cout<<test_str<<std::endl;
test_str++; 
std::cout<<test_str<<std::endl;
test_str+=0.12;
std::cout<<test_str<<std::endl;
test_str++;
std::cout<<test_str<<std::endl;
test_str++;
std::cout<<test_str<<std::endl;

std::cout<<"-----calcul-----"<<std::endl;

Zdcml test(1,0);

test++;
std::cout<<"test_chr=\"test_x++;\"  "<<test<<std::endl;

for (int i = 0; i<11; i++) test++;

std::cout<<"test_chr=\"test_x++;\"  "<<test<<std::endl;


test_dblx =888.88;
test_dblx%= 10;
if(test_str.CPFERR) std::cout<<"test_dblx%= 10;  "<<test_dblx.cerror()<<std::endl;
std::cout<<"test_dblx%= 10; "<<test_dblx<<std::endl;




test_dblx =7;
test =2;
test_dblx%= test;
if(test_str.CPFERR) std::cout<<"test_dblx%= test;  "<<test_dblx.cerror()<<std::endl;
std::cout<<"test_dblx%= test; "<<test_dblx<<std::endl;
return 0;
     
 }

