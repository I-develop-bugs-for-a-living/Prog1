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
    int limit = (n - 1) / 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || i + j == n-1) {
                if (i < limit) {
                    printf("%d ", i);
                } else {
                printf("%d ", n-1-i);
                }
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

// todo: implement helper functions for loops_e (recommended)
/*

    +--------+
   /        /
  /        /
 /        /
+--------+

*/

void middle_part(int n) {
    for (int i = 0; i < n; i++) {
        if (i == 0 || i == n-1) {
            printf("/");
        } else {
            printf(" ");
        }
    }
}

void edges(int n) {
    for (int i = 0; i < n; i++) {
        if (i == 0 || i == n-1) {
            printf("+");
        } else {
            printf("-");
        }
    }
}

void loops_e(int n) {
    // todo: implement
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i; j++) {
            printf(" ");
        }
        if (i == 0 || i == n-1) {
            edges(n*2);
        } else {
            middle_part(n*2);
        }
        printf("\n");
    }

}

// todo: implement helper functions for loops_f (recommended)

void middle_part_f(int n, bool new) {
    static int num = 0;
    if (new) {
        num = 0;
    }

    for (int i = 0; i < n/2; i++) {
        if (i == 0 || i == n/2) {
            printf("/");
        } else {
            printf("%d ", num);
            num++;
            if (num > 9) {
                num = 0;
            }
        }
    }
    printf("/");
}

void loops_f(int n) {
    bool new = true;
    // todo: implement
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i; j++) {
            printf(" ");
        }
        if (i == 0 || i == n-1) {
            edges(n*2);
        } else {
            middle_part_f(n*2, new);
            new = false;
        }
        printf("\n");
    }
}

int main(void) {
    // loops_a(5);
    // loops_b(5);
    // loops_c(5);
    // loops_d(5);
    // loops_a(9);
    // loops_b(9);
    // loops_c(9);
    // loops_d(9);
    //loops_e(3);
    //loops_e(4);
    //loops_e(5);
    //loops_e(9);
    //loops_e(12);
    loops_f(5);
    loops_f(9);
    return 0;
}
