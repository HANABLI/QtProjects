#include "trashcat.h"

TrashCat::TrashCat(Cat *parent)
    : Cat{parent}
{
    qInfo() << this << "Created";
    setObjectName("TrashCat");
}

TrashCat::~TrashCat()
{
    qInfo() << this << "Destroyed";
}

void TrashCat::eat()
{
    qInfo() << this << "Eat";
}

void TrashCat::sleep()
{
    qInfo() << this << "Sleep";
}

void TrashCat::move()
{
    qInfo() << this << "Move";
}
