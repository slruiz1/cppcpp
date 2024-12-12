#include <bits/stdc++.h>

using namespace std;

#if 0
Two players called  and  are playing a game with a starting number of stones. Player  always plays first, and the two players move in alternating turns. The game rules are as follows:

In a single move, a player can remove either , , or  stones from the game board.
If a player is unable to make a move, that player loses the game.
Given the starting number of stones, find and print the name of the winner.
P1 is named First and P2 is named Second.
Each player plays optimally, meaning they will not make a move that causes them to lose the game if a winning move exists.

For example, if n == 4 , P1 can make the following moves:

P1 removes 2 stones leaving 2. P2 will then remove 2 stones and win.
P1 removes 3 stones leaving 1. P2 cannot move and loses.
P1 would make the second play and win the game.

Function Description

Complete the gameOfStones function in the editor below.
It should return a string, either First or Second.

gameOfStones has the following parameter(s):

n: an integer that represents the starting number of stones
Input Format

The first line contains an integer t, the number of test cases.
Each of the next t lines contains an integer n, the number of stones in a test case.

Constraints

1 <= n,t <= 100

Output Format

On a new line for each test case, print First if the first player is the winner. Otherwise print Second.

Sample Input

8
1
2
3
4
5
6
7
10
Output:
Second
First
First
First
First
First
Second
First

#endif

string ltrim(const string &);
string rtrim(const string &);
#if 0
bool check_winner(int n, bool p1) {
    //printf("stones: %d, P%c\n", n, p1 ? '1' : '2');

    if (n <= 1)
        return false; // player can't make any moves and loses the game.

    if (n <= 6)
        return true; // player removes 2|3|5 stones, always winning the game.

    if (n == 7)
        return false; // all possible moves result in next player winning the game.

    if (!check_winner(n - 5, !p1)) // next player gets 5 less and loses
        return true;

    if (!check_winner(n - 3, !p1)) // next player gets 3 less and loses
        return true;

    if (!check_winner(n - 2, !p1)) // next player gets 2 less and loses
        return true;

    return false;
}

/*
 * Complete the 'gameOfStones' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER n as parameter.
 */

string gameOfStones(int n) {
    puts("Recursive solution...");
    return check_winner(n, true) ? "First" : "Second";
}

#else

/*
 * Complete the 'gameOfStones' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER n as parameter.
 */

struct node {
    int s = 0;
    int is_p1 = true;
    int cnt = 0;
};

string gameOfStones(int n) {
    puts("Iterative solution...");
    if (n > 1 && n < 7)
        return "First";

    stack<node> s;
    s.emplace(n, true, nullptr);

    while (!s.empty()) {
        auto [current, is_p1, cnt] = s.top();
        s.pop();
        if (current <= 7) {
            const bool winner = (current > 1 && current < 7);
            printf("stones: %d, winner: %d, P%c\n", current, winner, is_p1 ? '1' : '2');
            if (is_p1 && winner)
                return "First"; // P1 is the winner!
            continue;
        }

        s.emplace(current - 5, !is_p1, 0);
        s.emplace(current - 3, !is_p1, 0);
        s.emplace(current - 2, !is_p1, 0);
    }

    return "Second";
}
#endif

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string result = gameOfStones(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if_not(s.begin(), s.end(), [](char i) { return isspace(i); })
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if_not(s.rbegin(), s.rend(), [](char i) { return isspace(i); }).base(),
        s.end()
    );

    return s;
}
