#include "controleur.h"
#include <QDebug>

Controleur::Controleur(QObject *parent, array<int, 360>& distances)
    : QObject(parent), distances_mm(distances), erreur_precedente(0), somme_erreurs(0)
{

}

void Controleur::newDatas()
{
    // Initialisation:
    double vitesse_max = 1;
    double vitesse = 0.1;
    int angle_cible = 30;
    int distance_cible = 600;

    // correction de l'angle:
    int index_cible = (angle_cible + 180) % 360;
    double distance_actuelle = distances_mm[index_cible];
    double erreur = (distance_cible/600) - (distance_actuelle/600);
    somme_erreurs += erreur;
    double variation_erreur = erreur - erreur_precedente;
    double angle = kp * erreur + ki * somme_erreurs + kd * variation_erreur;
    erreur_precedente = erreur;
    if (angle > 1) angle = 1;
    if (angle < -1) angle -1;

    // correction de la vitesse :
    if (distance_actuelle <= distance_cible) {
        vitesse = vitesse_max * ((distance_actuelle) / distance_cible)+0.05;
    } else {
        vitesse = 0.1;
    }
    if (vitesse > vitesse_max) vitesse = vitesse_max;
    if (vitesse < -vitesse_max) vitesse = -vitesse_max;

    // emition du signal + affichage des valeurs
    emit deplacer(vitesse, angle);
    qDebug() << "Correction:" << angle;
    qDebug() << "vitesse:" << vitesse;


}

void Controleur::initPID(double _kp, double _ki, double _kd)
{
    kp = _kp;
    ki = _ki;
    kd = _kd;
}
