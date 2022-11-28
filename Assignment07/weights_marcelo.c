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
    w.unit = unit;
    w.amount = amount;
    return w;
}

bool test_within_weight(int line, Weight a, Weight e, double tolerance) {
    bool x = base_test_within_d(__FILE__, line, a.amount, e.amount, tolerance);
    bool u = base_test_equal_i(__FILE__, line, a.unit, e.unit);
    return x && u;
}

/*
Gibt das Gewicht in der aktuellen Einheit zurück. 
@param w sollte die Menge und die Einheit gespeichert habe mit der make_weight Funktion
*/
void print_weight(Weight w) {
    String einheit;
    switch (w.unit) {
    case G:
        einheit = "g";
        break;
    case KG:
        einheit = "kg";
        break;
    case T:
        einheit = "t";
        break;
    case LB:
        einheit = "lbs";
        break;
    default:
        break;
    }
    printf("%.2f %s\n", w.amount, einheit);
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
    switch (w.unit) {
        case G:
            w.amount *= 0.001;
            break;
        case KG:
            break;
        case T:
            w.amount *= 1000;
            break;
        case LB:
            w.amount *= 0.45359237;
            break;
        default:
            break;
    }
    w.unit = KG;
    switch (target_unit) {
        case G:
            w.amount *= 1000;
            break;
        case KG:
            break;
        case T:
            w.amount *= 0.001;
            break;
        case LB:
            w.amount *= 2.20462;
        default:
            break;
    }
    w.unit = target_unit;
    return w;
}

void to_unit_test(void) {
    test_within_weight(__LINE__, to_unit(make_weight(1000, G), KG), make_weight(1, KG), 1e-6);
    test_within_weight(__LINE__, to_unit(make_weight(2204.62, LB), T), make_weight(0.999999, T), 1e-6);
    test_within_weight(__LINE__, to_unit(make_weight(0.0893, T), LB), make_weight(196.872566, LB), 1e-6);
    test_within_weight(__LINE__, to_unit(make_weight(479, KG), G), make_weight(479000, G), 1e-6);
    test_within_weight(__LINE__, to_unit(make_weight(45398, G), KG), make_weight(45.398, KG), 1e-6);
    test_within_weight(__LINE__, to_unit(make_weight(0.45359237, KG), LB), make_weight(0.999999, LB), 1e-6);
}

// Weight, Weight -> int
// Compares two weights. Returns 0 if the two weights are equal, 
// -1 if w is smaller than v and +1 otherwise.
int compare(Weight w, Weight v) {
    switch (w.unit) {
        case G:
            w.amount *= 0.001;
            break;
        case KG:
            break;
        case T:
            w.amount *= 1000;
            break;
        case LB:
            w.amount *= 0.45359237;
            break;
        default:
            break;
    }
    w.unit = KG;
    switch (v.unit) {
        case G:
            v.amount *= 0.001;
            break;
        case KG:
            break;
        case T:
            v.amount *= 1000;
            break;
        case LB:
            v.amount *= 0.45359237;
            break;
        default:
            break;
    }
    v.unit = KG;
    if (v.amount - w.amount < 0) {
        return 1;
    } else {
        if(v.amount - w.amount > 0) {
            return -1;
        } else {
            return 0;
        }
    }
}

void compare_test(void) {
    test_equal_i(compare(make_weight(1000, G), make_weight(1, KG)), 0);
    test_equal_i(compare(make_weight(5, G), make_weight(0.005, KG)), 0);
    test_equal_i(compare(make_weight(8, T), make_weight(8000, KG)), 0);
    test_equal_i(compare(make_weight(1000000, G), make_weight(1, T)), 0);
    test_equal_i(compare(make_weight(5, KG), make_weight(10, LB)), 1);
    test_equal_i(compare(make_weight(9, G), make_weight(1, LB)), -1);
    test_equal_i(compare(make_weight(0.0000001, T), make_weight(1, LB)), -1);
    test_equal_i(compare(make_weight(1, LB), make_weight(1, KG)), -1);
    
}

int main(void) {
    print_weight_test();
    to_unit_test();
    compare_test();
    return 0;
}
