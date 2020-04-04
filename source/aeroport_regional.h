#ifndef __AEROPORT_REGIONAL_H__
#define __AEROPORT_REGIONAL_H__

/********BIBLIOTHEQUES********/

#include "terminal.h"


/********CLASSES********/

class AeroportRegional : public Terminal
{
	protected:
		const int maxAeroport = 1;

	public:
		AeroportRegional(std::string n, float lon, float lat);
		~AeroportRegional();

		unsigned int get_maxAeroport() override;
		void add_liaison_avion(Ligne<Avion>* LA) override;
		void add_liaison_train(Ligne<Train>* LT) override;
		Gare* get_gare() override;
};

#endif
