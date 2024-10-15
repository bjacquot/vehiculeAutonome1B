#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include <QObject>
#include <array>

using std::array;

class Controleur : public QObject
{
    Q_OBJECT

public:
    explicit Controleur(QObject *parent, array<int, 360>& distances);
    // coefficients:
    double kp;
    double ki;
    double kd;
    void initPID(double _kp, double _ki, double _kd);
    // erreurs:
    double erreur_precedente;
    double somme_erreurs;
    // tableau de valeur
    array<int, 360>& distances_mm;

signals:
    void deplacer(double vitesse, double angle);

public slots:
    void newDatas();

private:

};

#endif
