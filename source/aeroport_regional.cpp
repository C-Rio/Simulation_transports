/********BIBLIOTHEQUES********/

#include "aeroport_regional.h"


/********DEFINITION DES METHODES********/

AeroportRegional::AeroportRegional(std::string n, float lon, float lat) : Terminal(n, lon, lat)
{
	std::cout << "Creation AeroportRegional de " << get_nom() << std::endl;
}

AeroportRegional::~AeroportRegional(){}

unsigned int AeroportRegional::get_maxAeroport()
{
	return this->maxAeroport;
}

void AeroportRegional::add_liaison_avion(Ligne<Avion>* LA)
{
    if(LA->get_origine() == this)
    {
        if((get_nbLiaisons() < get_maxAeroport()) and (LA->get_destination()->get_nbLiaisons() < LA->get_destination()->get_maxAeroport()))
        {
            /*on crée la ligne d'avion électrique équivalente*/
            Ligne<AvionElectrique>* LAE = new Ligne<AvionElectrique>(LA->get_origine(), LA->get_destination());
            LAE->set_frequence(LA->get_frequence());
            LAE->set_tempsAttente(LA->get_tempsAttente());

            /*on ajoute les lignes dans le premier sens*/
            LA->get_origine()->add_ligne_avion(LA);
            LAE->get_origine()->add_ligne_avion_elec(LAE);

            /*on crée les lignes symétrique*/
            Ligne<Avion>* LA2 = new Ligne<Avion>(LA->get_destination(), LA->get_origine());
            Ligne<AvionElectrique>* LAE2 = new Ligne<AvionElectrique>(LAE->get_destination(), LAE->get_origine());

            /*on ajoute les lignes dans le second sens*/
            LA2->get_origine()->add_ligne_avion(LA2);
            LAE2->get_origine()->add_ligne_avion_elec(LAE2);
        }
        else
            std::cout << "Erreur: maximum de lignes déjà atteint\n";
    }
    else
        std::cout << "Erreur: add_liaison se fait sur l'origine\n";
}

void AeroportRegional::add_liaison_train(Ligne<Train>* LT){}

Gare* AeroportRegional::get_gare()
{
	return nullptr;
}
