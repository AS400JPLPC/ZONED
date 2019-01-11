Gestion de buffer fixe type AS400 traitement   char*   decimal   date   bool   time   text <br> <br>
pour les longueurs de zone étandoné la possibilité d'avoir des caractère sur 2 octets j'ai modifié et pris en compte l'UTF8 : donc la longueur est le nombre de caractère si vous définisez a(10) je considère que la zone ne fera pas plus de 10 caractères ceci est compatible avec les bases de données qui gère de même.<br>
 
<h1> RE-Typage </h1>

**Motivation**
cet ensemble est réalisé pour traiter les données entre les bases de données et le programme qui les utilises
on y retrouve le model de l'AS400 RPGILE cela ma permis de faire un export du model DDS (as400) définition data strucure
de fichier SQL de diminuer considerablement l'interface programmation sur PC étant bien entendu que sur l'AS400 tout est natif.
Afin de me rapprocher le plus possible de l'automatisation tel que le propose le compilateur RPGIV ILE 


**une class DECIMAL**

encore en test final mais vous avez un avant gout de comment ça tourne et ça tourne déjà 

Un nombre avec un développement décimal limité 34 chiffre <br>    

origine "Mike Cowlishaw" lire le PDF<br>

ex: Zdcml QSTKT(10,0); variable quantité stock de 10 chiffres<br>
Zdcml MPRIX(8,2); variable montant de 10 chiffres == 8 entier et  2 decimale  soit 10 dont 2  <br>

elle reprenent la plus grande partie de ce dont on abesoin pour faire de la gestion
bien-sur libre à vous de mettre les fonctions mathematique en oeuvre mais là je crois que c'est dommage
 de ne pas ce servir directement de la solution de base .....

les trow 

 lors de l'initialisation
 lors de division par zeros

 les calculs interne sont libre
 seul des allertes sont là pour informer si tout reste viable sinon NaN sera le resultat 

 la sortie je tronque le resultat au format donné c'est un parti pris car rien ne vous empêche de travailler avec des zones

 pour des 11.2 en 20.6 et de ramenez ..... 

 seul overflow peut vous genez mais là aussi les info sont de retour ...... mais c'est surtout dans les mouvements
 de zone entre elle ......
 prise en charge ',' '.'  sortie sql and cout only '.'


<p> J'ai fait ces fonctions pour travailler avec des bases de données pour de la gestion d'entreprise <p>

** une class CHAR* ** ou les tampons sont contrôlés

enfin de compte j'ai  avancé  dans mes élucubrations  <br>
je part du principe que les buffers sont ou ne sont pas écrient ....
C'est un excellent principe que j'ai repris de l'AS400 via 38 par contre vous avez un indicateur qui vous permet de savoir
ou plutôt de comprendre pourquoi et comment....

etc...

** une class DATE**
toujours en accords avec SQL mais toutes ces classes sont pour mieux gérer et simplifier la programmation mon but étant de
 revenir sur PC à une programmation de gestion ou l'on ne soccupe que de règle de gestion un peu comme on lit le journal.

** une class BOOL **
plus pour SQL compatibilité...

** une class TEXT **
c'est un principe sur lequel je vais me penché sérieusement actuellement elle est là pour traiter les string venant de SQL une
option qui permet tout en étant pas inscrit dans la convention SQL 92  et pourtant adopté dans beaucoup de moteur....
elle permet de ne plus avoir de soucie avec les longueurs prédéfini dans une database .... bon cela n'empĉhera pas d'avoir
 des normes par exemple pour les envoies postal.... les tests montrent que cela n'impacte pas les services ni la vitesse,
 faut-il encore être raisonnable...

** une class TIME **
plus pour SQL compatibilité...
bon mon expérience ... j'ai rarrement mis un time dans un fichier , peut-être  timestamp mais c'est déjà dans date...

tout ça fonctionnent ... et fera partit de l'ensemble comme un frameworck ....

@bientôt



