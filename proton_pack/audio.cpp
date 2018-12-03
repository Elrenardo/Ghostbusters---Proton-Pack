#include "audio.h"

//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Constructeur de Audio
Audio::Audio()
{
  this->mySoftwareSerial =  new SoftwareSerial( AUDIO_RX, AUDIO_TX );// RX, TX port
  this->myDFPlayer = new DFRobotDFPlayerMini();

  //init dialogue carte DFplayerMini
  this->mySoftwareSerial->begin( AUDIO_PORT_INIT );

  #ifdef PROTON_DEBUG
    Serial.println();
    Serial.println(F("DFRobot DFPlayer Mini Demo"));
    Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  #endif
  
  if (!this->myDFPlayer->begin(*this->mySoftwareSerial))//Use softwareSerial to communicate with mp3.
  {
    #ifdef PROTON_DEBUG
      Serial.println(F("Unable to begin:"));
      Serial.println(F("1.Please recheck the connection!"));
      Serial.println(F("2.Please insert the SD card!"));
    #endif
    while(true);
  }
  #ifdef PROTON_DEBUG
    Serial.println(F("DFPlayer Mini online."));
  #endif
  
  this->myDFPlayer->volume( AUDIO_VOLUME );  //Set volume value. From 0 to 30
  //this->myDFPlayer->play(9);  //Play the first mp3
}


//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
void Audio::OnPack()
{
  
}



//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
void Audio::OffPack()
{
  
}



//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
void Audio::OnGun()
{
  
}



//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
void Audio::OffGun()
{
  
}



