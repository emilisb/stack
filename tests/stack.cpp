#include "gtest/gtest.h"
#include "../src/stack.h"

typedef stack<int> stint;

TEST(Constructor, WithList) {
    stint st({ 1, 2, 3, 4 });
    EXPECT_EQ(4, st.size());
    EXPECT_EQ(4, st.top());
}

TEST(Access, Top) {
    stint st({ 1, 2, 3 });
    EXPECT_EQ(3, st.top());
}

TEST(Capacity, Empty) {
    stint st;
    EXPECT_TRUE(st.empty());

    st.push(1);
    EXPECT_FALSE(st.empty());
}

TEST(Capacity, Size) {
    stint st({ 1, 2, 3 });
    EXPECT_EQ(3, st.size());
}

TEST(Modifier, Push) {
    stint st({ 1, 2, 3 });
    st.push(9);

    EXPECT_EQ(4, st.size());
    EXPECT_EQ(9, st.top());
}

TEST(Modifier, Pop) {
    stint st({ 1, 2, 3 });
    st.pop();

    EXPECT_EQ(2, st.size());
    EXPECT_EQ(2, st.top());
}

TEST(Memory, ShouldReallocate) {
    stint st({ 1, 2, 3 });

    for (int i = 0; i < 100; i++) {
        st.push(i);
    }

    EXPECT_EQ(103, st.size());
    EXPECT_EQ(99, st.top());
}
