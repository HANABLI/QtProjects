#ifndef HOUSECAT_H
#define HOUSECAT_H

#include <QObject>
#include <QDebug>
#include "cat.h"

class HouseCat : public Cat
{
    Q_OBJECT
    Q_INTERFACES(iAnimal)
public:
    explicit HouseCat(Cat *parent = nullptr);
    ~HouseCat();

signals:

    // iAnimal interface
public:
    void eat() override;
    void sleep() override;
    void move() override;
};

#endif // HOUSECAT_H
