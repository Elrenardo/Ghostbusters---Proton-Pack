#include "protongun.h"


//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Constructeur
ProtonGun::ProtonGun()
{
  //Led Fixe
  pinMode( PROTONGUN_REDLED_STATIC   , OUTPUT );
  pinMode( PROTONGUN_ORANGELED_STATIC, OUTPUT );
  pinMode( PROTONGUN_ORANGEGUN_STATIC, OUTPUT );
  pinMode( PROTONGUN_VENTLED         , OUTPUT );

  //Switch
  pinMode( PROTONGUN_ACTIVATE_GUN_SWITCH , INPUT );
  pinMode( PROTONGUN_ACTIVATE_PACK_SWITCH, INPUT );
  pinMode( PROTONGUN_ACTIVATE_SWITCH     , INPUT );
  pinMode( PROTONGUN_INTENSITY_BUTTON    , INPUT );
  pinMode( PROTONGUN_REDGUN_BUTTON       , INPUT );
  

  //Init Vent
  if(digitalRead( PROTONGUN_ACTIVATE_PACK_SWITCH ))
  {
    this->etatVent = true;
    digitalWrite( PROTONGUN_VENTLED, HIGH );
  }
  else
  {
    this->etatVent = false;
    digitalWrite( PROTONGUN_VENTLED, LOW );
  }


  //Init Gun
  if(digitalRead( PROTONGUN_ACTIVATE_GUN_SWITCH ))
    this->on();
  else
    this->off();
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

