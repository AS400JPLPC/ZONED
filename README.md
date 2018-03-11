# ZONED
Gestion de buffer fixe  type AS400 traitement char* decimal date   

-une classe DECIMAL

Un nombre avec un développement décimal limité 31 chiffre ex: +29.2 = 31<br>
origine "Mike Cowlishaw" lire le PDF<br>
ex: Zdcml V_QSTKt(10,0);  variable quantité stock de 10 chiffres<br>
Zdcml KAMPRIX(8.2); variable montant de 10 chiffres dont 8 entier et 2 decimale<br>
<br>
<br>
operator=(const  int);<br>
operator=(const  long int);<br>
operator=(const double);<br>
operator=(const char*);<br>
operator=(const Zdcml  X_dcml);<br>

=OPERATEURS ARITHMETIQUES EXTERNES<br>
<code> + - * / %</code><br>
-<strong>possibilité</strong><br>
add(const  std::string fmt_str, ...);  <em><code>ex: n.add("%s,%s", a.ToChar(),b.ToChar());</code></em><br
sub(const  std::string fmt_str, ...);
mult(const std::string fmt_str, ...);
div(const  std::string fmt_str, ...);
mod(const Zdcml);
///OPERATEURS DE COMPARAISON------------------------------
<code>< > <= >= != cmp</code>
/// FONCTIONS OUTPUT ---return VAL-------------------------
ToChar(bool signe = false);       /// format text limit def ex: a(10,5); 1234567890.12345  nbr digit = 15
ConstChar(bool signe = false);    /// trim zero
StringChar(bool signe = false);   /// trim zero

ToInt();        /// cast par defaut
TolongInt();    /// cast par defaut
ToDouble();     /// cast par defaut
/// FONCTION Contrôle Type --------------------------------------
isTypDbl();     /// contrôle typ double
isTypInt();     /// contrôle typ Int
isTyplongInt(); /// contrôle typ long Int
IsZeros();      /// contrôle ZEROS
IsNegative();   /// contrôle IsNegative
IsDecimale();   /// contrôle si valeur Décimale
IsNumeric(const char *_X_); /// permet de tester si la valeur répond à un numeric

ToRound();      /// DEC_ROUND_HALF_EVEN
NoRound();      /// DEC_ROUND_DOWN
IsRound();      /// return  ToRound() or NoRound()        default  Noround
checkInt();                /// permet de tester si la valeur répond à un int
checkDouble();             /// permet de tester si la valeur répond à un double
checklongInt();            /// permet de tester si la valeur répond à un long int
ChekOverflow();            /// contrôle valeur def tampon
/// FONCTION Utilitaire --------------------------------------
ToEntier();         /// parti entiere
ToDec();            /// partie decimale
/// code retour _ERR_??? or OK ---------------------------------
status();
statusmsg();
Msgerr();

/// Format String--idem sprintf --------------------------

std::string string_format(const std::string fmt_str, ...);

___________________________________________________________________________________________

une classe DATE
merci aux internautes et différents forum et aux nombreuse personnes qui ont publiés les conformitées

Zdate operator=(const int  );
                    /// 20010101 YYYYMMDD      0 = 00010101
Zdate operator=(const char*);                       
                    /// "2001-01-01" = 20010101
                    /// "0001-01-01" YYYY-MM-DD (POUR Bd ex: Postgresql = 0)
                    /// NULL etant possible mais pose des problèmes lors de clef  Non NULL voir le manuel d'ou 00010101
                    /// pour faire de la gestion  acceptable Voir IBM  a pris le même raisonnement. Norme SQL
                    /// "*SYS"   YYYY-MM-DD  du system

/// opération logique pour comparer des dates entre elles

///---------------------------------------------------
/// YYYYMMDDHHMMSS + 3 quantieme naosecond 9 = 26 char
///---------------------------------------------------
session();        ///  n° unique
sysdattim();      ///  YYYYMMDDHHMMSS
///---------------------------------------------------
/// SYSTEM
///---------------------------------------------------
edtsysISO();      /// YYYY-MM-DD      ex: 1951-10-12   (const char*)
edtsysNUM();      /// YYYYMMDD
edtsysYMD();      /// YYYY/MM/DD
edtsysDMY();      /// jj/MM/YYYY
edtsysMDY();      /// MM/JJ/YYYY
edttimesys();     /// HH:mn:sec
edtsysYM();       /// YYYY/MM
edtsysMY();       /// MM/YYYY

longdatesys();
D_datesys();      /// Texte
M_datesys();      /// Texte

timehr();         /// heure
timemin();        /// minute
timesec();        /// seconde

sysYM();          /// YYYYMM
sysday();         /// DD
sysmonth();       /// MM
sysyear();        /// YYYY
sysyear2();       /// YY
syssiecle();      /// NN

datesys();        /// YYYYMMDD
edtsysISO();      /// YYYY-MM-DD

Quantiemesys();   /// Quantieme
NumeroJoursys();  /// le Numéro du jour
Semainesys();     /// le numéro de semaine

Decalage_heuresys();  /// 0 =été 1= hiver  -1 pas pris en compte

///---------------------------------------------------
/// Date personnel... table ... attention 00010101 = 0
/// les calculs sont manuels
///---------------------------------------------------
ToInt();          /// YYYYMMDD

edtISO();         /// YYYY-MM-DD  date ISO
edtNUM();         /// YYYYMMDD
edtYMD();         /// YYYY/MM/DD
edtDMY();         /// jj/MM/YYYY
edtMDY();         /// MM/JJ/YYYY
edtYM();          /// YYYY/MM
edtMY();          /// MM/YYYY
longdate();       /// vendredi 12 octobre 1950

ToChar(unsigned int date =0);     /// YYYYMMDD  full format
ConstChar(unsigned int date =0);  /// idem ToChar
StringChar(unsigned int date =0); /// idem ToChar

D_date();         /// Texte
M_date();         /// Texte

YM();             /// YYYYMM   periode ex: 195110
day();            /// Jour    ex: 12
month();          /// Mois    ex: 10
year();           /// Année   ex: 1951
year2();          /// deux dernier chiffres de l'année ex: 51
siecle();         /// siecle  ex: 20 pour 1951

isBissextile();   /// ? bisexe tille ;)
Addmonth(int);    /// MOIS + n
PremierJanvier(); /// recupèrer 1 janvier n° du jour
Quantieme();      /// Quantieme
NumeroJour();     /// le Numéro du jour 0 1 2 3 4 5 6
ResteJour();      /// le nombre jour restant dans l'année
Semaine();        /// le numéro de semaine
Ferie();          /// is fête ?? pour construire un calendrier ici ne sont mise que les dates française
                  /// j'ai fait pour les claculs de jour travaillé ex paye ou   quota production du mois  prévisionnel ..... 
///---------------------------------------------------
/// fonction status 
///---------------------------------------------------
status();
statusmsg();
Msgerr();
