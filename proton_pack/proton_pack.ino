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
//Varial d'action special
boolean is_vent = false;
boolean is_tir = false;



//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Initialisation Arduino
void setup()
{
  #ifdef PROTON_DEBUG
    Serial.begin( PROTON_DEBUG_SERIAL );
    Serial.println(F("PROTON PACK SETUP:"));
  #endif

  //Création du gestionnaire Audio
  Proton_audio = new Audio();
  Proton_audio->build();

  //Création Gestionnaire du Proton Gun
  Proton_protongun = new ProtonGun();

  //Création Gestionnaire du Cyclotron
  Proton_cyclotron = new Cyclotron();


  //Création Gestionnaire Power Cell
  Proton_powercell = new PowerCell();
/*
  //Création Gestionnaire de Fumée
  //Proton_fumee = new Fumee();
*/

  //-----------------------------------------------------
  //AutoActivate
  if( digitalRead(PROTONGUN_ACTIVATE_PACK_SWITCH))
    eventActivePack();
  if( digitalRead(PROTONGUN_ACTIVATE_GUN_SWITCH))
    eventActiveGun();
  if( digitalRead(PROTONGUN_INTENSITY_SWITCH))
    eventActiveIntensify();
  if( digitalRead(PROTONGUN_ACTIVATE_BUTTON))
    eventActiveTir();
    

  //-----------------------------------------------------
  //Création du task Manager
  myOS = new GPTaskManager();

  //Tache refresh LED
  myOS->add( refreshLight, 75 );//2000 ms / 15 led = 133.33 ms

  //Switch et Button
  myOS->event( digitalRead, PROTONGUN_ACTIVATE_PACK_SWITCH, eventActivePack     );
  myOS->event( digitalRead, PROTONGUN_ACTIVATE_GUN_SWITCH , eventActiveGun      );
  myOS->event( digitalRead, PROTONGUN_INTENSITY_SWITCH    , eventActiveIntensify);
  myOS->event( digitalRead, PROTONGUN_ACTIVATE_BUTTON     , eventActiveTir      );
  //myOS->event( digitalRead, PROTONGUN_REDGUN_BUTTON     , eventActiveEndGun   );
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
  //Proton_fumee->verifAllFrame();

  //Debug Gun INPUT
  /*Serial.println("GUN DEBUG ------");
  Serial.println( digitalRead( PROTONGUN_ACTIVATE_GUN_SWITCH ) );
  Serial.println( digitalRead( PROTONGUN_ACTIVATE_PACK_SWITCH ) );
  Serial.println( digitalRead( PROTONGUN_INTENSITY_SWITCH ) );
  Serial.println( digitalRead( PROTONGUN_ACTIVATE_BUTTON ) );
  delay(1000);*/
}


//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Callback Fonction d'actualisation des lumiéres
void refreshLight()
{
  Proton_powercell->next( eventEndPowerCell, is_tir );//Mode speed = is_tir
  Proton_protongun->nextBarrel();

  //Si on tir acceleration des lumiéres
  if(is_tir)
  {
    Proton_cyclotron->next();//Acceleration cyclotron
    Proton_protongun->updLedClign();//Acceleration clignotement led
  }
}
//Event cycle powercell fini
void eventEndPowerCell()
{
  Proton_cyclotron->next();
  Proton_protongun->updLedClign();
}


//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Switch Active pack ( centre bas )
void eventActivePack()
{
  //Audio Active
  Proton_audio->SwitchPack();
  
  //Activate Cyclotron and PowerCel
  Proton_cyclotron->activeSwitch();
  Proton_powercell->activeSwitch();
}


//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Switch Active pack ( centre haut )
void eventActiveGun()
{
  #ifdef PROTON_DEBUG
    Serial.println(F("GUN MARCHE:"));
  #endif

  //Audio Gun
  Proton_audio->SwitchGun();
  
  //Activate All light GUN, ignore Vent light
  Proton_protongun->activeSwitch();
}


//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Switch Intensify
void eventActiveIntensify()
{
  #ifdef PROTON_DEBUG
    Serial.println(F("VENT MARCHE:"));
  #endif

  //Si on tir on peux pas activé
  if(is_tir)
    return;

  //Audio Gun
  Proton_audio->SwitchVent();
  
  //Change Barrel sequence
  is_vent = Proton_protongun->ventSwitch();

  //Economiser energie
  //Proton_cyclotron->activeSwitch();
  //Proton_powercell->activeSwitch();
}

//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Bouton Tir
void eventActiveTir()
{
  #ifdef PROTON_DEBUG
    Serial.println(F("FEU MARCHE:"));
  #endif

  //Audio Tir
  is_tir = Proton_audio->AutoTir();

  //Change Barrel sequence
  if(!is_tir)
  if(is_vent)
  {
    delay(1000);
    Proton_audio->OnVent();
  }

  //Economiser energie
  //Proton_cyclotron->activeSwitch();
  //Proton_powercell->activeSwitch();
}


//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Bouton rouge fun du gun
/*void eventActiveEndGun()
{
  //?
  Proton_audio->GunSwitch();
}*/
