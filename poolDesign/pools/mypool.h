#ifndef MYPOOL_H
#define MYPOOL_H

#include <QObject>
#include <QDebug>
#include "../interfaces/iPool.h"
#include "mypoolitem.h"

class MyPool : public QObject, public iPool
{
    Q_OBJECT
public:
    explicit MyPool(QObject *parent = nullptr);
    ~MyPool();
signals:

    // iPool interface
public:
    iPoolItem *aquire() override;
    void release(iPoolItem *item) override;

private:
    QList<MyPoolItem*> m_list;
};

#endif // MYPOOL_H
