#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <cstdint>
#include <bitset>
#include <memory>

using namespace std;

#if 0
100000000 658061970 695098531 1430548937

100000000 178349423 584642695 2037647927

100000000 569099406 1607140150 823906344

Longest:
100000000 923092883 976061291 1205350525

#endif

constexpr size_t BF_SIZE = 1024*1024;
class BloomFilter {
    size_t hashFunctions = 3;
    bitset<BF_SIZE> bits{};

    inline size_t hash(const size_t number, size_t index) {
        return index + number;
    }
public:
    inline void add(const size_t number) {
        for (size_t i = 0; i < hashFunctions; ++i) {
            size_t index = hash(number, i) % BF_SIZE;
            bits[index] = true;
        }
    }

    inline bool contains(const size_t number) {
        for (size_t i = 0; i < hashFunctions; ++i) {
            size_t index = hash(number, i) % BF_SIZE;
            if (!bits[index]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N,S,P,Q;
    //unique_ptr<bitset<0x7fffffff>> bits(new bitset<0x7fffffff>());
    bitset<0x7fffffff>* bits = (bitset<0x7fffffff>*)std::aligned_alloc(128, sizeof(bitset<0x7fffffff>));
    auto& unique_nums = *bits;
    cin >> N >> S >> P >> Q;
    //cout << endl << "||~~> N=" << N << ", S=" << S << ", P=" << P << ", Q=" << Q << endl;
    uint64_t result = S;
    unique_nums[result] = true;
    for (int i = 1; i < N; ++i) {
        result = (result * P + Q) & 0x000000007fffffff; // want 0..(2^31 - 1)
        if (!unique_nums[result]) {
            unique_nums[result] = true;
        }
    }
    cout << unique_nums.count() << endl;
    free(bits);
    return 0;
}
