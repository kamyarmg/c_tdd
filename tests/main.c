// tests/main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h" 

int g_tests_run = 0;
int g_tests_failed = 0;
int g_failfast_mode = 0;
int g_all_mode = 0;     

void runadd_tests();

int main(int argc, char *argv[])
{
    system("cls || clear");
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "failfast") == 0)
        {
            g_failfast_mode = 1;
            TEST_SUITE_START("FAIL-FAST");
        }
        else if (strcmp(argv[i], "all") == 0)
        {
            g_all_mode = 1;
            TEST_SUITE_START("SHOW ALL TESTS");
        }
    }
    if (argc == 1)
    {
        TEST_SUITE_START("SHOW FAILED TESTS");
    }

    runadd_tests();

    TEST_SUITE_END();

    return (g_tests_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
