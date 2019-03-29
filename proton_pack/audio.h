//-------------------------------------------------------
//-------------------------------------------------------
/*
NAME    : Audio Proton pack
BY      : Teysseire Guillaume
TIME    : 03/12/2018
UPDA    : 03/12/2018
WEB     : studiogoupil.fr
VERSION : 1.00
*/
//-------------------------------------------------------
//-------------------------------------------------------
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

#include "define.h"


//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
/*Gestion Audio Du pack de proton*/
class Audio
{
  public:
    Audio();
    void build();

    /*--- Switch le pack de proton --- */
    void SwitchPack();

    /*--- Activer le pack de proton --- */
    void OnPack();

    /*--- Desactiver le pack de proton --- */
    void OffPack();

   /*--- Switch Gun --- */
    void SwitchGun();

    /*--- Activer le gun --- */
    void OnGun();
    
    /*--- Desactiver le gun --- */
    void OffGun();

    /*--- Auto tir --- */
    boolean AutoTir();


    /*--- Switch vent ---*/
    boolean SwitchVent();

   /*--- On vent ---*/
    void OnVent();

    /*--- Off vent ---*/
    void OffVent();

    
  private:
    SoftwareSerial *mySoftwareSerial; // RX, TX port
    DFRobotDFPlayerMini *myDFPlayer;//Carte DFplayerMini

    boolean pack = false;
    boolean gun  = false;
    boolean vent = false;
    boolean tir  = false;
  
};
