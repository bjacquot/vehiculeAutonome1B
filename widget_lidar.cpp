#include "widgetlidar.h"


WidgetLIDAR::WidgetLIDAR(QWidget *parent,array<int,360>&distances) : QWidget(parent),distances_mm(distances)
{

}



void WidgetLIDAR::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.translate(width() / 2, height() / 2);
    painter.scale(0.2,0.2);


    // Maintenant, (0, 0) est au centre du widget
    painter.drawLine(-1000, 0, 1000, 0);  // Ligne horizontale passant par le centre
    painter.drawLine(0, -1000, 0, 1000);
    // Boucle pour dessiner 360 lignes (un rayon pour chaque degré)
    for (int angle = 0; angle < 360; ++angle) {
        // Convertir l'angle en radians
        double radians = angle * M_PI / 180.0;
        // Calculer les coordonnées du point à l'extrémité du rayon
        int x = static_cast<int>(distances_mm[angle] * cos(radians));
        int y = static_cast<int>(distances_mm[angle] * sin(radians));
        // Dessiner la ligne partant du centre (0,0) vers (x,y)
        painter.drawLine(0, 0, x, y);
    }
}
