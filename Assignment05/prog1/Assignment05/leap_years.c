/*
 * Compile:         make X
 * Run:             ./X
 * Compile and Run: make X && ./X
 */
#include "base.h" // prog1lib

int number_of_days(int year) {
    bool multiple_of_four = year % 4 == 0;
    bool multiple_of_hundred = year % 4 == 0;
    bool multiple_of_fourhundred = year % 4 == 0;
    if(!multiple_of_four || (multiple_of_hundred && !multiple_of_fourhundred)) {
        return 365;
    } else {
        return 366;
    }
}
int main(void) {
    test_equal_i(number_of_days(4), 366);
    test_equal_i(number_of_days(50), 365);
    test_equal_i(number_of_days(400), 366);
    test_equal_i(number_of_days(2022), 365);
}