#ifndef ORDER_H
#define ORDER_H

#include "Limit.h"

// define Order class
class Order {
    public:
        double idNumber;
        bool buyOrSell;
        double shares;
        double limit;
        double entryTime;
        double eventTime;
        Order* nextOrder;
        Order* PrevOrder;
        Limit* parentLimit;

        Order(); // constructor

        int pushOrder(Limit* limit, Order* new_order);

        Order* popOrder(Limit* limit);

        int removeOrder(Order* order);
};







#endif
