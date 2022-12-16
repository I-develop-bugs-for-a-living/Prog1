/*
Compile: make tree_to_string
Run: ./tree_to_string
make tree_to_string && ./tree_to_string
*/

#include "base.h"
#include "int_array.h"

typedef struct Tree Tree;
struct Tree {
    char* value;
    Tree* left;
    Tree* right;
};

Tree* new_tree(Tree* left, char* value, Tree* right) {
    Tree* t = xcalloc(1, sizeof(Tree));
    t->left = left;
    t->value = value;
    t->right = right;
    return t;
}

void print_tree(Tree* n) {
    if (n == NULL) {
        prints("_");
    } else if (n->left == NULL && n->right == NULL) {
        prints("(");
        prints(n->value);
        prints(")");
    } else {
        prints("(");
        print_tree(n->left);
        prints(", ");
        prints(n->value);
        prints(", ");
        print_tree(n->right);
        prints(")");
    }
}

void print_tree_ln(Tree* t) {
    print_tree(t);
    println();
}

int tree_length_as_string(Tree* t) {
    // todo: implement
    return 0;
}

char* tree_to_string_rec(Tree* t, char* s) {
    // todo: implement
    return "";
}

char* tree_to_string(Tree* t) {
    int n = tree_length_as_string(t);
    char* s = xmalloc(n + 1);
    tree_to_string_rec(t, s);
    s[n] = '\0';
    return s;
}

Tree* leaf(char* value) {
    return new_tree(NULL, value, NULL);
}

Tree* node(Tree* left, char* value, Tree* right) {
    return new_tree(left, value, right);
}

void test(void) {
    Tree* t;

    // empty tree
    t = NULL;
    print_tree_ln(t);
    test_equal_i(tree_length_as_string(t), 1);
    test_equal_s(tree_to_string(t), "_");

    // one-element tree
    t = leaf("100");
    print_tree_ln(t);
    test_equal_i(tree_length_as_string(t), 5);
    test_equal_s(tree_to_string(t), "(100)");
    
    // one-element tree
    t = node(NULL, "1", leaf("2"));
    print_tree_ln(t);
    test_equal_i(tree_length_as_string(t), 11);
    test_equal_s(tree_to_string(t), "(_, 1, (2))");

    //   1000
    // 124  110
    t = node(leaf("124"), "1000", leaf("110"));
    print_tree_ln(t);
    test_equal_i(tree_length_as_string(t), 20);
    test_equal_s(tree_to_string(t), "((124), 1000, (110))");

    //   -100
    // 10   110
    t = node(leaf("10"), "-100", leaf("110"));
    print_tree_ln(t);
    test_equal_i(tree_length_as_string(t), 19);
    test_equal_s(tree_to_string(t), "((10), -100, (110))");
    
    //  -101
    //  2   5
    // 1 3 4 6
    t = node(node(leaf("1"), "2", leaf("3")), "-101", node(leaf("4"), "5", leaf("6")));
    print_tree_ln(t);
    test_equal_i(tree_length_as_string(t), 36);
    test_equal_s(tree_to_string(t), "(((1), 2, (3)), -101, ((4), 5, (6)))");

    //          -101
    //       2        5
    //    0     3   4   6
    // -10 210
    t = node(node(node(leaf("-10"), "0", leaf("200")), "2", leaf("3")), "-101", node(leaf("4"), "5", leaf("6")));
    print_tree_ln(t);
    test_equal_i(tree_length_as_string(t), 50);
    test_equal_s(tree_to_string(t), "((((-10), 0, (200)), 2, (3)), -101, ((4), 5, (6)))");

    //                1
    //          2           3
    //     -4      NULL
    // NULL   5
    t = node(node(node(NULL, "-4", leaf("5")), "2", NULL), "1", leaf("3"));
    print_tree_ln(t);
    test_equal_i(tree_length_as_string(t), 30);
    test_equal_s(tree_to_string(t), "(((_, -4, (5)), 2, _), 1, (3))");
}

int main(void) {
    test();
    return 0;
}

