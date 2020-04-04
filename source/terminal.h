#ifndef __TERMINAL_H__
#define __TERMINAL_H__

/********BIBLIOTHEQUES********/

#include <iostream>
#include <vector>
#include <assert.h>

#define _USE_MATH_DEFINES
#include <cmath>

#include "ligne.h"


/********CONSTANTES********/

#define RT 6378


/********STRUCTURES********/

struct flux_s
{
  int passagers;
  class Terminal * dest;
};


/********CLASSES********/

class Gare;

class Terminal
{
  protected :

    std::string nom;
    float longitude;
    float latitude;
    std::vector<Ligne<Train>*> liaisonsTrain;
    std::vector<Ligne<Avion>*> liaisonsAvion;
    std::vector<Ligne<AvionElectrique>*> liaisonsAvionElec;
    std::vector<flux_s*> flux;

  public :

    // Constructeur & Destructeur
    Terminal(std::string str, float lon, float lat);
    ~Terminal();

    // Getters & Setters
    std::string get_nom() const;
    void set_nom(std::string str);

    float get_longitude() const;
    void set_longitude(float lon);

    float get_latitude() const;
    void set_latitude(float lat);

    Ligne<Train>* get_liaison_train(unsigned int i) const;
    Ligne<Avion>* get_liaison_avion(unsigned int i) const;
    Ligne<AvionElectrique>* get_liaison_avion_elec(unsigned int i) const;

    unsigned int get_nbLiaisons() const;
    virtual unsigned int get_maxAeroport()=0;

    int get_flux(Terminal* T) const;
    void set_flux(Terminal* T, int passagers);

    virtual Gare* get_gare()=0;

    // Autres méthodes
    virtual void add_liaison_train(Ligne<Train>* LT)=0;
    virtual void add_liaison_avion(Ligne<Avion>* LA)=0;

    void add_ligne_train(Ligne<Train>* LT);
    void add_ligne_avion(Ligne<Avion>* LA);
    void add_ligne_avion_elec(Ligne<AvionElectrique>* LAE);

    float distance(float lon, float lat);

};

#endif
