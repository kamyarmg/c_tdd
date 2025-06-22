// tests/test_utils.h
#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>  
#include <string.h>


#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"


#define EPSILON 0.000001


extern int g_tests_run;
extern int g_tests_failed;
extern int g_failfast_mode; 
extern int g_all_mode;      

#define TEST_ASSERT(condition, message)                                                        \
    do                                                                                         \
    {                                                                                          \
        g_tests_run++;                                                                         \
        if (!(condition))                                                                      \
        {                                                                                      \
            g_tests_failed++;                                                                  \
            fprintf(stderr, RED "[FAILURE]: %s:%d - %s\n" RESET, __FILE__, __LINE__, message); \
            if (g_failfast_mode)                                                               \
            {                                                                                  \
                exit(EXIT_FAILURE);                                                            \
            }                                                                                  \
        }                                                                                      \
        else if (g_all_mode)                                                                   \
        {                                                                                      \
            printf(GREEN "[PASSED]: %s:%d - %s\n" RESET, __FILE__, __LINE__, message);         \
        }                                                                                      \
    } while (0)

#define TEST_ASSERT_DOUBLE_EQUALS(a, b, message) \
    TEST_ASSERT(fabs((a) - (b)) < EPSILON, message)

#define TEST_SUITE_START(name)                         \
    printf(YELLOW "Running Tests (%s)\n" RESET, name); \
    printf("----------------------------------------\n");

#define TEST_SUITE_END()                                              \
    printf("----------------------------------------\n");             \
    printf("Total tests run: %d\n", g_tests_run);                     \
    if (g_tests_failed == 0)                                          \
    {                                                                 \
        printf(GREEN "All tests passed!\n" RESET);                    \
    }                                                                 \
    else                                                              \
    {                                                                 \
        printf(RED "Total tests failed: %d\n" RESET, g_tests_failed); \
    }

#endif // TEST_UTILS_H
