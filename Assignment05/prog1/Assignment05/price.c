/*
 * Compile:         make X
 * Run:             ./X
 * Compile and Run: make X && ./X
 */
#include "base.h" // prog1lib

// todo: define constants
const int KLEINE_MENGE_GRENZE = 10;
const int KLEINE_MENGE_PREIS = 90;
const int GROSSE_MENGE_GRENZE = 50;
const int GROSSE_MENGE_PREIS = 75;
const int MINDEST_MENGE_GRENZE = 0;
const int MINDEST_MENGE_PREIS = 0;
const int MINDEST_BESTELLWERT = 2000;
const int VERSANDKOSTEN_PAUSCHALE = 500;

// Hello to you

// todo: write function price

/* 
The function price calculates the price for a given amount of items.
The price is calculated according to the following rules:
- If the amount is smaller than 10, the price is 100 cents per item.
- If the amount is between 10 and 50, the price is 90 cents per item.
- If the amount is larger than 50, the price is 75 cents per item.
- If the amount is smaller than 0, the price is 0 cents per item.
- If the total price is smaller than 2000 cents, 500 cents are added to the total price.
*/

int price(int menge) {
    double preis = 0;
    if (menge <= MINDEST_MENGE_GRENZE) {
        return MINDEST_MENGE_PREIS;
    } else if (menge < KLEINE_MENGE_GRENZE) {
        preis = menge * 100;
    } else if (menge < GROSSE_MENGE_GRENZE) {
        preis = menge * KLEINE_MENGE_PREIS;
    } else if (menge >= GROSSE_MENGE_GRENZE) {
        preis = menge * GROSSE_MENGE_PREIS;
    } else {
        preis = MINDEST_MENGE_PREIS;
    }
    if (preis < MINDEST_BESTELLWERT) {
        // printf("Added Versand to %f\n", preis);
        preis = preis + VERSANDKOSTEN_PAUSCHALE;
        // printd(preis);
    }
    return preis; 
};

// todo: write function price_test
void price_test(void) {
    test_equal_i(price(1), 600);
    test_equal_i(price(10),1400);
    test_equal_i(price(11),1490);
    test_equal_i(price(30),2700);
    test_equal_i(price(50),3750);
    test_equal_i(price(51),3825);
    test_equal_i(price(-1), 0);
    test_equal_i(price(0), 0);
    test_equal_i(price(22), 2480);
};

// test returned values of price using test_equal_i

int main(void) {
    // todo: call price_test function
    price_test();
    return 0;
}