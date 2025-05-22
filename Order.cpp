#include "HFTLOB.h"

Order::Order(int idNumber, bool isBuy, int shares, int limit): idNumber(idNumber), isBuy(isBuy), shares(shares), limit(limit), entryTime(), eventTime(), nextOrder(nullptr), PrevOrder(nullptr), parentLimit(nullptr) {}


