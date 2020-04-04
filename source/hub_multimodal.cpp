/********BIBLIOTHEQUES********/

#include "hub_multimodal.h"


/********DEFINITION DES METHODES********/

HubMultimodal::HubMultimodal(std::string n, float lon, float lat) : HubAeroport(n, lon, lat)
{
    gare = new Gare(n, lon, lat);
	std::cout << "Creation HubMultimodal de " << get_nom() << std::endl;
}

HubMultimodal::~HubMultimodal(){}

Gare* HubMultimodal::get_gare()
{
	return this->gare;
}

void HubMultimodal::add_liaison_train(Ligne<Train>* LT)
{
    if(LT->get_origine() == this->get_gare())
    {
        /*on ajoute la ligne dans le premier sens*/
        LT->get_origine()->add_ligne_train(LT);

        /*on crée la ligne symétrique*/
        Ligne<Train>* LT2 = new Ligne<Train>(LT->get_destination(), LT->get_origine());

        /*on ajoute la ligne dans le second sens*/
        LT2->get_origine()->add_ligne_train(LT2);
    }
    else
        std::cout << "Erreur: add_liaison se fait sur l'origine\n";
}
