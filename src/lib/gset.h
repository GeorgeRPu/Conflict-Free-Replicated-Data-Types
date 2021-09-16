#ifndef GSET_H
#define GSET_H

#include <unordered_set>

// grow only set
template <class T>
class GSet {
private:
    std::unordered_set<T> set;
public:
    GSet() {}

    ~GSet() {
        delete set;
    }

    void add(T el) {
        set.insert(el);
    }

    bool has(T el) {
        return set.find(el) != set.end();
    }

    void merge(GSet<T>* other) {
        for (T el : other->set) {
            set.insert(el);
        }
    }
};

#endif
