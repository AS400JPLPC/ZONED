Gestion de buffer fixe type AS400 traitement char* decimal date

<h1> RE-Typage </h1>

**Motivation**
cet ensemble est réalisé pour traiter les données entre les bases de données et le programme qui les utilises
on y retrouve le model de l'AS400 RPGILE cela ma permis de faire un export du model DDS (as400) définition data strucure de fichier SQL de diminuer considerablement l'interface programmation sur PC étant bien entendu que sur l'AS400 tout est natif.Afin de me rapprocher le plus possible de l'automatisation tel que le propose le compilateur RPGIV ILE 


**une classe DECIMAL**

Un nombre avec un développement décimal limité 31 chiffre ex: +31.2 = 31 chiffre dont 29 entier et  2 decimal<br>
origine "Mike Cowlishaw" lire le PDF<br>
ex: Zdcml QSTKT(10,0); variable quantité stock de 10 chiffres<br>
Zdcml MPRIX(10.2); variable montant de 10 chiffres dont 8 entier et 2 decimale<br>

**OPERATEURS ARITHMETIQUES**
<pre><code>
 + - * / %
add sub mult div mod  pcent 
ex: n.add("%s,%s", a.tochar(),b.tochar());</code></pre>

**OPERATEURS DE COMPARAISON**<br>
== > <  <= >= != cmp<br>
**FONCTIONS OUTPUT ---return VAL**<br>
<pre><code>
tochar(bool signe = false);          /// format text limit def ex: a(10,5); 1234567890.12345  nbr digit = 15
toconstCchar(bool signe = false);    /// trim zero
tostring(bool signe = false);        /// trim zero</code></pre>

**FONCTION Contrôle Type**
<pre><code>
bool        istypint();     /// contrôle typ Int
bool        istyplongint(); /// contrôle typ long Int
bool        iszeros();      /// contrôle ZEROS
bool        isnegative();   /// contrôle IsNegative
bool        isdecimale();   /// contrôle si valeur Décimale
bool        isnumeric(const char *<em>X</em>); /// permet de tester si la valeur répond à un numeric</p>
void        toround();      /// DEC<em>ROUND</em>HALF<em>EVEN
void        noround();      /// DEC</em>ROUND_DOWN
bool        isround();      /// return  ToRound() or NoRound()        default  Noround
unsigned int checkint();                /// permet de tester si la valeur répond à un int
unsigned int checkdouble();             /// permet de tester si la valeur répond à un double
unsigned int checklongint();            /// permet de tester si la valeur répond à un long int
unsigned int chekoverflow();            /// contrôle valeur def tampon
</code></pre>
**FONCTION Utilitaire**
<pre><code>
char *     toentier();         /// parti entiere
char *     todec();            /// partie decimale
</code></pre>
**code retour <em>ERR</em>??? or OK**
<pre><code>
unsigned int status();
char*        statusmsg();
bool         msgerr();</code></pre>
**Format String--idem sprintf**
<pre><code>
std::string string<em>format(const std::string fmt</em>str, ...);</code></pre>
<br><br>
**une classe Date**
très classique je remercie tous les internautes qui par leurs publication ma permis de mettre en forme cette classe

*la date 0001-01-01 est valide pour ce programme uniquement pour donnée une Valeur "0"*
<pre><code>
    Zdate operator=(const int  );                       /// 20010101 YYYYMMDD      0 = 00010101
    Zdate operator=(const char*);                       /// "2001-01-01" = 20010101
                                                        /// "0001-01-01" YYYY-MM-DD (POUR Bd ex: Postgresql = 0)
                                                        /// NULL etant possible mais pose des problèmes lors de clef  Non NULL voir le manuel d'ou 00010101
                                                        /// pour faire de la gestion  acceptable Voir IBM  a pris le même raisonnement. Norme SQL
                                                        /// "*SYS"   YYYY-MM-DD  du system

    Zdate& operator++(int);                             /// prefix    + 1
    Zdate& operator--(int);                             /// postfix   + 1
    Zdate& operator+(const int);                        /// prefix    + n day
    Zdate& operator-(const int);                        /// postfix   - n day

    bool operator == (const Zdate);                     /// opération logique pour comparer des dates entre elles
    bool operator <  (const Zdate);
    bool operator >  (const Zdate);
    bool operator >= (const Zdate);
    bool operator <= (const Zdate);
    bool operator != (const Zdate);
    unsigned int  cmp(const Zdate) ;
</code></pre>
**YYYYMMDDHHMMSS + 3 quantieme naosecond 9 = 26 char**
<pre><code>
    char* session();        ///  n° unique
    char* sysdattim();      ///  YYYYMMDDHHMMSS
</code></pre>
**SYSTEM**
<pre><code>
    char* edtsysNUM();      /// YYYYMMDD
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


    int   quantiemesys();   /// Quantieme
    int   numeroJoursys();  /// le Numéro du jour
    int   semainesys();     /// le numéro de semaine

    int   Decalage_heuresys();  /// 0 =été 1= hiver  -1 pas pris en compte
</code></pre>
**Date personnel... table ... attention 00010101 = 0 **
<pre><code>
    int   toint();          /// YYYYMMDD

    char* edtISO();         /// YYYY-MM-DD  date ISO
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

    bool  isbissextile();   /// ? bisexe tille ;)
    void  Addmonth(int);    /// MOIS + n
    int   PremierJanvier(); /// recupèrer 1 janvier n° du jour
    int   quantieme();      /// Quantieme
    int   numeroJour();     /// le Numéro du jour 0 1 2 3 4 5 6
    int   ResteJour();      /// le nombre jour restant dans l'année
    int   semaine();        /// le numéro de semaine
    int   ferier();         /// is fête ?? pour construire un calendrier
</code></pre>
**FONCTIONS status**
<pre><code>
unsigned int   status();
char*          statusmsg();
bool  Msgerr();
</code></pre>
<br>
<br>
<br>
<br>
**Buffer fixe char**<br>
Mon problème était la cohésion avec la base de donnée donc avec des buffers fixe<br>
Zchar NOM[10]; conforme avec les definitions SQL et traitement base de Données 
je me suis appuyé sur la façon de traiter de l'AS400 /38 ... 
**AFFECTATION BUFFER **
<pre><code>
char*         tochar();
const char*   toconstchar();
std::string        tostring();

Zchar operator=(const Zchar);
Zchar operator+=(const Zchar);
Zchar operator=(const char*);
Zchar operator+=( const char*);


Zchar           concat(const std::string fmt, ...);                                       // Concat from string
Zchar           reset();

///  substring
Zchar           replace(const char*  scrut ,const char * );
Zchar           move(const char*   src);
Zchar           movel(const char*   src);
Zchar           move(const Zchar);
Zchar           movel(const Zchar);
Zchar           extrac(const char*   src   ,unsigned int  , unsigned int  );
Zchar           extrac(const Zchar         ,unsigned int  , unsigned int  );
Zchar           strtrim(const Zchar );
char *          extractochar(unsigned int  , unsigned int  );
</code></pre>
**FONCTIONS UTILE** 
<pre><code>
unsigned int    locfind( const char*);
unsigned int    sizebuf();
unsigned int    sizeval();
</code></pre>
**FONCTIONS operateur**
<pre><code>
bool operator!=( const char* );
bool operator==( const char* );
bool operator<( const char*  );
bool operator>( const char*  );
bool operator<=( const char* );
bool operator>=( const char* );
unsigned   int cmp( const char* );

bool operator!=( Zchar );
bool operator==( Zchar );
bool operator<( Zchar  );
bool operator>=( Zchar );
bool operator<=( Zchar );
bool operator>( Zchar  );
unsigned   int  cmp( Zchar );
</code></pre>
**FONCTIONS status**
<pre><code>
unsigned int   status();
char*          statusmsg();
bool           msgerr();
</code></pre>
<br>
<p> J'ai fait ces fonctions pour travailler avec des bases de données pour de la gestion d'entreprise <p>
