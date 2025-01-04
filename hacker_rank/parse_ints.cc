#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	stringstream ss(str);
    vector<int> ret;
    int i;
    char c;
    while (ss >> i) {
        ret.push_back(i);
        ss >> c; //skip delimiter
    }
    return ret;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(size_t i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    return 0;
}
