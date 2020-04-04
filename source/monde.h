#ifndef __MONDE_H__
#define __MONDE_H__

/********BIBLIOTHEQUES********/

#include "voyage.h"
#include "hub_multimodal.h"
#include "aeroport_international.h"
#include "aeroport_regional.h"


/********CONSTANTES********/

#define PAR 0
#define ROM 1
#define LYO 2
#define BRU 3
#define NAP 4


/********CLASSES********/

class Monde
{
    protected :

        Terminal* T[5];
        Voyage* V[20];

    public :

        Monde();
        ~Monde();

        Terminal* get_term(unsigned int i) const;
        Voyage* get_voy(unsigned int i) const;

        /*initialise les flux de passagers entre terminaux*/
        void init_flux();

        /*switch sur s pour créer le bon scenario*/
        /*initialise les terminaux et les lignes*/
        void scenario(unsigned int s);
};

#endif
