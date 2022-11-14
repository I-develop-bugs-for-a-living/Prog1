/*
 * Compile:         make X
 * Run:             ./X
 * Compile and Run: make X && ./X
 */
#include "base.h" // prog1lib

// todo: define constants
const short KLEINE_MENGE_GRENZE = 10;
const float KLEINE_MENGE_PREIS = 0.9;
const short GROSSE_MENGE_GRENZE = 50;
const float GROSSE_MENGE_PREIS = 0.75;
const short MINDEST_MENGE_GRENZE = 0;
const float MINDEST_MENGE_PREIS = 0;
const short MINDEST_BESTELLWERT = 20;
const short VERSANDKOSTEN_PAUSCHALE = 5;

// Hello to you

// todo: write function price
int price(int menge) {
    int preis = 0;
    if (menge < KLEINE_MENGE_GRENZE) {
        preis = menge * 1;
    } else if (menge < GROSSE_MENGE_GRENZE) {
        preis = menge * KLEINE_MENGE_PREIS;
    } else {
        preis = menge * GROSSE_MENGE_PREIS;
    }
    if (preis < MINDEST_BESTELLWERT) {
        preis = preis + VERSANDKOSTEN_PAUSCHALE;
    }
    return preis; // Convert in cent
};

// todo: write function price_test
void price_test(void) {
    int result = price(9);
    printf("Menge 10: %d \n", result);
};

// test returned values of price using test_equal_i

int main(void) {
    // todo: call price_test function
    price_test();
    return 0;
}

