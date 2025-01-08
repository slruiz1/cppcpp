#include <iostream>

int main()
{
        int array[3][4] = {
                {1, 2, 3, 4},
                {5, 6, 7, 8},
                {9, 10, 11, 12}
        };

        // Print the array elements and their memory addresses
        // Q: Given an 2D array assume that we are reading it element in row order and column order which would be better/faster?
        // A: column order, iterate thru cols first reading memory sequentially
        for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 4; ++j) {
                        std::cout << "row[" << i << "], col[" << j << "] = " << array[i][j]
                                << " Address: " << &array[i][j] << std::endl;
                }
        }

        return 0;
}
