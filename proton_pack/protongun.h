//-------------------------------------------------------
//-------------------------------------------------------
/*
NAME    : Proton GUN Proton Pack
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
/*Gestion du Proton Gun*/
class ProtonGun
{
   public:
    ProtonGun();

    /*--- Activer le ProtonGun --- */
    void on();

    /*--- Desactiver le ProtonGun --- */
    void off();

    /*--- Update --- */
    void next();

    /*--- Update Barrel Led --- */
    void nextBarrel();

    /*--- Switch Activation --- */
    void activeSwitch();

    /*--- Switch Vent --- */
    void ventSwitch();

    /*--- Switch Tir --- */
    void tirSwitch();

    /*--- On Tir --- */
    void onTir();

    /*--- Off Tir --- */
    void offTir();
    
   private:
    void setBarrelLed( unsigned char posi, int led );
   
     //Activate
     bool etat = true;
     //Activate vent
     bool etatVent = true;
     //Activation GUN
     bool etatTir = false;
     //clignotement light blanche
     bool switchCligLight = false;
     //Barrel compte
     unsigned char barrel_compte = PROTONGUN_BARREL_MIN;
};
