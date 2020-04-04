#ifndef __HUB_AEROPORT_H__
#define __HUB_AEROPORT_H__

/********BIBLIOTHEQUES********/

#include "terminal.h"


/********CLASSES********/

class HubAeroport : public Terminal
{
protected:
		const int maxAeroport = 12;

	public:
		HubAeroport(std::string n, float lon, float lat);
		~HubAeroport();

		unsigned int get_maxAeroport() override;
		void add_liaison_avion(Ligne<Avion>* LA) override;
		void add_liaison_train(Ligne<Train>* LT) override;
		Gare* get_gare() override;
};

#endif
