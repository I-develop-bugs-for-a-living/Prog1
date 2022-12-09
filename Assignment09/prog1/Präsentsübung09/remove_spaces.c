/*
make remove_spaces && ./remove_spaces
*/
#include "base.h"

// Variante 1:
// void remove_spaces(char *s)
// {
//     int j = 0;
//     for (int i = 0; s[i] != '\0'; i++) {
//         if (s[i] != ' ') {
//             s[j] = s[i];
//             j++;
//         }
//     }
//     s[j] = '\0';
// }


// Variante 2:
void remove_spaces(char *s)
{
    char *j = s;
    for (; *s != '\0'; s++) {
        if (*s != ' ') {
            *j = 'a';
            j++;
        }
    }
    *j = '\0';
}

int main(void)
{
    char s[64];

    strcpy(s, "a   bb   c ");
    remove_spaces(s);
    test_equal_s(s, "abbc");

    strcpy(s, " aa  bbb cccc ");
    remove_spaces(s);
    test_equal_s(s, "aabbbcccc");

    strcpy(s, "   ");
    remove_spaces(s);
    test_equal_s(s, "");

    return 0;
}
