#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#if 0
7
1 Jesse 20
1 Jess 12
1 Jess 18
3 Jess
3 Jesse
2 Jess
3 Jess
#endif

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    unsigned val, y, q;
    string key;
    cin >> q;
    map<string,unsigned> m;
    for (size_t i=0; i < q; ++i) {
        cin >> y;
        switch(y) {
            case 1: // Add the marks Y to the student whose name is X.
                cin >> key;
                cin >> val;
                m[key] += val;
                break;

            case 2: // Erase the marks of the students whose name is X.
                cin >> key;
                m[key] = 0;
                break;

            case 3: // Print the marks of the students whose name is X. (If X didn't get any marks print 0.)
                cin >> key;
                const auto iter = m.find(key);
                if (iter != m.cend()) {
                    cout << iter->second << endl;
                } else {
                    cout << '0' << endl;
                }
                break;
        }
    }
    return 0;
}

