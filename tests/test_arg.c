#include "../include/my.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(check_arg, basic_test_second_part) {
    int expected_result = 84;
    int result = valid_n_arg(0);
    cr_assert_eq(result, expected_result);
}

Test(check_arg1, basic_test_second_part) {
    int expected_result = 84;
    int result = valid_n_arg(1);
    cr_assert_eq(result, expected_result);
}

Test(check_arg2, basic_test_second_part) {
    int expected_result = 0;
    int result = valid_n_arg(2);
    cr_assert_eq(result, expected_result);
}

Test(check_arg3, basic_test_second_part) {
    int expected_result = 84;
    int result = valid_n_arg(3);
    cr_assert_eq(result, expected_result);
}

Test(check_arg4, basic_test_second_part) {
    int expected_result = 0;
    int result = valid_n_arg(4);
    cr_assert_eq(result, expected_result);
}

Test(check_arg5, basic_test_second_part) {
    int expected_result = 84;
    int result = valid_n_arg(5);
    cr_assert_eq(result, expected_result);
}

Test(check_arg6, basic_test_second_part) {
    int expected_result = 0;
    int result = valid_n_arg(6);
    cr_assert_eq(result, expected_result);
}

Test(check_ilid1, basic_test_second_part) {
    int ac = 3;
    char* av[] = {"program_name", "0*1*2*3*4", "1"};
    int expected_result = 0;
    int result = validate_coefficient(av, ac);
    cr_assert_eq(result, expected_result);
}

Test(check_lid2, basic_test_second_part) {
    int ac = 5;
    char* av[] = {"program_name", "0*0*9", "1*3*5", "2*4*6", "8*8*8"};
    int expected_result = 0;
    int result = validate_coefficient(av, ac);
    cr_assert_eq(result, expected_result);
}

Test(checat1, basic_test_second_part) {
    int ac = 6;
    char* av[] = {"program_name", "0*0.654*9", "1*3*5", "2*4*6", "8*8*8", "0*4*0*7"};
    int expected_result = 84;
    int result = validate_coefficient(av, ac);
    cr_assert_eq(result, expected_result);
}

Test(cheat, basic_test_second_part) {
    int ac = 5;
    char* av[] = {"program_name", "0*0.654*9", "1*3*5", "2*4*6", "8*8*8"};
    int expected_result = 84;
    int result = validate_coefficient(av, ac);
    cr_assert_eq(result, expected_result);
}

Test(checrr0, basic_test_second_part) {
    int ac = 3;
    char* av[] = {"program_name", "0*1*2*3*4", "z"};
    int expected_result = 84;
    int result = validate_coefficient(av, ac);
    cr_assert_eq(result, expected_result);
}
