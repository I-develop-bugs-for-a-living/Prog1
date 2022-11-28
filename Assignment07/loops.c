/*
Compile: make loops
Run: ./loops
make loops && ./loops
*/

#include "base.h"

void loops_a(int n) {
    // todo: implement
    for (int i = 1; i < n+1; i++) {

        for (int j = 1; j < i+1; j++) {
            printf("%d ", j);
        }
        printf("\n");
    
    }
}

void loops_b(int n) {
    // todo: implement
    for (int i = 1; i < n+1; i++) {
        for (int j = n - i + 1; j > 1; j--) {
            printf("  ");
        }
        for (int k = 1; k < i+1; k++) {
            printf("%d ", k);
        }
        printf("\n");
    }
}

void loops_c(int n) {
    // todo: implement
    for (int i = 1; i < n+1; i++) {
        for (int j = n + 1 - i; j > 1; j--) {
            printf(" ");
        }
        for (int k = 1; k < i+1; k++) {
            printf("%d ", k);
        }
        printf("\n");
    }
}

/*
0       0
  1   1  
    2    
  1   1  
0       0
*/

void loops_d(int n) {
    // todo: implement
    for (int i = 0; i < n; i++) {
        for (int j = n - i; j < n; j++) {
            printf("  ");
        }

        printf("%d", i);

        for (int k = 0; k < n - i; k++) {
            printf(" ");
        }

        printf("%d \n", i);
    }
}

// todo: implement helper functions for loops_e (recommended)

void loops_e(int n) {
    // todo: implement
}

// todo: implement helper functions for loops_f (recommended)

void loops_f(int n) {
    // todo: implement
}

int main(void) {
    // loops_a(5);
    // loops_b(5);
    // loops_c(5);
    loops_d(5);
    // loops_a(9);
    // loops_b(9);
    // loops_c(9);
    // loops_d(9);
    loops_e(3);
    loops_e(4);
    loops_e(5);
    loops_e(9);
    loops_e(12);
    loops_f(5);
    loops_f(9);
    return 0;
}
