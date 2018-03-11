<h1>ZONED</h1>

<p>Gestion de buffer fixe  type AS400 traitement char* decimal date   </p>


<p>une classe DECIMAL</p>

<p>Un nombre avec un développement décimal limité 31 chiffre ex: +29.2 = 31<br>
origine "Mike Cowlishaw" lire le PDF<br>
ex: Zdcml QSTKt(10,0);  variable quantité stock de 10 chiffres<br>
Zdcml MPRIX(8.2); variable montant de 10 chiffres dont 8 entier et 2 decimale<br>
<pre><code>operator=(const  int)
operator=(const  long int)
operator=(const double)
operator=(const char*)
operator=(const Zdcml  X</em>dcml)<pre></code>
<p>OPERATEURS ARITHMETIQUES EXTERNES</p>
<pre><code\ + - * / % <pre></code>
<h1>possibilité</h1>
<pre><code>
add(const  std::string fmt<em>str, ...)     <em>ex:n.add("%s,%s", a.ToChar(),b.ToChar());</em>
sub(const  std::string fmt</em>str, ...)
mult(const std::string fmt<em>str, ...)
div(const  std::string fmt</em>str, ...)
mod(const Zdcml)<pre></code>
OPERATEURS DE COMPARAISON<br>
&lt; > &lt;= >= != cmp<br>
FONCTIONS OUTPUT return VAL<br>
  ToChar(bool signe = false)        <em>/// format text limit def ex: a(10,5); 1234567890.12345  nbr digit = 15</em><br>
  ConstChar(bool signe = false)     <em>/// trim zero</code></em><br>
  StringChar(bool signe = false)    <em>/// trim zero</code></em><br></p>

<p>ToInt();     /// cast par defaut<br>
TolongInt();    /// cast par defaut<br>
ToDouble();     /// cast par defaut<br>
/// FONCTION Contrôle Type --------------------------------------<br>
isTypDbl();     /// contrôle typ double<br>
isTypInt();     /// contrôle typ Int<br>
isTyplongInt(); /// contrôle typ long Int<br>
IsZeros();      /// contrôle ZEROS<br>
IsNegative();   /// contrôle IsNegative<br>
IsDecimale();   /// contrôle si valeur Décimale<br>
IsNumeric(const char * xxxx); /// permet de tester si la valeur répond à un numeric</p>

<p>ToRound();      /// DEC<em>ROUND</em>HALF<em>EVEN<br>
NoRound();      /// DEC</em>ROUND<em>DOWN<br>
IsRound();      /// return  ToRound() or NoRound()        default  Noround<br><br>
checkInt();                /// permet de tester si la valeur répond à un int<br>
checkDouble();             /// permet de tester si la valeur répond à un double<br>
checklongInt();            /// permet de tester si la valeur répond à un long int<br>
ChekOverflow();            /// contrôle valeur def tampon<br>
/// FONCTION Utilitaire --------------------------------------<br>
ToEntier();         /// parti entiere<br>
ToDec();            /// partie decimale<br>
/// code retour _ERR</em>??? or OK ---------------------------------<br>
status();<br>
statusmsg();<br>
Msgerr();</p>

<p>/// Format String--idem sprintf --------------------------</p>

<p>std::string string<em>format(const std::string fmt</em>str, ...);</p>

<hr />

<p>class Zdate</p>

<p>/// la date 0001-01-01 est valide pour ce programme uniquement pour donnée une Valeur "0"</p>

<pre><code>Zdate operator=(const int  );                       /// 20010101 YYYYMMDD      0 = 00010101
Zdate operator=(const char*);                       /// "2001-01-01" = 20010101
                                                    /// "0001-01-01" YYYY-MM-DD (POUR Bd ex: Postgresql = 0)
                                                    /// NULL etant possible mais pose des problèmes lors de clef  Non NULL voir le manuel d'ou 00010101
                                                    /// pour faire de la gestion  acceptable Voir IBM  a pris le même raisonnement. Norme SQL
                                                    /// "*SYS"   YYYY-MM-DD  du system

Zdate&amp; operator++(int);                             /// prefix    + 1
Zdate&amp; operator--(int);                             /// postfix   + 1
Zdate&amp; operator+(const int);                        /// prefix    + n day
Zdate&amp; operator-(const int);                        /// postfix   - n day

bool operator == (const Zdate);                     /// opération logique pour comparer des dates entre elles
bool operator &lt;  (const Zdate);
bool operator &gt;  (const Zdate);
bool operator &gt;= (const Zdate);
bool operator &lt;= (const Zdate);
bool operator != (const Zdate);
unsigned int  cmp(const Zdate) ;


YYYYMMDDHHMMSS + 3 quantieme naosecond 9 = 26 char

char* session();        ///  n° unique
char* sysdattim();      ///  YYYYMMDDHHMMSS
</code></pre>

<p>SYSTEM</p>

<pre><code>char* edtsysNUM();      /// YYYYMMDD
char* edtsysYMD();      /// YYYY/MM/DD
char* edtsysDMY();      /// jj/MM/YYYY
char* edtsysMDY();      /// MM/JJ/YYYY
char* edttimesys();     /// HH:mn:sec
char* edtsysYM();       /// YYYY/MM
char* edtsysMY();       /// MM/YYYY

char* longdatesys();
char* D_datesys();      /// Texte
char* M_datesys();      /// Texte

int   timehr();         /// heure
int   timemin();        /// minute
int   timesec();        /// seconde

int   sysYM();          /// YYYYMM
int   sysday();         /// DD
int   sysmonth();       /// MM
int   sysyear();        /// YYYY
int   sysyear2();       /// YY
int   syssiecle();      /// NN

int   datesys();        /// YYYYMMDD
char* edtsysISO();      /// YYYY-MM-DD


int   Quantiemesys();   /// Quantieme
int   NumeroJoursys();  /// le Numéro du jour
int   Semainesys();     /// le numéro de semaine

int   Decalage_heuresys();  /// 0 =été 1= hiver  -1 pas pris en compte
</code></pre>

<p>///
/// Date personnel... table ... attention 00010101 = 0
///
    int   ToInt();          /// YYYYMMDD</p>

<pre><code>char* edtISO();         /// YYYY-MM-DD  date ISO
char* edtNUM();         /// YYYYMMDD
char* edtYMD();         /// YYYY/MM/DD
char* edtDMY();         /// jj/MM/YYYY
char* edtMDY();         /// MM/JJ/YYYY
char* edtYM();          /// YYYY/MM
char* edtMY();          /// MM/YYYY
char* longdate();       /// vendredi 12 octobre 1950

char* ToChar(unsigned int date =0);             /// YYYYMMDD  full format
const char*   ConstChar(unsigned int date =0);  /// idem ToChar
std::string   StringChar(unsigned int date =0); /// idem ToChar

char* D_date();         /// Texte
char* M_date();         /// Texte

int   YM();             /// YYYYMM   periode
int   day();            /// Jour
int   month();          /// Mois
int   year();           /// Année
int   year2();          /// deux dernier chiffre de l'année
int   siecle();         /// siecle

bool  isBissextile();   /// ? bisexe tille ;)
void  Addmonth(int);    /// MOIS + n
int   PremierJanvier(); /// recupèrer 1 janvier n° du jour
int   Quantieme();      /// Quantieme
int   NumeroJour();     /// le Numéro du jour 0 1 2 3 4 5 6
int   ResteJour();      /// le nombre jour restant dans l'année
int   Semaine();        /// le numéro de semaine
int   Ferie();          /// is fête ?? pour construire un calendrier
</code></pre>
<p>FONCTIONS status </p>
</code></pre>unsigned int   status();
char*          statusmsg();
bool  Msgerr();</code></pre>



