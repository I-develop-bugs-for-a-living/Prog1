/*
Compile: make matrix
Run: ./matrix
*/

#include "base.h" // http://hci.uni-hannover.de/files/prog1lib/base_8h.html

struct Matrix {
    int rows; // number of rows
    int cols; // number of columns
    double** data; // a pointer to an array of n_rows pointers to rows; a row is an array of n_cols doubles 
};
typedef struct Matrix Matrix;

/**
Creates a zero-initialized matrix of rows and columns matrix.
@param[in] n_rows number of rows
@param[in] n_cols number of columns
@return a pointer to an array of n_rows pointers to rows; a row is an array of n_cols doubles 
*/
Matrix* make_matrix(int n_rows, int n_cols) {
    // todo: implement
    Matrix *m = xmalloc(sizeof(Matrix));
    m->rows = n_rows;
    m->cols = n_cols;
    m->data = xcalloc(n_rows, sizeof(double*));
    for (int i = 0; i < n_rows; i++) {
        m->data[i] = xcalloc(n_cols, sizeof(double));
    }
    return m;
}

/**
Creates a zero-initialized matrix of rows and columns matrix.
@param[in] data an array of doubles, ordered row-wise
@param[in] n_rows number of rows
@param[in] n_cols number of columns
@return a pointer to an array of n_rows pointers to rows; a row is an array of n_cols doubles 
*/
Matrix* copy_matrix(double* data, int n_rows, int n_cols) {
    // todo: implement
    Matrix *m = make_matrix(n_rows, n_cols);
    int counter = 0;
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            m->data[i][j] = data[counter];
            counter++;
        }
    }
    return m;
}

/**
Print a matrix.
@param[in] m the matrix to print
*/
void print_matrix(Matrix* m) {
    // todo: implement
    for (int i = 0; i < m->rows; i++) {
        printf("[ ");
        for (int j = 0; j < m->cols; j++) {
            printf("%.2f ", m->data[i][j]);
        }
        printf("]\n");
    }
    printf("\n");
}

/**
Add two matrices.
@param[in] a the first operand
@param[in] b the second operand
@return a new matrix whose elements are the element-wise sums of a and b
*/
Matrix* add_matrices(/*in*/ Matrix* a, /*in*/ Matrix* b) {
    // todo: implement
    if (!(a->cols == b->cols && a->rows == b->rows)) {
        return NULL;
    }
    Matrix *m = make_matrix(a->rows, b->cols);

    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            m->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
    return m;
}

/**
Free a matrix.
@param[in] m the matrix to free
*/
void free_matrix(Matrix* m) {
    // todo: implement
    for (int i = 0; i < m->rows; i++) {
        free(m->data[i]);
    }
    free(m->data);
    free(m);
}

void matrix_test(void) {
    double a[] = { 
        1, 2, 3, 
        4, 5, 6, 
        7, 8, 9 };
    Matrix* m1 = copy_matrix(a, 3, 3);
    print_matrix(m1);

    double a2[] = { 
        1, 2, 3, 
        4, 5, 6 };
    Matrix* m2 = copy_matrix(a2, 2, 3);
    print_matrix(m2);

    double a3[] = { 
        1, 2, 
        3, 4, 
        5, 6 };
    Matrix* m3 = copy_matrix(a3, 3, 2);
    print_matrix(m3);

    double a4[] = { 
        10, 20, 
        30, 40, 
        50, 60 };
    Matrix* m4 = copy_matrix(a4, 3, 2);
    print_matrix(m4);

    Matrix* m5 = add_matrices(m3, m4);
    print_matrix(m5);
    
    free_matrix(m1);
    free_matrix(m2);
    free_matrix(m3);
    free_matrix(m4);
    free_matrix(m5);
}

int main(void) {
    base_init();
    report_memory_leaks(true);
    matrix_test();
    return 0;
}
