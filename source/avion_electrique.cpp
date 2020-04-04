/********BIBLIOTHEQUES********/

#include "avion_electrique.h"


/********DEFINITION DES METHODES********/

AvionElectrique::AvionElectrique(){}

AvionElectrique::~AvionElectrique(){}

int AvionElectrique::get_capacite() const
{
  return this->capacite;
}

float AvionElectrique::get_vitesse() const
{
  return this->vitesse;
}

float AvionElectrique::get_empreinte() const
{
  return this->empreinte;
}
