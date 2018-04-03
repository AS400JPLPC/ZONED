Gestion de buffer fixe type AS400 traitement   char*   decimal   date   bool   time   text

<h1> RE-Typage </h1>

**Motivation**
cet ensemble est réalisé pour traiter les données entre les bases de données et le programme qui les utilises
on y retrouve le model de l'AS400 RPGILE cela ma permis de faire un export du model DDS (as400) définition data strucure
de fichier SQL de diminuer considerablement l'interface programmation sur PC étant bien entendu que sur l'AS400 tout est natif.
Afin de me rapprocher le plus possible de l'automatisation tel que le propose le compilateur RPGIV ILE 


**une class DECIMAL**

Un nombre avec un développement décimal limité 31 chiffre ex: +29.2 = 31 chiffre dont 29 entier et  2 decimal<br>
origine "Mike Cowlishaw" lire le PDF<br>
ex: Zdcml QSTKT(10,0); variable quantité stock de 10 chiffres<br>
Zdcml MPRIX(8.2); variable montant de 10 chiffres dont 8 entier et 2 decimale<br>

<p> J'ai fait ces fonctions pour travailler avec des bases de données pour de la gestion d'entreprise <p>

** une class CHAR* ** ou les tampons sont contrôlés

enfin de compte j'ai  avancé  dans mes élucubrations  vous vous apercevrez que j'utilise  la fonction try ... catch ou trow
je part du principe que les buffers sont ou ne sont pas écrient ....
C'est un excellent principe que j'ai repris de l'AS400 via 38 par contre vous avez un indicateur qui vous permet de savoir
ou plutôt de comprendre pourquoi et comment....

vous retrouverez tous ces principes dans ce projet il nen sera pas de même pour le wrapper PGSQL que je suis entrain de validé.

il ce peut que je modifie par exmples j'ai rajouter des sorties pour prendre en compte les long long int etc...

** une class DATE**
toujours en accords avec SQL mais toutes ces classes sont pour mieux gérer et simplifier la programmation mon but étant de
 revenir sur PC à une programmation de gestion ou l'on ne soccupe que de règle de gestion un peu comme on lit le journal.

** une class BOOL **
plus pour SQL compatibilité...

** une class TEXT **
c'est un principe sur lequel je vais me penché sérieusement actuellement elle est là pour traiter les string vevant de SQL une
option qui permet tout en étant pas inscrit dans la convention SQL 92  et pourtant adopté dans beaucoup de moteur....
elle permet de ne plus avoir de soucie avec les longueurs prédéfini dans une database .... bon cela n'empĉhera pas d'avoir
 des normes par exemple pour les envoies postal.... les tests montre que cela n'impacte pas les services ni la vitesse,
 faut-il encore être raisonnable...

** une class TIME **
plus pour SQL compatibilité...
bon mon expérience ... j'ai rarrement mis un time dans un fichier , peut-être  timestamp mais c'est déjà dans date...

tout ça fonctionnent et n'est pas clos .... et fera partit de l'ensemble comme un frameworck ....

@bientôt 


