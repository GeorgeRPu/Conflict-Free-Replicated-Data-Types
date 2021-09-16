#include "lib/rga.h"
#include <gtest/gtest.h>

class RGATest : public ::testing::Test {
protected:
    RGA* rga_a;
    RGA* rga_bc;

    void SetUp() override {
        rga_a = new RGA();
        rga_a->insert(0, 'a');
        rga_bc = new RGA();
        rga_bc->insert(0, 'a');
        rga_gc->insert(1, 'b');
    }
}
