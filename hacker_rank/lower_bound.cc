#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#if 0
 8
 1 1 2 2 6 9 9 15
 4
 1
 4
 9
 15
#endif

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    unsigned n, q;
    cin >> n;
    vector<unsigned> nums(n);
    for (size_t i=0; i < n; ++i) {
        cin >> nums[i];
    }
    cin >> q;
    for (unsigned i=0; i < q; ++i) {
        cin >> n;
        // Search for 1st element x such that i <= x
        auto lower = lower_bound(nums.cbegin(), nums.cend(), n);
        if (lower != nums.end()) {
            if (*lower <= n) {
                cout << "Yes " << (lower-nums.begin())+1  << endl;
            } else {
                cout << "No " << (lower-nums.begin())+1  << endl;
            }
        }
    }

    return 0;
}

