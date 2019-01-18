//-------------------------------------------------------
//-------------------------------------------------------
/*
NAME    : Fumee Proton Pack
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
/*Gestion du Fumee via cigarette electronique*/
class Fumee
{
   public:
    Fumee();

    /*--- On ---*/
    void on();

    /*--- Off ---*/
    void off();

    /*--- Switch --*/
    void fumeeSwitch();

    /*--- Verif temps actif ----*/
    void verifAllFrame();
    
   private:

   //activate fumee
   bool etat = false;
   unsigned long start = 0;
   unsigned long vent = 0;
    
};
