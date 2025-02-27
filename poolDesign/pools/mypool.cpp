#include "mypool.h"

MyPool::MyPool(QObject *parent)
    : QObject{parent}
{

}

MyPool::~MyPool() {
    qDeleteAll(m_list);
    m_list.clear();
}

iPoolItem *MyPool::aquire()
{
    foreach(MyPoolItem* item, m_list) {
        if (item->aquired() == false) {
            item->setAquired(true);
            return item;
        }
    }

    MyPoolItem* item = new MyPoolItem();
    item->setAquired(true);
    m_list.append(item);
    return item;
}

void MyPool::release(iPoolItem *item)
{
    if (!item) return;
    item->reset();
}
