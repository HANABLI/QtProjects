#include "cat.h"

Cat::Cat(QObject *parent)
    : QObject{parent}, id(QUuid::createUuid())
{}


QUuid Cat::getId() const
{
    qInfo() << "id: " << id;
    return id;
}

void Cat::eat()
{
    qInfo() << this << "Eat";
}

void Cat::sleep()
{
    qInfo() << this << "Sleep";
}

void Cat::move()
{
    qInfo() << this << "Move";
}
