#ifndef MATERIEL_H
#define MATERIEL_H

#include <QObject>
#include <array>
using namespace std;

class Materiel : public QObject
{
    Q_OBJECT
public:
    Materiel();

protected:
    array<int,360> distances_mm;

public slots:
    virtual void deplacer(double _vitesse, double _angle)=0;

signals:
    void newDatas();

};

#endif // MATERIEL_H
