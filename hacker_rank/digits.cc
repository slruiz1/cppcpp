#include <bits/stdc++.h>
#if 0
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string_view>
#endif
using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int a,b;
    cin >> a;
    cin >> b;
    array<string_view, 10> digits = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    for (int n =a; n<=b; n++) {
        if (n >=1 && n <=9)
            printf("%.*s\n", (int)digits[n].size(), digits[n].data());
        else {
            printf("%s\n", n % 2 == 0 ? "even" : "odd" );            
        }
    }
    return 0;
}
