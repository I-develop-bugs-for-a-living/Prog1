#include "base.h"

int main(void) {
    printiln(number_of_days(4));

}

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