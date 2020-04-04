#ifndef __VOYAGE_H__
#define __VOYAGE_H__


/********BIBLIOTHEQUES********/

#include <type_traits>
#include "terminal.h"


/********CONSTANTES********/

#define TRAIN 0
#define AVION 1
#define AVION_ELECTRIQUE 2


/********STRUCTURES********/

struct correspondances
{
    std::vector<Ligne<Train>*> lignesTrain;
    int indiceTrain = 0;
    std::vector<Ligne<Avion>*> lignesAvion;
    int indiceAvion = 0;
    std::vector<Ligne<AvionElectrique>*> lignesAvionElec;
    int indiceAvionElec = 0;
    std::vector<unsigned int> ordre;
};


/********CLASSES********/

class Voyage
{
  protected :

    Terminal * origine;
    Terminal * destination;
    correspondances cor;

  public:

    Voyage(Terminal *, Terminal *);
    ~Voyage();

    Terminal * get_origine() const;
    Terminal * get_destination() const;
    unsigned int get_nbCor() const;

    void set_origine(Terminal*);
    void set_destination(Terminal*);

    void calcul(unsigned int nbPassagers);
    void affiche(float temps, float carbone);
    void reset();

    template <class type> void ajouter_ligne(type L)
    {
      if (std::is_same<type, Ligne<Train>*>::value)
      {
          this->cor.lignesTrain.push_back((Ligne<Train>*)L);
          this->cor.ordre.push_back(TRAIN);
      }

      else if (std::is_same<type, Ligne<Avion>*>::value)
      {
          this->cor.lignesAvion.push_back((Ligne<Avion>*)L);
          this->cor.ordre.push_back(AVION);
      }

      else if (std::is_same<type, Ligne<AvionElectrique>*>::value)
      {
          this->cor.lignesAvionElec.push_back((Ligne<AvionElectrique>*)L);
          this->cor.ordre.push_back(AVION_ELECTRIQUE);
      }
    }
};

#endif
