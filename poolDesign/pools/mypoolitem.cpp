#include "mypoolitem.h"

MyPoolItem::MyPoolItem(QObject *parent)
    : QObject{parent}
{
    m_aquired = false;
    qInfo() << this << "constructed";
}


void MyPoolItem::reset()
{
    m_aquired = false;
    qInfo() << this << "reset";
}

bool MyPoolItem::aquired()
{
    return m_aquired;
}

void MyPoolItem::setAquired(bool aquired)
{
    qInfo() << this << "aquired" << aquired;
    m_aquired = aquired;
}

void MyPoolItem::test()
{
    qInfo() << this << "test";

}

