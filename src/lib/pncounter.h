#ifndef PNCOUNTER_H
#define PNCOUNTER_H

#include "gcounter.h"

// positive-negative counter
class PNCounter {
private:
    int n;          // number of nodes
    int id;         // unique node identifier between 0 and n
    GCounter* inc;  // increment gcounter
    GCounter* dec;  // decrement gcounter
public:
    PNCounter(int id, int n);
    ~PNCounter();
    void increment();
    void decrement();
    int value();
    void merge(PNCounter* other);
};

#endif
