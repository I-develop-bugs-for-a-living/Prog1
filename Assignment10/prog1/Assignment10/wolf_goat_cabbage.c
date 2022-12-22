/*
Compile: make wolf_goat_cabbage
Run: ./wolf_goat_cabbage
make wolf_goat_cabbage && ./wolf_goat_cabbage
*/

#include "base.h"

// Represents a single list node. The value is dynamically allocated. The node 
// is the owner of the value and has to free it when itself is released.
struct Node {
    String value; // dynamically allocated string, release memory!
    struct Node* next; // self-reference
};
typedef struct Node Node;

// Create a list node. Copies the value (into dynamically allocated storage).
Node* new_node(String value, Node* next) {
    Node* node = xcalloc(1, sizeof(Node));
    node->value = s_copy(value); // s_copy performs dynamic allocation
    node->next = next;
    return node;
}

// Prints the components of the given list.
void print_list(Node* list) {
    if (list == NULL) {
        printf("[]");
    } else {
        printf("[%s", list->value);
        for (Node* n = list->next; n != NULL; n = n->next) {
            printf(" %s", n->value);
        }
        printf("]");
    }
}

// Print list followed by a newline.
void println_list(Node* list) {
    print_list(list);
    printsln("");
}

// Free all nodes of the list, including the values it contains.
void free_list(Node* list) {
    if (list == NULL) {
        return;
    }
    // todo: implement (Aufgabe 1)
    // (there will be memory leaks if this function is not yet implemented)
    if (list->next != NULL) {
        //printf("Calling free_list again\n");
        free_list(list->next);
    }
    free(list->value);
    free(list);
}


bool test_equal_lists(int line, Node* list1, Node* list2);

/*
Example calls for test_equal_lists.
Expected output (line numbers may differ):
Line 63: The lists are equal.
Line 66: The lists are equal.
Line 70: The lists are equal.
Line 74: The values at node 0 differ: hello <-> you.
Line 78: The lists are equal.
Line 82: The values at node 1 differ: second <-> hello.
Line 86: list1 is shorter than list2.
Line 90: list1 is longer than list2.
*/
void test_equal_lists_test(void) {
    Node* list1 = NULL;
    Node* list2 = NULL;
    test_equal_lists(__LINE__, list1, list2);
    //printf("I made it to %d", __LINE__);
    list1 = new_node("hello", NULL);
    list2 = list1;
    test_equal_lists(__LINE__, list1, list2);
    //printf("I made it to %d", __LINE__);
    free_list(list1);
    list1 = new_node("hello", NULL);
    list2 = new_node("hello", NULL);
    //printf("I made it to %d", __LINE__);
    test_equal_lists(__LINE__, list1, list2);
    free_list(list1); free_list(list2);
    list1 = new_node("hello", NULL);
    list2 = new_node("you", NULL);
    test_equal_lists(__LINE__, list1, list2);
    free_list(list1); free_list(list2);
    list1 = new_node("first", new_node("second", NULL));
    list2 = new_node("first", new_node("second", NULL));
    test_equal_lists(__LINE__, list1, list2);
    free_list(list1); free_list(list2);
    list1 = new_node("first", new_node("second", NULL));
    list2 = new_node("first", new_node("hello", NULL));
    test_equal_lists(__LINE__, list1, list2);
    free_list(list1); free_list(list2);
    list1 = new_node("first", new_node("second", NULL));
    list2 = new_node("first", new_node("second", new_node("third", NULL)));
    test_equal_lists(__LINE__, list1, list2);
    free_list(list1); free_list(list2);
    list1 = new_node("first", new_node("second", new_node("third", NULL)));
    list2 = new_node("first", new_node("second", NULL));
    test_equal_lists(__LINE__, list1, list2);
    free_list(list1); free_list(list2);
}

// Checking whether two string lists are equal.
bool test_equal_lists(int line, Node* list1, Node* list2) {
    // todo: implement (Aufgabe 1)
    if (list1 == NULL && list2 == NULL) {
        printf("Line %d: The lists are equal.\n", line);
        return true;
    }
    Node* listOne = list1;
    Node* listTwo = list2;
    int counter = 0;

    while (s_equals(listOne->value, listTwo->value)) {
        //printf("listOne->next: %p, listTwo->next:%p \n", listOne->next, listTwo->next);
        if (listOne->next == NULL && listTwo->next == NULL) {
            printf("Line %d: The lists are equal. \n", line);
            return true;
        } else if (listOne->next == NULL) {
            printf("Line %d: list1 is shorter than list2. \n", line);
            return false;
        } else if (listTwo->next == NULL) {
            printf("Line %d: list1 is longer than list2. \n", line);
            return false;
        }
        listOne = listOne->next;
        listTwo = listTwo->next;
        counter++;


    }

    printf("Line %d: The values at node 1 differ: %s <-> %s \n", line, listOne->value, listTwo->value);
    

    return false;
}


int length_list(Node* list);

// Example calls for length_list (below).
void length_list_test(void) {
    // todo: implement (Aufgabe 1)
    // todo: at least 3 checks, with test_equal_i(actual, expected);
    Node* list1 = new_node("First", new_node("Second", new_node("Third", NULL)));
    test_equal_i(length_list(list1), 3);
    free_list(list1);
    list1 = new_node("First", new_node("Second", new_node("Third", new_node("Forth", NULL))));
    test_equal_i(length_list(list1), 4);
    free_list(list1);
    list1 = NULL;
    test_equal_i(length_list(list1), 0);
}

// Number of elements of the list.
int length_list(Node* list) {
    int n = 0;
    for (Node* node = list; node != NULL; node = node->next) n++;
    return n;
}

int index_list(Node* list, String s);

// Example calls for index_list (below).
void index_list_test(void) {
    // todo: implement (Aufgabe 1)
    // todo: at least 3 checks, with test_equal_i(actual, expected);
    Node* list1 = new_node("Hello", new_node("World", new_node("!", NULL)));
    String s = "!";
    test_equal_i(index_list(list1, s), 2);
    
    s = "?";
    test_equal_i(index_list(list1, s), -1);
    free_list(list1);
    
    list1 = new_node("Old", new_node("MC", new_node("Donald", new_node("had", new_node("a", new_node("farm", NULL))))));
    s = "farm";
    test_equal_i(index_list(list1, s), 5);
    free_list(list1);

}

// Return index of s in list, or -1 if s is not in list.
int index_list(Node* list, String s) {
    // todo: implement (Aufgabe 1)
    require("S must be unequal NULL", s != NULL);
    int counter = 0;
    for (Node* liste = list; liste != NULL; liste = liste->next) {
        if (s_equals(liste->value, s)) {
            return counter;
        }
        counter++;
    }
    return -1;
}

// Check whether list contains s.
bool contains_list(Node* list, String s) {
    return index_list(list, s) >= 0;
}

Node* remove_list(Node* list, int index);

// Example calls for remove_list (below).
void remove_list_test(void) {
    // todo: implement (Aufgabe 1)
    // todo: at least 3 checks, with test_equal_lists(__LINE__, actual, expected);
    Node* list1 = new_node("hello", new_node("world", new_node("!", NULL)));
    Node* list2 = new_node("hello", new_node("!", NULL));
    test_equal_lists(__LINE__, remove_list(list1, 1), list2);

    free_list(list1);
    free_list(list2);


    list1 = new_node("hello", new_node("world", new_node("!", NULL)));
    list2 = new_node("hello", new_node("world", NULL));
    test_equal_lists(__LINE__, remove_list(list1, 2), list2);

    free_list(list1);
    free_list(list2);
    

    list1 = new_node("Alle", new_node("Meine", new_node("Entchen", new_node("Schwimmen", new_node("Auf", new_node("Dem", new_node("See!", NULL)))))));
    list2 = new_node("Meine", new_node("Entchen", new_node("Schwimmen", new_node("Auf", new_node("Dem", new_node("See!", NULL))))));
    Node * list3 = remove_list(list1, 0);
    test_equal_lists(__LINE__, list3, list2);

    free_list(list3);
    free_list(list2);
}

#define ensure_code(length, newLength) (length == newLength+1)

// Remove element at position index from list. The element at index has to be deleted.
Node* remove_list(Node* list, int index) {
    // todo: implement (Aufgabe 1)
    int length = 0;
    for (Node* list1 = list; list1->next != NULL; list1 = list1->next) {
        length++;
    }
    ensure("Index not out of range", index <= length);
    ensure("Index not negativ", index >= 0);
    Node* list2 = list;
    if (index == 0 && length == 0) {
        list = NULL;
        free(list2->value);
        free(list2);
    } else if (index == 0) {
        list = list->next;
        free(list2->value);
        free(list2);
    } else {
        for (int i = 0; i < index-1; i++) {
            list2 = list2->next;
        }
        Node* item = list2->next;
        list2->next = list2->next->next;
        free(item->value);
        free(item);
    }

    // POSTCONDITION
    int newLength = 0;
    if (list == NULL) {
        return list;
    }
    for (Node* list3 = list; list3->next !=0; list3 = list3->next) {
        newLength++;
    }
    //Postcondition makes absolutly no fucking sense
    ensure_code(length, newLength);

    return list;
}


Node* append_list(Node * list, String input) {
    if (list == NULL) {
        list = new_node(input, NULL);
        return list;
    } else {
        Node * list1 = list;
        for (; list1->next != NULL; list1 = list1->next) {

        }
        list1->next = new_node(input, NULL);
        return list;
    }
}

///////////////////////////////////////////////////////////////////////////

// The boat may either be at the left or right river bank. 
// We don't care for the transition (boat crossing the river).
enum Position {
    LEFT, RIGHT
};

// The data that represents the state of the puzzle.
typedef struct {
    // List of objects on the left river bank.
    Node* left;

    // List of objects on the right river bank.
    Node* right;

    // List of objects in the boat. The boat has a capacity of one object only.
    Node* boat;

    // Current boat position.
    enum Position position;
} Puzzle;

// Initialize the state of the puzzle.
Puzzle make_puzzle(void) {
    return (Puzzle){ new_node("Wolf", new_node("Ziege", new_node("Kohl", NULL))), NULL, NULL, LEFT };
}

// Print the current state of the puzzle.
void print_puzzle(Puzzle* p) {
    print_list(p->left);
    if (p->position == RIGHT) prints("     ");
    print_list(p->boat);
    if (p->position == LEFT)  prints("     ");
    println_list(p->right);  
}

// Release memory and quit.
void finish_puzzle(Puzzle* p) {
    free_list(p->left);
    free_list(p->right);
    free_list(p->boat);
    exit(0);
}

void evaluate_puzzle(Puzzle* p) {
    // todo: implement (Aufgabe 2)
    int rightLength = 0;
    for (Node* right = p->right; right != NULL; right = right->next) {
        rightLength++;
    }
    if (p->position == RIGHT && contains_list(p->right, "Ziege") && contains_list(p->right, "Kohl") && contains_list(p->right, "Wolf")) {
        printf("You solved the puzzle\n");
        finish_puzzle(p);
    } else if (p->position == LEFT && ((contains_list(p->right, "Ziege") && contains_list(p->right, "Kohl")) || (contains_list(p->right, "Ziege") && contains_list(p->right, "Wolf")))) {
        printf("Failure\n");
        finish_puzzle(p);
    } else if (p->position == RIGHT && ((contains_list(p->left, "Ziege") && contains_list(p->left, "Kohl")) || (contains_list(p->left, "Ziege") && contains_list(p->left, "Wolf")))) {
        printf("Failure\n");
        finish_puzzle(p);
    }
    printf("End of eval\n");
}

int moveAnimals(Puzzle* p, String input) {
    if (p->position == LEFT) {
        printf("I moved the %s on the boat\n", input);

        if (contains_list(p->left, input)) {
            p->left = remove_list(p->left, index_list(p->left, input));
            p->boat = append_list(p->boat, input);
        } else if (contains_list(p->boat, input)) {
            p->boat = remove_list(p->boat, index_list(p->boat, input));
            p->left = append_list(p->left, input);
        } else {
            printf("Animal doesn't exist idiot\n");
            return -1;
        }

    } else if (p->position == RIGHT) {
        printf("I moved the %s on land\n", input);

        if (contains_list(p->right, input)) {
            p->right = remove_list(p->right, index_list(p->right, input));
            p->boat = append_list(p->boat, input);
        } else if (contains_list(p->boat, input)) {
            p->boat = remove_list(p->boat, index_list(p->boat, input));
            p->right = append_list(p->right, input);
        } else {
            printf("Animal is not on boat idiot. Big brain move 🤯\n");
            return -1;
        }
    }
}

void moveBoat(Puzzle* p, String input) {
    printf("THe input is : %s %d\n", input, s_equals(input, "r"));

    if (s_equals(input, "r")) {
        printf("I moved the Boat\n");
        p->position = RIGHT;
    } else {
        p->position = LEFT;
    }
}


void play_puzzle(Puzzle* p) {
    // todo: implement (Aufgabe 2)
    print_puzzle(p);
    // ...
    while (true) {
        printf("Enter your Operation: ");
        String input = s_input(100);
        if (s_equals(input, "r") || s_equals(input, "l")) {
            printf("%d, %d\n", s_equals(input, "r"), s_equals(input, "l"));
            moveBoat(p, input);
        } else {
            moveAnimals(p, input);
        }
        free(input);
        print_puzzle(p);
        evaluate_puzzle(p);
    }

}

///////////////////////////////////////////////////////////////////////////

int main(void) {
    report_memory_leaks(true);

    test_equal_lists_test();
    length_list_test();
    index_list_test();
    remove_list_test();
    
    Puzzle p = make_puzzle();
    play_puzzle(&p);
    return 0;
}
