#include "src/lib/pncounter.h"
#include <gtest/gtest.h>

class PNCounterTest : public ::testing::Test {
protected:
    PNCounter* pnc0;
    PNCounter* pnc_neg1;
    PNCounter* pnc2;

    void SetUp() override {
        pnc0 = new PNCounter(0, 3);
        pnc_neg1 = new PNCounter(1, 3);
        pnc_neg1->decrement();
        pnc2 = new PNCounter(2, 3);
        pnc2->increment();
        pnc2->increment();
    }
};

TEST_F(PNCounterTest, DoesIncrement) {
    int before = pnc0->value();
    pnc0->increment();
    int after = pnc0->value();
    EXPECT_EQ(after - before, 1);
}

TEST_F(PNCounterTest, DoesDecrement) {
    int before = pnc0->value();
    pnc0->decrement();
    int after = pnc0->value();
    EXPECT_EQ(before - after, 1);
}

TEST_F(PNCounterTest, IncrementCancelsDecrement) {
    int before = pnc0->value();
    pnc0->increment();
    pnc0->decrement();
    int after = pnc0->value();
    EXPECT_EQ(after, before);
}

TEST_F(PNCounterTest, StartsAtZero) {
    EXPECT_EQ(pnc0->value(), 0);
}

TEST_F(PNCounterTest, Merges2Correctly) {
    pnc0->merge(pnc_neg1);
    EXPECT_EQ(pnc0->value(), -1);
}

TEST_F(PNCounterTest, Merges3Correctly) {
    pnc0->merge(pnc2);
    pnc0->merge(pnc_neg1);
    EXPECT_EQ(pnc0->value(), 1);
}
