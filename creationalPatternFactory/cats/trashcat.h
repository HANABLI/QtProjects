#ifndef TRASHCAT_H
#define TRASHCAT_H

#include <QObject>
#include <QDebug>
#include "cat.h"

class TrashCat : public Cat
{
    Q_OBJECT
    Q_INTERFACES(iAnimal)
public:
    explicit TrashCat(Cat *parent = nullptr);
    ~TrashCat();

signals:

    // iAnimal interface
public:
    void eat() override;
    void sleep() override;
    void move() override;
};

#endif // TRASHCAT_H
