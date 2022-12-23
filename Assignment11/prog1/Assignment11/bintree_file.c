#include "base.h"

typedef struct Tree Tree;
struct Tree {
    int value;
    Tree* left;
    Tree* right;
};

Tree* new_tree(Tree* left, int value, Tree* right) {
    Tree* t = xmalloc(sizeof(Tree));
    t->value = value;
    t->left = left;
    t->right = right;
    return t;
}

Tree* new_leaf(int value) {
    return new_tree(NULL, value, NULL);
}

void print_tree(Tree* tree) {
    if (tree == NULL) {
        printf("_");
    } else {
        printf("(");
        print_tree(tree->left);
        printf(", %d, ", tree->value);
        print_tree(tree->right);
        printf(")");
    }
}

void println_tree(Tree* tree) {
    print_tree(tree);
    printf("\n");
}

// Writes a byte to a file. Returns true if the operation was successful.
bool write_byte(FILE* file, char c) {
    require_not_null(file);
    // https://en.cppreference.com/w/c/io/fputc
    return fputc(c, file) != EOF;
}

// Writes an int to a file. Returns true if the operation was successful.
bool write_int(FILE* file, int i) {
    require_not_null(file);
    // https://en.cppreference.com/w/c/io/fwrite
    return fwrite(&i, sizeof(int), 1, file) == 1;
}

// Reads a byte from a file. Returns true if the operation was successful.
bool read_byte(FILE* file, /*out*/char* c) {
    require_not_null(file);
    require_not_null(c);
    int i = fgetc(file);
    if (i == EOF) return false;
    *c = i;
    return true;
}

// Reads an int from a file. Returns true if the operation was successful.
bool read_int(FILE* file, /*out*/int* i) {
    require_not_null(file);
    require_not_null(i);
    return fread(i, sizeof(int), 1, file) == 1;
}

// Writes a tree to a file. Returns true if the operation was successful.
bool write_tree_rec(FILE* file, Tree* tree) {
    require_not_null(file);
    // todo: implement
    return true;
}

// Writes a tree to a file. Returns true if the operation was successful.
bool write_tree(char* filename, Tree* tree) {
    require_not_null(filename);
    FILE* file = fopen(filename, "wb");
    if (file == NULL) return false;
    bool ok = write_tree_rec(file, tree);
    fclose(file);
    return ok;
}

// Reads a tree from a file. Returns true if the operation was successful.
bool read_tree_rec(FILE* file, /*out*/Tree** tree) {
    require_not_null(file);
    require_not_null(tree);
    char c;
    if (!read_byte(file, &c)) return false;
    // todo: implement
    // ...
    return true;
}

// Reads a tree from a file. Returns true if the operation was successful.
bool read_tree(char* filename, /*out*/Tree** tree) {
    require_not_null(filename);
    require_not_null(tree);
    // https://en.cppreference.com/w/c/io/fopen
    FILE* file = fopen(filename, "rb");
    if (file == NULL) return false;
    bool ok = read_tree_rec(file, tree);
    // https://en.cppreference.com/w/c/io/fclose
    fclose(file);
    return ok;
}

void test_tree(Tree* t) {
    println_tree(t);
    printbln(write_tree("mytree.dat", t));
    Tree* s = NULL;
    printbln(read_tree("mytree.dat", &s));
    println_tree(s);
}

int main(void) {
    test_tree(NULL);
    test_tree(new_leaf(0x12345678));;
    test_tree(new_tree(new_leaf(1), 2, NULL));
    test_tree(new_tree(NULL, 2, new_leaf(3)));
    test_tree(new_tree(new_leaf(1), 2, new_leaf(3)));
    test_tree(new_tree(new_tree(new_leaf(3), 2, NULL), 1, new_tree(NULL, 4, new_leaf(5))));
    return 0;
}
