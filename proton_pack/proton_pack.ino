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

//Création Task Manager
GPTaskManager *myOS = NULL;
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

  //Création Gestionnaire du Proton Gun
  Proton_protongun = new ProtonGun();

  //Création Gestionnaire Power Cell
  Proton_powercell = new PowerCell();

  //Création Gestionnaire du Cyclotron
  Proton_cyclotron = new Cyclotron();

  //Création Gestionnaire de Fumée
  Proton_fumee = new Fumee();


  //-----------------------------------------------------
  //Création du task Manager
  myOS = new GPTaskManager();

  //Tache refresh LED
  myOS->add( refreshLight, 134 );//2000 ms / 15 led = 133.33 ms

  //Switch et Button
  myOS->event( digitalRead, PROTONGUN_ACTIVATE_GUN_SWITCH , eventActiveGun       );
  myOS->event( digitalRead, PROTONGUN_ACTIVATE_PACK_SWITCH, eventActivePack      );
  myOS->event( digitalRead, PROTONGUN_ACTIVATE_SWITCH     , eventActiveSwitch    );
  myOS->event( digitalRead, PROTONGUN_INTENSITY_BUTTON    , eventActiveIntensify );
  myOS->event( digitalRead, PROTONGUN_REDGUN_BUTTON       , eventActiveEndGun    );
}



//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Boucle frame Arduino
void loop()
{
  //Update Task Manager
  myOS->update();
  //Verification pour la sécurité de la fumée
  Proton_fumee->verifAllFrame();
}


//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Callback Fonction d'actualisation des lumiéres
void refreshLight()
{
  Proton_powercell->next( eventEndPowerCell );
  Proton_protongun->nextBarrel();
}
//Event cycle powercell fini
void eventEndPowerCell()
{
  Proton_cyclotron->next();
  Proton_protongun->next();
}


//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Switch Active pack ( centre haut )
void eventActiveGun()
{
  //Activate All light GUN, ignore Vent light
  Proton_protongun->activeSwitch();
}



//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Switch Active pack ( centre bas )
void eventActivePack()
{
  //Activate Cyclotron and PowerCel
  Proton_cyclotron->activeSwitch();
  Proton_powercell->activeSwitch();
}


//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Switch Activate ( vent light )
void eventActiveSwitch()
{
  Proton_protongun->ventSwitch();
}


//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Bouton Intensify
bool tir = false;
void eventActiveIntensify()
{
  //Activate TIR
  if(!tir)
    Proton_audio->OnGun();
  else
    Proton_audio->OffGun();
  //inversion
  tir = !tir;
  
  //Change Barrel sequence
  Proton_protongun->tirSwitch();
}


//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Bouton rouge fun du gun
void eventActiveEndGun()
{
  //?
  Proton_audio->GunSwitch();
}
