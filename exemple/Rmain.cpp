#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctemplate/template.h>

#include <cgicc/CgiDefs.h>
#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>

/// var commune Html
#include "FBDSQL.hpp"
#include "ZONED.hpp"
PG_DB *DB ;

#include "FRIWEB.hpp"           /// fichier session
#include "LTL1COMA.hpp"          /// fichier Init web


#include "FNADOS.hpp"           /// entete de commande
#include "LNBDOSA.hpp"          /// logique détail commande

#include "FKEDOS.hpp"           /// demande de livraison
#include "FSEDOS.hpp"           /// log demande de livraison

#include "LRHBLVA.hpp"          /// repiquage Automatique

#include "FKTDSTK.hpp"          /// additif fichier stock code LOGO
#include "FKTESTK.hpp"          /// additif fichier stock code DIAMETRE
#include "FKTFSTK.hpp"          /// ADDITIF FKTSTK LOGO DIAMETRE

#include "LKTSTKA.hpp"          /// logique entete stock
#include "LKSSTKA.hpp"          /// logique détail stock

#include "LKEDOSQ.hpp"          /// logique demande lvr
#include "LRHBLVB.hpp"          /// logique Article Speciaux


#include "LC2ACLIB.hpp"         /// logique client web                      NCLI/NCLX/NCLY
#include "LTL2COMD.hpp"         /// user autorisation special
#include "LTL2COMK.hpp"         /// user autorisation special               SOC/DOS/ARTICLE
#include "LTL5COMA.hpp"         /// PASSWORD & ADRESSE MAIL POUR -HTML

#include "LC2ACLIX.hpp"         /// liste des addresses

using namespace std;
string output;


const string ENV[ 24 ] = {
        "COMSPEC", "DOCUMENT_ROOT", "GATEWAY_INTERFACE",
        "HTTP_ACCEPT", "HTTP_ACCEPT_ENCODING",
        "HTTP_ACCEPT_LANGUAGE", "HTTP_CONNECTION",
        "HTTP_HOST", "HTTP_USER_AGENT", "PATH",
        "QUERY_STRING", "REMOTE_ADDR", "REMOTE_PORT",
        "REQUEST_METHOD", "REQUEST_URI", "SCRIPT_FILENAME",
        "SCRIPT_NAME", "SERVER_ADDR", "SERVER_ADMIN",
        "SERVER_NAME","SERVER_PORT","SERVER_PROTOCOL",
        "SERVER_SIGNATURE","SERVER_SOFTWARE" };



string  vHTTP;
char    vlib[6]  ;
int     vport =0;

Zchar    NON(1);    /* const = N */
Zchar    OUI(1);    /* const = O */
bool INDERR;        /* indicateur Erreur */

const char * C_HIDDEN   = "style='visibility:hidden'";
const char * C_VISIBLE  = "style='visibility:visible'";

Zchar       V_NJOB(26);     /* N° Session   */
Zchar       V_MSG(70);
Zchar       H_NFMT(3);      /* N° page Html */
Zdcml       V_NFMT(3,0);


Zchar       V_FXX(3);       /* cmd clavier = Fonction */
Zdcml       V_NCLI(6,0);    /* N° client */
Zchar       V_C2AECLX(5);   /* N° client du client (spécifique Renault */


Zchar       V_TRV(1024);

int       DATESYS ;


/// FX01SFL
Zdcml     V_KSFL(4,0);    /* ligne sous fichier communication avec programme */
Zchar     H_KSFL(3);
Zdcml     LIGN1(4,0);
Zchar     V_ECLX(5);

Zdcml     V_LINE(3,0);    /* Nombre d'article avec Qte saisie */

Zchar     V_KART(11);
Zchar     V_CREF(100);    /// reference client article
Zdcml     V_CCND(6,0);    /// zone web conditionement
Zdcml     V_QREL(10,0);   /// zone web qte reel
Zdcml     V_QSTK(10,0);   /// zone web qte en stock
Zdcml     V_QRELt(10,0);  /// zone de travaille
Zdcml     V_QSTKt(10,0);  /// zone de travaille
Zdcml     V_QLVD(10,0);   /// zone web qte demandé


char  *vNAME =new char[30];
Zdcml     V_QTE(10,0);    /// zone web qte commandé
Zdcml     V_XCF(6,0);     /// zone web conditionement
Zdcml     V_QINI(10,0);   /// zone web qte initiale


PG_FRIWEB   *FRIWEB ;

PG_LTL1COMA *LTL1COMA ;     /* fichier client   "Init Web                                                  TL1CNOM*/

PG_FNADOS   *FNADOS  ;      /* Fichier Commande "Entete  de commande                                       ("NANDOS")*/
PG_LNBDOSA  *LNBDOSA ;      /* logique Commande "Article de commande                                       ("NBNDOS", "NBCGIM", "NBCDPO", "NBCSTD")*/

PG_FKEDOS   *FKEDOS  ;      /* Fichier Demande   "Suivit de demande de livraison                           ("KENDOS", "KE0LVD", "KENCLI", "KENCLX", "KENCLY", "KECGIM", "KECDPO", "KECSTD")*/
PG_FSEDOS   *FSEDOS  ;      /* Fichier log       "Suivit de demande de livraison                           ("SENDOS", "SECISO")*/

PG_LRHBLVA  *LRHBLVA ;      /* repiquage Automatique                                                       ("RHNCLI", "RHNCLX", "RHNCLY", "RHCGIM", "RHCDPO", "RHCSTD") */
PG_FKTDSTK  *FKTDSTK ;      /* additif fichier stock code LOGO                                             ("KTDCLGO") */
PG_FKTESTK  *FKTESTK ;      /* additif fichier stock code DIAMETRE                                         ("KTECDIA") */
PG_FKTFSTK  *FKTFSTK ;      /* additif FKTSTK  LOGO  DIAMETRE                                              ("KTFCGIM", "KTFCDPO", "KTFCSTD") */


PG_LKEDOSQ  *LKEDOSQ ;      /* logique   RINDOS/RINCLI/RINCLX/RINCLY/KECGIM/KECDPO/KECSTD/KE0LVD*/

PG_LKTSTKA  *LKTSTKA ;      /* Fichier Stock    "Article                                                   ("KTCGIM", "KTCDPO", "KTCSTD")*/
PG_LKSSTKA  *LKSSTKA ;      /* logique   KSCGIM/KSCDPO/KSCSTD/KSNDOS/KSZLOT/KSCEPL/KSCPLT/KSNXBO*/

PG_LRHBLVB  *LRHBLVB ;      /* logique   RHCGIM/RHCDPO/RHCSTD*/

PG_LC2ACLIB  *LC2ACLIB ;    /* logique   RIECLI/RIECLX/RINCLI/RINCLX/RINCLY */


PG_LTL2COMD  *LTL2COMD ;    /* logique   TL2CNOM/TL2NDOS/TL2NVER/TL2CGIM/TL2CDPO/TL2CSTD*/
PG_LTL2COMK  *LTL2COMK ;    /* logique   TL2CNOM/TL2NDOS/TL2CGIM/TL2CDPO/TL2CSTD*/
PG_LTL5COMA  *LTL5COMA ;    /* logique   TL5NCLI/TL5CIDU/TL5CPWD */


PG_LC2ACLIX  *LC2ACLIX ;    /* logique   RIECLI/RIECLX/RINCLI/RINCLX   lecture global     */



void getenvHTTP();
void aff_F00INI();

//void INIT_field();
void rtvenvvar();           /// récupère les varirables POST

void aff_FX01SFL();         /// Traitement page 1 Type RENAULT

void write_FSEDOS();        /// Log de mise à jour de livraison
void aff_FX03DMD();         /// traitement affichage de livraison
void maj_FX03DMD();         /// traitement mise à jour de livraison
using namespace cgicc;

Cgicc formData;
int main ()
{

DATESYS = KE0LVD.datesys();
NON = "N";
OUI = "O";
INDOFF;

DB->db_con();

FRIWEB->def_field();
LTL1COMA->def_field();
FNADOS->def_field();
LNBDOSA->def_field();

FKEDOS->def_field();
FSEDOS->def_field();


LRHBLVA->def_field();
LKTSTKA->def_field();
FKTDSTK->def_field();
FKTESTK->def_field();
FKTFSTK->def_field();

LKEDOSQ->def_field();
LKSSTKA->def_field();
LRHBLVB->def_field();

LC2ACLIB->def_field();
LTL2COMD->def_field();
LTL2COMK->def_field();
LTL5COMA->def_field();



DB->db_autocommitOFF();



rtvenvvar();

         if ( IN03 ) {
                V_MSG="";
                aff_F00INI();
                DB->~PG_DB();
                return 0;
        }

        if(IN40 ==  ON)  aff_F00INI();
        else {

        if(EQ == RIZUSR.cmp("RNLTX")) {


        if ( IN21 ) aff_FX03DMD();
        if ( IN11 ) maj_FX03DMD() ;
         }


}
    DB->~PG_DB();

   return 0;
}



void rtvenvvar(){


getenvHTTP();




if(vport ==0) {
///  trt console

    V_NJOB   = "20161024174033298089004534";
    V_NFMT   = "1";
    V_FXX    ="F11";
    V_KSFL   = "???*";
    V_ECLX   = "??";
    V_LINE   = 1;
}
else {
    V_NJOB   = formData("V_NJOB").c_str();
    V_FXX    = formData("V_FXX").c_str();
    V_NFMT   = formData("V_NFMT").c_str();
    V_KSFL   = formData("V_KSFL").c_str();
    V_ECLX   = formData("V_ECLX").c_str();
    V_LINE   = formData("V_LINE").c_str();
}



    IN40 =  OFF;
     if (26 >  strlen(V_NJOB.ToChar()))
     {
        IN40 =  ON;
        V_MSG ="Session Invalide 00";
        return;
    }

    if (V_NFMT.status() !=NOTERR)  {
            IN40 =  ON;
            V_MSG = "Mauvaise connexion  bad cconnexion 01";
            return;
    }


    if(V_KSFL.status() != NOTERR) {
            IN40 =  ON;
            V_MSG = "Mauvaise connexion  bad cconnexion 02";
            return;
    }

    if(!FRIWEB->chain(V_NJOB)) {
            IN40 =  ON;
            V_MSG = "Mauvaise connexion  bad cconnexion 03";
            return;
    }
    RINCLZ = V_KSFL;
    if(!LC2ACLIB->chain(RIECLI,RIECLX,RINCLI,RINCLX,RINCLZ)) {
            IN40 =  ON;
            V_MSG = "Mauvaise connexion  bad cconnexion 04";
            return;
    }

     if(EQ == RIWSSL.cmp("O")) {  /// a modifier apres test
            if ( vport != 443) {
            IN40 =  ON;
            V_MSG = "Mauvaise connexion  bad cconnexion 05";
            return;
            }
     }

     if(EQ != RINFMT.cmp(V_NFMT)) {  /// suivit du N° page
            IN40 =  ON;
            V_MSG="Mauvaise connexion  bad cconnexion 06";
            return;
            }

     if(EQ == RIZUSR.cmp("RNLTX")) {
        IN40 =  OFF;

     if(!LTL1COMA->chain(RICNOM))
            {
            IN40 =  ON;
            V_MSG = "Mauvaise connexion  bad connexion 07";
            return;
            }

     if(EQ != V_NFMT.cmp(1) && EQ == V_FXX.cmp("F21")) {  /// suivit du N° page
            IN40 =  ON;
            V_MSG = "Mauvaise connexion  bad connexion 08";
            return;
            }
     if (EQ == V_FXX.cmp("F21")) {
            IN21 = ON;
     }






     if(NE == V_NFMT.cmp(1) && EQ == V_FXX.cmp("F11")) {  /// suivit du N° page
            IN40 =  ON;
            V_MSG = "Mauvaise connexion  bad connexion 09";
            return;
            }


     if (EQ == V_FXX.cmp("F11")) {
            IN11 = ON;
     if(!LC2ACLIB->chain(RIECLI,RIECLX,RINCLI,RINCLX,RINCLZ)) {
            IN40 =  ON;
            V_MSG = "Mauvaise connexion  bad cconnexion 10";
            return;
    }
    } else IN11 = OFF;



     if (EQ == V_FXX.cmp("F12")) IN12 = ON;
     if (EQ == V_FXX.cmp("F03")) IN03 = ON;

    IN40 =  OFF;
    DB->db_begin();

    if(true == FRIWEB->chkrow(V_NJOB)) FRIWEB->updrow(V_NJOB);

    DB->db_commit();
    DB->db_end();
    return;
    }




}




///--------------------------------------------
/// traiement saisie quantité Article
///--------------------------------------------



void aff_FX03DMD()
{
FNADOS->chain(RINDOS);
RINFMT = 1;  /// page mise à jour Article


ctemplate::TemplateDictionary FX03DMD ("FX03DMD");

FX03DMD.SetTemplateGlobalValue("HTTPS", vHTTP);
FX03DMD.SetTemplateGlobalValue("XLIBP", vlib);


///___________________________________

             FX03DMD.SetValue("IMGLOGO", (const char*)RIZLNK.ToChar());     /// * IMGLOGO
             FX03DMD.SetValue("C2AZNOM", (const char*)C2AZNOM.ToChar());    /// * NOM CLIENT
             FX03DMD.SetValue("C2AECLI", (const char*)C2AECLI.ToChar());    /// * N°Compte
             FX03DMD.SetValue("C2AECLX", (const char*)C2AECLX.ToChar());    /// * Code Adresse
             FX03DMD.SetValue("C2AZRU1", (const char*)C2AZRU1.ToChar());    /// * RUE1
             FX03DMD.SetValue("C2AZRU2", (const char*)C2AZRU2.ToChar());    /// * RUE2
             FX03DMD.SetValue("C2AZVIL", (const char*)C2AZVIL.ToChar());    /// * VILLE
             if (C2ANPTT > 0 )
             FX03DMD.SetValue("C2ANPTT", (const char*)C2ANPTT.ToChar());    /// * Code Postal FR
             else
             FX03DMD.SetValue("C2AZPTT", (const char*)C2AZPTT.ToChar());    /// * Code Postal Non FR

             FX03DMD.SetValue("C2ACPAY", (const char*)C2ACPAY.ToChar());    /// * code pays
             FX03DMD.SetValue("NAZCDE", (const char*)NAZCDE.ToChar());      /// * Ref.Imprimer

             if ( RITLNG == "FRA") FX03DMD.SetValue("TXTA", "Veuillez Choisir  un article et entrez une Quantitée");
             if ( RITLNG == "ENG") FX03DMD.SetValue("TXTA", "Want To Choose an item and entry a Quantity");
             FX03DMD.ShowSection("TOP");
/// OPT
             ctemplate::TemplateDictionary*  OPT_dict = FX03DMD.AddSectionDictionary("OPT");
             LTL2COMD->setEQ(RICNOM);
             if ( LTL2COMD->readEQ() ) do {
                    if(RINDOS == TL2NDOS) {
                        if( LNBDOSA->chain(RINDOS,TL2CGIM,TL2CDPO,TL2CSTD)  && TL2SHS == 0 ) {
                        FKTFSTK->chain(TL2CGIM,TL2CDPO,TL2CSTD);
                            if ( FKTDSTK->chain(KTFCLGO) ) {
                                OPT_dict->AddSectionDictionary("OPT");
                                OPT_dict->SetValue("OPTSTE",(const char*) KTDZLGO.ToChar());      /// * Code regroupement catalogue
                                OPT_dict->ShowSection("OPT");
                            }
                        }
                    }
            } while (LTL2COMD->readEQ() );

/// FILTRE
             FX03DMD.ShowSection("FILTRE");
/// MGRID
             FX03DMD.SetValue("V_DIR", (const char*)RIZUSR.ToChar());     /// * Folder = USER
             FX03DMD.ShowSection("MGRID");
/// IMG00 - IMG01 - IMG99
            if (TL1WIMG=="N") FX03DMD.ShowSection("IMG00");
            else FX03DMD.ShowSection("IMG01");
            FX03DMD.ShowSection("IMG99");


/// MGRID00
            ctemplate::TemplateDictionary*  MGRID00_dict = FX03DMD.AddSectionDictionary("MGRID00");
        if( EQ ==  RITLNG.cmp("FRA"))
                {
                    MGRID00_dict->SetValue("CQTE","Quantité");
                    MGRID00_dict->SetValue("CART","Article");
                    MGRID00_dict->SetValue("CREF","Référence");
                    MGRID00_dict->SetValue("CCND","Packaging");
                    MGRID00_dict->SetValue("CDMD","Demande");
                    MGRID00_dict->SetValue("CLVR","Expédié");
                    MGRID00_dict->SetValue("CSTE","Produits");
                    MGRID00_dict->SetValue("CQSTK","Q.Stock");
                    MGRID00_dict->SetValue("CQRL","Q.Réel");
                    MGRID00_dict->SetValue("CQINI","Q.Init");
                    MGRID00_dict->SetValue("CMINI","Q.Mini");
                    MGRID00_dict->SetValue("CMAXI","Q.Maxi");
                    MGRID00_dict->SetValue("CNDOS","N.DOS");
                }
        if( EQ ==  RITLNG.cmp("ENG"))
                {
                    MGRID00_dict->SetValue("CQTE","Quantity");
                    MGRID00_dict->SetValue("CART","Item");
                    MGRID00_dict->SetValue("CREF","Référence");
                    MGRID00_dict->SetValue("CCND","Packaging");
                    MGRID00_dict->SetValue("CDMD","Delivery");
                    MGRID00_dict->SetValue("CLVR","Sent");
                    MGRID00_dict->SetValue("CSTE","Products");
                    MGRID00_dict->SetValue("CQSTK","QT-STK");
                    MGRID00_dict->SetValue("CQRL","QT-REEL");
                    MGRID00_dict->SetValue("CQINI","QT-INIT");
                    MGRID00_dict->SetValue("CMINI","QT-MINI");
                    MGRID00_dict->SetValue("CMAXI","QT-MAXI");
                    MGRID00_dict->SetValue("CNDOS","N.DOS");
                }

            MGRID00_dict->SetValue("WH00","O");
            MGRID00_dict->SetValue("WH01", (const char*)TL1WH01.ToChar());
            MGRID00_dict->SetValue("WH02", (const char*)TL1WH02.ToChar());
            MGRID00_dict->SetValue("WH03", (const char*)TL1WH03.ToChar());
            MGRID00_dict->SetValue("WH04", (const char*)TL1WH04.ToChar());
            MGRID00_dict->SetValue("WH05", (const char*)TL1WH05.ToChar());
            MGRID00_dict->SetValue("WH06", (const char*)TL1WH06.ToChar());

            MGRID00_dict->ShowSection("MGRID00");
/// CTRLSTK
            if ( TL1WCSK=="O" )  FX03DMD.ShowSection("CTRLSTK");
/// FINCTRL

            FX03DMD.ShowSection("FINCTRL");
/// LIGN
/// RECUPERATION ARTICLE DU CLIENT
           LTL2COMD->setEQ(RICNOM);
           LIGN1 = 1;
             if ( LTL2COMD->readEQ() ) do {
                 if (RINDOS == TL2NDOS) {
                      IN55 =OFF;
                      /// affiche article si client autorisé
                      if( LRHBLVB->chkrow(TL2CGIM,TL2CDPO,TL2CSTD)) { if (false == LRHBLVA->chkrow(RINCLI,RINCLX,RINCLZ,TL2CGIM,TL2CDPO,TL2CSTD)) IN55 = ON; }

                     if( LNBDOSA->chain(RINDOS,TL2CGIM,TL2CDPO,TL2CSTD ) && TL2SHS == 0 && IN55 == OFF ) {

                           LKTSTKA->chain(TL2CGIM,TL2CDPO,TL2CSTD);
                           LKEDOSQ->clrfield();
                           KE0LVD= DATESYS; IN55 = OFF;
                           if( LKEDOSQ->chain(RINDOS,RINCLI,RINCLX,RINCLZ,TL2CGIM,TL2CDPO,TL2CSTD,KE0LVD) ) IN55 = ON;

                            ctemplate::TemplateDictionary*  LIGN_dict = FX03DMD.AddSectionDictionary("LIGN");
                            LIGN_dict->AddSectionDictionary("LIGN");
                             V_KART.concat("%s%s%s",TL2CGIM.ToChar(), TL2CDPO.ToChar(),TL2CSTD.ToChar());
                            LIGN_dict->SetValue("VKEYID",(const char*) V_KART.ToChar());                            /// * Key Code ARTICLE
                            if(IN55 == OFF) LIGN_dict->SetValue("KEQLVD",(const char*) KEQLVD.ToChar());            /// * QT demander ARTICLE
                            LIGN_dict->SetValue("KECSTD",(const char*) TL2CSTD.ToChar());                           /// * Code Article
                            if(IN55 == OFF)V_QLVD = 0; else V_QLVD= KEQLVD;                                         /// * Quantité demandé
                            LIGN_dict->SetValue("KEQLVD",(const char*)  V_QLVD.ConstChar()  );

                            if(TL1WAFF.cmp('O') ) LIGN_dict->SetValue("V_CREF",  KTZLBA.ToChar());                  /// * texte Article

                            V_CCND.mult("%s,%s",KTNXBO.ToChar(),KTXCFU.ToChar());
                            LIGN_dict->SetValue("V_CCND",(const char*) V_CCND.ToDec());                             /// * CONDITIONNEMENT

                            if(IN55 == OFF) LIGN_dict->SetValue("KE0LVD",(const char*) " ");                        /// * Date demande  livraison
                            else {
                                  LIGN_dict->SetValue("KE0LVD",(const char*) KE0LVD.edtDMY());
                            }
                            if(IN55 == OFF or KE0LVR.ToInt() == 10101) LIGN_dict->SetValue("KE0LVR"," ");                                      /// * Date effectué livraison
                            else {
                                  LIGN_dict->SetValue("KE0LVR",(const char*) KE0LVR.edtDMY());
                            }
                            FKTFSTK->chain(TL2CGIM,TL2CDPO,TL2CSTD);
                            IN55 = OFF;
                            if(FKTDSTK->chain(KTFCLGO)) IN55 = ON;
                            if(IN55 == ON) LIGN_dict->SetValue("KTDZLGO",(const char*) KTDZLGO.ToChar());            /// * LOGO
                            else LIGN_dict->SetValue("KTDZLGO","");
/*                            V_QREL = 0; V_QSTK = 0 ;

                            LKSSTKA->setEQ(TL2CGIM,TL2CDPO,TL2CSTD);
                               if (LKSSTKA->readEQ()) do {
                                  V_QRELt = 0; V_QSTKt = 0 ;
                                        if(TL1WCSK.cmp('O') && KSNDOS.cmp(RINDOS))
                                                    {
                                                     V_QRELt.mult("%s,%s",KSNBTE.ToChar(),KSNXBO.ToChar());
                                                     if ( V_QREL == 0 )  V_QREL =V_QRELt; else V_QREL +=V_QRELt;
                                                     V_QSTKt.mult("%s,%s,%s",KSNBTE.ToChar(),KSNXBO.ToChar(),KSXCFU.ToChar());
                                                     if ( V_QSTK == 0 )  V_QSTK =V_QSTKt; else V_QSTK +=V_QSTKt;
                                                    }
                                         if(TL1WCSK.cmp('N'))
                                                    {
                                                     V_QSTKt.mult("%s,%s,%s",KSNBTE.ToChar(),KSNXBO.ToChar(),KSXCFU.ToChar());
                                                     if ( V_QSTK == 0 )  V_QSTK =V_QSTKt; else V_QSTK +=V_QSTKt;
                                                    }
                            } while (LKSSTKA->readEQ() );
*/
                            if(KTQREL==0) LIGN_dict->SetValue("KTQREL"," ");                                        /// * Qte reel
                            else LIGN_dict->SetValue("KTQREL",(const char*) KTQREL.ToChar());
                            if(KTQDST==0) LIGN_dict->SetValue("V_QREL"," ");                                        /// * Qte en stock
                            else LIGN_dict->SetValue("V_QREL",(const char*) KTQDST.ToChar());


                        LIGN_dict->SetValue("V_QINI",(const char*) V_QLVD.ToChar());                                /// * QT.INIT
                        LIGN_dict->SetValue("V_MINI","0");                                                          /// * QT.MINI
                        LIGN_dict->SetValue("V_MAXI","0");                                                          /// * QT.MAXI
                        LIGN_dict->SetValue("V_NDOS",(const char*) RINDOS.ToChar());                                /// * N° DOSSIER
                        LIGN_dict->SetValue("LIGN1" ,(const char*) LIGN1.ToChar());                                 /// * N° ligne
                        LIGN_dict->ShowSection("LIGN");
                        LIGN1 += 1;
                    } /// ligne detail
                  } /// Dossier encours
                 } while (LTL2COMD->readEQ() );/// rajout article suplémentaire

/// FIN00
///----------------------------------

            ctemplate::TemplateDictionary*  FIN00_dict = FX03DMD.AddSectionDictionary("FIN00");
            FIN00_dict->AddSectionDictionary("FIN00");
            FIN00_dict->SetValue("RITLNG", (const char*)RITLNG.ToChar());

        if( EQ ==  RITLNG.cmp("FRA"))
                {
                FIN00_dict->SetValue("F12", "Abandon");
                FIN00_dict->SetValue("F03", "Quitter");
                FIN00_dict->SetValue("F11", "Enregistrer");
                FIN00_dict->SetValue("F14", "Repiquage");
                }

        if( EQ ==  RITLNG.cmp("ENG"))
                {
                FIN00_dict->SetValue("F12", "Return");
                FIN00_dict->SetValue("F03", "Leave");
                FIN00_dict->SetValue("F11", "Save");
                FIN00_dict->SetValue("F14", "OverPrint");
                }

            FIN00_dict->SetValue("HTTPS", vHTTP);
            FIN00_dict->SetValue("XLIBP", vlib);

            FIN00_dict->SetValue("FART", ("Article"));
            FIN00_dict->SetValue("V_NJOB",(const char*)V_NJOB.ToChar());
            FIN00_dict->ShowSection("FIN00");
/// FIN01
/// Send sections  AFFICHAGE STOCK
            if (EQ == TL1WSTK.cmp("O"))
                {
                    ctemplate::TemplateDictionary*  FIN01_dict = FX03DMD.AddSectionDictionary("FIN01");
                    FIN01_dict->AddSectionDictionary("FIN01");
                    FIN01_dict->SetValue("V_NJOB",(const char*)V_NJOB.ToChar());
                    FIN01_dict->ShowSection("FIN01");
                }
/// FIN02
/// Send sections  DESELECT
            ctemplate::TemplateDictionary*  FIN02_dict = FX03DMD.AddSectionDictionary("FIN02");
            FIN02_dict->AddSectionDictionary("FIN02");
            FIN02_dict->ShowSection("FIN02");
/// FIN14
/// Send sections  AFFICHAGE REPIQUAGE
            if (EQ == TL1WRPQ.cmp("O"))
                {
                    ctemplate::TemplateDictionary*  FIN14_dict = FX03DMD.AddSectionDictionary("FIN14");
                    FIN14_dict->AddSectionDictionary("FIN14");

                if( EQ ==  RITLNG.cmp("FRA"))
                {
                FIN14_dict->SetValue("F14", "Repiquage");
                }

                if( EQ ==  RITLNG.cmp("ENG"))
                {
                FIN14_dict->SetValue("F14", "OverPrint");
                }
                    FIN14_dict->ShowSection("FIN14");
                }
///-------------------------------------  fin de page
/// END

            ctemplate::TemplateDictionary*  END_dict = FX03DMD.AddSectionDictionary("END");
            END_dict->AddSectionDictionary("END");

            END_dict->SetValue("V_FXX", ("F21"));

            END_dict->SetValue("RITLNG", (const char*)RITLNG.ToChar());

            END_dict->SetValue("V_NFMT", (const char*)RINFMT.ToChar());

            END_dict->SetValue("V_NJOB",(const char*)V_NJOB.ToChar());

            END_dict->SetValue("V_KSFL",(const char*)RINCLZ.ToChar());

            END_dict->SetValue("V_ECLX",(const char*)RIECLX.ToChar());

            END_dict->SetValue("V_XART","00000000000");

            END_dict->SetValue("V_LINE","000");

            FIN00_dict->SetValue("MSGERR", "");


 END_dict->ShowSection("END");

 output="";
 /// conversion
  ctemplate::ExpandTemplate("FX03DMD.tpl", ctemplate::DO_NOT_STRIP, &FX03DMD, &output);

///---------

if (vport == 0 ) {
  FILE* pFile = fopen("FX03DMD.html", "w");
  fputs (output.c_str(),pFile);
  fclose (pFile);
} else {
        cout << "Content-type:text/html\r\n\r\n";
        cout<<output.c_str()<<endl;
       }

DB->db_begin();
    if( true == FRIWEB->chkrow(V_NJOB)) FRIWEB->updrow(V_NJOB);
    DB->db_commit();
DB->db_end();

}


///--------------------------------------------
/// traiement saisie quantité Article
///--------------------------------------------



void maj_FX03DMD()
{
    int nbrLigne = V_LINE.ToInt();


char  *vNAME =new char[30];
Zdcml     V_QTE(10,0);    /// zone web qte commandé
Zdcml     V_XCF(6,0);     /// zone web conditionement
Zdcml     V_QINI(10,0);   /// zone web qte initiale


    DB->db_commit();
    DB->db_begin();

    if(nbrLigne > 0 ) {
        for (int occurs = 1 ; occurs <= nbrLigne; occurs++ )
        {
            FKEDOS->clrfield() ;
if(vport  !=0) {
            sprintf(vNAME ,"V_KART%d", occurs);
            V_KART   = formData(vNAME).c_str();

            KECGIM.Extrac(V_KART,1,1);
            KECDPO = atoi(V_KART.ExtracToChar(2,2));
            KECSTD.Extrac(V_KART,4,8);

            sprintf(vNAME ,"V_QTE%d", occurs);
            V_QTE   = atoi(formData(vNAME).c_str());

            sprintf(vNAME ,"V_XCF%d", occurs);
            V_XCF   = atoi(formData(vNAME).c_str());

            sprintf(vNAME ,"V_QINI%d", occurs);
            V_QINI   = atoi(formData(vNAME).c_str());
}
if(vport ==0) {
             sprintf(vNAME ,"V_KART%d", occurs);
            V_KART   = "S21RDS50X69";


            KECGIM.Extrac(V_KART,1,1);
            KECDPO = atoi(V_KART.ExtracToChar(2,2));
            KECSTD.Extrac(V_KART,4,8);


            V_QTE   = 50000;


            V_XCF   =2500;


            V_QINI   = 0;
            fprintf(stderr,"ok_03");
}
            KE0LVD= DATESYS; fprintf(stderr,"ok");
            if( LTL2COMK->chkrow(RICNOM,RINDOS,KECGIM,KECDPO,KECSTD)) {
                            KE0LVD= DATESYS; IN55 = OFF;
                           if( LKEDOSQ->chain(RINDOS,RINCLI,RINCLX,RINCLZ,KECGIM,KECDPO,KECSTD,KE0LVD) )
                           {  /// UPDATE
                               if (V_QTE == 0 and V_QINI > 0) FKEDOS->delrow(RINDOS,KE0LVD,RINCLI,RINCLX,RINCLZ,KECGIM,KECDPO,KECSTD);
                               if (V_QTE > 0 and KEQLVR == 0) { KEQLVD = V_QTE;
                                                              FKEDOS->updrow(RINDOS,KE0LVD,RINCLI,RINCLX,RINCLZ,KECGIM,KECDPO,KECSTD);
                                                               write_FSEDOS();
                               }
                           }
                           else {
                                if (V_QTE > 0 ) {
                                   KE0LVR = 0 ; KE999E= DATESYS; KE999M= DATESYS; KENBL = 0, KENCLI = RINCLI;   KENCLX= RINCLX; KENCLY= RINCLZ;
                                   KENDOS= RINDOS;   KEQLVD= V_QTE;  KEQLVR =0 ;
                                                              FKEDOS->addrow(KENDOS,KE0LVD,KENCLI,KENCLX,KENCLY,KECGIM,KECDPO,KECSTD);
                                                               write_FSEDOS();
                               }

                           }
            }

        }; // for
   }; // nbrLigne
    DB->db_commit();
    DB->db_end();
   aff_FX03DMD();

}
void write_FSEDOS()
{
      ///         FSEDOS         TEXTE('HISTORIQUE CLIENT LIVRAISON MULTIPLE              ')

SECISO = SE999E.session()   ; ///   C_KEY DATE-TIME-NSCD
SECSTD = KECSTD             ; ///   COD_ART._STK/DIVERS
SECDPO = KECDPO             ; ///   CODE DEPOT
SECGIM = KECGIM             ; ///   CODE GESTION_IMP/STK
SECIDU = RICIDU             ; ///   CODE ID. USER
SECPWD = RICPWD             ; ///   CODE PASSWORD
SE0LVD = KE0LVD             ; ///   DATE LIV. DEMANDE
SE0LVR = KE0LVR             ; ///   DATE LIV. REEL

SE999E = "*SYS"             ; ///   DATE DE CREATION ENR
SEECLI = RIECLI             ; ///   N° CLIENT        EXT
SEECLX = RIECLX             ; ///   CLIENT N°INDEX   EXT

SENBL  = KENBL              ; ///   N° BON LIVRAISON

SENCLI = KENCLI             ; ///   N° CLIENT
SENCLX = KENCLX             ; ///   CLIENT N°INDEX  BASE
SENCLY = KENCLY             ; ///   CLIENT INDEX /INDEX



SENCWI = C2ANCWI            ; ///   CLIENT FACT      WEB
SENCWX = C2ANCWX            ; ///   CLIENT FACT IDX  WEB


SENDOS = KENDOS             ; ///   N.CHRONO DOSSIER
SEQLVD = KEQLVD             ; ///   QTE_LIVREE_DEMANDEE
SEQLVR = KEQLVR             ; ///   QTE_LIVREE_REELLE

SEZWRF = KEZWRF             ; ///   REF DE CDE WEB

 FSEDOS->addrow(SENDOS,SECISO);

}
#include "../INCLUDE/F00INI.cpp"   /// Renvoie en première page du site (ex: société inconnue
#include "../INCLUDE/GetEnvHttp.cpp"  /// récupère les variables d'envirronement
