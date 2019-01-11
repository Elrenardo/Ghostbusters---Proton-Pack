#include "protongun.h"


//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Constructeur
ProtonGun::ProtonGun()
{
  this->etat = true;
  this->etatTir = false;
  
  //Led Fixe
  pinMode( PROTONGUN_REDLED_STATIC   , OUTPUT );
  pinMode( PROTONGUN_ORANGELED_STATIC, OUTPUT );
  pinMode( PROTONGUN_ORANGEGUN_STATIC, OUTPUT );
  pinMode( PROTONGUN_VENTLED         , OUTPUT );
  
  this->etatVent = true;
  digitalWrite( PROTONGUN_VENTLED, HIGH );

  this->on();
}


//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//On
void ProtonGun::on()
{
  this->etat = true;

  digitalWrite( PROTONGUN_REDLED_STATIC   , HIGH );
  digitalWrite( PROTONGUN_ORANGELED_STATIC, HIGH );
  digitalWrite( PROTONGUN_ORANGEGUN_STATIC, HIGH );

  #ifdef PROTON_DEBUG
    Serial.println(F("ProtonGun ON"));
  #endif
}


//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Off
void ProtonGun::off()
{
  this->etat = false;

  digitalWrite( PROTONGUN_REDLED_STATIC   , LOW );
  digitalWrite( PROTONGUN_ORANGELED_STATIC, LOW );
  digitalWrite( PROTONGUN_ORANGEGUN_STATIC, LOW );

  #ifdef PROTON_DEBUG
    Serial.println(F("ProtonGun OFF"));
  #endif
}


//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Off
void ProtonGun::next()
{
  if(!this->etat)
    return;

   //TODO
   //Led clignotante
}


//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Switch main
void ProtonGun::activeSwitch()
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
//Switch vent
void ProtonGun::ventSwitch()
{
  if(this->etatVent)
  {
    this->etatVent = false;
    digitalWrite( PROTONGUN_VENTLED, LOW );
    
    #ifdef PROTON_DEBUG
      Serial.println(F("Vent OFF"));
    #endif
  }
  else
  {
    this->etatVent = true;
    digitalWrite( PROTONGUN_VENTLED, HIGH );

    #ifdef PROTON_DEBUG
      Serial.println(F("Vent ON"));
    #endif
  }
}



//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Switch Tir
void ProtonGun::tirSwitch()
{
  if(!this->etat)
    return;
    
  if(this->etatTir)
  {
    
  }
  else
  {
    
  }
}

