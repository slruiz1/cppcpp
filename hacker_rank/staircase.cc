#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'staircase' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

void staircase(int n) {
    int j;
    for (int i = 0; i < n; i++) {
        for (j = n - i - 1; j > 0; j--) {
                putchar(' ');
        }
        for (j = i; j >= 0; j--) {
                putchar('#');
        }
        putchar('\n');
    }
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    staircase(n);

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
