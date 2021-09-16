#include "src/lib/gset.h"
#include <gtest/gtest.h>

class GSetTest : public ::testing::Test {
protected:
    GSet<char>* set;
    GSet<char>* setA;
    GSet<char>* setB;

    void SetUp() override {
        set = new GSet<char>();
        setA = new GSet<char>();
        setA->add('A');
        setB = new GSet<char>();
        setB->add('B');
    }
};

TEST_F(GSetTest, DoesAdd) {
    set->add('C');
    EXPECT_FALSE(set->has('A'));
    EXPECT_FALSE(set->has('B'));
    EXPECT_TRUE(set->has('C'));
}

TEST_F(GSetTest, StartsEmpty) {
    EXPECT_FALSE(set->has('A'));
    EXPECT_FALSE(set->has('B'));
    EXPECT_FALSE(set->has('C'));
}

TEST_F(GSetTest, Merges2Correctly) {
    set->merge(setA);
    EXPECT_TRUE(set->has('A'));
    EXPECT_FALSE(set->has('B'));
    EXPECT_FALSE(set->has('C'));
}

TEST_F(GSetTest, Merges3Correctly) {
    set->merge(setB);
    set->merge(setA);
    EXPECT_TRUE(set->has('A'));
    EXPECT_TRUE(set->has('B'));
    EXPECT_FALSE(set->has('C'));
}
