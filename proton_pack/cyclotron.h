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
    void On();

    /*--- Desactiver le cyclotron --- */
    void Off();

    /*--- Activer la lumiére suivante --- */
    void Next();

    /*--- Reset la lumiére à la premiére --- */
    void ResetLight();

   private:
   
    //Activer ou pas
    boolean etat; // 0=off, 1=on
    
    //compter les leds
    unsigned char compte;// 0-3
};

