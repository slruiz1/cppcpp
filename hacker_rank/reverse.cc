#include <bits/stdc++.h>

using namespace std;
#if 0
vector<string> split(const string& str) {
    vector<string> tokens;
    string::size_type start = 0, end;
    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }
    return tokens;
}
#endif
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i=0; i<n; i++) {
        //cin >> nums[i];
        int res = scanf("%d", &nums[i]);
        if (res != 1) return -1;
    }
    string tmp;
    for (auto citer = nums.rbegin(); citer != nums.rend(); ++citer) {
        tmp.append(std::to_string(*citer)).append(" ");
    }
    if (!tmp.empty())
        tmp.pop_back();
    cout << tmp;
    return 0;
}

