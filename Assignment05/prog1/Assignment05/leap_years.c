<<<<<<< HEAD
#include "base.h"

int number_of_days(int year) {
    bool multiple_of_four = (year % 4 == 0);
    bool multiple_of_hundred = (year % 100 == 0);
    bool multiple_of_fourhundred = (year % 400 == 0);
    if (!multiple_of_four || (multiple_of_hundred && !multiple_of_fourhundred) ) {
        return 365;
    } else {
        return 366;
    }
}

int test_number_of_years(void) {
    test_equal_i(number_of_days(2000), 366);
    test_equal_i(number_of_days(2001), 365);
    test_equal_i(number_of_days(2002), 365);
    test_equal_i(number_of_days(2003), 365);
    test_equal_i(number_of_days(2004), 366);
    test_equal_i(number_of_days(10), 365);
    test_equal_i(number_of_days(100), 365);
    test_equal_i(number_of_days(400), 366);
    test_equal_i(number_of_days(800), 366);
    test_equal_i(number_of_days(1200), 366);
    return 0;
}

int main(void) {
    test_number_of_years();
    return 0;
=======
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
>>>>>>> d0c02ad8a49113f835b449f0074b7d510f131094
}