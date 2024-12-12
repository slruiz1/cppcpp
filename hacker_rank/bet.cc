#include <bits/stdc++.h>
#if 0
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#endif
using namespace std;
#include <random>

/// \brief A random number generator that creates integers in the specified range.
///        By default uses the min/max of the specified type.
template <class IntType, IntType MIN = std::numeric_limits<IntType>::min(), IntType MAX = std::numeric_limits<IntType>::max()>
class rng {
    std::random_device rd; 
    std::uniform_int_distribution<IntType> distrib;
    std::mt19937_64 gen;
public:
    rng()
        : rd      ()  
        , distrib (MIN, MAX)
        , gen     ()  
    {   
            this->seed();
    }   

    void seed() { this->gen.seed(this->rd()); }
    IntType rand() { return this->distrib(this->gen); }
};

size_t s_module_id = 0;  // module id used for tracking fetches
rng<uint8_t, 0, 1> s_rng; // random number generator

namespace {
/// initialize random number generator
void init_rng()
{
    s_rng.seed();
}

uint8_t get_random_number() {
    return s_rng.rand();
}

}

float go_bet(int num) {
    float bal = 2.00f;
    for (int i=0; i<num; i++) {
        bal -= 1.00;
        const auto val = get_random_number();
        //const int toss = val % 2;
        bal += (val != 0) ? 0.55 : 1.55;
        //printf("num: %d, val: %u, bal: %.2f\n", num, val, bal);
        if (bal <= 0.00)
            break;
    }
    return bal;
}

int main() {
    init_rng();

    int num;
    cin >> num;
    auto balance = go_bet(num);
    cout << balance << endl;
    return 0;
}
