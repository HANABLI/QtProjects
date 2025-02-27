#ifndef CAT_H
#define CAT_H

#include <QObject>
#include <QDebug>

#include "../interfaces/iAnimal.h"

class Cat : public QObject, public iAnimal
{
    Q_OBJECT
    Q_INTERFACES(iAnimal)
public:
    explicit Cat(QObject *parent = nullptr);

signals:

    // iAnimal interface
public:
    QUuid getId() const override;
    void eat() override;
    void sleep() override;
    void move() override;
protected:
    QUuid id;
};

#endif // CAT_H
