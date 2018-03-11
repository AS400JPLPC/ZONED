Gestion de buffer fixe type AS400 traitement char* decimal date

une classe DECIMAL

Un nombre avec un développement décimal limité 31 chiffre ex: +29.2 = 31
origine "Mike Cowlishaw" lire le PDF
ex: Zdcml QSTKt(10,0); variable quantité stock de 10 chiffres
Zdcml MPRIX(8.2); variable montant de 10 chiffres dont 8 entier et 2 decimale

<p>**OPERATEURS ARITHMETIQUES <br>
 + - * / %</p>

<p>add sub mult div mod <br>
ex: n.add("%s,%s", a.ToChar(),b.ToChar());</p>

<p>**OPERATEURS DE COMPARAISON<br>
== &lt; > &lt;= >= != cmp</p>

<p>**FONCTIONS OUTPUT ---return VAL<br></p>

<p><pre><code>ToChar(bool signe = false);       /// format text limit def ex: a(10,5); 1234567890.12345  nbr digit = 15
ConstChar(bool signe = false);    /// trim zero
StringChar(bool signe = false);   /// trim zero
<pre><code>
**FONCTION Contrôle Type 
bool        isTypInt();     /// contrôle typ Int
bool        isTyplongInt(); /// contrôle typ long Int
bool        IsZeros();      /// contrôle ZEROS
bool        IsNegative();   /// contrôle IsNegative
bool        IsDecimale();   /// contrôle si valeur Décimale
bool        IsNumeric(const char *<em>X</em>); /// permet de tester si la valeur répond à un numeric</p>

<p>void        ToRound();      /// DEC<em>ROUND</em>HALF<em>EVEN
void        NoRound();      /// DEC</em>ROUND_DOWN
bool        IsRound();      /// return  ToRound() or NoRound()        default  Noround
unsigned int checkInt();                /// permet de tester si la valeur répond à un int
unsigned int checkDouble();             /// permet de tester si la valeur répond à un double
unsigned int checklongInt();            /// permet de tester si la valeur répond à un long int
unsigned int ChekOverflow();            /// contrôle valeur def tampon
/// FONCTION Utilitaire --------------------------------------
char *     ToEntier();         /// parti entiere
char *     ToDec();            /// partie decimale</p>

<p>/// code retour <em>ERR</em>??? or OK ---------------------------------
unsigned int status();
char*        statusmsg();
bool         Msgerr();</p>

<p>/// Format String--idem sprintf --------------------------</p>

<p>std::string string<em>format(const std::string fmt</em>str, ...);</p>

