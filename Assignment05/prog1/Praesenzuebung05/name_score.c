/*
Compile: make name_score
Run: ./name_score
make name_score && ./name_score
*/

#include "base.h"

// todo: write purpose statement
int score(String name) {
    int i = 0;
    int score = 0;
    while (i < s_length(name)) {
        // every vowel is worth 1 point
        if (s_get(name, i) == 'a' || s_get(name, i) == 'e' || s_get(name, i) == 'i' || s_get(name, i) == 'o' || s_get(name, i) == 'u') {
            score++;
        } else if (s_get(name, i) == 'j' || s_get(name, i) == 'p' || s_get(name, i) == 'q') {
                score += 5;
        } else if (s_get(name, i) >= 'v')
        {
            score += 3;
        } else if (s_get(name, i) >= 'a' && s_get(name, i) <= 'z') {
            printf("Vowel: %c", s_get(name, i));
            
        } else {
            printf("Invalid character: %c \n", s_get(name, i));
            return -1;
        }

        i++;
        
    }
    return score; // todo: implement
}

void test_score(void) {
    test_equal_i(score("saeiou"), 5);
    test_equal_i(score("aeiroua"), 6);
    test_equal_i(score("qhjp"), 15);
    test_equal_i(score("qjcpv"), 18);
    test_equal_i(score("äöü"), -1);
    test_equal_i(score("a b"), -1);
}

int main(void) {
    test_score();
    printsln("Geben Sie Ihren Namen ein: ");
    String name = s_input(100);
    prints("Der Score für Ihren Namen ist: ");
    int s = score(name);
    printiln(s);
    return 0;
}
