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
  pinMode( PROTONGUN_PLASMA          , OUTPUT );

  //Switch
  pinMode( PROTONGUN_ACTIVATE_GUN_SWITCH , INPUT );
  pinMode( PROTONGUN_ACTIVATE_PACK_SWITCH, INPUT );
  pinMode( PROTONGUN_ACTIVATE_SWITCH     , INPUT );
  pinMode( PROTONGUN_INTENSITY_BUTTON    , INPUT );
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
  pinMode( PROTONGUN_BARREL_11, OUTPUT );
  pinMode( PROTONGUN_BARREL_12, OUTPUT );
  pinMode( PROTONGUN_BARREL_13, OUTPUT );
  pinMode( PROTONGUN_BARREL_14, OUTPUT );
  pinMode( PROTONGUN_BARREL_15, OUTPUT );
  pinMode( PROTONGUN_BARREL_16, OUTPUT );
  pinMode( PROTONGUN_BARREL_17, OUTPUT );
  pinMode( PROTONGUN_BARREL_18, OUTPUT );
  pinMode( PROTONGUN_BARREL_19, OUTPUT );
  pinMode( PROTONGUN_BARREL_20, OUTPUT );

  
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
void ProtonGun::next()
{
  if(!this->etat)
    return;

   //TODO
   if(switchCligLight)
    digitalWrite( PROTONGUN_ORANGEGUN_STATIC, LOW );
   else
    digitalWrite( PROTONGUN_ORANGEGUN_STATIC, HIGH );

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
  this->setBarrelLed( 11, PROTONGUN_BARREL_11 );
  this->setBarrelLed( 12, PROTONGUN_BARREL_12 );
  this->setBarrelLed( 13, PROTONGUN_BARREL_13 );
  this->setBarrelLed( 14, PROTONGUN_BARREL_14 );
  this->setBarrelLed( 15, PROTONGUN_BARREL_15 );
  this->setBarrelLed( 16, PROTONGUN_BARREL_16 );
  this->setBarrelLed( 17, PROTONGUN_BARREL_17 );
  this->setBarrelLed( 18, PROTONGUN_BARREL_18 );
  this->setBarrelLed( 19, PROTONGUN_BARREL_19 );
  this->setBarrelLed( 20, PROTONGUN_BARREL_20 );
   
   this->barrel_compte++;
   if(this->barrel_compte >= PROTONGUN_BARREL_MAX)
    this->barrel_compte = PROTONGUN_BARREL_MIN;
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
void ProtonGun::ventSwitch()
{
  if(this->etatVent)
  {
    #ifdef PROTON_DEBUG
      Serial.println(F("Vent OFF"));
    #endif
    this->etatVent = false;
    digitalWrite( PROTONGUN_VENTLED, LOW );
  }
  else
  {
    #ifdef PROTON_DEBUG
      Serial.println(F("Vent ON"));
    #endif
    this->etatVent = true;
    digitalWrite( PROTONGUN_VENTLED, HIGH );
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
    this->onTir();
  else
    this->offTir();
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
    digitalWrite( PROTONGUN_PLASMA, HIGH );
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
    
    #ifdef PROTON_DEBUG
      Serial.println(F("Tir OFF"));
    #endif

   this->etatTir = false;
   digitalWrite( PROTONGUN_PLASMA, LOW );
}
