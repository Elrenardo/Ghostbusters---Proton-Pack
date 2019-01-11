#include "cyclotron.h"

//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Constructeur
Cyclotron::Cyclotron()
{
  //Desactiver le cyclotron
  this->etat = false;
  
  //reset led
  this->resetLight();

  //Activation
  this->on();
}



//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//On
void Cyclotron::on()
{
  this->etat = true;

  #ifdef PROTON_DEBUG
    Serial.println(F("Cyclotron ON"));
  #endif
}


//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Off
void Cyclotron::off()
{
  this->etat = false;
  this->resetLight();

  #ifdef PROTON_DEBUG
    Serial.println(F("Cyclotron OFF"));
  #endif
}


//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Switch
void Cyclotron::activeSwitch()
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
//Lumiére suivante
void Cyclotron::next()
{
  if( !this->etat )
    return;

  switch(this->compte)
  {
    case 0:
      digitalWrite( CYCLOTRON_1 ,HIGH);
      digitalWrite( CYCLOTRON_2 ,LOW);
      digitalWrite( CYCLOTRON_3 ,LOW);
      digitalWrite( CYCLOTRON_4 ,LOW);
    break;
    
    case 1:
      digitalWrite( CYCLOTRON_1 ,LOW);
      digitalWrite( CYCLOTRON_2 ,HIGH);
      digitalWrite( CYCLOTRON_3 ,LOW);
      digitalWrite( CYCLOTRON_4 ,LOW);
    break;
    
    case 2:
      digitalWrite( CYCLOTRON_1 ,LOW);
      digitalWrite( CYCLOTRON_2 ,LOW);
      digitalWrite( CYCLOTRON_3 ,HIGH);
      digitalWrite( CYCLOTRON_4 ,LOW);
    break;
    
    case 3:
      digitalWrite( CYCLOTRON_1 ,LOW);
      digitalWrite( CYCLOTRON_2 ,LOW);
      digitalWrite( CYCLOTRON_3 ,LOW);
      digitalWrite( CYCLOTRON_4 ,HIGH);
    break;
  }

  #ifdef PROTON_DEBUG
    Serial.println("Cyclotron light: "+this->compte);
  #endif

  //incrémente
  this->compte++;

  //Si on dépasse le max on reset
  if(this->compte == 4 )
    this->resetLight();
}



//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Reset Lumiére
void Cyclotron::resetLight()
{
  this->compte = 0;
}



