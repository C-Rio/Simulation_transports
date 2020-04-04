/********BIBLIOTHEQUES********/

#include "gare.h"


/********DEFINITION DES METHODES********/

Gare::Gare(std::string n, float lon, float lat) : Terminal(n, lon, lat)
{
	std::cout << "Creation Gare de " << get_nom() << std::endl;
}

Gare::~Gare(){}

void Gare::add_liaison_train(Ligne<Train>* LT)
{
    if(LT->get_origine() == this)
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

void Gare::add_liaison_avion(Ligne<Avion>* LA){}

unsigned int Gare::get_maxAeroport()
{
    return 0;
}

Gare* Gare::get_gare()
{
	return nullptr;
}
