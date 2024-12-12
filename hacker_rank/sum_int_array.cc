#include <bits/stdc++.h>
#include <numeric>
#include <functional>
#include <algorithm>
#include <array>
#include <cassert>
#include <complex>
#include <iostream>
#include <vector>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'simpleArraySum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY ar as parameter.
 */

int simpleArraySum(vector<int> ar) {
    return std::accumulate(ar.begin(), ar.end(), 0); // <slr>
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string ar_count_temp;
    getline(cin, ar_count_temp);

    int ar_count = stoi(ltrim(rtrim(ar_count_temp)));

    string ar_temp_temp;
    getline(cin, ar_temp_temp);

    vector<string> ar_temp = split(rtrim(ar_temp_temp));

    vector<int> ar(ar_count);

    for (int i = 0; i < ar_count; i++) {
        int ar_item = stoi(ar_temp[i]);
printf(" %d", ar_item);
        ar[i] = ar_item;
    }

    int result = simpleArraySum(ar);

printf("\nsum: %d\n", result);
    fout << result << "\n";

    fout.close();

    return 0;
}

static auto is_space = [](char i) { return isspace(i); };

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if_not(s.begin(), s.end(), is_space)
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if_not(s.rbegin(), s.rend(), is_space).base(),
        //find_if_not(s.rbegin(), s.rend(), [](char i) { return isspace(i); }).base(),
        s.end()
    );
        //find_if(s.rbegin(), s.rend(), [](char a){ return !isspace(a); }),
        //find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),

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
