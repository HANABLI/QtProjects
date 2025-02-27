#include <QCoreApplication>

#include <QDebug>
#include <QObject>
#include <QRandomGenerator>
#include <QSharedPointer>
#include "cats/catfactory.h"
#include "interfaces/iAnimal.h"
/**
 * @brief main: this is an Abstract Factory Designe example
 *        Im creating related items without specifiying a concrete class
 *
 * @param argc
 * @param argv
 * @return
 */

void makeAnimals (QList<QSharedPointer<iAnimal>> &animals, int count) {
    CatFactory factory;

    for (int i = 0; i < count; i++) {
        QSharedPointer<iAnimal> animal;
        int value = QRandomGenerator::global()->bounded(0, 3);

        switch (value) {
        case 0:
            animal = factory.createSmall();
            break;
        case 1:
            animal = factory.createMedium();
            break;
        case 2:
            animal = factory.createLarge();
            break;
        default:
            qInfo() << "Other";
        }

        animals.append(animal);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<QSharedPointer<iAnimal>> animals;
    QList<QSharedPointer<Leopard>> leopards;
    makeAnimals(animals, 25);

    foreach (QSharedPointer<iAnimal> animal, animals) {
        animal->getId();
        animal->eat();
        animal->move();
        animal->sleep();
    }

    for (auto& animal: animals) {
        // Step 1: Convert QSharedPointer<iAnimal> to QSharedPointer<QObject>
        QSharedPointer<QObject> obj = animal.dynamicCast<QObject>();

        if (!obj) continue;  // Skip if conversion fails

        // Step 2: Convert QSharedPointer<QObject> to QSharedPointer<Leopard>
        QSharedPointer<Leopard> leopard = obj.dynamicCast<Leopard>();
        if (leopard) {
            leopards.append(leopard);
        }
    }

    foreach (QSharedPointer<Leopard> leo, leopards) {
        qInfo() << leo->objectName() << ": "; leo->getId();
    }

    animals.clear();
    leopards.clear();
    return a.exec();
}
