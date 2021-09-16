#include "src/lib/gcounter.h"
#include <gtest/gtest.h>

class GCounterTest : public ::testing::Test {
protected:
    GCounter* gc0;
    GCounter* gc1;
    GCounter* gc2;

    void SetUp() override {
        gc0 = new GCounter(0, 3);
        gc1 = new GCounter(1, 3);
        gc1->increment();
        gc2 = new GCounter(2, 3);
        gc2->increment();
        gc2->increment();
    }
};

TEST_F(GCounterTest, DoesIncrement) {
    int before = gc0->value();
    gc0->increment();
    int after = gc0->value();
    EXPECT_EQ(after - before, 1);
}

TEST_F(GCounterTest, StartsAtZero) {
    EXPECT_EQ(gc0->value(), 0);
}

TEST_F(GCounterTest, Merges2Correctly) {
    gc0->merge(gc1);
    EXPECT_EQ(gc0->value(), 1);
}

TEST_F(GCounterTest, Merges3Correctly) {
    gc0->merge(gc2);
    gc0->merge(gc1);
    EXPECT_EQ(gc1->value(), 3);
}
