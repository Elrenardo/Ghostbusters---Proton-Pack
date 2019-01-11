//-------------------------------------------------------
//-------------------------------------------------------
/*
NAME    : Power Cell Proton Pack
BY      : Teysseire Guillaume
TIME    : 03/12/2018
UPDA    : 03/12/2018
WEB     : studiogoupil.fr
VERSION : 1.00
*/
//-------------------------------------------------------
//-------------------------------------------------------
#include "Arduino.h"

#include "define.h"

//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
/*Gestion du PowerCell*/
class PowerCell
{
   public:
    PowerCell();

    /*--- Activer le PowerCell --- */
    void on();

    /*--- Desactiver le PowerCell --- */
    void off();

    /*--- Switch Activation --- */
    void activeSwitch();

    /*--- Update Affichage ( callback appelé lorsque le power cell ce vide ) --- */
    void next( void (*callback)() );
    
   private:
    //Active
    bool etat = true;
    //Compte 
    unsigned char compte = 0;

    //SetLed
    void setLed( unsigned char posi, int led );
    //Reset compte
    bool addCompte();
    
    
};
