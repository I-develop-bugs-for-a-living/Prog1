#include "base.h"

//stack for the opening parentheses. 
typedef struct Node {
    char parentheses;
    struct Node *next;
} Node;



Node* new_list(void) {
    return xcalloc(1, sizeof(Node));
}

Node* new_node(char parentheses, Node* next) {
    Node* node = xcalloc(1, sizeof(Node));
    node->parentheses = parentheses;
    node->next = next;
    return node;
}

void free_list(Node* List) {
    struct Node *tmp;
    while(List != NULL) {
    tmp = List;
    List = List->next;
    free(tmp);
    }
}


Node* prepend_list(char parentheses, Node* List) {
    return new_node(parentheses, List);
}


Node* remove_first_of_list(Node* stack){
    if(stack == NULL) return NULL;
    Node *tmp;
    tmp = stack;
    free(tmp);
    return stack->next;
}


/*
Checks if the given String has correct parentheses. ( ), [ ], { }, < >
Creates a stack. Every time the character is a opening parentheses it gets pushed to the top of the stack.
If the character is a closing parentheses it gets checkt if it is the matching parentheses to the topmost parentheses on the stack.
If this is the case the parentheses gets pop of the stack and the program continues.
@param text the string that is getting tested
@return a bool which indicates if the parentheses are all close.
*/
bool verify_parentheses(String text) {
    // TODO
    Node* stack = NULL;
    for (int i = 0; text[i] != '\0'; i++) {
        printf("Index: %d\n", i+1);
        printf("Der zu überprüfende Character: %c\n",text[i]);
        if(text[i] == '(') {
            printf("Als Klammer erkannt.\n");
            stack = prepend_list(text[i], stack);
            printf("Oberstes Stack Element: %c\n", stack->parentheses);
        }
        if(text[i] == '[') {
            printf("Als Klammer erkannt.\n");
            stack = prepend_list(text[i], stack);
            printf("Oberstes Stack Element: %c\n", stack->parentheses);
        }
        if(text[i] == '{') {
            printf("Als Klammer erkannt.\n");
            stack = prepend_list(text[i], stack);
            printf("Oberstes Stack Element: %c\n", stack->parentheses);
        }
        if(text[i] == '<') {
            printf("Als Klammer erkannt.\n");
            stack = prepend_list(text[i], stack);
            printf("Oberstes Stack Element: %c\n", stack->parentheses);
        }
        if(text[i] == ')') {
            if (stack->parentheses == '(') {
                printf("Matching parentheses: ( ) \n->Removing from stack\n");
                stack = remove_first_of_list(stack);
                printf("Neues oberstes Element: %c\n", stack->parentheses);
            } else {
                printf("No matching parentheses found\n Stack contains: %c\n -> clearing stack\n", stack->parentheses);
                free_list(stack);
                return false;
            }
        }
        if(text[i] == ']') {
            if (stack->parentheses == '[') {
                printf("Matchting parentheses: [ ]\n->Removing from stack\n");
                stack = remove_first_of_list(stack);
                printf("Neues oberstes Element: %c\n", stack->parentheses);
            } else {
                printf("No matching parentheses found\n Stack contains: %c\n -> clearing stack\n", stack->parentheses);
                free_list(stack);
                return false;
            }
        }
        if(text[i] == '}') {
            if (stack->parentheses == '{') {
                printf("Matchting parentheses: { } \n->Removing from stack\n");
                stack = remove_first_of_list(stack);
                printf("Neues oberstes Element: %c\n", stack->parentheses);
            } else {
                printf("No matching parentheses found\n Stack contains: %c\n -> clearing stack\n", stack->parentheses);
                free_list(stack);
                return false;
            }
        }    
        if(text[i] == '>') {
            if (stack->parentheses == '<') {
                printf("Matchting parentheses: <> \n->Removing from stack\n");
                stack = remove_first_of_list(stack);
                printf("Neues oberstes Element: %c\n", stack->parentheses);
            } else {
                printf("No matching parentheses found\n Stack contains: %c\n -> clearing stack\n", stack->parentheses);
                free_list(stack);
                return false;
            }
            
        }
    }
    free_list(stack);
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