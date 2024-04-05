#include "../include/my.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>


Test(check_err1, basic_test_second_part) {
    int ac = 3;
    char* av[] = {"program_name", "a*1*2*3*4", "1"};
    int expected_result = 84;
    int result = s_main(ac, av);
    cr_assert_eq(result, expected_result);
}

Test(check_err2, basic_test_second_part) {
    int ac = 3;
    char* av[] = {"program_name", "0*a*2*3*4", "1"};
    int expected_result = 84;
    int result = s_main(ac, av);
    cr_assert_eq(result, expected_result);
}

Test(check_err3, basic_test_second_part) {
    int ac = 3;
    char* av[] = {"program_name", "0*1*a*3*4", "1"};
    int expected_result = 84;
    int result = s_main(ac, av);
    cr_assert_eq(result, expected_result);
}

Test(check_err4, basic_test_second_part) {
    int ac = 3;
    char* av[] = {"program_name", "0*1*2*ug*4", "1"};
    int expected_result = 84;
    int result = s_main(ac, av);
    cr_assert_eq(result, expected_result);
}

Test(check_err5, basic_test_second_part) {
    int ac = 3;
    char* av[] = {"program_name", "0*1*2*3*e", "1"};
    int expected_result = 84;
    int result = s_main(ac, av);
    cr_assert_eq(result, expected_result);
}