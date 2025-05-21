#ifndef LIMIT_H
#define LIMIT_H

#include "Order.h"

// define Limit class (representing a single limit price)
class Limit {
    public:
        double limitPrice;
        double size;
        double totalVolume;
        Limit* parent;
        Limit* leftChild;
        Limit* rightChild;
        Order* headOrder;
        Order* tailOrder;

        Limit(); // constructor

        
};


#endif
