#ifndef LWWSET_H
#define LWWSET_H

#include "gset.h"
#include <chrono>
#include <unordered_map>

using time_point = std::chrono::time_point<std::chrono::system_clock>;

// last write wins set
// if add and remove are simultaneous, favor the remove
template<class T>
class LWWSet {
private:
    GSet<T>* add_set;                             // element additions
    GSet<T>* rm_set;                              // element removals
    std::unordered_map<T, time_point> add_times;  // timestamps for element additions
    std::unordered_map<T, time_point> rm_times;   // timestamps for element removals
public:
    LWWSet() {
        add_set = new GSet<T>();
        rm_set = new GSet<T>();
    }

    ~LWWSet() {
        delete add_set;
        delete rm_set;
    }

    void add(T el) {
        add_set->add(el);
        add_times[el] = std::chrono::system_clock::now();
    }

    void remove(T el) {
        rm_set->add(el);
        rm_times[el] = std::chrono::system_clock::now();
    }

    bool has(T el) {
        if (!add_set->has(el)) {
            return false;
        // add_set must have el
        } else if (!rm_set->has(el)) {
            return true;
        // both add_set and rm_set have el
        } else {
            // favors removes if timestamps are identical
            return add_times[el] > rm_times[el] ? true : false;
        }
    }

    void merge(LWWSet<T>* other) {
        add_set->merge(other->add_set);
        rm_set->merge(other->rm_set);
        for (std::pair<T, time_point> x : other->add_times) {
            T el = x.first;
            time_point timestamp = x.second;
            if (add_times.find(el) == add_times.end() || el > add_times[timestamp]) {
                add_times[el] = timestamp;
            }
        }
        for (std::pair<T, time_point> x : other->rm_times) {
            T el = x.first;
            time_point timestamp = x.second;
            if (rm_times.find(el) == rm_times.end() || timestamp > rm_times[el]) {
                rm_times[el] = timestamp;
            }
        }
    }
};

#endif
