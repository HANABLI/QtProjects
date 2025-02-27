#include "housecat.h"

HouseCat::HouseCat(Cat *parent)
    : Cat{parent}
{
    qInfo() << this << "Created";
    setObjectName("HouseCat");
}

HouseCat::~HouseCat()
{
    qInfo() << this << "Destroyed";
}

void HouseCat::eat()
{
    qInfo() << this << "Eat";
}

void HouseCat::sleep()
{
    qInfo() << this << "Sleep";
}

void HouseCat::move()
{
    qInfo() << this << "Move";
}
