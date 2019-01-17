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
 

Zchar a(10) ;


a="1éÀ";
std::cout<<a<<std::endl;

a+="67890";
std::cout<<a<<std::endl;

Zchar b(15) ;
b="123456789012345";
std::cout<<b<<std::endl;


Zchar w(4) ;
w="àéla";
std::cout<<w<<std::endl;
w.ToUper();
std::cout<<w<<"   "<<w.deflen()<<" clen "<<w.clen()<<std::endl;
std::cout<<"   w >"<<w<<"   w.Chr() >  "<<w.Chr()<<" w.ConstChr()  >"<<w.ConstChr()<<" w.Str() > "<<w.Str()<<std::endl;

Zchar Tw(100) ;
std::cout<<"-------------"<<std::endl;
Tw.Extrac(a ,1,3 );
if (Tw.CPFERR ) std::cout<<"   msgerr :		>"<<Tw.cerror()<<std::endl;
std::cout<<a<<"   Tw.Extrac(a ,1, 2 ) :		>"<<Tw<<std::endl;
Zchar Tx(100) ;
a="z";
Tw=" bonjour méméà{ test ";
Tw.Replace("o","z");
if (Tw.CPFERR ) std::cout<<"   msgerr :		>"<<Tw.cerror()<<std::endl;
std::cout<<a<<"   "<<"Tw.Replace(\"o\",\"z\")		>"<<Tw<<std::endl;
Tw.Replace(a.Chr(),"o");
if (Tw.CPFERR ) std::cout<<"   msgerr :		>"<<Tw.cerror()<<std::endl;
std::cout<<a<<"   "<<"Tw.Replace(a.Chr() = o ,\"o\")		>"<<Tw<<std::endl;


Tx.concat("TEXT concat  %s %d  text %s",Tw.Chr(),10,b.Chr());
if (Tx.CPFERR ) std::cout<<"   msgerr :		>"<<Tx.cerror()<<std::endl;
std::cout<<"Tx.concat(\"bonjour  %s %d  text %s\",Tw.Chr(),10,b.Chr()); >"<<Tx<<std::endl;

a="àéla";
b="àéla";
if ( a == b) std::cout<<"if ( a == b) " << std::endl; else std::cout<<"no if ( a == b)"<<std::endl;
if ( a <  b) std::cout<<"if ( a <  b) " << std::endl; else std::cout<<"no if ( a <  b)"<<std::endl;
if ( a >  b) std::cout<<"if ( a >  b) " << std::endl; else std::cout<<"no if ( a >  b)"<<std::endl;
if ( a != b) std::cout<<"if ( a != b) " << std::endl; else std::cout<<"no if ( a != b)"<<std::endl;
if ( a <= b) std::cout<<"if ( a <= b) " << std::endl; else std::cout<<"no if ( a <= b)"<<std::endl;
if ( a >= b) std::cout<<"if ( a >= b) " << std::endl; else std::cout<<"no if ( a >= b)"<<std::endl;

if ( EQ == a.cmp( b) ) std::cout<<"if (EQ == a.cmp( b)) " << std::endl; else std::cout<<"no if (EQ == a.cmp( b))"<<std::endl;
if ( LT == a.cmp( b) ) std::cout<<"if (LT == a.cmp( b)) " << std::endl; else std::cout<<"no if (LT == a.cmp( b))"<<std::endl;
if ( GT == a.cmp( b) ) std::cout<<"if (GT == a.cmp( b)) " << std::endl; else std::cout<<"no if (GT == a.cmp( b))"<<std::endl;
std::cout<<"-------------"<<std::endl;




b="123456789012345";
a=b;
std::cout<<"  a= b  "<<a;

if (a.CPFERR ) std::cout<<"   msgerr :		>"<<a.cerror()<<std::endl;

std::cout<<"-------------"<<std::endl;


b="1234567890";
if ( a == b) std::cout<<"if ( a == b) " << std::endl; else std::cout<<"no if ( a == b)"<<std::endl;
if ( a <  b) std::cout<<"if ( a <  b) " << std::endl; else std::cout<<"no if ( a <  b)"<<std::endl;
if ( a >  b) std::cout<<"if ( a >  b) " << std::endl; else std::cout<<"no if ( a >  b)"<<std::endl;
if ( a != b) std::cout<<"if ( a != b) " << std::endl; else std::cout<<"no if ( a != b)"<<std::endl;
if ( a <= b) std::cout<<"if ( a <= b) " << std::endl; else std::cout<<"no if ( a <= b)"<<std::endl;
if ( a >= b) std::cout<<"if ( a >= b) " << std::endl; else std::cout<<"no if ( a >= b)"<<std::endl;

if ( EQ == a.cmp( b) ) std::cout<<"if (EQ == a.cmp( b)) " << std::endl; else std::cout<<"no if (EQ == a.cmp( b))"<<std::endl;
if ( LT == a.cmp( b) ) std::cout<<"if (LT == a.cmp( b)) " << std::endl; else std::cout<<"no if (LT == a.cmp( b))"<<std::endl;
if ( GT == a.cmp( b) ) std::cout<<"if (GT == a.cmp( b)) " << std::endl; else std::cout<<"no if (GT == a.cmp( b))"<<std::endl;
std::cout<<"-------------"<<std::endl;



b="123456789012356";
if ( a == b) std::cout<<"if ( a == b) " << std::endl; else std::cout<<"no if ( a == b)"<<std::endl;
if ( a <  b) std::cout<<"if ( a <  b) " << std::endl; else std::cout<<"no if ( a <  b)"<<std::endl;
if ( a >  b) std::cout<<"if ( a >  b) " << std::endl; else std::cout<<"no if ( a >  b)"<<std::endl;
if ( a != b) std::cout<<"if ( a != b) " << std::endl; else std::cout<<"no if ( a != b)"<<std::endl;
if ( a <= b) std::cout<<"if ( a <= b) " << std::endl; else std::cout<<"no if ( a <= b)"<<std::endl;
if ( a >= b) std::cout<<"if ( a >= b) " << std::endl; else std::cout<<"no if ( a >= b)"<<std::endl;

if ( EQ == a.cmp( b) ) std::cout<<"if (EQ == a.cmp( b)) " << std::endl; else std::cout<<"no if (EQ == a.cmp( b))"<<std::endl;
if ( LT == a.cmp( b) ) std::cout<<"if (LT == a.cmp( b)) " << std::endl; else std::cout<<"no if (LT == a.cmp( b))"<<std::endl;
if ( GT == a.cmp( b) ) std::cout<<"if (GT == a.cmp( b)) " << std::endl; else std::cout<<"no if (GT == a.cmp( b))"<<std::endl;
std::cout<<"-------------"<<std::endl;



b="1234";
if ( a == b) std::cout<<"if ( a == b) " << std::endl; else std::cout<<"no if ( a == b)"<<std::endl;
if ( a <  b) std::cout<<"if ( a <  b) " << std::endl; else std::cout<<"no if ( a <  b)"<<std::endl;
if ( a >  b) std::cout<<"if ( a >  b) " << std::endl; else std::cout<<"no if ( a >  b)"<<std::endl;
if ( a != b) std::cout<<"if ( a != b) " << std::endl; else std::cout<<"no if ( a != b)"<<std::endl;
if ( a <= b) std::cout<<"if ( a <= b) " << std::endl; else std::cout<<"no if ( a <= b)"<<std::endl;
if ( a >= b) std::cout<<"if ( a >= b) " << std::endl; else std::cout<<"no if ( a >= b)"<<std::endl;

if ( EQ == a.cmp( b) ) std::cout<<"if (EQ == a.cmp( b)) " << std::endl; else std::cout<<"no if (EQ == a.cmp( b))"<<std::endl;
if ( LT == a.cmp( b) ) std::cout<<"if (LT == a.cmp( b)) " << std::endl; else std::cout<<"no if (LT == a.cmp( b))"<<std::endl;
if ( GT == a.cmp( b) ) std::cout<<"if (GT == a.cmp( b)) " << std::endl; else std::cout<<"no if (GT == a.cmp( b))"<<std::endl;
std::cout<<"-------------"<<std::endl;

std::cout<<a.Chr()<<std::endl;
std::cout<<a.ConstChr()<<std::endl;
std::cout<<a.Str()<<std::endl;

std::cout<<"-------------"<<std::endl;

Zchar text(100);

b="12345.12345";
text.concat("bonjour  %s %d  text %s",a.Chr(),10,b.Chr());
if (b.CPFERR ) std::cout<<"   msgerr :		>"<<b.cerror()<<std::endl;
std::cout<<"text.concat(\"bonjour  %s %d  text %s\",a.Chr(),10,b.Chr())		>"<<text<<std::endl;

std::cout<<"-------------"<<std::endl;

text.Replace(a.Chr(),"z");
if (a.CPFERR ) std::cout<<"   msgerr :		>"<<a.cerror()<<std::endl;
std::cout<<"text.Replace(a.Chr(),\"z\")		>"<<text<<std::endl;

text.Replace("z",a.Chr());
if (a.CPFERR ) std::cout<<"   msgerr :		>"<<a.cerror()<<std::endl;
std::cout<<"text.Replace(a.Chr(),\"z\")		>"<<text<<std::endl;

std::cout<<"-------------"<<std::endl;
Zchar text_A(20);
text_A.concat("bonjour  %s %d  text %s jpl marie",a.Chr(),10,b.Chr());
if (text_A.CPFERR ) std::cout<<"   msgerr :		>"<<text_A.cerror()<<std::endl;
std::cout<<"text_A.concat(\"bonjour  %s %d  text %s jpl marie\",a.Chr(),10,b.Chr())		>"<<text_A<<std::endl;

std::cout<<"-------------"<<std::endl;
b="12345.12345";
text.concat("bonjour  %s %d  text %s",a.Chr(),10,b.Chr());
if (b.CPFERR ) std::cout<<"   msgerr :		>"<<text.cerror()<<std::endl;
std::cout<<"text.concat(\"bonjour  %s %d  text %s\",a.Chr(),10,b.Chr())		>"<<text<<std::endl;

std::cout<<"-------------"<<std::endl;

text.clear();
std::cout<<" text.clear() :		>"<<text<<std::endl;

std::cout<<"-------------"<<std::endl;
text.Extrac(a ,1, 2 );
if (a.CPFERR ) std::cout<<"   msgerr :		>"<<text.cerror()<<std::endl;
std::cout<<"text.Extrac(a ,1, 2 ) :		>"<<text<<std::endl;
std::cout<<"-------------"<<std::endl;
text.Extrac(a ,3, 6 );
if (a.CPFERR ) std::cout<<"   msgerr :		>"<<text.cerror()<<std::endl;
std::cout<<"text.Extrac(a ,3, 6 ) :		>"<<a<<"--"<<text<<std::endl;
std::cout<<"-------------"<<std::endl;



Zchar text_B(5); //----> POUR DEBUG
text_B.name("text_B debug : ");
text_B.Extrac(b ,1, 7 );
std::cout<<"text_B.Extrac(b ,1, 7 ) :		>"<<text<<std::endl;
if (text_B.CPFERR ) std::cout<<"   msgerr :		>"<<text_B.cerror()<<std::endl;
std::cout<<text_B<<std::endl;

std::cout<<"-------------"<<std::endl;
std::cout<<"text_B.Extrac(b ,7,2   9, 8 ) :		>"<<std::endl;
text_B.Extrac(b ,7, 2 );	/// beug text_B.Extrac(b ,7,2   9, 8 );
if (text_B.CPFERR ) std::cout<<"   msgerr :		>"<<text_B.cerror()<<std::endl;
std::cout<<text_B<<std::endl;

std::cout<<"-------------"<<std::endl;
std::cout<<"text_B.Extrac(b ,0,4  17, 18 ) :		>"<<std::endl;
text_B.Extrac(b ,0, 4 );	/// beug text_B.Extrac(b ,0,4  17, 18 );
if (text_B.CPFERR ) std::cout<<"   msgerr :		>"<<text_B.cerror()<<std::endl;
std::cout<<text_B<<std::endl;

std::cout<<"-------------"<<std::endl;
std::cout<<"text_B.Extrac(b ,7,1  18 ) :		>"<<std::endl;
text_B.Extrac(b ,7, 1 );	/// beug text_B.Extrac(b ,7,1  18 );
if (text_B.CPFERR ) std::cout<<"   msgerr :		>"<<text_B.cerror()<<std::endl;
std::cout<<text_B<<std::endl;

std::cout<<"-------------"<<std::endl;
text.Extrac("boéjour" ,3, 4 );
std::cout<<"text.Extrac(\"bonjour\" ,3, 4 ) :		>"<<std::endl;
if (text.CPFERR ) std::cout<<"   msgerr :		>"<<text.cerror()<<std::endl;
std::cout<<text<<std::endl;

std::cout<<"-------------"<<std::endl;
std::cout<<"text.Extrac(\"bonjour\" ,88  4, 3) :		>"<<std::endl;
text.Extrac("bonjour" ,4, 3 );  /// beug  text.Extrac("bonjour" ,88  3, 4 )
if (text.CPFERR ) std::cout<<"   msgerr :		>"<<text.cerror()<<std::endl;
std::cout<<text<<std::endl;

std::cout<<"-------------"<<std::endl;
std::cout<<"text.Extrac(\"bonjour\" ,1,6  ,88  ) :		>"<<std::endl;
text.Extrac("bonjour" ,1, 6 );  /// beug  text.Extrac("bonjour" ,1,6  ,88 )
if (text.CPFERR ) std::cout<<"   msgerr :		>"<<text.cerror()<<std::endl;
std::cout<<text<<std::endl;
std::cout<<"-------------"<<std::endl;

text.Extrac("bonjour" ,0, 4 );
std::cout<<"text_B.Extrac(\"bonjour\" ,0, 4 ) :		>"<<std::endl;
if (text.CPFERR ) std::cout<<"   msgerr :		>"<<text.cerror()<<std::endl;
std::cout<<text<<std::endl;
std::cout<<"-------------"<<std::endl;

text_A = "temps----123456789" ;
text_A.Movel("carapace");
std::cout<<"text.Move(\"carapace\" ); :		>"<<text_A<<std::endl;
if (text_A.CPFERR ) std::cout<<"   msgerr :		>"<<text_A.cerror()<<std::endl;

std::cout<<"-------------"<<std::endl;

text_A = "temps----123456789" ;
text_A.Movel("carapace , mile sabort , saperlipopette");
std::cout<<"text.Move(\"carapace , mile sabort , saperlipopette\" ); :		>"<<text_A<<"<"<<std::endl;
if (text_A.CPFERR ) std::cout<<"   msgerr :		>"<<text_A.cerror()<<std::endl;

std::cout<<"-------------"<<std::endl;
text_A.clear();
text_A = "1951/";
std::cout<<"1951/"<<std::endl;
if (text_A.CPFERR ) std::cout<<"   msgerr :		>"<<text_A.cerror()<<std::endl;
std::cout<<text_A<<std::endl;
text_A+=("12");
std::cout<<"1951/"<<std::endl;
if (text_A.CPFERR ) std::cout<<"   msgerr :		>"<<text_A.cerror()<<std::endl;
std::cout<<text_A<<std::endl;
text_A+=("/10");
std::cout<<"1951/12/10"<<std::endl;
if (text_A.CPFERR ) std::cout<<"   msgerr :		>"<<text_A.cerror()<<std::endl;
std::cout<<text_A<<std::endl;


std::cout<<"-------------"<<std::endl;
text_A.clear();
text_A = "1951";
std::cout<<"1951/12/10"<<std::endl;
text.clear();
std::cout<<"1951"<<std::endl;
text+=(text_A);
if (text.CPFERR ) std::cout<<"   msgerr :		>"<<text_A.cerror()<<std::endl;
std::cout<<text_A<<std::endl;
text_A = "/12";
std::cout<<"/12"<<std::endl;
text+=(text_A);
if (text.CPFERR ) std::cout<<"   msgerr :		>"<<text_A.cerror()<<std::endl;
std::cout<<text<<std::endl;
text_A = "/10";
std::cout<<"/10"<<std::endl;
text+=(text_A);
if (text_A.CPFERR ) std::cout<<"   msgerr :		>"<<text_A.cerror()<<std::endl;
std::cout<<text<<std::endl;


std::cout<<"text.cfind(\"10\")"<<"--"<<text<<std::endl;
std::cout<<text.cfind("10")<<std::endl;
std::cout<<"text.sfind(\"12\")"<<"--"<<text<<std::endl;
std::string st = "12";
std::cout<<text.sfind(st)<<std::endl;

text_A = "10";
text_B = "11";

std::cout<<text_A<<"  ---  "<<text_B<<std::endl;






if ( text_A == text_B) std::cout<<"if ( text_A == text_B)"<<std::endl; else  std::cout<<"if ( text_A == text_B) *no"<<std::endl;
if ( text_A != text_B) std::cout<<"if ( text_A != text_B)"<<std::endl; else  std::cout<<"if ( text_A != text_B) *no"<<std::endl;
if ( text_A <= text_B) std::cout<<"if ( text_A <= text_B)"<<std::endl; else  std::cout<<"if ( text_A <= text_B) *no"<<std::endl;
if ( text_A >= text_B) std::cout<<"if ( text_A >= text_B)"<<std::endl; else  std::cout<<"if ( text_A >= text_B) *no"<<std::endl;

if ( text_A < text_B) std::cout<<"if ( text_A < text_B)"<<std::endl; else  std::cout<<"if ( text_A < text_B) *no"<<std::endl;
if ( text_A > text_B) std::cout<<"if ( text_A > text_B)"<<std::endl; else  std::cout<<"if ( text_A > text_B) *no"<<std::endl;

text="boéjour";
text.ToUper();
if (text_A.CPFERR ) std::cout<<"   msgerr :		>"<<text_A.cerror()<<std::endl;
std::cout<<text<<std::endl;

text="boÉjour";
text.ToLower();
if (text_A.CPFERR ) std::cout<<"   msgerr :		>"<<text_A.cerror()<<std::endl;
std::cout<<text<<std::endl;


Zchar text_X(4);

text_X = "éé";
 
std::cout<<"  text_X = \"éééé <4  \"  "<<text_X<<"len "<<text_X.deflen()<<" clen "<<text_X.clen()<<std::endl;
if (text_X.CPFERR ) std::cout<<"   msgerr :		>"<<text_X.cerror()<<std::endl;


     return (0);

}
