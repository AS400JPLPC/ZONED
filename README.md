# ZONED
Gestion de buffer fixe  type AS400 traitement char* decimal date   

une classe DECIMAL

Un nombre avec un développement décimal limité 31 chiffre ex: +29.2 = 31 
origine "Mike Cowlishaw" ne pas blamer...
ex: Zdcml V_QSTKt(10,0);  variable quantité stock de 10 chiffres
Zdcml KAMPRIX(8.2); variable montant de 10 chiffres dont 8 entier et 2 decimale

Zdcml& operator=(const  int);
Zdcml& operator=(const  long int);
Zdcml& operator=(const double);
Zdcml& operator=(const char*);
Zdcml& operator=(const Zdcml  X_dcml);

//OPERATEURS ARITHMETIQUES EXTERNES --------------------------------------------
+ - * / %
possibilité 
add(const  std::string fmt_str, ...);  /// ex: n.add("%s,%s", a.ToChar(),b.ToChar());
sub(const  std::string fmt_str, ...);
mult(const std::string fmt_str, ...);
div(const  std::string fmt_str, ...);
mod(const Zdcml);
///OPERATEURS DE COMPARAISON------------------------------
< > <= >= != cmp
/// FONCTIONS OUTPUT ---return VAL-------------------------
ToChar(bool signe = false);       /// format text limit def ex: a(10,5); 1234567890.12345  nbr digit = def
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






