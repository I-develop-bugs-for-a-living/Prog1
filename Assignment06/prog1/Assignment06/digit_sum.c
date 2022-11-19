<<<<<<< HEAD
#include "base.h"
/*bildet die Quersumme oder die alternierende Quersumme*/
int digit_sum(unsigned number, bool alternating) {
    int sum = 0;
    int value = 1;
    String string_of_int = s_of_int(number);
    //printf("Digit: %s \n", string_of_int);
    if (alternating) {
        for(int i = 0; i < s_length(string_of_int); i++) {
            sum += (s_get(string_of_int, i) - 48) * value;
            value *= -1;
            //printiln(sum);
        }
    } else {
        for(int i = 0; i < s_length(string_of_int); i++) {
            //printc(s_get(string_of_int, i));
            sum += s_get(string_of_int, i) - 48;
            //printiln(sum);
        }
    }
    //printf("\n");
    
    return sum;
}

bool divisible_by_eleven(unsigned number) {
    // OPTIONAL TODO
    return false;
}


void digit_sum_test() {
    // TODO
    test_equal_i(digit_sum(10, false), 1);
    test_equal_i(digit_sum(333, false), 9);
    test_equal_i(digit_sum(333, true), 3);
    test_equal_i(digit_sum(3333, true), 0);
    test_equal_i(digit_sum(234, true), 3);
    test_equal_i(digit_sum(3333, false), 12);

    // OPTIONAL TODO
    // test_equal_i(divisible_by_eleven(12), false);
    // test_equal_i(divisible_by_eleven(11), true);
}

int main(void) {
    digit_sum_test();
    return 0;
}
=======
#include "base.h"
/*bildet die Quersumme oder die alternierende Quersumme*/
int digit_sum(unsigned number, bool alternating) {
    int sum = 0;
    int value = 1;
    String string_of_int = s_of_int(number);
    //printf("Digit: %s \n", string_of_int);
    if (alternating) {
        for(int i = 0; i < s_length(string_of_int); i++) {
            sum += (s_get(string_of_int, i) - 48) * value;
            value *= -1;
            //printiln(sum);
        }
    } else {
        for(int i = 0; i < s_length(string_of_int); i++) {
            //printc(s_get(string_of_int, i));
            sum += s_get(string_of_int, i) - 48;
            //printiln(sum);
        }
    }
    //printf("\n");
    
    return sum;
}

bool divisible_by_eleven(unsigned number) {
    // OPTIONAL TODO
    return false;
}


void digit_sum_test() {
    // TODO
    test_equal_i(digit_sum(10, false), 1);
    test_equal_i(digit_sum(333, false), 9);
    test_equal_i(digit_sum(333, true), 3);
    test_equal_i(digit_sum(3333, true), 0);
    test_equal_i(digit_sum(234, true), 3);
    test_equal_i(digit_sum(3333, false), 12);

    // OPTIONAL TODO
    // test_equal_i(divisible_by_eleven(12), false);
    // test_equal_i(divisible_by_eleven(11), true);
}

int main(void) {
    digit_sum_test();
    return 0;
}
>>>>>>> d0c02ad8a49113f835b449f0074b7d510f131094
