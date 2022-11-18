/*
Compile: make park_house
Run: ./park_house
make park_house && ./park_house
*/

#include "base.h"

/* Design a function that returns the state of a park house given the number
of free parking spots */

typedef enum ParkHouseState {
	// todo
    fullParkHouse,
    almostfullParkHouse,
    freeParkHouse
} ParkHouseState;

ParkHouseState det_park_house_state(int free_spots);

String print_park_house_state(ParkHouseState state);

static void det_park_house_state_test() {
    //todo
    test_equal_i(det_park_house_state(0), fullParkHouse);
    test_equal_i(det_park_house_state(1), almostfullParkHouse);
    test_equal_i(det_park_house_state(12), freeParkHouse);

}
//a) todo
ParkHouseState det_park_house_state(int free_spots) {
    switch (free_spots ? (free_spots / 10) : -1) {
        case -1:
            return fullParkHouse;
        case 0:
            return almostfullParkHouse;
        default:
            return freeParkHouse;
    }
    return fullParkHouse;
}

// b) todo
String print_park_house_state(ParkHouseState state) {
    switch (state) {
        case fullParkHouse:
            return "The Park House is full";
        case almostfullParkHouse:
            return "The Park House is almost full";
        case freeParkHouse:
            return "The Park House is free";
        default:
            return "unknown";
    }
    return "";
}


int main(void) {
    det_park_house_state_test();
    printsln(print_park_house_state(det_park_house_state(0)));
    printsln(print_park_house_state(det_park_house_state(8)));
    printsln(print_park_house_state(det_park_house_state(21)));
    printsln(print_park_house_state(det_park_house_state(100)));
    while(true) {
        printf("Enter the number of free parking spots: ");
        int free_spots = i_input();
        printsln(print_park_house_state(det_park_house_state(free_spots)));
    }
    return 0;
}

