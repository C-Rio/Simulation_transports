/********BIBLIOTHEQUES********/

#include "terminal.h"


/********DEFINITION DES METHODES********/

Terminal::Terminal(std::string str, float lon, float lat)
{
  this->nom = str;
  this->longitude = lon;
  this->latitude = lat;
  this->liaisonsTrain = std::vector<Ligne<Train>*>(0);
  this->liaisonsAvion = std::vector<Ligne<Avion>*>(0);
  this->liaisonsAvionElec = std::vector<Ligne<AvionElectrique>*>(0);
  this->flux = std::vector<flux_s*>(0);
}

Terminal::~Terminal()
{
  for(unsigned int i=0; i < this->liaisonsTrain.size(); i++)
    delete this->liaisonsTrain[i];

  for(unsigned int i=0; i < this->liaisonsAvion.size(); i++)
    delete this->liaisonsAvion[i];

  for(unsigned int i=0; i < this->liaisonsAvionElec.size(); i++)
    delete this->liaisonsAvionElec[i];

  for(unsigned int i=0; i < this->flux.size(); i++)
    delete this->flux[i];
}

std::string Terminal::get_nom() const
{
  return this->nom;
}

void Terminal::set_nom(std::string str)
{
  this->nom = str;
}

float Terminal::get_longitude() const
{
  return this->longitude;
}

void Terminal::set_longitude(float lon)
{
  this->longitude = lon;
}

float Terminal::get_latitude() const
{
  return this->latitude;
}

void Terminal::set_latitude(float lat)
{
  this->latitude = lat;
}

Ligne<Train>* Terminal::get_liaison_train(unsigned int i) const
{
    assert(i < this->liaisonsTrain.size());
    return this->liaisonsTrain[i];
}

Ligne<Avion>* Terminal::get_liaison_avion(unsigned int i) const
{
    assert(i < this->liaisonsAvion.size());
    return this->liaisonsAvion[i];
}

Ligne<AvionElectrique>* Terminal::get_liaison_avion_elec(unsigned int i) const
{
    assert(i < this->liaisonsAvionElec.size());
    return this->liaisonsAvionElec[i];
}

unsigned int Terminal::get_nbLiaisons() const
{
    return this->liaisonsAvion.size();
}

int Terminal::get_flux(Terminal * T) const
{
    for (unsigned int i=0; i < flux.size(); i++)
    {
      if (flux[i]->dest == T)
      {
        return flux[i]->passagers;
      }
    }
    return -1;
}

void Terminal::set_flux(Terminal* T, int passagers)
{
  bool b = false;

  /*on parcourt les flux existants*/
  for (unsigned int i=0; i < flux.size(); i++)
  {
    /*s'il existe, on le modifie*/
    if (flux[i]->dest == T)
    {
        b = true;
        flux[i]->passagers = passagers;
        break;
    }
  }
  /*sinon, on le crée*/
  if (b == false)
  {
      flux_s * f = new flux_s();
      f->dest = T;
      f->passagers = passagers;
      this->flux.push_back(f);
  }
}

void Terminal::add_ligne_train(Ligne<Train>* LT)
{
    this->liaisonsTrain.push_back(LT);
}

void Terminal::add_ligne_avion(Ligne<Avion>* LA)
{
    this->liaisonsAvion.push_back(LA);
}

void Terminal::add_ligne_avion_elec(Ligne<AvionElectrique>* LAE)
{
    this->liaisonsAvionElec.push_back(LAE);
}

float Terminal::distance(float lon, float lat)
{
  /*calcul de la circonférence de la Terre*/
  unsigned int CT = 2 * M_PI * RT;

  /*calcul de la distance d'un degré*/
  float degre = CT/360.0;

  lon -= this->get_longitude();
  lat -= this->get_latitude();

  return sqrt(pow(lon * degre, 2) + pow(lat * degre, 2));
}
