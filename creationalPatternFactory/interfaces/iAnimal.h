#ifndef IANIMAL_H
#define IANIMAL_H
#include <QUuid>
#include <QObject>
class iAnimal {
public:
    virtual QUuid getId() const = 0;
    virtual void eat() = 0;
    virtual void sleep() = 0;
    virtual void move() = 0;
    virtual ~iAnimal() {}; // We are going to make some people mad. but we need to free the memory
};

#define iAnimal_iid "iAnimal"
Q_DECLARE_INTERFACE(iAnimal, iAnimal_iid)
#endif // IANIMAL_H
