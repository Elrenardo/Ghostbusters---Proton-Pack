#include "audio.h"

//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Constructeur de Audio
Audio::Audio()
{
  this->pack = false;
  this->gun  = false;
  this->vent = false;
  this->tir  = false;
  
  this->mySoftwareSerial =  new SoftwareSerial( AUDIO_RX, AUDIO_TX );// RX, TX port
  this->myDFPlayer = new DFRobotDFPlayerMini();
}


//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
void Audio::build()
{
  //init dialogue carte DFplayerMini
  this->mySoftwareSerial->begin( AUDIO_PORT_INIT );

  #ifdef PROTON_DEBUG
    Serial.println();
    Serial.println(F("DFRobot DFPlayer Mini Demo"));
    Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  #endif

  /*if (!this->myDFPlayer->begin(*mySoftwareSerial))//Use softwareSerial to communicate with mp3.
  {
    #ifdef PROTON_DEBUG
      Serial.println(F("Unable to begin:"));
      Serial.println(F("1.Please recheck the connection!"));
      Serial.println(F("2.Please insert the SD card!"));
    #endif
    //while(true);
  }*/
  
  this->myDFPlayer->begin(*mySoftwareSerial);//Use softwareSerial to communicate with mp3.
  #ifdef PROTON_DEBUG
    Serial.println(F("DFPlayer Mini online."));
    Serial.println();
  #endif
  
  this->myDFPlayer->volume( AUDIO_VOLUME );  //Set volume value. From 0 to 30
  this->myDFPlayer->enableDAC();
}


//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
void Audio::OnPack()
{
  this->pack = true;
  this->myDFPlayer->play( AUDIO_PLAY_PACK_ON );
}



//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
void Audio::OffPack()
{
  this->pack = false;
  this->myDFPlayer->play( AUDIO_PLAY_PACK_OFF );
}

//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
void Audio::SwitchPack()
{
  if(this->pack)
    this->OffPack();
  else
    this->OnPack();
}



//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
void Audio::OnGun()
{
  this->gun = true;

  //this->myDFPlayer->play( AUDIO_PLAY_GUN_ON );
}



//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
void Audio::OffGun()
{
  this->gun = false;
}


//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
void Audio::SwitchGun()
{
  /*if(this->gun)
    this->OffGun();
  else
    this->OnGun();*/
}


//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
boolean Audio::AutoTir()
{
  this->myDFPlayer->pause();
  
  if( this->tir )
  {
    //stop
    this->tir = false;
    this->myDFPlayer->disableLoop();
    this->myDFPlayer->play( AUDIO_PLAY_STREAM_OFF );
  }
  else
  {
    //start
    this->tir = true;
    this->myDFPlayer->play( AUDIO_PLAY_STREAM_ON );
    delay(750);
    this->myDFPlayer->loop( AUDIO_PLAY_STREAM );
  }
  return this->tir;
}



//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
boolean Audio::SwitchVent()
{
  this->myDFPlayer->pause();
  
  if( this->vent )
    OffVent();
  else
    this->OnVent();
    
  return this->vent;
}


//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
void Audio::OnVent()
{
    this->vent = true;
    this->myDFPlayer->loop( AUDIO_PLAY_GUN_VENT );
}

//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
void Audio::OffVent()
{
    this->vent = false;
    this->myDFPlayer->disableLoop();
    this->myDFPlayer->pause();
}
