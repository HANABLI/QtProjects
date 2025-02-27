#include "leopard.h"

Leopard::Leopard(Cat *parent)
    : Cat{parent}
{
    qInfo() << this << "Created";
    setObjectName("Leopard");
}

Leopard::~Leopard()
{
    qInfo() << this << "Destroyed";
}

void Leopard::eat()
{
    qInfo() << this << "Eat";
}

void Leopard::sleep()
{
    qInfo() << this << "Sleep";
}

void Leopard::move()
{
    qInfo() << this << "Move";
}
