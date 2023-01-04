#include "base.h"

typedef struct {
    char data;
    struct Node *next;
} Node;


// make a stack of characters
typedef struct {
    Node *top;
    int size;
} Stack;

// create a new stack
Stack *new_stack() {
    Stack *stack = xmalloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}


// push a character onto the stack
void push(Stack *stack, char c) {
    Node *node = xmalloc(sizeof(Node));
    node->data = c;
    node->next = stack->top;
    stack->top = node;
    stack->size++;
}

// pop a character off the stack
void pop(Stack *stack) {
    if (stack->size == 0) {
        return 0;
    }
    Node *node = stack->top;
    stack->top = node->next;
    free(node);
    stack->size--;
}

void print_stack(Stack *stack) {
    Node *startNode = stack->top;
    int counter = stack->size;
    printf("The Stack:\n");
    while(startNode != NULL) {
        printf("%d| %c\n", counter, startNode->data);
        counter--;
        startNode = startNode->next;
    }
}

void free_stack(Stack *stack) {
    Node *startNode = stack->top;
    Node *tempNode = NULL;
    while(startNode != NULL) {
        tempNode = startNode->next;
        free(startNode);
        startNode = tempNode;
    }
    free(stack);
}


bool verify_parentheses(String text) {
    Stack *stack = new_stack();
    while(*text != '\0') {
        switch (*text)
        {
        case '(':
        case '[':
        case '<':
        case '{':
            /* code */
            push(stack, *text);
            break;
        
        case '>':
        case ')':
        case ']':
        case '}':
            if (*text == '>' && stack->top->data == '<') {
                pop(stack);
            } else if (*text == ')' && stack->top->data == '(') {
                pop(stack);
            } else if (*text == ']' && stack->top->data == '[') {
                pop(stack);
            } else if (*text == '}' && stack->top->data == '{') {
                pop(stack);
            } else {
                push(stack, *text);
            }
            break;
        }
        text++;
    }
    print_stack(stack);
    int stack_size = stack->size;
    free_stack(stack);

    if(stack_size == 0) {

        return true;
    }

    return false;
}

int main(void) {
    report_memory_leaks(true);

    Stack *stack = new_stack();
    push(stack, 'a');
    push(stack, 'b');
    print_stack(stack);
    pop(stack);
    print_stack(stack);
    free_stack(stack);

    test_equal_i(verify_parentheses(""), true);
    test_equal_i(verify_parentheses("Hello World"), true);
    test_equal_i(verify_parentheses("()"), true);
    test_equal_i(verify_parentheses("<{[()]}>"), true);
    test_equal_i(verify_parentheses("<{[)]}>"), false);
    test_equal_i(verify_parentheses("( Test ) "), true);
    test_equal_i(verify_parentheses("(1+2)*[2+3+(1 + 6/5)]"), true);
    test_equal_i(verify_parentheses("(an unmatched left parenthesis creates an unresolved tension that will stay with you all day"), false);
    test_equal_i(verify_parentheses("< [ > ]"), false);
    test_equal_i(verify_parentheses("<{[()]}"), false);
    test_equal_i(verify_parentheses("(<<({[({<{<({<([[[<[{(<{(<{{<[{<{{{<<{([<<<{{[{<<[[(([{[[[([(({()}))])]]]}]))]]>>}]}}>>>])}>>}}}>}]>}}>)}>)}]>]]])>})>}>})]})>>)"), true);

    return 0;
}
