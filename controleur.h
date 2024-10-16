#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include <QObject>
#include <array>

using std::array;

class Controleur : public QObject
{
    Q_OBJECT

public:
    Controleur(array<int,360>&_distances_mm);
    // coefficients:
    bool isRunning=false;
    double kp;
    double ki;
    double kd;
    void initPID(double _kp);
    // erreurs:
    double erreur_precedente;
    double somme_erreurs;
    array<int,360>&distances_mm;


signals:
    void deplacer(double vitesse, double angle);

public slots:
    void newDatas();
    void on();
    void off();


private:

};

#endif
