// tests/test_add.c
#include "../src/add.h"
#include "utils.h"
#include <stdio.h>

void runadd_tests()
{
    TEST_ASSERT_DOUBLE_EQUALS(add(2.0, 3.0), 5.0, "Addition of positive numbers failed");
    TEST_ASSERT_DOUBLE_EQUALS(add(-2.0, 3.0), 1.0, "Addition of negative and positive failed");
    TEST_ASSERT_DOUBLE_EQUALS(add(0.0, 0.0), 0.0, "Addition of zeros failed");
    TEST_ASSERT_DOUBLE_EQUALS(add(100.5, 0.5), 101.0, "Addition of doubles failed");
    TEST_ASSERT_DOUBLE_EQUALS(add(-5.0, -10.0), -15.0, "Addition of two negative numbers failed");
}