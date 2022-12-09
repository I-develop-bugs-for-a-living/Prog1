/*
make count_utf8 && ./count_utf8
*/
#include "base.h"

/*
Encoding of UTF-8 characters:
# byte 1   byte 2   byte 3   byte 4
1 0xxxxxxx 
2 110xxxxx 10xxxxxx
3 1110xxxx 10xxxxxx 10xxxxxx
4 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
*/

int count_utf8(void) {
    // implement
    return 0;
}

int main(void) {
    int n = count_utf8();
    printf("%d\n", n);
    return 0;
}
