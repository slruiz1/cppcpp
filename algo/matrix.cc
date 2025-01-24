#include <bits/stdc++.h>

using namespace std;


// From : https://www.agner.org/optimize/optimizing_cpp.pdf
// The C++ standard does not currently define an efficient way of making a matrix with
// dimensions determined at run time. Example 9.7 shows a possible solution:

// Example 9.7
// Template for a matrix. The dimensions are decided at run time
// This template makes a matrix of arbitrary dimensions
// There is no bounds checking

template <typename T>
class Matrix {
    public:
        // constructor with number of rows and columns
        Matrix(int rows, int columns) {
            // save number of rows and columns
            this->rows = rows;
            this->columns = columns;
            // allocate memory
            p = new T[rows * columns];
            if (p == 0) {
                // .. error message here: allocation failed
            }
            else {
                // initialize all elements to zero
                for (int i = 0; i < rows * columns; i++) {
                    p[i] = 0;
                }
            }
        }
        // get number of rows
        int nrows() const {
            return rows;
        }
        // get number of columns
        int ncols() const {
            return columns;
        }
        // destructor
        ~Matrix() {
            if (p) delete[] p; // free the memory
        }

        T* operator[](int x) {
            return p + x * columns;
        }

        // Operator [] gives a pointer to row number r.
        // A second [] with the column number gives a single element
#if 0
        T * operator[] (int r) {
            // no bounds check
            return p + r * columns;
        }
#endif
        Matrix(const Matrix&) = delete;
        Matrix& operator=(const Matrix&) = delete;

    protected:
        int rows=0; // number of rows
        int columns=0; // number of columns
        T * p{nullptr}; // pointer to memory
};

int main() {
    // ...
    // Example of use:
    // Make a matrix of doubles with 8 rows and 10 columns
    Matrix<double> mat(8,10);
    // Put a value in row 3, column 5
    mat[3][5] = 12.34;
    // Print out the matrix
    for (int r = 0; r < mat.nrows(); r++) {
        for (int c = 0; c < mat.ncols(); c++) {
            printf("%5.2f ", mat[r][c]);
        }
        printf("\n");
    }
    return 0;
}
