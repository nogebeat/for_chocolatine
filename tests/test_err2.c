#include "../include/my.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>


Test(check_err6, basic_test_second_part) {
    int ac = 3;
    char* av[] = {"program_name", "rsbsf", "1"};
    int expected_result = 84;
    int result = s_main(ac, av);
    cr_assert_eq(result, expected_result);
}

Test(check_err7, basic_test_second_part) {
    int ac = 3;
    char* av[] = {"program_name", "10+4", "1"};
    int expected_result = 84;
    int result = s_main(ac, av);
    cr_assert_eq(result, expected_result);
}

Test(check_err8, basic_test_second_part) {
    int ac = 3;
    char* av[] = {"program_name", "10+4", "a"};
    int expected_result = 84;
    int result = s_main(ac, av);
    cr_assert_eq(result, expected_result);
}

Test(check_err9, basic_test_second_part) {
    int ac = 3;
    char* av[] = {"program_name", "0*1*2*3*4", "1+8"};
    int expected_result = 84;
    int result = s_main(ac, av);
    cr_assert_eq(result, expected_result);
}

Test(check_err10, basic_test_second_part) {
    int ac = 3;
    char* av[] = {"program_name", "0*1*2-3*4", "1 + a"};
    int expected_result = 84;
    int result = s_main(ac, av);
    cr_assert_eq(result, expected_result);
}