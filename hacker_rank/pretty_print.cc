#include <iostream>
#include <iomanip> 
using namespace std;
#if 0
2
100.345 2006.008 2331.41592653498
100.345 2006.008 2331.41592653498
#endif


int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;

        std::ios old_state(nullptr);
        old_state.copyfmt(std::cout);
        cout << nouppercase << showbase << hex << setw(0) << static_cast<long long int>(A) << endl;
        cout << setw(15) << setfill('_') << right << showpos << setprecision(2) << fixed <<  B << endl;
        cout << uppercase << noshowpos << setprecision(9) << scientific << C << endl;
        std::cout.copyfmt(old_state);
	}
	return 0;
}
