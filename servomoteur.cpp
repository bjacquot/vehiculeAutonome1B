#include "servomoteur.h"

ServoMoteur::ServoMoteur(const int pwmChannel, const int _centerDuty_us, const int _gainDuty_us)
    : pwm(2,pwmChannel,50), centerDuty_us(_centerDuty_us), gainDuty_us(_gainDuty_us)
{
    pos=0;
    updatePos();
}

void ServoMoteur::updatePos()
{
    float duty=(pos*gainDuty_us+centerDuty_us)*1000;
    pwm.setDuty((int)duty);
}

void ServoMoteur::setPosition(double newPos)
{
    if (newPos!=pos)
    {
        pos=newPos;
        if (pos>1) pos=1;
        if (pos<-1) pos=-1;
        updatePos();
    }
}
