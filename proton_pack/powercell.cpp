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

  //For testing PIN
  /*digitalWrite( POWERCELL_01, LOW );
  digitalWrite( POWERCELL_02, LOW );
  digitalWrite( POWERCELL_03, LOW );
  digitalWrite( POWERCELL_04, LOW );
  digitalWrite( POWERCELL_05, LOW );
  digitalWrite( POWERCELL_06, LOW );
  digitalWrite( POWERCELL_07, LOW );
  digitalWrite( POWERCELL_08, LOW );
  digitalWrite( POWERCELL_09, LOW );
  digitalWrite( POWERCELL_10, LOW );
  digitalWrite( POWERCELL_11, LOW );
  digitalWrite( POWERCELL_12, HIGH );*/
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

  digitalWrite( POWERCELL_01, LOW );
  digitalWrite( POWERCELL_02, LOW );
  digitalWrite( POWERCELL_03, LOW );
  digitalWrite( POWERCELL_04, LOW );
  digitalWrite( POWERCELL_05, LOW );
  digitalWrite( POWERCELL_06, LOW );
  digitalWrite( POWERCELL_07, LOW );
  digitalWrite( POWERCELL_08, LOW );
  digitalWrite( POWERCELL_09, LOW );
  digitalWrite( POWERCELL_10, LOW );
  digitalWrite( POWERCELL_11, LOW );
  digitalWrite( POWERCELL_12, LOW );

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
void PowerCell::next( void (*callback)(), boolean tir )
{
  if(!this->etat)
    return;

    /*if(tir)
    {
        digitalWrite( POWERCELL_01, LOW );
        digitalWrite( POWERCELL_02, LOW );
        digitalWrite( POWERCELL_03, LOW );
        digitalWrite( POWERCELL_04, LOW );
        digitalWrite( POWERCELL_05, LOW );
        digitalWrite( POWERCELL_06, LOW );
        digitalWrite( POWERCELL_07, LOW );
        digitalWrite( POWERCELL_08, LOW );
        digitalWrite( POWERCELL_09, LOW );
        digitalWrite( POWERCELL_10, LOW );
        digitalWrite( POWERCELL_11, LOW );
        digitalWrite( POWERCELL_12, LOW );
        
        this->compte = 0;
      return;
    }*/

  //Set LED
  this->setLed( 1,  POWERCELL_01, tir );
  this->setLed( 2,  POWERCELL_02, tir );
  this->setLed( 3,  POWERCELL_03, tir );
  this->setLed( 4,  POWERCELL_04, tir );
  this->setLed( 5,  POWERCELL_05, tir );
  this->setLed( 6,  POWERCELL_06, tir );
  this->setLed( 7,  POWERCELL_07, tir );
  this->setLed( 8,  POWERCELL_08, tir );
  this->setLed( 9,  POWERCELL_09, tir );
  this->setLed( 10, POWERCELL_10, tir );
  this->setLed( 11, POWERCELL_11, tir );
  this->setLed( 12, POWERCELL_12, tir );
  
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
void PowerCell::setLed( unsigned char posi, int led, boolean tir )
{
  //Mode tir
  if(tir)
  {
    if( this->compte == posi )
      digitalWrite( led, HIGH );
    else
      digitalWrite( led, LOW );
  }
  //Mode chargeur
  else
  {
    if( this->compte >= posi )
      digitalWrite( led, HIGH );
    else
      digitalWrite( led, LOW );
  }
}


//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Add Compte ( renvoi false lors ce que le compteur ce reset
bool PowerCell::addCompte()
{
  this->compte++;
  
  if(this->compte>12)
  {
    this->compte = 1;
    return false;
  }
  return true;
}
