#ifndef ORDER_H
#define ORDER_H

#include "Limit.h"

// define Order class
class Order {
    // not sure if these should be public or private
    public:
        int idNumber;
        bool buyOrSell;
        int shares;
        int limit;
        int entryTime;
        int eventTime;
        Order* nextOrder;
        Order* PrevOrder;
        Limit* parentLimit;
};







#endif
