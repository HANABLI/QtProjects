#ifndef LEOPARD_H
#define LEOPARD_H

#include <QObject>
#include <QDebug>
#include "cat.h"


class Leopard : public Cat
{
    Q_OBJECT
    Q_INTERFACES(iAnimal)
public:
    explicit Leopard(Cat *parent = nullptr);
    ~Leopard();
signals:

    // iAnimal interface
public:
    void eat() override;
    void sleep() override;
    void move() override;
};

#endif // LEOPARD_H
