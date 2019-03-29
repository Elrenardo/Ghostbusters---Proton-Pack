//-------------------------------------------------------
//-------------------------------------------------------
/*
NAME    : Cyclotron Proton Pack
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
/*Gestion du Cyclotron*/
class Cyclotron
{
   public:
    Cyclotron();

    /*--- Activer le cyclotron --- */
    void on();

    /*--- Desactiver le cyclotron --- */
    void off();

    /*--- Switch Activation --- */
    void activeSwitch();

    /*--- Activer la lumiére suivante --- */
    void next();

    /*--- Reset la lumiére à la premiére --- */
    void resetLight();

   private:
   
    //Activer ou pas
    boolean etat = false; // 0=off, 1=on
    
    //compter les leds
    unsigned char compte;// 0-3
};
