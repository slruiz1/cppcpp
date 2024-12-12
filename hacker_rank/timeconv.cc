#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    int hour = stoi(s);
    if (s[s.size()-2] == 'A') {
        // AM: 0..11
        if (hour >= 12) hour = 0;
    } else {
        // PM: 12..23
        if (hour != 12) hour += 12;
    }
    // convert hour to char 
    s[0] = '0' + (hour/10);
    s[1] = '0' + hour % 10;
    s.pop_back();
    s.pop_back();
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
