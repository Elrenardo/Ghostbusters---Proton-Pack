#include "powercell.h"


//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Constructeur
PowerCell::PowerCell()
{
  //Set Pin Mode
  pinMode( POWERCELL_01, OUTPUT );
  pinMode( POWERCELL_02, OUTPUT );
  pinMode( POWERCELL_03, OUTPUT );
  pinMode( POWERCELL_04, OUTPUT );
  pinMode( POWERCELL_05, OUTPUT );
  pinMode( POWERCELL_05, OUTPUT );
  pinMode( POWERCELL_07, OUTPUT );
  pinMode( POWERCELL_08, OUTPUT );
  pinMode( POWERCELL_09, OUTPUT );
  pinMode( POWERCELL_10, OUTPUT );
  pinMode( POWERCELL_11, OUTPUT );
  pinMode( POWERCELL_12, OUTPUT );
  pinMode( POWERCELL_13, OUTPUT );
  pinMode( POWERCELL_14, OUTPUT );
  pinMode( POWERCELL_15, OUTPUT );

  //Activation
  if(digitalRead( PROTONGUN_ACTIVATE_PACK_SWITCH ))
    this->on();
  else
   this->off();
}


//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//On
void PowerCell::on()
{
  this->etat = true;

  #ifdef PROTON_DEBUG
    Serial.println(F("PowerCell ON"));
  #endif
}


//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Off
void PowerCell::off()
{
  this->etat = false;
  this->compte = 0;

  #ifdef PROTON_DEBUG
    Serial.println(F("PowerCell OFF"));
  #endif
}


//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Switch
void PowerCell::activeSwitch()
{
  if(this->etat)
    this->off();
  else
    this->on();
}


//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Update PowerCell
void PowerCell::next( void (*callback)() )
{
  if(!this->etat)
    return;
    
  //Set LED
  this->setLed( 1,  POWERCELL_01 );
  this->setLed( 2,  POWERCELL_02 );
  this->setLed( 3,  POWERCELL_03 );
  this->setLed( 4,  POWERCELL_04 );
  this->setLed( 5,  POWERCELL_05 );
  this->setLed( 6,  POWERCELL_06 );
  this->setLed( 7,  POWERCELL_07 );
  this->setLed( 8,  POWERCELL_08 );
  this->setLed( 9,  POWERCELL_09 );
  this->setLed( 10, POWERCELL_10 );
  this->setLed( 11, POWERCELL_11 );
  this->setLed( 12, POWERCELL_12 );
  this->setLed( 13, POWERCELL_13 );
  this->setLed( 14, POWERCELL_14 );
  this->setLed( 15, POWERCELL_15 );
  
  //update compteur
  if( !this->addCompte() )
  {
    //compteur ce reset
    (*callback)();
  }
}


//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Set Led Arduino
void PowerCell::setLed( unsigned char posi, int led )
{
  if( this->compte >= posi )
    digitalWrite( led, HIGH );
  else
    digitalWrite( led, LOW );
}


//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Add Compte ( renvoi false lors ce que le compteur ce reset
bool PowerCell::addCompte()
{
  this->compte++;
  if(this->compte>15)
  {
    this->compte = 1;
    return false;
  }
  return true;
}

