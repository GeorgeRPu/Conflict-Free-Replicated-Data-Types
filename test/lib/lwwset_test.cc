#include "src/lib/lwwset.h"
#include <gtest/gtest.h>

class LWWSetTest : public ::testing::Test {
protected:
    LWWSet<char>* set;
    LWWSet<char>* setA;
    LWWSet<char>* setB;

    void SetUp() override {
        set = new LWWSet<char>();
        setA = new LWWSet<char>();
        setA->add('A');
        setB = new LWWSet<char>();
        setB->add('B');
    }
};

TEST_F(LWWSetTest, DoesAdd) {
    set->add('C');
    EXPECT_FALSE(set->has('A'));
    EXPECT_FALSE(set->has('B'));
    EXPECT_TRUE(set->has('C'));
}

TEST_F(LWWSetTest, DoesRemoveExistingElement) {
    setA->remove('A');
    EXPECT_FALSE(setA->has('A'));
    EXPECT_FALSE(setA->has('B'));
    EXPECT_FALSE(setA->has('C'));
}

TEST_F(LWWSetTest, DoesRemoveNonExistantElement) {
    setA->remove('C');
    EXPECT_TRUE(setA->has('A'));
    EXPECT_FALSE(setA->has('B'));
    EXPECT_FALSE(setA->has('C'));
}

TEST_F(LWWSetTest, StartsEmpty) {
    EXPECT_FALSE(set->has('A'));
    EXPECT_FALSE(set->has('B'));
    EXPECT_FALSE(set->has('C'));
}

TEST_F(LWWSetTest, LastWriteShouldWin) {
    set->add('A');
    set->remove('A');
    set->remove('A');
    set->add('A');
    EXPECT_TRUE(set->has('A'));
    EXPECT_FALSE(set->has('B'));
    EXPECT_FALSE(set->has('C'));
}

TEST_F(LWWSetTest, Merges2Correctly) {
    set->merge(setA);
    EXPECT_TRUE(set->has('A'));
    EXPECT_FALSE(set->has('B'));
    EXPECT_FALSE(set->has('C'));
}

TEST_F(LWWSetTest, Merges3Correctly) {
    setA->merge(setB);
    setA->merge(set);
    EXPECT_TRUE(setA->has('A'));
    EXPECT_FALSE(setA->has('B'));
    EXPECT_FALSE(setA->has('C'));
}
