#ifndef ZIND_H_INCLUDED
#define ZIND_H_INCLUDED
#include <stdio.h>
#include <cstring>
#include <cstdio>
namespace __ZONED__
{


bool Zind[101];
void Zind_Init_All() { for (int i= 0 ; i <=100;i++) Zind[i] = false ; Zind[0] =true; Zind[100] =false; }

#ifndef INDOFF
#define INDOFF Zind_Init_All()
#endif

#ifndef  ON
#define  ON  Zind[0]
#endif

#ifndef  OFF
#define  OFF Zind[100]
#endif

#ifndef IN01
#define IN01 Zind[1]
#endif

#ifndef IN02
#define IN02 Zind[2]
#endif

#ifndef IN03
#define IN03 Zind[3]
#endif

#ifndef IN04
#define IN04 Zind[4]
#endif

#ifndef IN05
#define IN05 Zind[5]
#endif

#ifndef IN06
#define IN06 Zind[6]
#endif

#ifndef IN08
#define IN08 Zind[8]
#endif

#ifndef IN09
#define IN09 Zind[9]
#endif

#ifndef IN10
#define IN10 Zind[10]
#endif

#ifndef IN11
#define IN11 Zind[11]
#endif

#ifndef IN12
#define IN12 Zind[12]
#endif

#ifndef IN13
#define IN13 Zind[13]
#endif

#ifndef IN14
#define IN14 Zind[14]
#endif

#ifndef IN15
#define IN15 Zind[15]
#endif

#ifndef IN16
#define IN16 Zind[16]
#endif

#ifndef IN17
#define IN17 Zind[17]
#endif

#ifndef IN18
#define IN18 Zind[18]
#endif

#ifndef IN19
#define IN19 Zind[19]
#endif

#ifndef IN20
#define IN20 Zind[20]
#endif

#ifndef IN21
#define IN21 Zind[21]
#endif

#ifndef IN22
#define IN22 Zind[22]
#endif

#ifndef IN23
#define IN23 Zind[23]
#endif

#ifndef IN24
#define IN24 Zind[24]
#endif

#ifndef IN25
#define IN25 Zind[25]
#endif

#ifndef IN26
#define IN26 Zind[26]
#endif

#ifndef IN27
#define IN27 Zind[27]
#endif

#ifndef IN28
#define IN28 Zind[28]
#endif

#ifndef IN29
#define IN29 Zind[29]
#endif

#ifndef IN30
#define IN30 Zind[30]
#endif

#ifndef IN31
#define IN31 Zind[31]
#endif

#ifndef IN32
#define IN32 Zind[32]
#endif

#ifndef IN33
#define IN33 Zind[33]
#endif

#ifndef IN34
#define IN34 Zind[34]
#endif

#ifndef IN35
#define IN35 Zind[35]
#endif

#ifndef IN36
#define IN36 Zind[36]
#endif

#ifndef IN37
#define IN37 Zind[37]
#endif

#ifndef IN38
#define IN38 Zind[38]
#endif

#ifndef IN39
#define IN39 Zind[39]
#endif

#ifndef IN40
#define IN40 Zind[40]
#endif

#ifndef IN41
#define IN41 Zind[41]
#endif

#ifndef IN42
#define IN42 Zind[42]
#endif

#ifndef IN43
#define IN43 Zind[43]
#endif

#ifndef IN44
#define IN44 Zind[44]
#endif

#ifndef IN45
#define IN45 Zind[45]
#endif

#ifndef IN46
#define IN46 Zind[46]
#endif

#ifndef IN47
#define IN47 Zind[47]
#endif

#ifndef IN48
#define IN48 Zind[48]
#endif

#ifndef IN49
#define IN49 Zind[49]
#endif

#ifndef IN50
#define IN50 Zind[50]
#endif

#ifndef IN51
#define IN51 Zind[51]
#endif

#ifndef IN52
#define IN52 Zind[52]
#endif

#ifndef IN53
#define IN53 Zind[53]
#endif

#ifndef IN54
#define IN54 Zind[54]
#endif

#ifndef IN55
#define IN55 Zind[55]
#endif

#ifndef IN56
#define IN56 Zind[56]
#endif

#ifndef IN57
#define IN57 Zind[57]
#endif

#ifndef IN58
#define IN58 Zind[58]
#endif

#ifndef IN59
#define IN59 Zind[59]
#endif

#ifndef IN60
#define IN60 Zind[60]
#endif

#ifndef IN61
#define IN61 Zind[61]
#endif

#ifndef IN62
#define IN62 Zind[62]
#endif

#ifndef IN63
#define IN63 Zind[63]
#endif

#ifndef IN64
#define IN64 Zind[64]
#endif

#ifndef IN65
#define IN65 Zind[65]
#endif

#ifndef IN66
#define IN66 Zind[66]
#endif

#ifndef IN67
#define IN67 Zind[67]
#endif

#ifndef IN68
#define IN68 Zind[68]
#endif

#ifndef IN69
#define IN69 Zind[69]
#endif

#ifndef IN70
#define IN70 Zind[70]
#endif

#ifndef IN71
#define IN71 Zind[71]
#endif

#ifndef IN72
#define IN72 Zind[72]
#endif

#ifndef IN73
#define IN73 Zind[73]
#endif

#ifndef IN74
#define IN74 Zind[74]
#endif

#ifndef IN75
#define IN75 Zind[75]
#endif

#ifndef IN76
#define IN76 Zind[76]
#endif

#ifndef IN77
#define IN77 Zind[77]
#endif

#ifndef IN78
#define IN78 Zind[78]
#endif

#ifndef IN79
#define IN79 Zind[79]
#endif

#ifndef IN80
#define IN80 Zind[80]
#endif

#ifndef IN81
#define IN81 Zind[81]
#endif

#ifndef IN82
#define IN82 Zind[82]
#endif

#ifndef IN83
#define IN83 Zind[83]
#endif

#ifndef IN84
#define IN84 Zind[84]
#endif

#ifndef IN85
#define IN85 Zind[85]
#endif

#ifndef IN86
#define IN86 Zind[86]
#endif

#ifndef IN87
#define IN87 Zind[87]
#endif

#ifndef IN88
#define IN88 Zind[88]
#endif

#ifndef IN89
#define IN89 Zind[89]
#endif

#ifndef IN90
#define IN90 Zind[90]
#endif

#ifndef IN91
#define IN91 Zind[91]
#endif

#ifndef IN92
#define IN92 Zind[92]
#endif

#ifndef IN93
#define IN93 Zind[93]
#endif

#ifndef IN94
#define IN94 Zind[94]
#endif

#ifndef IN95
#define IN95 Zind[95]
#endif

#ifndef IN96
#define IN96 Zind[96]
#endif

#ifndef IN97
#define IN97 Zind[97]
#endif

#ifndef IN98
#define IN98 Zind[98]
#endif

#ifndef IN99
#define IN99 Zind[99]
#endif


}
#endif // ZIND_H_INCLUDED
