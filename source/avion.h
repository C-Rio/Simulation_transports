#ifndef __AVION_H__
#define __AVION_H__

/********BIBLIOTHEQUES********/

#include <iostream>


/********CLASSES********/

class Avion
{
  protected :
      static const int capacite = 150;
      static constexpr float vitesse = 700;
      static constexpr float empreinte = 18;

  public :
    Avion();
    ~Avion();
    int get_capacite() const;
    float get_vitesse() const;
    float get_empreinte() const;

};

#endif
