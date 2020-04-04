/********BIBLIOTHEQUES********/

#include "avion.h"


/********DEFINITION DES METHODES********/

Avion::Avion(){}

Avion::~Avion(){}

int Avion::get_capacite() const
{
  return this->capacite;
}

float Avion::get_vitesse() const
{
  return this->vitesse;
}

float Avion::get_empreinte() const
{
  return this->empreinte;
}
