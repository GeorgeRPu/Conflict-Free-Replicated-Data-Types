#include "gcounter.h"
#include "pncounter.h"

PNCounter::PNCounter(int id, int n) {
    inc = new GCounter(id, n);
    dec = new GCounter(id, n);
}

PNCounter::~PNCounter() {
    delete inc;
    delete dec;
}

void PNCounter::increment() {
    inc->increment();
}

void PNCounter::decrement() {
    dec->increment();
}

int PNCounter::value() {
    return inc->value() - dec->value();
}

void PNCounter::merge(PNCounter* other) {
    inc->merge(other->inc);
    dec->merge(other->dec);
}
