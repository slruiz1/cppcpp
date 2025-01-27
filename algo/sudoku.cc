#include <bits/stdc++.h>

using namespace std;

#if 0
  You are given a a 9 x 9 Sudoku board board. A Sudoku board is valid if the following rules are followed:

      Each row must contain the digits 1-9 without duplicates.
      Each column must contain the digits 1-9 without duplicates.
      Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without duplicates.

  Return true if the Sudoku board is valid, otherwise return false

  Note: A board does not need to be full or be solvable to be valid.

  Example 1:

  Input: board = 
  [["1","2",".",".","3",".",".",".","."],
   ["4",".",".","5",".",".",".",".","."],
   [".","9","8",".",".",".",".",".","3"],
   ["5",".",".",".","6",".",".",".","4"],
   [".",".",".","8",".","3",".",".","5"],
   ["7",".",".",".","2",".",".",".","6"],
   [".",".",".",".",".",".","2",".","."],
   [".",".",".","4","1","9",".",".","8"],
   [".",".",".",".","8",".",".","7","9"]]

  Output: true

  Example 2:

  Input: board = 
  [["1","2",".",".","3",".",".",".","."],
   ["4",".",".","5",".",".",".",".","."],
   [".","9","1",".",".",".",".",".","3"],
   ["5",".",".",".","6",".",".",".","4"],
   [".",".",".","8",".","3",".",".","5"],
   ["7",".",".",".","2",".",".",".","6"],
   [".",".",".",".",".",".","2",".","."],
   [".",".",".","4","1","9",".",".","8"],
   [".",".",".",".","8",".",".","7","9"]]

  Output: false

  Explanation: There are two 1's in the top-left 3x3 sub-box.
#endif

class Sudoku {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int N = (int)board.size();
        std::bitset<10> set; // digits 0..9
        for (int r=0; r < N; ++r) {
            set.reset();
            for (int c=0; c < N; ++c) {
                const char digit = board[r][c];
                // Skip over invalid digit/char
                if (!isdigit(digit) || digit == '0') continue;
                const int idx = digit - '0';
                // Find digit in set, if found then return false
                if (set[idx]) {
                    cout << "ROW check, duplicate digit was found: " << digit << " on row: " << r+1 << ", col: " << c+1 << endl;
                    return false; // duplicate!
                }
                set[idx] = true;
            }
        }
        //cout << "----------, rows: " << N << endl;
        for (int c=0; c < N; ++c) {
            set.reset();
            for (int r=0; r < N; ++r) {
                const char digit = board[r][c];
                if (!isdigit(digit) || digit == '0') continue;
                //cout << "digit '" << digit << "' on row: " << r+1 << ", col: " << c+1 << endl;
                const int idx = digit - '0';
                if (set[idx]) {
                    cout << "COL check, duplicate digit was found: " << digit << " on row: " << r+1 << ", col: " << c+1 << endl;
                    return false; // duplicate!
                }
                set[idx] = true;
            }
        }

        const int B = 3;
        for (int x=0; x < B; ++x) {
            for (int y=0; y < B; ++y) {
                set.reset();
                for (int r=x*B; r < (x*B)+B; ++r) {
                    for (int c=y*B; c < (y*B)+B; ++c) {
                        const char digit = board[r][c];
                        if (!isdigit(digit) || digit == '0') continue;
                        const int idx = digit - '0';
                        if (set[idx]) {
                            cout << "BOX [" << x+1 << "," << y+1 << "] check, duplicate digit was found: " << digit << " on row: " << r+1 << ", col: " << c+1 << endl;
                            return false; // duplicate!
                        }
                        set[idx] = true;
                    }
                }
            }
        }

        return true;
    }
};

int main() {
    Sudoku s;
    {
        vector<vector<char>> board = {
            {'1','2','.','.','3','.','.','.','.'},
            {'4','.','.','5','.','.','.','.','.'},
            {'.','9','8','.','.','.','.','.','3'},
            {'5','.','.','.','6','.','.','.','4'},
            {'.','.','.','8','.','3','.','.','5'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','.','.','.','.','.','2','.','.'},
            {'.','.','.','4','1','9','.','.','8'},
            {'.','.','.','.','8','.','.','7','9'}
        };
        bool is_valid = s.isValidSudoku(board);
        cout << "board is " << (is_valid ? "valid." : "invalid.") << endl;
    }

    {
        vector<vector<char>> invalid_board = {
            {'1','2','.','.','3','.','.','.','.'},
            {'4','.','.','5','.','.','.','.','.'},
            {'.','9','.','.','.','.','.','.','3'},
            {'5','.','.','.','6','.','.','.','4'},
            {'.','.','.','8','.','3','.','.','5'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','.','.','.','.','.','2','7','.'},
            {'.','.','.','4','1','9','7','.','8'},
            {'.','.','.','.','8','.','.','6','9'} 
        };

        bool is_valid = s.isValidSudoku(invalid_board);
        cout << "board is " << (is_valid ? "valid." : "invalid.") << endl;
    }
    return 0;
}
