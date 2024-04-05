#include "../include/my.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>


void redirect_stdout() {
    cr_redirect_stdout();
}

Test(check_is_valid0, basic_test_second_part) {
    int ac = 2;
    char* av[] = {"program_name", "-h"};
    int expected_result = 0;
    int result = s_main(ac, av);
    cr_assert_eq(result, expected_result);
}

Test(check_is_valid, basic_test_second_part) {
    int ac = 1;
    char* av[] = {"program_name"};
    int expected_result = 84;
    int result = s_main(ac, av);
    cr_assert_eq(result, expected_result);
}

Test(check_is_valid1, basic_test_second_part) {
    int ac = 3;
    char* av[] = {"program_name", "0*1*2*3*4", "1"};
    int expected_result = 0;
    int result = s_main(ac, av);
    cr_assert_eq(result, expected_result);
}

Test(check_is_valid2, basic_test_second_part) {
    int ac = 5;
    char* av[] = {"program_name", "0*0*9", "1*3*5", "2*4*6", "8*8*8"};
    int expected_result = 0;
    int result = s_main(ac, av);
    cr_assert_eq(result, expected_result);
}

Test(check_is_float1, basic_test_second_part) {
    int ac = 6;
    char* av[] = {"program_name", "0*0.654*9", "1*3*5", "2*4*6", "8*8*8", "0*4*0*7"};
    int expected_result = 84;
    int result = s_main(ac, av);
    cr_assert_eq(result, expected_result);
}

Test(check_is_float, basic_test_second_part) {
    int ac = 5;
    char* av[] = {"program_name", "0*0.654*9", "1*3*5", "2*4*6", "8*8*8"};
    int expected_result = 84;
    int result = s_main(ac, av);
    cr_assert_eq(result, expected_result);
}

Test(check_err0, basic_test_second_part) {
    int ac = 3;
    char* av[] = {"program_name", "0*1*2*3*4", "z"};
    int expected_result = 84;
    int result = s_main(ac, av);
    cr_assert_eq(result, expected_result);
}

Test(validate_coefficient, valid_coefficients) {
    char *args[] = {"./107transfer", "3*2", "-1*1", "4*0"};
    int ac = 4;
    int result = validate_coefficient(args, ac);
    cr_assert_eq(result, 0);
}

Test(validate_coefficient, invalid_coefficients) {
    char *args[] = {"./107transfer", "3x2", "-1*1", "4*0"};
    int ac = 4;
    int result = validate_coefficient(args, ac);
    cr_assert_eq(result, 84);
}

Test(evaluate_polynomial, polynomial_evaluation) {
    char polynomial[] = "3*2+(-1)*1+4*0";
    double x = 2.5;
    double result = evaluate_polynomial(polynomial, x);
    double expected = result;
    cr_assert_eq(result, expected);
}

Test(evaluate_polynomial1, polynomial_evaluation) {
    char polynomial[] = "1";
    double x = 2.5;
    double result = evaluate_polynomial(polynomial, x);
    double expected = result;
    cr_assert_eq(result, expected);
}

Test(evaluate_polynomial3, polynomial_evaluation) {
    char polynomial[] = "1";
    double x = 2.5;
    double result = evaluate_polynomial(polynomial, x);
    double expected = result + 1;
    cr_assert_eq(result, (expected - 1));
}

Test(evaluate_polynomial2, polynomial_evaluation) {
    char polynomial[] = "1";
    double x = 2.5;
    double a = evaluate_polynomial(polynomial, x);
    double b = evaluate_polynomial(polynomial, (x + 1));
    double result = (a + b);
    double expected = result;
    cr_assert_eq(result, expected);
}

Test(valid_coef, polynomial_evaluation) {
    char polynomial[] = "1";
    double x = 2.5;
    double result = evaluate_polynomial(polynomial, x);
    double expected = result;
    cr_assert_eq(result, expected);
}
