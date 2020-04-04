#ifndef __GARE_H__
#define __GARE_H__

/********BIBLIOTHEQUES********/

#include "terminal.h"


/********CLASSES********/

class Gare : public Terminal
{
	public:

		Gare(std::string n, float lon, float lat);
		~Gare();

		void add_liaison_train(Ligne<Train>* LT) override;
		void add_liaison_avion(Ligne<Avion>* LA) override;
		unsigned int get_maxAeroport() override;
        Gare* get_gare() override;
};

#endif
