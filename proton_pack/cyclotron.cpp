#include "cyclotron.h"

//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Constructeur
Cyclotron::Cyclotron()
{
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

  //Ne pas mettre dans resetLight, ca cause un souci !
  analogWrite( CYCLOTRON_1 ,0);
  analogWrite( CYCLOTRON_2 ,0);
  analogWrite( CYCLOTRON_3 ,0);
  analogWrite( CYCLOTRON_4 ,0);

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
      analogWrite( CYCLOTRON_1 ,1024);
      analogWrite( CYCLOTRON_2 ,0);
      analogWrite( CYCLOTRON_3 ,0);
      analogWrite( CYCLOTRON_4 ,0);
    break;
    
    case 1:
      analogWrite( CYCLOTRON_1 ,0);
      analogWrite( CYCLOTRON_2 ,1024);
      analogWrite( CYCLOTRON_3 ,0);
      analogWrite( CYCLOTRON_4 ,0);
    break;
    
    case 2:
      analogWrite( CYCLOTRON_1 ,0);
      analogWrite( CYCLOTRON_2 ,0);
      analogWrite( CYCLOTRON_3 ,1024);
      analogWrite( CYCLOTRON_4 ,0);
    break;
    
    case 3:
      analogWrite( CYCLOTRON_1 ,0);
      analogWrite( CYCLOTRON_2 ,0);
      analogWrite( CYCLOTRON_3 ,0);
      analogWrite( CYCLOTRON_4 ,1024);
    break;
  }

  /*#ifdef PROTON_DEBUG
    Serial.println("Cyclotron light: "+this->compte);
  #endif*/

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
