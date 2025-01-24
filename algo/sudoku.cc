#include <bits/stdc++.h>

using namespace std;


// // You are given a a 9 x 9 Sudoku board board. A Sudoku board is valid if the following rules are followed:

// //     Each row must contain the digits 1-9 without duplicates.
// //     Each column must contain the digits 1-9 without duplicates.
// //     Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without duplicates.

// // Return true if the Sudoku board is valid, otherwise return false

// // Note: A board does not need to be full or be solvable to be valid.

// // Example 1:

// // Input: board = 
// // [["1","2",".",".","3",".",".",".","."],
// //  ["4",".",".","5",".",".",".",".","."],
// //  [".","9","8",".",".",".",".",".","3"],
// //  ["5",".",".",".","6",".",".",".","4"],
// //  [".",".",".","8",".","3",".",".","5"],
// //  ["7",".",".",".","2",".",".",".","6"],
// //  [".",".",".",".",".",".","2",".","."],
// //  [".",".",".","4","1","9",".",".","8"],
// //  [".",".",".",".","8",".",".","7","9"]]

// // Output: true

// // Example 2:

// // Input: board = 
// // [["1","2",".",".","3",".",".",".","."],
// //  ["4",".",".","5",".",".",".",".","."],
// //  [".","9","1",".",".",".",".",".","3"],
// //  ["5",".",".",".","6",".",".",".","4"],
// //  [".",".",".","8",".","3",".",".","5"],
// //  ["7",".",".",".","2",".",".",".","6"],
// //  [".",".",".",".",".",".","2",".","."],
// //  [".",".",".","4","1","9",".",".","8"],
// //  [".",".",".",".","8",".",".","7","9"]]

// // Output: false

// // Explanation: There are two 1's in the top-left 3x3 sub-box.


class Sudoku {
    std::array<char, 10> m_set{};
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int nrows = 0;
        for (const auto& row: board) {
            auto& set = m_set;
            ++nrows;
            int ncols = 0;
            set.fill('\0');
            for (const char digit : row) {
                ++ncols;
                // Find digit in set, if found then return false
                if (!isdigit(digit) || digit == '0') continue;
                const int idx = digit - '0';
                if (set[idx] != '\0') {
                    cout << "duplicate digit was found: "
                        << digit << " on row: " << nrows
                        << ", col: " << ncols << endl;
                    return false; // duplicate!
                }
                set[idx] = digit;
                //cout << "set[" << idx << "]=" << digit << "' on row: " << nrows << ", col: " << ncols << endl;
            }
        }
        //cout << "----------, rows: " << nrows << endl;
        for (int c=0; c <= nrows; ++c) {
            auto& set = m_set;
            set.fill('\0');
            for (int r=0; r < nrows; ++r) {
                const char digit = board[r][c];
                if (!isdigit(digit) || digit == '0') continue;
                //cout << "digit '" << digit << "' on row: " << r+1 << ", col: " << c+1 << endl;
                const int idx = digit - '0';
                if (set[idx] != '\0') {
                    cout << "duplicate digit was found: "
                        << digit << " on row: " << r+1
                        << ", col: " << c+1 << endl;
                    return false; // duplicate!
                }
                set[idx] = digit;
            }
        }
        return true;
    }
};

int main() {
    vector<vector<char>> invalid_board = {
       {'1','2','.','.','3','.','.','.','.'},
       {'4','.','.','5','.','.','.','.','.'},
       {'.','9','1','.','.','.','.','.','3'},
       {'5','.','.','.','6','.','.','.','4'},
       {'.','.','.','8','.','3','.','.','5'},
       {'7','.','.','.','2','.','.','.','6'},
       {'.','.','.','.','.','.','2','.','8'},
       {'.','.','.','4','1','9','.','.','8'},
       {'.','.','.','.','8','.','.','7','9'} 
    };

    Sudoku s;
    bool is_valid = s.isValidSudoku(invalid_board);
    cout << "board is " << (is_valid ? "valid." : "invalid.") << endl;

    return 0;
}
