#include "gcounter.h"
#include <assert.h>

GCounter::GCounter(int id, int n) {
    assert(id < n);
    this->id = id;
    this->n = n;
    inc = new int[n];
}

GCounter::~GCounter() {
    delete inc;
}

void GCounter::increment() {
    inc[id] += 1;
}

int GCounter::value() {
    int value = 0;
    for (int i = 0; i < n; i++) {
        value += inc[i];
    }
    return value;
}

void GCounter::merge(GCounter* other) {
    for (int i = 0; i < n; i++) {
        inc[i] = inc[i] > other->inc[i] ? inc[i] : other->inc[i];
    }
}
