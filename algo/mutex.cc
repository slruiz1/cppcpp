#include <bits/stdc++.h>

using namespace std;

// USE: mutexlock if we expect to be waiting for a VERY SHORT period of time.
//      keep thread alive, busy waiting on lock

int main() {
    // Random number generator
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution dist(10, 20);

    // Create vector of random numbers
    std::vector<int> v;
    std::generate_n(std::back_inserter(v), 1 << 20,
        [&]() { return dist(mt); });

    printf("Generated %lu random numbers\n", v.size());

    // lock to access the list
    std::mutex m;

    // Function that removes items from the list in parallel
    auto work = [&]() {
        // run until there are no more items
        while (true) {
            // Grab the lock before doing anything
            std::lock_guard<std::mutex> lg(m);

            // Check if there are no more items
            if (v.empty()) break;

            // Remove item from the list
            v.pop_back();
        }
    };

    // Spawn threads
    const int num_threads = 8;
    std::vector<std::jthread> threads;
    for (int i=0; i < num_threads; ++i) {
        threads.emplace_back(work);
    }

    return 0;
}
