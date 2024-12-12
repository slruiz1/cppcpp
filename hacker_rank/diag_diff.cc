#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'diagonalDifference' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

int diagonalDifference(const vector<vector<int>>& arr) {
    const int n = arr.size();
    const int npos = n-1;
    int d1 = 0, d2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
                if (i == j) d1 += arr[i][j];
                if (npos-i == j) d2 += arr[i][j];
        }
    }
    return abs(d1-d2);
}
    //printf ("n: %d, npos: %d, d1: %d, d2: %d, diff: %d\n", n, npos, d1, d2, abs(d1-d2));

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i].resize(n);

        string arr_row_temp_temp;
        getline(cin, arr_row_temp_temp);

        vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int arr_row_item = stoi(arr_row_temp[j]);

            arr[i][j] = arr_row_item;
        }
    }

    int result = diagonalDifference(arr);

    fout << result << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
