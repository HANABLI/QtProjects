#ifndef IPOOL_H
#define IPOOL_H

#include "iPoolItem.h"

class iPool {
public:
    virtual iPoolItem* aquire() = 0;
    virtual void release(iPoolItem* item) = 0;
    virtual ~iPool() {};
};

#endif // IPOOL_H
