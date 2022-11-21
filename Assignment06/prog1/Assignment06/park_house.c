/*
Compile: make park_house
Run: ./park_house
make park_house && ./park_house
*/

#include "base.h"

/* Design a function that returns the state of a park house given the number
of free parking spots */

/*Definiert die einzelnen Zustände des Parkhauses*/

typedef enum ParkHouseState {
    FULL_PARK_HOUSE = 0,
    NEARLY_FULL_PARK_HOUSE,
    FREE_PARK_HOUSE = 10,
} ParkHouseState;

ParkHouseState det_park_house_state(int free_spots);

String print_park_house_state(ParkHouseState state);

/*Testet ob det_park_house_state richtig funktioniert*/
static void det_park_house_state_test() {
    test_equal_i(det_park_house_state(0), 0);
    test_equal_i(det_park_house_state(5), 1);
    test_equal_i(det_park_house_state(90), 10);
    test_equal_i(det_park_house_state(10), 10);
}

/*Bestimmt den Zustand des Parkhauses und gibt ihn als ParkHouseState aus*/
ParkHouseState det_park_house_state(int free_spots) {
    /*Verhindert das eine negative Zahl eingegeben wird*/
    if (free_spots < 0) {
        printsln("free spots, error: negative amount");
        exit(1);
        } else if (free_spots == FULL_PARK_HOUSE) {
            return FULL_PARK_HOUSE;
        } else if (free_spots < FREE_PARK_HOUSE && free_spots > FULL_PARK_HOUSE) {
            return NEARLY_FULL_PARK_HOUSE;
        } else {
            return FREE_PARK_HOUSE;
    }
    return 0;
}
/* b) Gibt den aktuellen Zustand des Parkhaus als String aus,
 basierend auf den ausgegeben Zustand von der Funktion det_park_house_state. */
String print_park_house_state(ParkHouseState state) {
    switch (state) {
    case FREE_PARK_HOUSE:
        return "Das Parkhaus hat frei Plätze.";
        break;
    case NEARLY_FULL_PARK_HOUSE:
        return "Das Parkhaus ist fast voll.";
        break;
    case FULL_PARK_HOUSE:
        return "Das Parkhaus ist voll.";
        break;
    default:
        break;
    }
    return 0;
}


int main(void) {
    det_park_house_state_test();
    printsln(print_park_house_state(det_park_house_state(0)));
    printsln(print_park_house_state(det_park_house_state(8)));
    printsln(print_park_house_state(det_park_house_state(21)));
    return 0;
}

