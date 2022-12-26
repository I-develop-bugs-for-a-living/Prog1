#include "base.h"

typedef struct {
    int top_position;
    char parentheses[100];
}Stack;

Stack make_parentheses_stack() {
    Stack s;
    s.top_position = 0;
    return s;
}

/*
Checks if the given String has correct parentheses. ( ), [ ], { }, < >
Creates a stack. Every time the character is a opening parentheses it gets pushed to the top of the stack.
If the character is a closing parentheses it gets checkt if it is the matching parentheses to the topmost parentheses on the stack.
If this is the case the parentheses gets pop of the stack and the program continues.
@param text the string that is getting tested
@return a bool which indicates if the parentheses are all close.
*/
String opening_parentheses = "([{<";
String closing_parentheses = ")]}>";
bool verify_parentheses(String text) {
    // TODO
    Stack parentheses_stack = make_parentheses_stack();
    for (int i = 0; text[i] != '\0'; i++) {
        for (int j = 0; opening_parentheses[j] != '\0'; j++){
            if (text[i] == opening_parentheses[j]){
                parentheses_stack.parentheses[parentheses_stack.top_position] = text[i];
                parentheses_stack.top_position++;
            }
        }
        for (int j = 0; closing_parentheses[j] != '\0'; j++){
            if (text[i] == closing_parentheses[j]){
                if(parentheses_stack.parentheses[parentheses_stack.top_position] == opening_parentheses[j]) {
                    parentheses_stack.parentheses[parentheses_stack.top_position] = '0';
                    parentheses_stack.top_position--;
                } else {
                    printf("No Matching Parentheses for %c\n", opening_parentheses[j]);
                    return false;
                }
            } 
        }
    }
    return true;
}

int main(void) {
    report_memory_leaks(true);

    test_equal_b(verify_parentheses(""), true);
    test_equal_b(verify_parentheses("Hello World"), true);
    test_equal_b(verify_parentheses("()"), true);
    test_equal_b(verify_parentheses("<{[()]}>"), true);
    test_equal_b(verify_parentheses("<{[)]}>"), false);
    test_equal_b(verify_parentheses("( Test ) "), true);
    test_equal_b(verify_parentheses("(1+2)*[2+3+(1 + 6/5)]"), true);
    test_equal_b(verify_parentheses("(an unmatched left parenthesis creates an unresolved tension that will stay with you all day"), false);
    test_equal_b(verify_parentheses("< [ > ]"), false);
    test_equal_b(verify_parentheses("<{[()]}"), false);
    test_equal_b(verify_parentheses("(<<({[({<{<({<([[[<[{(<{(<{{<[{<{{{<<{([<<<{{[{<<[[(([{[[[([(({()}))])]]]}]))]]>>}]}}>>>])}>>}}}>}]>}}>)}>)}]>]]])>})>}>})]})>>)"), true);

    return 0;
}