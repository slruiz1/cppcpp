#include <cstdint>
#include <climits>

#define INF INT_MAX
#define FUNCTION(func,op) void func(int& a, int b) { a = ((a)op(b)?(a):(b)); }
#define toStr(s) #s
#define io(x) cin >> x
#define foreach(v,i) for (size_t i = 0; i < v.size(); ++i)

#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif 

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main(){
	int n; cin >> n;
	vector<int> v(n, 0);
	foreach(v, i) {
		io(v)[i];
	}
	int mn = INF;
	int mx = -INF;
	foreach(v, i) {
		minimum(mn, v[i]);
		maximum(mx, v[i]);
	}
	int ans = mx - mn;
	cout << toStr(Result =) <<' '<< ans;
	return 0;

}
