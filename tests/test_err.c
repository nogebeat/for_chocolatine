#include "../include/my.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>


Test(check, basic_test_second_part) {
    int ac = 5;
    char* av[] = {"program_name", "0*a*9", "1*3*5", "2*4*6", "8*8*8"};
    int expected_result = 84;
    int result = s_main(ac, av);
    cr_assert_eq(result, expected_result);
}

Test(check2, basic_test_second_part) {
    int ac = 5;
    char* av[] = {"program_name", "0*0*9", "1*a*5", "2*4*6", "8*8*8"};
    int expected_result = 84;
    int result = s_main(ac, av);
    cr_assert_eq(result, expected_result);
}

Test(check1, basic_test_second_part) {
    int ac = 5;
    char* av[] = {"program_name", "0*0*9", "1*3*5", "2*4rgd6", "8*8*8"};
    int expected_result = 84;
    int result = s_main(ac, av);
    cr_assert_eq(result, expected_result);
}

Test(check3, basic_test_second_part) {
    int ac = 5;
    char* av[] = {"program_name", "0*0*9", "1*3*5", "2*4*6", "8*fdn*8"};
    int expected_result = 84;
    int result = s_main(ac, av);
    cr_assert_eq(result, expected_result);
}

Test(check4, basic_test_second_part) {
    int ac = 5;
    char* av[] = {"program_name", "0*0dsbs*9", "1*3dsbvsw*5", "2*4dsvbwd*6", "8*dvwsd8*8"};
    int expected_result = 84;
    int result = s_main(ac, av);
    cr_assert_eq(result, expected_result);
}
