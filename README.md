<h1>ZONED</h1>

<p>Gestion de buffer fixe  type AS400 traitement char* decimal date   </p>

<p>-une classe DECIMAL</p>

<p>Un nombre avec un développement décimal limité 31 chiffre ex: +29.2 = 31<br>
origine "Mike Cowlishaw" lire le PDF<br>
ex: Zdcml QSTKt(10,0);  variable quantité stock de 10 chiffres<br>
Zdcml MPRIX(8.2); variable montant de 10 chiffres dont 8 entier et 2 decimale<br>
operator=(const  int)<br>
operator=(const  long int)<br>
operator=(const double)<br>
operator=(const char*)<br>
operator=(const Zdcml  X</em>dcml)<br></p>
<p>OPERATEURS ARITHMETIQUES EXTERNES<br>
\ + - * / % <br></p>
<h1>possibilité</h1>
<p>
add(const  std::string fmt<em>str, ...)  <em>ex:<code>n.add("%s,%s", a.ToChar(),b.ToChar());</code></em><br>
sub(const  std::string fmt</em>str, ...)<br>
mult(const std::string fmt<em>str, ...)<br>
div(const  std::string fmt</em>str, ...)<br>
mod(const Zdcml)<br>
OPERATEURS DE COMPARAISON<br>
&lt; > &lt;= >= != cmp<br>
-<strong>FONCTIONS OUTPUT return VAL</strong><br>
  <code>ToChar(bool signe = false);</code>      <em><code>/// format text limit def ex: a(10,5); 1234567890.12345  nbr digit = 15</code></em><br>
  <code>ConstChar(bool signe = false);</code>   <em><code>/// trim zero</code></em><br>
  <code>StringChar(bool signe = false);</code>  <em><code>/// trim zero</code></em><br></p>

<p>ToInt();        /// cast par defaut
TolongInt();    /// cast par defaut
ToDouble();     /// cast par defaut
/// FONCTION Contrôle Type --------------------------------------
isTypDbl();     /// contrôle typ double
isTypInt();     /// contrôle typ Int
isTyplongInt(); /// contrôle typ long Int
IsZeros();      /// contrôle ZEROS
IsNegative();   /// contrôle IsNegative
IsDecimale();   /// contrôle si valeur Décimale
IsNumeric(const char *<em>X</em>); /// permet de tester si la valeur répond à un numeric</p>

<p>ToRound();      /// DEC<em>ROUND</em>HALF<em>EVEN
NoRound();      /// DEC</em>ROUND<em>DOWN
IsRound();      /// return  ToRound() or NoRound()        default  Noround
checkInt();                /// permet de tester si la valeur répond à un int
checkDouble();             /// permet de tester si la valeur répond à un double
checklongInt();            /// permet de tester si la valeur répond à un long int
ChekOverflow();            /// contrôle valeur def tampon
/// FONCTION Utilitaire --------------------------------------
ToEntier();         /// parti entiere
ToDec();            /// partie decimale
/// code retour _ERR</em>??? or OK ---------------------------------
status();
statusmsg();
Msgerr();</p>

<p>/// Format String--idem sprintf --------------------------</p>

<p>std::string string<em>format(const std::string fmt</em>str, ...);</p>

<hr />

<p>une classe DATE
merci aux internautes et différents forum et aux nombreuse personnes qui ont publiés les conformitées</p>

<p>Zdate operator=(const int  );
                    /// 20010101 YYYYMMDD      0 = 00010101
Zdate operator=(const char<em>); <br />
                    /// "2001-01-01" = 20010101
                    /// "0001-01-01" YYYY-MM-DD (POUR Bd ex: Postgresql = 0)
                    /// NULL etant possible mais pose des problèmes lors de clef  Non NULL voir le manuel d'ou 00010101
                    /// pour faire de la gestion  acceptable Voir IBM  a pris le même raisonnement. Norme SQL
                    /// "</em>SYS"   YYYY-MM-DD  du system</p>

<p>/// opération logique pour comparer des dates entre elles</p>

<p>///---------------------------------------------------
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
edtsysMY();       /// MM/YYYY</p>

<p>longdatesys();
D<em>datesys();      /// Texte
M</em>datesys();      /// Texte</p>

<p>timehr();         /// heure
timemin();        /// minute
timesec();        /// seconde</p>

<p>sysYM();          /// YYYYMM
sysday();         /// DD
sysmonth();       /// MM
sysyear();        /// YYYY
sysyear2();       /// YY
syssiecle();      /// NN</p>

<p>datesys();        /// YYYYMMDD
edtsysISO();      /// YYYY-MM-DD</p>

<p>Quantiemesys();   /// Quantieme
NumeroJoursys();  /// le Numéro du jour
Semainesys();     /// le numéro de semaine</p>

<p>Decalage_heuresys();  /// 0 =été 1= hiver  -1 pas pris en compte</p>

<p>///------------------------------------------------
/// Date personnel... table ... attention 00010101 = 0
/// les calculs sont manuels<br>
///---------------------------------------------------</p
<p>ToInt();          /// YYYYMMDD

edtISO();         /// YYYY-MM-DD  date ISO
edtNUM();         /// YYYYMMDD
edtYMD();         /// YYYY/MM/DD
edtDMY();         /// jj/MM/YYYY
edtMDY();         /// MM/JJ/YYYY
edtYM();          /// YYYY/MM
edtMY();          /// MM/YYYY
longdate();       /// vendredi 12 octobre 1950</p>

<p>ToChar(unsigned int date =0);     /// YYYYMMDD  full format
ConstChar(unsigned int date =0);  /// idem ToChar
StringChar(unsigned int date =0); /// idem ToChar</p>

<p>D<em>date();         /// Texte
M</em>date();         /// Texte</p>

<p>YM();             /// YYYYMM   periode ex: 195110
day();            /// Jour    ex: 12
month();          /// Mois    ex: 10
year();           /// Année   ex: 1951
year2();          /// deux dernier chiffres de l'année ex: 51
siecle();         /// siecle  ex: 20 pour 1951</p>

<p>isBissextile();   /// ? bisexe tille ;)
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
Msgerr();</p>

