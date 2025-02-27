#include "catfactory.h"

CatFactory::CatFactory(QObject *parent)
    : QObject{parent}
{}


QSharedPointer<iAnimal> CatFactory::createSmall()
{
    return QSharedPointer<HouseCat>::create();
}

QSharedPointer<iAnimal> CatFactory::createMedium()
{
    return QSharedPointer<TrashCat>::create();
}

QSharedPointer<iAnimal> CatFactory::createLarge()
{
    return QSharedPointer<Leopard>::create();
}
