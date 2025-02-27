#include <QCoreApplication>

#include "interfaces/iPoolItem.h"
#include "pools/mypoolitem.h"
#include "pools/mypool.h"
/**
 * Object pool example
 *
 * Re-using objects
 *
 * it can save resources and make thinks a bit faster
 *
 */

void useItem(MyPool &pool, int max) {
    qInfo() << "Grabbing" << max << "items";

    QList<MyPoolItem*> items;

    for(int i = 0; i < max; i++) {
        MyPoolItem* item = static_cast<MyPoolItem*>(pool.aquire());
        items.append(item);
    }

    foreach (MyPoolItem* item, items) {
        item->test();
    }

    foreach (MyPoolItem* item, items) {
        pool.release(item);
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyPool pool;
    useItem(pool, 5);

    MyPoolItem* item = static_cast<MyPoolItem*>(pool.aquire());

    useItem(pool, 3);

    return a.exec();
}
