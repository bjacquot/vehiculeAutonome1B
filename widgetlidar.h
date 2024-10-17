#ifndef WIDGETLIDAR_H
#define WIDGETLIDAR_H
#include <QtGui>
#include <QWidget>
#include <array>

using namespace std;
class WidgetLIDAR : public QWidget
{
    Q_OBJECT
public:
    array<int,360>&distances_mm;
    WidgetLIDAR(QWidget *parent,array<int, 360>&distances);
    void paintEvent(QPaintEvent *event);

};

#endif // WIDGETLIDAR_H
