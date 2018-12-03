//-------------------------------------------------------
//-------------------------------------------------------
/*
NAME    : Main Proton pack
BY      : Teysseire Guillaume
TIME    : 03/12/2018
UPDA    : 03/12/2018
WEB     : studiogoupil.fr
VERSION : 1.00
*/
//-------------------------------------------------------
//-------------------------------------------------------
//Lib

#include <GPTaskManager.h>
#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//projet .h

#include "define.h"
#include "audio.h"
#include "cyclotron.h"
#include "powercell.h"
#include "protongun.h"
#include "fumee.h"

//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Global Main Var

//Audio
Audio *Proton_audio;
//Power Cell
PowerCell *Proton_powercell;
//Cyclotron
Cyclotron *Proton_cyclotron;
//Proton Gun
ProtonGun *Proton_protongun;
//Fumee
Fumee *Proton_fumee;



//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Initialisation Arduino
void setup()
{
  #ifdef PROTON_DEBUG
    Serial.begin( PROTON_DEBUG_SERIAL );
  #endif

  //Création du gestionnaire Audio
  Proton_audio = new Audio();

  //Création Gestionnaire Power Cell
  Proton_powercell = new PowerCell();

  //Création Gestionnaire du Cyclotron
  Proton_cyclotron = new Cyclotron();

  //Création Gestionnaire du Proton Gun
  Proton_protongun = new ProtonGun();

  //Création Gestionnaire de Fumée
  Proton_fumee = new Fumee();
  
}



//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Boucle frame Arduino
void loop()
{

}
