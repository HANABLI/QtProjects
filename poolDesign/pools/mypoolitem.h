#ifndef MYPOOLITEM_H
#define MYPOOLITEM_H

#include <QObject>
#include <QDebug>

#include "../interfaces/iPoolItem.h"

class MyPoolItem : public QObject, public iPoolItem
{
    Q_OBJECT
public:
    explicit MyPoolItem(QObject *parent = nullptr);

signals:

    // iPoolItem interface
public:
    void reset() override;
    bool aquired() override;
public:
    void setAquired(bool aquired);
    void test();
private:
    bool m_aquired;
};

#endif // MYPOOLITEM_H
