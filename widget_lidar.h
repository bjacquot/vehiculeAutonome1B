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
    explicit WidgetLIDAR(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    array<int,360>distances;
signals:

};

#endif // WIDGETLIDAR_H
