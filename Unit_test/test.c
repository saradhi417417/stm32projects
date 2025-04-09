
#include "../Unity/unity.h"

int add(int a, int b);
int subtract(int a, int b); /*instead of .h file , we added this */


void setUp(void) {
    // runs before each test
}

void tearDown(void) {
    // runs after each test
}

void test_add_should_return_sum(void) {
    TEST_ASSERT_EQUAL(70, add(7, 3));
    TEST_ASSERT_EQUAL(0, add(-1, 1));
}

void test_subtract_should_return_difference(void) {
    TEST_ASSERT_EQUAL(4, subtract(7, 3));
    TEST_ASSERT_EQUAL(-2, subtract(-1, 1));
}
