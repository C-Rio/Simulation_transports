/********BIBLIOTHEQUES********/

#include "monde.h"


/********DEFINITION DES METHODES********/

Monde::Monde()
{
    for(unsigned int i=0; i<5; i++)
        T[i] = nullptr;
    for(unsigned int i=0; i<20; i++)
        V[i] = nullptr;
}

Monde::~Monde(){}

Terminal* Monde::get_term(unsigned int i) const
{
    assert(i < 5);
    return this->T[i];
}

Voyage* Monde::get_voy(unsigned int i) const
{
    assert(i < 20);
    return this->V[i];
}

void Monde::init_flux()
{
    T[PAR]->set_flux(T[ROM], 10000);
    T[PAR]->set_flux(T[LYO], 18000);
    T[PAR]->set_flux(T[BRU], 12500);
    T[PAR]->set_flux(T[NAP], 4000);

    T[ROM]->set_flux(T[PAR], 9000);
    T[ROM]->set_flux(T[LYO], 6000);
    T[ROM]->set_flux(T[BRU], 5000);
    T[ROM]->set_flux(T[NAP], 11000);

    T[LYO]->set_flux(T[PAR], 19000);
    T[LYO]->set_flux(T[ROM], 6500);
    T[LYO]->set_flux(T[BRU], 6000);
    T[LYO]->set_flux(T[NAP], 2500);

    T[BRU]->set_flux(T[PAR], 13000);
    T[BRU]->set_flux(T[ROM], 4500);
    T[BRU]->set_flux(T[LYO], 5500);
    T[BRU]->set_flux(T[NAP], 2000);

    T[NAP]->set_flux(T[PAR], 5000);
    T[NAP]->set_flux(T[ROM], 10000);
    T[NAP]->set_flux(T[LYO], 3000);
    T[NAP]->set_flux(T[BRU], 2500);
}

void Monde::scenario(unsigned int s)
{
    switch(s)
    {
        default :
            std::cout << "Scenario vide" << std::endl;
            break;

        case 1 :
            T[PAR] = new HubAeroport("Paris", 2.3333, 48.8667);
            T[ROM] = new AeroportInternational("Rome", 12.5113, 41.8919);
            T[LYO] = new AeroportRegional("Lyon", 4.8500, 45.7500);
            T[BRU] = new AeroportRegional("Bruxelles", 4.3488, 50.8505);
            T[NAP] = new AeroportRegional("Naples", 14.2464, 40.8563);

            T[PAR]->add_liaison_avion(new Ligne<Avion>(T[PAR], T[ROM]));
            T[PAR]->add_liaison_avion(new Ligne<Avion>(T[PAR], T[LYO]));
            T[PAR]->add_liaison_avion(new Ligne<Avion>(T[PAR], T[BRU]));
            T[ROM]->add_liaison_avion(new Ligne<Avion>(T[ROM], T[NAP]));
            break;


        case 2 :
            T[PAR] = new HubMultimodal("Paris", 2.3333, 48.8667);
            T[ROM] = new AeroportInternational("Rome", 12.5113, 41.8919);
            T[LYO] = new AeroportRegional("Lyon", 4.8500, 45.7500);
            T[BRU] = new Gare("Bruxelles", 4.3488, 50.8505);
            T[NAP] = new AeroportRegional("Naples", 14.2464, 40.8563);

            T[PAR]->add_liaison_avion(new Ligne<Avion>(T[PAR], T[ROM]));
            T[PAR]->add_liaison_avion(new Ligne<Avion>(T[PAR], T[LYO]));
            T[PAR]->add_liaison_train(new Ligne<Train>(T[PAR]->get_gare(), T[BRU]));
            T[ROM]->add_liaison_avion(new Ligne<Avion>(T[ROM], T[NAP]));
            break;


        case 3 :
            T[PAR] = new HubMultimodal("Paris", 2.3333, 48.8667);
            T[ROM] = new HubMultimodal("Rome", 12.5113, 41.8919);
            T[LYO] = new Gare("Lyon", 4.8500, 45.7500);
            T[BRU] = new Gare("Bruxelles", 4.3488, 50.8505);
            T[NAP] = new Gare("Naples", 14.2464, 40.8563);

            T[PAR]->add_liaison_avion(new Ligne<Avion>(T[PAR], T[ROM]));
            T[PAR]->add_liaison_train(new Ligne<Train>(T[PAR]->get_gare(), T[LYO]));
            T[PAR]->add_liaison_train(new Ligne<Train>(T[PAR]->get_gare(), T[BRU]));
            T[ROM]->add_liaison_train(new Ligne<Train>(T[ROM]->get_gare(), T[LYO]));
            T[ROM]->add_liaison_train(new Ligne<Train>(T[ROM]->get_gare(), T[NAP]));
            break;


        case 4 :
            T[PAR] = new AeroportInternational("Paris", 2.3333, 48.8667);
            T[ROM] = new AeroportInternational("Rome", 12.5113, 41.8919);
            T[LYO] = new AeroportInternational("Lyon", 4.8500, 45.7500);
            T[BRU] = new AeroportInternational("Bruxelles", 4.3488, 50.8505);
            T[NAP] = new AeroportInternational("Naples", 14.2464, 40.8563);

            T[PAR]->add_liaison_avion(new Ligne<Avion>(T[PAR], T[ROM]));
            T[PAR]->add_liaison_avion(new Ligne<Avion>(T[PAR], T[LYO]));
            T[PAR]->add_liaison_avion(new Ligne<Avion>(T[PAR], T[BRU]));
            T[PAR]->add_liaison_avion(new Ligne<Avion>(T[PAR], T[NAP]));
            T[ROM]->add_liaison_avion(new Ligne<Avion>(T[ROM], T[LYO]));
            T[ROM]->add_liaison_avion(new Ligne<Avion>(T[ROM], T[BRU]));
            T[ROM]->add_liaison_avion(new Ligne<Avion>(T[ROM], T[NAP]));
            T[LYO]->add_liaison_avion(new Ligne<Avion>(T[LYO], T[BRU]));
            T[LYO]->add_liaison_avion(new Ligne<Avion>(T[LYO], T[NAP]));
            T[BRU]->add_liaison_avion(new Ligne<Avion>(T[BRU], T[NAP]));
            break;


        case 5 :
            T[PAR] = new Gare("Paris", 2.3333, 48.8667);
            T[ROM] = new Gare("Rome", 12.5113, 41.8919);
            T[LYO] = new Gare("Lyon", 4.8500, 45.7500);
            T[BRU] = new Gare("Bruxelles", 4.3488, 50.8505);
            T[NAP] = new Gare("Naples", 14.2464, 40.8563);

            T[PAR]->add_liaison_train(new Ligne<Train>(T[PAR], T[LYO]));
            T[PAR]->add_liaison_train(new Ligne<Train>(T[PAR], T[BRU]));
            T[ROM]->add_liaison_train(new Ligne<Train>(T[ROM], T[LYO]));
            T[ROM]->add_liaison_train(new Ligne<Train>(T[ROM], T[NAP]));
            break;


        case 6 :
            T[PAR] = new HubAeroport("Paris", 2.3333, 48.8667);
            T[ROM] = new AeroportRegional("Rome", 12.5113, 41.8919);
            T[LYO] = new AeroportRegional("Lyon", 4.8500, 45.7500);
            T[BRU] = new AeroportRegional("Bruxelles", 4.3488, 50.8505);
            T[NAP] = new AeroportRegional("Naples", 14.2464, 40.8563);

            T[PAR]->add_liaison_avion(new Ligne<Avion>(T[PAR], T[ROM]));
            T[PAR]->add_liaison_avion(new Ligne<Avion>(T[PAR], T[LYO]));
            T[PAR]->add_liaison_avion(new Ligne<Avion>(T[PAR], T[BRU]));
            T[PAR]->add_liaison_avion(new Ligne<Avion>(T[PAR], T[NAP]));
            break;
    }

    init_flux();
}
