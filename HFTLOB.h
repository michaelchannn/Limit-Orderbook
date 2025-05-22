#ifndef HFTLOB_H
#define HFTLOB_H

#include <unordered_map>
#include <chrono>

// define book class (containing both buy tree and sell tree)
class Book {
    private:
        Limit* buyTree; // root node of buy tree
        Limit* sellTree; // root node of buy tree
        Limit* highestBuy; // highest buy limit price
        Limit* lowestSell; // lowest sell limit price
        std::unordered_map<long long, Limit*> limitMap; // allow for O(1) lookup of limit price
        std::unordered_map<int, Order*> orderMap; // allow for O(1) lookup of order

    public:
        Book::Book();

        Limit* addNewLimit(Limit* root, Limit* newLimit); // helper function to add limit price to tree
        Limit* findMax(Limit* root) const; // find right-most leaf of tree (for highest buy)
        Limit* findMin(Limit* root) const; // find left-most leaf of tree (for lowest sell)
        int addOrder(Order* newOrder);
        int cancelOrder(int idNumber);
        int executeOrder(int idNumber, int shares);
        
};

// define Limit class (representing a single limit price)
class Limit {
    public:
        long long limitPrice;
        int size;
        int totalVolume;
        Limit* parent;
        Limit* leftChild;
        Limit* rightChild;
        Order* headOrder;
        Order* tailOrder;

        Limit(long long limitPrice); // constructor
};

// define Order class
class Order {
    public:
        int idNumber;
        bool isBuy; // 1 (true) = buy, 0 (false) = sell
        int shares;
        int limit; // limit price of order
        std::chrono::time_point<std::chrono::high_resolution_clock> entryTime; // time order first entered the book
        std::chrono::time_point<std::chrono::high_resolution_clock> eventTime; // time of the most recent event affecting the order (modify, cancel, etc)
        Order* nextOrder;
        Order* PrevOrder;
        Limit* parentLimit;

        Order(int idNumber, bool isBuy, int shares, int limit); // constructor
};

// order functions
int pushOrder(Limit* limit, Order* new_order);

Order* popOrder(Limit* limit);

int removeOrder(Order* order);

// Limit functions
int addNewLimit(Limit* root, Limit* newLimit);











    




#endif
