/*
Compile: make loops
Run: ./loops
make loops && ./loops
*/

#include "base.h"

void loops_a(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++){
            printf("%d ", j);
        }
        printf("\n");
    }
    printf("\n");
}

void loops_b(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = i; j < n; j++) {
            printf("  ");
        }
        for (int k = 1; k <= i; k++) {
            printf("%d ", k);
        }
        printf("\n");
    }
    printf("\n");
}

void loops_c(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = i; j < n; j++) {
            printf("  ");
        }
        for (int k = 1; k <= i; k++) {
            printf("% d  ", k);
        }
        printf("\n");
    }
    printf("\n");
}

void loops_d(int n) {
    int max = n / 2;
    int min = 0;
    int number = 0;
    int intervall = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i == j) || (i + j) == n - 1) {
                printf("%d", number);
            } else {
                printf(" ");
            }
        }
    if (number == max) {
        intervall *= -1;
    }
    number += intervall;
    printf("\n");
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
    loops_a(5);
    loops_b(5);
    loops_c(5);
    loops_d(5);
    loops_a(9);
    loops_b(9);
    loops_c(9);
    loops_d(9);
    loops_e(3);
    loops_e(4);
    loops_e(5);
    loops_e(9);
    loops_e(12);
    loops_f(5);
    loops_f(9);
    return 0;
}
