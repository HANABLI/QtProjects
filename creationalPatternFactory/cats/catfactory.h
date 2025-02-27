#ifndef CATFACTORY_H
#define CATFACTORY_H

#include <QObject>

#include "../interfaces/iAnimalFactory.h"
#include "housecat.h"
#include "leopard.h"
#include "trashcat.h"

class CatFactory : public QObject, public iAnimalFactory
{
    Q_OBJECT
public:
    explicit CatFactory(QObject *parent = nullptr);
signals:

    // iAnimalFactory interface
public:
    QSharedPointer<iAnimal> createSmall() override;
    QSharedPointer<iAnimal> createMedium() override;
    QSharedPointer<iAnimal> createLarge() override;
};

#endif // CATFACTORY_H
