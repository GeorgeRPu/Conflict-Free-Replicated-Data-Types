#include "src/lib/gcounter.h"
#include "src/lib/gset.h"
#include "src/lib/lwwset.h"
#include "src/lib/pncounter.h"
#include "src/lib/rga.h"
#include <iostream>

int main(int argc, char const *argv[]) {
    std::cout << "Instantiating one of each CRDT" << std::endl;

    std::cout << "Instantiating GCounter" << std::endl;
    GCounter* gc = new GCounter(0, 1);
    std::cout << "Instantiating PNCounter" << std::endl;
    PNCounter* pnc = new PNCounter(0, 1);
    std::cout << "Instantiating GSet" << std::endl;
    GSet<char>* gs = new GSet<char>();
    std::cout << "Instantiating LWWSet" << std::endl;
    LWWSet<char>* lwws = new LWWSet<char>();

    return 0;
}
