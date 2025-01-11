#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
#if 0
8
1 9
1 6
1 10
1 4
3 6
3 14
2 6
3 6
#endif

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    unsigned x, y, q;
    cin >> q;
    set<unsigned> s;
    for (size_t i=0; i < q; ++i) {
        cin >> y >> x;
        switch(y) {
            case 1: // Add an element x to the set.
                s.insert(x);
                break;

            case 2: // Delete an element x from the set. (If the number  is not present in the set, then do nothing).
                s.erase(x);
                break;

            case 3: // If the number x is present in the set, then print "Yes"(without quotes) else print "No"(without quotes).
                const auto iter = s.find(x);
                cout << (iter != s.cend() ? "Yes" : "No") << endl;
                break;
        }
    }
    return 0;
}

