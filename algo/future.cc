#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;

void findOdd(std::promise<ull> OddSumPromise, ull start, ull end) {
        int OddSum = 0;
        for (ull i = start; i <= end; ++i) {
                if (i & 1) {
                        OddSum += i;
                }
        }
        OddSumPromise.set_value(OddSum);
}

int main () {
        ull start = 0, end = 1900000000;

		ull ceil(end/256);
		cout << "ceil " << ceil << endl;

        std::promise<ull> OddSum;
        std::future<ull> OddFuture = OddSum.get_future(); // promise returns waitable object.

        cout << "C++ Thread Created!!!" << endl;
        std::thread t1(findOdd, std::move(OddSum), start, end); // constructor uses variadic template.
		std::this_thread::yield();
        cout << "Waiting For Result..." << endl;
        auto sum = OddFuture.get();
        cout << "OddSum: " << sum << endl; // future can still access promised data.
        cout << "Completed!! " << endl;
        t1.join(); 
        return 0;
}
