#ifndef GCOUNTER_H
#define GCOUNTER_H

// grow only counter
class GCounter {
private:
    int n;     // number of nodes
    int id;    // unique node identifier between 0 and n - 1
    int* inc;  // number of incremements for each node
public:
    GCounter(int id, int n);
    ~GCounter();
    void increment();
    int value();
    void merge(GCounter* other);
};

#endif
