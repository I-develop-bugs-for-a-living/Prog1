/*
Compile: make loops
Run: ./loops
make loops && ./loops
*/

#include "base.h"

// Prints a sequence of n c's.
void printcs(char c, int n) {
    for (int x = 0; x < n; x++) printc(c);
}

void print_row(char outer, char inner, int width) {
    // g) implement, using printc(char c) and println() and helper function printcs (above)
}

// Prints a row like this: +---+ (for n = 4), + (for n = 0), ++ (for n = 1), +-+ (for n = 2)
void print_outer_row(int width) {
    // d) implement, using printc(char c) and println() and helper function printcs (above)
}

// Prints a row like this: |   | (for n = 4), | (for n = 0), || (for n = 1), | | (for n = 2)
void print_inner_row(int width) {
    // e) implement, using printc(char c) and println() and helper function printcs (above)
}

/*
Creates a rectangle of the given width and height.
Examples:
rect(0, 0);
+

rect(0, 1);
+
+

rect(1, 0);
++

rect(1, 1);
++
++

rect(2, 1);
+-+
+-+

rect(4, 3);
+---+
|   |
|   |
+---+
*/
void rect(int width, int height) {
    // f) implement, using helper functions print_inner_row and print_outer_row
}

int main(void) {
    int i;//, j, k;

    // a) convert to a for-loop
    i = 0;
    while (i < 5) {
        printi(i);
        i = i + 1;
    }
    println();

    // for-loop:
    // ...

    // b) convert to a for-loop
    i = 10;
    while (i >= 0) {
        printi(i);
        i = i - 2;
    }
    println();

    // for-loop:
    // ...

    // c) convert to a for-loop
    i = 1;
    while (i < 100000) {
        printiln(i);
        i *= 2;
    }

    // for-loop:
    // ...

    rect(0, 0);
    println();
    rect(0, 1);
    println();
    rect(1, 0);
    println();
    rect(1, 1);
    println();
    rect(2, 1);
    println();
    rect(1, 2);
    println();
    rect(4, 3);
    println();
    rect(7, 4);
    println();

    return 0;
}
