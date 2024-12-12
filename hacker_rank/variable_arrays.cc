#include <bits/stdc++.h>

using namespace std;

vector<string> split(const string& str) {
    vector<string> tokens;
    string::size_type start = 0, end;
    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }
    return tokens;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m;
    cin >> n;
    cin >> m;

    vector<vector<int>> a;
    a.reserve(n);
    for (int i=0; i<n; i++) {
        int k;
        cin >> k;
        auto& row = a.emplace_back(k);
        for (int j=0; j<k; j++) {
            cin >> row[j];
        }
    }

    vector<pair<int,int>> q(m);
    for (int i=0; i<m; i++) {
        cin >> q[i].first;
        cin >> q[i].second;
    }   
    for (int i = 0; i < m; i++) {
        cout << a[q[i].first][q[i].second] << endl;
    }   
    return 0;
}

