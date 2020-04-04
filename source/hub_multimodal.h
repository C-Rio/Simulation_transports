#ifndef __HUB_MULTIMODAL_H__
#define __HUB_MULTIMODAL_H__

/********BIBLIOTHEQUES********/

#include "hub_aeroport.h"
#include "gare.h"


/********CLASSES********/

class HubMultimodal : public HubAeroport
{
	protected:
		Gare* gare;

	public:
		HubMultimodal(std::string, float, float);
		~HubMultimodal();

		Gare* get_gare() override;
		void add_liaison_train(Ligne<Train>* LT) override;
};

#endif
