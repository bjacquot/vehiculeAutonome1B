#include "controleur.h"
#include <QDebug>

Controleur::Controleur(array<int,360>&_distances_mm) : distances_mm(_distances_mm)
{
}

void Controleur::newDatas()
{
 if (isRunning == true)
 {
    double distance_consigne = 600;
    double angle_consigne = 90;
    double vitesse = 0.2;

    double distance_actuelle = distances_mm[angle_consigne];

    double erreur = distance_actuelle-distance_consigne;

    double angle = kp * erreur;


    emit deplacer(vitesse, angle);
    qDebug() << "Correction:" << angle;
    qDebug() << "vitesse:" << vitesse;
  }
 else
 {
    emit deplacer(0,0);
    qDebug() << " la voiture est arretée "  ;
 }

}

void Controleur::on()
{
    isRunning=true;
}

void Controleur::off()
{
    isRunning=false;
}

void Controleur::initPID(double _kp)
{
    kp = _kp;
}


