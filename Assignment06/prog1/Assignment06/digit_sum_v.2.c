#include "base.h"

/*Überprüft die Anzahl der Ziffern der Zahl*/
int even_or_uneven (int number) {
    int times;
    while(number) {
        number /= 10;
        times++;
    }
    if (times % 2 == 0){
        return -1;
    } else {
        return 1;
    }
}


/*bildet die Quersumme oder die alternierende Quersumme*/
int digit_sum(unsigned number, bool alternating) {
    int sum = 0;
    int sign = even_or_uneven(number);
    while (number) {
        if (alternating) {
            sum += number % 10 * sign;
            number /= 10;
            sign *= -1;
        } else {
            sum += number % 10;
            number /= 10;
        }
    }
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
    test_equal_i(digit_sum(463, false), 13);
    test_equal_i(digit_sum(6497, true), 4);
    

    // OPTIONAL TODO
    // test_equal_i(divisible_by_eleven(12), false);
    // test_equal_i(divisible_by_eleven(11), true);
}

int main(void) {
    digit_sum_test();
    return 0;
}
