/********BIBLIOTHEQUES********/

#include "train.h"


/********DEFINITION DES METHODES********/

Train::Train(){}

Train::~Train(){}

int Train::get_capacite() const
{
  return this->capacite;
}

float Train::get_vitesse() const
{
  return this->vitesse;
}

float Train::get_empreinte() const
{
  return this->empreinte;
}
