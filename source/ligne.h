#ifndef __LIGNE_H__
#define __LIGNE_H__


/********BIBLIOTHEQUES********/

#include "train.h"
#include "avion_electrique.h"
#include "avion.h"


/********CLASSES********/

class Terminal;

template <class T>
class Ligne
{
  protected :

    Terminal* origine;
    Terminal* destination;
    unsigned int frequence;
    unsigned int tempsAttente;
    T mt;

  public :

    Ligne(Terminal* orig, Terminal* dest)
    {
      origine = orig;
      destination = dest;
      frequence = 0;
      tempsAttente = 0;
      mt = T();
    }

    ~Ligne(){}

    Terminal* get_origine() const
    {
        return this->origine;
    }

    void set_origine(const Terminal* orig)
    {
        this->origine = orig;
    }

    Terminal* get_destination() const
    {
        return this->destination;
    }

    void set_destination(const Terminal* dest)
    {
        this->destination = dest;
    }

    unsigned int get_frequence() const
    {
        return this->frequence;
    }

    void set_frequence(unsigned int freq)
    {
        this->frequence = freq;
    }

    unsigned int get_tempsAttente() const
    {
        return this->tempsAttente;
    }

    void set_tempsAttente(unsigned int tps)
    {
        this->tempsAttente = tps;
    }

    T get_mt() const
    {
        return this->mt;
    }

    void set_mt(const T& transport)
    {
        this->mt = transport;
    }
};

#endif
