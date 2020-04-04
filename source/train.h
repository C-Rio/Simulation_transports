#ifndef __TRAIN_H__
#define __TRAIN_H__

/********BIBLIOTHEQUES********/

#include <iostream>


/********CLASSES********/

class Train
{
  protected :
      static const int capacite = 1000;
      static constexpr float vitesse = 250;
      static constexpr float empreinte = 1.5;

  public :
    Train();
    ~Train();
    int get_capacite() const;
    float get_vitesse() const;
    float get_empreinte() const;

};

#endif
