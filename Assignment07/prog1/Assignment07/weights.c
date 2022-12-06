/*
Compile: make weights
Run: ./weights
*/

#include "base.h"

// 1 lb = 0.45359237 kg

typedef enum unit_e {
    G,
    KG,
    T,
    LB
} Unit;


typedef struct weight_s {
    double amount;
    Unit unit;
} Weight;

Weight make_weight(double amount, Unit unit) {
    // todo
    Weight w;
    w.amount = amount;
    w.unit = unit;
    return w;
}

bool test_within_weight(int line, Weight a, Weight e, double tolerance) {
    bool x = base_test_within_d(__FILE__, line, a.amount, e.amount, tolerance);
    bool u = base_test_equal_i(__FILE__, line, a.unit, e.unit);
    return x && u;
}

void print_weight(Weight w) {
    // todo
    String unit;
    switch (w.unit) {
        case G:
            unit = "g";
            break;
        case KG:
            unit = "kg";
            break;
        case T:
            unit = "t";
            break;
        case LB:
            unit = "LBS";
            break;
    }
    printf("%.2f %s \n", w.amount, unit);
}

void print_weight_test() {
    print_weight(make_weight(1234, G));
    print_weight(make_weight(4.749, KG));
    print_weight(make_weight(3.1001, T));
    print_weight(make_weight(5.40006, LB));
}

// Weight, Unit -> Weight
// Convert weight to the given target unit.
Weight to_unit(Weight w, Unit target_unit) {
    float LB_IN_KG = 0.4535923;
    // todo
    double grams = 0;
    // first convert to gramms then to target unit
    switch (w.unit) {
        case (G):
            grams = (double)w.amount;
            break;

        case (KG):
            grams = (double)(w.amount * 1000);
            break;

        case (T):
            grams = (double)(w.amount * 1000 * 1000);
            break;

        case (LB):
            grams = (double)(w.amount * LB_IN_KG * 1000);
            break;
    }
    // convert to target unit
    switch (target_unit) {
        case G:
            return make_weight(grams, G);
            break;
        case KG:
            return make_weight(grams / 1000, KG);
            break;
        case T:
            return make_weight(grams / (1000 * 1000), T);
            break;
        case LB:  
            return make_weight((grams / (1000)) * LB_IN_KG, LB);
            break;

    }
}

void to_unit_test(void) {
    test_within_weight(__LINE__, to_unit(make_weight(1000, G), KG), make_weight(1, KG), 1e-6);
    // todo: add tests (at least 5)
    test_within_weight(__LINE__, to_unit(make_weight(100, G), KG), make_weight(0.1, KG), 1e-6);
    test_within_weight(__LINE__, to_unit(make_weight(1000, KG), T), make_weight(1, T), 1e-6);
    test_within_weight(__LINE__, to_unit(make_weight(40, KG), LB), make_weight(18.1437, LB), 1e-4);
    test_within_weight(__LINE__, to_unit(make_weight(1, T), G), make_weight(1 * 1000 * 1000, G), 1e-6);
    test_within_weight(__LINE__, to_unit(make_weight(10, T), KG), make_weight(10000, KG), 1e-6);
}

// Weight, Weight -> int
// Compares two weights. Returns 0 if the two weights are equal, 
// -1 if w is smaller than v and +1 otherwise.
int compare(Weight w, Weight v) {
    // todo
    Weight weight_in_same_unit = to_unit(v, w.unit);
    if (weight_in_same_unit.amount == w.amount) {
        return 0;
    } else if (weight_in_same_unit.amount >= w.amount) {
        return -1;
    } else {
        return 1;
    }
    return 0;
}

void compare_test(void) {
    test_equal_i(compare(make_weight(1000, G), make_weight(1, KG)), 0);
    // todo: add tests (at least 5)
    test_equal_i(compare(make_weight(1001, G), make_weight(1, KG)), 1);
    test_equal_i(compare(make_weight(999, G), make_weight(1, KG)), -1);
    test_equal_i(compare(make_weight(50, LB), make_weight(100, KG)), 1);
    test_equal_i(compare(make_weight(51, T), make_weight(100, G)), 1);
    test_equal_i(compare(make_weight(1, T), make_weight(1001, KG)), -1);
}

int main(void) {
    print_weight_test();
    to_unit_test();
    compare_test();
    return 0;
}
