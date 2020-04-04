#ifndef __AEROPORT_INTERNATIONAL_H__
#define __AEROPORT_INTERNATIONAL_H__

/********BIBLIOTHEQUES********/

#include "terminal.h"


/********CLASSES********/

class AeroportInternational : public Terminal
{
	protected:
		const int maxAeroport = 4;

	public:
		AeroportInternational(std::string n, float lon, float lat);
		~AeroportInternational();

		unsigned int get_maxAeroport() override;
		void add_liaison_avion(Ligne<Avion>* LA) override;
		void add_liaison_train(Ligne<Train>* LT) override;
		Gare* get_gare() override;
};

#endif
