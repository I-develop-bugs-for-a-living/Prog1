#include "base.h"

int indentation(char * s) {
    require_not_null(s);
    // todo
    int counter = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ') {
            counter++;
        } else if (s[i] == '\t') {
            return -1;
        } else {
            return counter;
        }
    }
    return counter;
}

char * left_trim(char * s) {
    for(; *s != '\0';) {
        if (*s == ' ') {
            s++;
        } else if (*s == '\t') {
            for (; *s != '\0'; s++) {
            }
            return s;
        } else {
            return s;
        }
    };
    return s;
}

char * extract_comment(char * s) {
    require_not_null(s);
    // todo
    bool slash = false;
    for (; *s != '\0'; s++) {
        if (*s == '/') {
            if (slash == true) {
                s++;
                for (; *s != '\0'; s++) {
                    if (*s == ' ') {

                    } else {
                        return s;
                    }
                }
            }
            slash = true;
        } else if (*s != '/') {
            slash = false;
        }
    }
    return s;
}

void indentation_test(void) {
    test_equal_i(indentation(""), 0);
    test_equal_i(indentation(" "), 1);
    test_equal_i(indentation("x"), 0);
    test_equal_i(indentation("\t"), -1); // error
    test_equal_i(indentation("  "), 2);
    test_equal_i(indentation("x "), 0);
    test_equal_i(indentation("\t "), -1); // error
    test_equal_i(indentation(" x"), 1);
    test_equal_i(indentation("xy"), 0);
    test_equal_i(indentation("\tx"), -1); // error
    test_equal_i(indentation(" \t"), -1); // error
    test_equal_i(indentation("  \t"), -1); // error
    test_equal_i(indentation("x\t"), 0);
    test_equal_i(indentation("\t\t"), -1); // error
    test_equal_i(indentation("    \tx"), -1); // error
    test_equal_i(indentation("    \t x"), -1); // error
    test_equal_i(indentation("xy \t"), 0);
    test_equal_i(indentation(" xyz \t"), 1);
    test_equal_i(indentation("  abcd \t"), 2);
    test_equal_i(indentation("    a \t"), 4);
    test_equal_i(indentation("  "), 2);
    test_equal_i(indentation("    "), 4);
    test_equal_i(indentation("    hello \t "), 4);
}

void left_trim_test(void) {
    test_equal_s(left_trim("   sample  "), "sample  ");
    test_equal_s(left_trim("Hello World"), "Hello World");
    test_equal_s(left_trim("    hello"), "hello");
    test_equal_s(left_trim("  Hello World"), "Hello World");
    test_equal_s(left_trim("\t\tHello"), ""); // error
    test_equal_s(left_trim("    \tHello"), ""); // error
}

void extract_comment_test(void) {
    test_equal_s(extract_comment("int i = 4/2;"), "");
    test_equal_s(extract_comment("int i = 0; // a new integer"), "a new integer");
    test_equal_s(extract_comment("   double f = 0.0; //   a new double"), "a new double");
    test_equal_s(extract_comment("  bool b = false; //a new bool"), "a new bool");
    test_equal_s(extract_comment("  bool b = false; //a new bool  "), "a new bool  ");
    test_equal_s(extract_comment("  bool b = false; //"), "");
    test_equal_s(extract_comment("int i = 0;"), "");
}

int main(void) {
    indentation_test();
    left_trim_test();
    extract_comment_test();
    return 0;
}
