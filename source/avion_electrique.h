#ifndef __AVION_ELECTRIQUE_H__
#define __AVION_ELECTRIQUE_H__

/********BIBLIOTHEQUES********/

#include <iostream>


/********CLASSES********/

class AvionElectrique
{
  protected :
      static const int capacite = 100;
      static constexpr float vitesse = 400;
      static constexpr float empreinte = 6;

  public :
    AvionElectrique();
    ~AvionElectrique();
    int get_capacite() const;
    float get_vitesse() const;
    float get_empreinte() const;


};




#endif
