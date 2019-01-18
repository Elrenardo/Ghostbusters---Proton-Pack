#include "fumee.h"


//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Constructeur
Fumee::Fumee()
{
  pinMode( FUMEE_01  , OUTPUT );
  pinMode( FUMEE_VENT, OUTPUT );
}


//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Activer Fumé
void Fumee::on()
{
  this->etat  = false;
  this->start = millis();
  digitalWrite( FUMEE_01, HIGH );
  digitalWrite( FUMEE_VENT, LOW );
}


//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Desactiver Fumé
void Fumee::off()
{
  this->etat = false;
  digitalWrite( FUMEE_01, LOW );

  this->vent = millis();
  digitalWrite( FUMEE_VENT, HIGH );
}


//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//-------------------------------------------------------
//Switch fumée
void Fumee::fumeeSwitch()
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
void Fumee::verifAllFrame()
{
  unsigned long t = this->start + FUMEE_MAX_ON;
  unsigned long actu = millis();

  //Si le temps est dépassé, on coupe la fumée pour eviter de griller la cigarette electronique
  if( actu > t )
  {
    this->off();
    this->etat = true; //Special pour eviter bug avec le switch
  }

  //Coupage mode vent
  t = this->vent + FUMEE_VENT_ON;
  if( actu > t )
  {
    digitalWrite( FUMEE_VENT, LOW );
  }
}
