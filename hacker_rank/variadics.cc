#include <iostream>
#include <vector>
using namespace std;

// Enter your code for reversed_binary_value<bool...>()
template<bool...digits>
int reversed_binary_value() {
    constexpr bool bits[] = {digits...};
    constexpr int numBits = sizeof...(digits);
    int reversed = 0;
    for (int i = 0; i < numBits; ++i) {
        if (bits[i]) {
            reversed |= (1 << i);
        }
        //reversed += std::pow(2,i) * bits[i];
        //reversed |= ((bits[i] & 1) << i);
    }
    return reversed;
}

template <int n, bool...digits>
struct CheckValues {
  	static void check(int x, int y)
  	{
    	CheckValues<n-1, 0, digits...>::check(x, y);
    	CheckValues<n-1, 1, digits...>::check(x, y);
  	}
};

template <bool...digits>
struct CheckValues<0, digits...> {
  	static void check(int x, int y)
  	{
    	int z = reversed_binary_value<digits...>();
    	std::cout << (z+64*y==x);
  	}
};

int main()
{
  	int t; std::cin >> t;

  	for (int i=0; i!=t; ++i) {
		int x, y;
    	cin >> x >> y;
    	cout << "\n";
    	CheckValues<6>::check(x, y);  // 2^6 function types generated, recursively call each other
    	cout << "\n";
  	}
}
