/********BIBLIOTHEQUES********/

#include "voyage.h"


/********DEFINITION DES METHODES********/

Voyage::Voyage(Terminal* orig, Terminal* dest)
{
    this->destination = dest;
    this->origine = orig;
    this->cor.lignesAvion = std::vector<Ligne<Avion> *>(0);
    this->cor.lignesTrain = std::vector<Ligne<Train> *>(0);
    this->cor.lignesAvionElec = std::vector<Ligne<AvionElectrique> *>(0);
    this->cor.ordre = std::vector<unsigned int>(0);
}

Voyage::~Voyage(){}

Terminal* Voyage::get_origine() const
{
    return origine;
}

Terminal* Voyage::get_destination() const
{
    return destination;
}

unsigned int Voyage::get_nbCor() const
{
    return (this->cor.lignesTrain.size() + this->cor.lignesAvionElec.size() + this->cor.lignesAvion.size());
}

void Voyage::set_origine(Terminal* orig)
{
    this->origine = orig;
}

void Voyage::set_destination(Terminal* dest)
{
    this->destination = dest;
}

void Voyage::calcul(unsigned int nbPassagers)
{
    float temps = 0;
    float carbone = 0;

    int capacite, n;
    float d, lon, lat, c, v;

    if(nbPassagers == 0)
    {
        affiche(temps, carbone);
        return;
    }

    for(unsigned int i=0; i < get_nbCor(); i++)
    {
        n = nbPassagers;
        switch(cor.ordre[i])
        {
          case TRAIN :
            capacite = cor.lignesTrain[cor.indiceTrain]->get_mt().get_capacite();
            lon = cor.lignesTrain[cor.indiceTrain]->get_destination()->get_longitude();
            lat = cor.lignesTrain[cor.indiceTrain]->get_destination()->get_latitude();
            d = cor.lignesTrain[cor.indiceTrain]->get_origine()->distance(lon, lat);
            c = cor.lignesTrain[cor.indiceTrain]->get_mt().get_empreinte();
            v = cor.lignesTrain[cor.indiceTrain]->get_mt().get_vitesse();
            carbone += c * d;
            while(n > capacite)
            {
                n -= capacite;
                carbone += c * d;
            }
            temps += cor.lignesTrain[cor.indiceTrain]->get_tempsAttente();
            temps += d/v;
            cor.indiceTrain++;
            break;


          case AVION :
            capacite = cor.lignesAvion[cor.indiceAvion]->get_mt().get_capacite();
            lon = cor.lignesAvion[cor.indiceAvion]->get_destination()->get_longitude();
            lat = cor.lignesAvion[cor.indiceAvion]->get_destination()->get_latitude();
            d = cor.lignesAvion[cor.indiceAvion]->get_origine()->distance(lon, lat);
            c = cor.lignesAvion[cor.indiceAvion]->get_mt().get_empreinte();
            v = cor.lignesAvion[cor.indiceAvion]->get_mt().get_vitesse();
            carbone += c * d;
            while(n > capacite)
            {
                n -= capacite;
                carbone += c * d;
            }
            temps += cor.lignesAvion[cor.indiceAvion]->get_tempsAttente();
            temps += d/v;
            cor.indiceAvion++;
            break;


          case AVION_ELECTRIQUE :
            capacite = cor.lignesAvionElec[cor.indiceAvionElec]->get_mt().get_capacite();
            lon = cor.lignesAvionElec[cor.indiceAvionElec]->get_destination()->get_longitude();
            lat = cor.lignesAvionElec[cor.indiceAvionElec]->get_destination()->get_latitude();
            d = cor.lignesAvionElec[cor.indiceAvionElec]->get_origine()->distance(lon, lat);
            c = cor.lignesAvionElec[cor.indiceAvionElec]->get_mt().get_empreinte();
            v = cor.lignesAvionElec[cor.indiceAvionElec]->get_mt().get_vitesse();
            carbone += c * d;
            while(n > capacite)
            {
                n -= capacite;
                carbone += c * d;
            }
            temps += cor.lignesAvionElec[cor.indiceAvionElec]->get_tempsAttente();
            temps += d/v;
            cor.indiceAvionElec++;
            break;

          default :
            std::cout << "Erreur : valeur incorrecte dans l'ordre des correspondances\n";
            break;
        }
    }

    affiche(temps, carbone);
    reset();
}

void Voyage::affiche(float temps, float carbone)
{
    std::cout << "Temps : " << temps << std::endl;
    std::cout << "Empreinte carbone : " << carbone << std::endl;
}

void Voyage::reset()
{
    cor.indiceTrain = 0;
    cor.indiceAvion = 0;
    cor.indiceAvionElec = 0;
}
