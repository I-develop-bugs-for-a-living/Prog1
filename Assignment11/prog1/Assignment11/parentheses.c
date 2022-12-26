#include "base.h"

//stack for the opening parentheses. 
typedef struct Node {
    char parentheses;
    struct Node *next;
} Node;


/*
Creates a new node with a parentheses saved.
@param parentheses The parentheses which are save in the node.
@param next A pointer to the next node of the list.
@return A pointer to the new node.
*/
Node* new_node(char parentheses, Node* next) {
    Node* node = xcalloc(1, sizeof(Node));
    node->parentheses = parentheses;
    node->next = next;
    return node;
}

/*
Frees the allocated memory of the stack
@param stack that should get freed
*/
void free_list(Node* List) {
    struct Node *tmp;
    while(List != NULL) {
    tmp = List;
    List = List->next;
    free(tmp);
    }
}

/*
Pushes a new node to the top of the stack.
@param stack the old stack
@return The new stack
*/
Node* prepend_list(char parentheses, Node* List) {
    return new_node(parentheses, List);
}

/*
Pops the top entry of the stack.
@param stack the old stack
@return The new stack
*/
Node* remove_first_of_list(Node* stack){
    if(stack == NULL) return NULL;
    Node *tmp;
    tmp = stack;
    stack = stack->next;
    free(tmp);
    return stack;
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
    String opening_parentheses = "([{<";
    String closing_parentheses = ")]}>";
    Node* stack = NULL;
    for (int i = 0; text[i] != '\0'; i++) {
        for (int j = 0; opening_parentheses[j] != '\0'; j++) {
            if(text[i] == opening_parentheses[j]) {
                stack = prepend_list(text[i], stack);
            }
        }
        for (int j = 0; closing_parentheses[j] != '\0'; j++) {
            if(text[i] == closing_parentheses[j]) {
                if (stack->parentheses == opening_parentheses[j]) {
                    stack = remove_first_of_list(stack);
                } else {
                    free_list(stack);
                    return false;
                }
            }
        }
    }    
    if (stack != NULL) {
        free_list(stack);
        return false;
    } else {
        free_list(stack);
        return true;
    }
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