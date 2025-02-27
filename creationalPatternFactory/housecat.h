#ifndef HOUSECAT_H
#define HOUSECAT_H

#include <QObject>
#include "interfaces/iAnimal.h"

class HouseCat : public QObject
{
    Q_OBJECT
public:
    explicit HouseCat(QObject *parent = nullptr);

signals:
};

#endif // HOUSECAT_H
