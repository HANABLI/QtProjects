#ifndef IANIMALFACTORY_H
#define IANIMALFACTORY_H

#include "iAnimal.h"
#include <QSharedPointer>

class iAnimalFactory {
public:
    virtual QSharedPointer<iAnimal> createSmall() = 0;
    virtual QSharedPointer<iAnimal> createMedium() = 0;
    virtual QSharedPointer<iAnimal> createLarge() = 0;
    virtual ~iAnimalFactory() {}; //we are going to make some people mad. but we need to free to memory
};

#endif // IANIMALFACTORY_H
