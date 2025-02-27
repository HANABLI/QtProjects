#ifndef IPOOLITEM_H
#define IPOOLITEM_H

class iPoolItem {
public:

    virtual void reset() = 0;
    virtual bool aquired() = 0;
    virtual ~iPoolItem() {};

};

#endif // IPOOLITEM_H
