#include "protongun.h"


//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Constructeur
ProtonGun::ProtonGun()
{
  //Switch
  pinMode( PROTONGUN_ACTIVATE_GUN_SWITCH , INPUT );
  pinMode( PROTONGUN_ACTIVATE_PACK_SWITCH, INPUT );
  pinMode( PROTONGUN_INTENSITY_SWITCH    , INPUT );
  pinMode( PROTONGUN_ACTIVATE_BUTTON     , INPUT );
  pinMode( PROTONGUN_REDGUN_BUTTON       , INPUT );

  //Barrel
  pinMode( PROTONGUN_BARREL_01, OUTPUT );
  pinMode( PROTONGUN_BARREL_02, OUTPUT );
  pinMode( PROTONGUN_BARREL_03, OUTPUT );
  pinMode( PROTONGUN_BARREL_04, OUTPUT );
  pinMode( PROTONGUN_BARREL_05, OUTPUT );
  pinMode( PROTONGUN_BARREL_06, OUTPUT );
  pinMode( PROTONGUN_BARREL_07, OUTPUT );
  pinMode( PROTONGUN_BARREL_08, OUTPUT );
  pinMode( PROTONGUN_BARREL_09, OUTPUT );
  pinMode( PROTONGUN_BARREL_10, OUTPUT );

  //Test Barrel PIN
  /*digitalWrite( PROTONGUN_BARREL_01, LOW );
  digitalWrite( PROTONGUN_BARREL_02, LOW );
  digitalWrite( PROTONGUN_BARREL_03, LOW );
  digitalWrite( PROTONGUN_BARREL_04, LOW );
  digitalWrite( PROTONGUN_BARREL_05, LOW );
  digitalWrite( PROTONGUN_BARREL_06, LOW );
  digitalWrite( PROTONGUN_BARREL_07, LOW );
  digitalWrite( PROTONGUN_BARREL_08, LOW );
  digitalWrite( PROTONGUN_BARREL_09, LOW );
  digitalWrite( PROTONGUN_BARREL_10, HIGH );*/
}


//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//On
void ProtonGun::on()
{
  this->etat = true;
  
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

  //off barrel
  digitalWrite( PROTONGUN_BARREL_01, LOW );
  digitalWrite( PROTONGUN_BARREL_02, LOW );
  digitalWrite( PROTONGUN_BARREL_03, LOW );
  digitalWrite( PROTONGUN_BARREL_04, LOW );
  digitalWrite( PROTONGUN_BARREL_05, LOW );
  digitalWrite( PROTONGUN_BARREL_06, LOW );
  digitalWrite( PROTONGUN_BARREL_07, LOW );
  digitalWrite( PROTONGUN_BARREL_08, LOW );
  digitalWrite( PROTONGUN_BARREL_09, LOW );
  digitalWrite( PROTONGUN_BARREL_10, LOW );

  //ok clignotement
  digitalWrite( PROTONGUN_WHITELED_FLASHING, LOW );

  #ifdef PROTON_DEBUG
    Serial.println(F("ProtonGun OFF"));
  #endif
}


//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
void ProtonGun::updLedClign()
{
  if(!this->etat)
    return;

   //TODO
   if(switchCligLight)
    digitalWrite( PROTONGUN_WHITELED_FLASHING, LOW );
   else
    digitalWrite( PROTONGUN_WHITELED_FLASHING, HIGH );

    switchCligLight = !switchCligLight;
}


//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
void ProtonGun::nextBarrel()
{
  if(!this->etat)
    return;

  if( this->etatVent )
  {
      switch(this->barrel_compte)
      {
        case 0:
          digitalWrite( PROTONGUN_BARREL_01, HIGH );
          digitalWrite( PROTONGUN_BARREL_02, LOW );
          digitalWrite( PROTONGUN_BARREL_03, LOW );
          digitalWrite( PROTONGUN_BARREL_04, LOW );
          digitalWrite( PROTONGUN_BARREL_05, LOW );
          digitalWrite( PROTONGUN_BARREL_06, LOW );
          digitalWrite( PROTONGUN_BARREL_07, LOW );
          digitalWrite( PROTONGUN_BARREL_08, LOW );
          digitalWrite( PROTONGUN_BARREL_09, LOW );
          digitalWrite( PROTONGUN_BARREL_10, HIGH );
        break;
        case 1:
          digitalWrite( PROTONGUN_BARREL_01, LOW );
          digitalWrite( PROTONGUN_BARREL_02, HIGH );
          digitalWrite( PROTONGUN_BARREL_03, LOW );
          digitalWrite( PROTONGUN_BARREL_04, LOW );
          digitalWrite( PROTONGUN_BARREL_05, LOW );
          digitalWrite( PROTONGUN_BARREL_06, LOW );
          digitalWrite( PROTONGUN_BARREL_07, LOW );
          digitalWrite( PROTONGUN_BARREL_08, LOW );
          digitalWrite( PROTONGUN_BARREL_09, HIGH );
          digitalWrite( PROTONGUN_BARREL_10, LOW );
        break;
        case 2:
          digitalWrite( PROTONGUN_BARREL_01, LOW );
          digitalWrite( PROTONGUN_BARREL_02, LOW );
          digitalWrite( PROTONGUN_BARREL_03, HIGH );
          digitalWrite( PROTONGUN_BARREL_04, LOW );
          digitalWrite( PROTONGUN_BARREL_05, LOW );
          digitalWrite( PROTONGUN_BARREL_06, LOW );
          digitalWrite( PROTONGUN_BARREL_07, LOW );
          digitalWrite( PROTONGUN_BARREL_08, HIGH );
          digitalWrite( PROTONGUN_BARREL_09, LOW );
          digitalWrite( PROTONGUN_BARREL_10, LOW );
        break;
        case 3:
          digitalWrite( PROTONGUN_BARREL_01, LOW );
          digitalWrite( PROTONGUN_BARREL_02, LOW );
          digitalWrite( PROTONGUN_BARREL_03, LOW );
          digitalWrite( PROTONGUN_BARREL_04, HIGH );
          digitalWrite( PROTONGUN_BARREL_05, LOW );
          digitalWrite( PROTONGUN_BARREL_06, LOW );
          digitalWrite( PROTONGUN_BARREL_07, HIGH );
          digitalWrite( PROTONGUN_BARREL_08, LOW );
          digitalWrite( PROTONGUN_BARREL_09, LOW );
          digitalWrite( PROTONGUN_BARREL_10, LOW );
        break;
        case 4:
          digitalWrite( PROTONGUN_BARREL_01, LOW );
          digitalWrite( PROTONGUN_BARREL_02, LOW );
          digitalWrite( PROTONGUN_BARREL_03, LOW );
          digitalWrite( PROTONGUN_BARREL_04, LOW );
          digitalWrite( PROTONGUN_BARREL_05, HIGH );
          digitalWrite( PROTONGUN_BARREL_06, HIGH );
          digitalWrite( PROTONGUN_BARREL_07, LOW );
          digitalWrite( PROTONGUN_BARREL_08, LOW );
          digitalWrite( PROTONGUN_BARREL_09, LOW );
          digitalWrite( PROTONGUN_BARREL_10, LOW );
        break;
        case 5:
          digitalWrite( PROTONGUN_BARREL_01, LOW );
          digitalWrite( PROTONGUN_BARREL_02, LOW );
          digitalWrite( PROTONGUN_BARREL_03, LOW );
          digitalWrite( PROTONGUN_BARREL_04, LOW );
          digitalWrite( PROTONGUN_BARREL_05, LOW );
          digitalWrite( PROTONGUN_BARREL_06, LOW );
          digitalWrite( PROTONGUN_BARREL_07, LOW );
          digitalWrite( PROTONGUN_BARREL_08, LOW );
          digitalWrite( PROTONGUN_BARREL_09, LOW );
          digitalWrite( PROTONGUN_BARREL_10, LOW );

          //Reset
          this->barrel_compte = 0;
        break;
      }

      this->barrel_compte++;
  }
  else
  {
    //Serial.println(F("UPD"));
    
    //Set Barrel LED
    this->setBarrelLed( 1,  PROTONGUN_BARREL_01 );
    this->setBarrelLed( 2,  PROTONGUN_BARREL_02 );
    this->setBarrelLed( 3,  PROTONGUN_BARREL_03 );
    this->setBarrelLed( 4,  PROTONGUN_BARREL_04 );
    this->setBarrelLed( 5,  PROTONGUN_BARREL_05 );
    this->setBarrelLed( 6,  PROTONGUN_BARREL_06 );
    this->setBarrelLed( 7,  PROTONGUN_BARREL_07 );
    this->setBarrelLed( 8,  PROTONGUN_BARREL_08 );
    this->setBarrelLed( 9,  PROTONGUN_BARREL_09 );
    this->setBarrelLed( 10, PROTONGUN_BARREL_10 );
     
    this->barrel_compte++;
    if(this->barrel_compte >= PROTONGUN_BARREL_MAX+1 )
      this->barrel_compte = PROTONGUN_BARREL_MIN;
  }
}



//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Set Led Arduino
void ProtonGun::setBarrelLed( unsigned char posi, int led )
{
  //Limite ignore
  if(posi < PROTONGUN_BARREL_MIN )
    return;
  if(posi > PROTONGUN_BARREL_MAX )
    return;

  //Gestion Led
  if( this->barrel_compte >= posi )
    digitalWrite( led, HIGH );
  else
    digitalWrite( led, LOW );
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
boolean ProtonGun::ventSwitch()
{
  this->barrel_compte = 0;
  
  if(this->etatVent)
  {
    #ifdef PROTON_DEBUG
      Serial.println(F("Vent OFF"));
    #endif
    this->etatVent = false;
  }
  else
  {
    #ifdef PROTON_DEBUG
      Serial.println(F("Vent ON"));
    #endif
    this->etatVent = true;
  }
  return this->etatVent;
}



//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Switch Tir
boolean ProtonGun::tirSwitch()
{
  if(!this->etat)
    return false;
    
  if(this->etatTir)
    this->onTir();
  else
    this->offTir();

  return this->etatTir;
}

//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Activer Tir
void ProtonGun::onTir()
{
    if(!this->etat)
      return;
   
    #ifdef PROTON_DEBUG
      Serial.println(F("Tir ON"));
    #endif

    this->etatTir = true;
    this->barrel_compte = 0;
}

//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Arreter tir
void ProtonGun::offTir()
{
    if(!this->etat)
      return;

    digitalWrite( PROTONGUN_BARREL_01, LOW );
    digitalWrite( PROTONGUN_BARREL_02, LOW );
    digitalWrite( PROTONGUN_BARREL_03, LOW );
    digitalWrite( PROTONGUN_BARREL_04, LOW );
    digitalWrite( PROTONGUN_BARREL_05, LOW );
    digitalWrite( PROTONGUN_BARREL_06, LOW );
    digitalWrite( PROTONGUN_BARREL_07, LOW );
    digitalWrite( PROTONGUN_BARREL_08, LOW );
    digitalWrite( PROTONGUN_BARREL_09, LOW );
    digitalWrite( PROTONGUN_BARREL_10, LOW );
    
    #ifdef PROTON_DEBUG
      Serial.println(F("Tir OFF"));
    #endif

   this->etatTir = false;
}
