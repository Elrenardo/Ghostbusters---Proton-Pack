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

    /*--- Activer le pack de proton --- */
    void OnPack();

    /*--- Desactiver le pack de proton --- */
    void OffPack();

    /*--- Activer le tir --- */
    void OnGun();
    
    /*--- Desactiver le tir --- */
    void OffGun();

    
  private:
    SoftwareSerial *mySoftwareSerial; // RX, TX port
    DFRobotDFPlayerMini *myDFPlayer;//Carte DFplayerMini
  
};

