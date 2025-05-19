#ifndef LIMIT_H
#define LIMIT_H

#include "Order.h"

// define Limit class (representing a single limit price)
class Limit {
    // public or private? idk
    public:
        int limitPrice;
        int size;
        int totalVolume;
        Limit* parent;
        Limit* leftChild;
        Limit* rightChild;
        Order* headOrder;
        Order* tailOrder;
};


#endif
