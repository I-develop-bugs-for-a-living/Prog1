/*
 * Compile:         make X
 * Run:             ./X
 * Compile and Run: make X && ./X
 */
#include "base.h" // prog1lib

// todo: define constants
int preis = 100;
int mengenrabatt_klein = 10;
int preis_mengenrabatt_klein = 90;
int mengenrabatt_groß = 50;
int preis_mengenrabatt_groß = 75;
int versandfrei = 2000;
int versandpauschale = 500;

// todo: write function price
int kosten;
int price(int einheiten) {
    if (einheiten < 0) {
        return 0;
    }else if(einheiten >= mengenrabatt_groß) {
        kosten = einheiten * preis_mengenrabatt_groß;
    } else if (einheiten >= mengenrabatt_klein) {
        kosten = einheiten * preis_mengenrabatt_klein;
    } else {
        kosten = einheiten*preis;
    }
    
    if (kosten < versandfrei) {
        return kosten + versandpauschale;
    } else {
        return kosten;
    }
}
// todo: write function price_test
// test returned values of price using test_equal_i
void price_test(void) {
    test_equal_i(price(2), 700);
    test_equal_i(price(-5), 0);
    test_equal_i(price(10), 1400);
    test_equal_i(price(20), 2300);
    test_equal_i(price(50), 3750);
    test_equal_i(price(100), 7500);
}


int main(void) {
    // todo: call price_test function
    price_test();
    return 0;
}

