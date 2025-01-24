#include <bits/stdc++.h>
#include <pthread.h>
#include <atomic>
#include <immintrin.h>

pthread_barrier_t barrier;

using namespace std;

// USE: spinlock if we expect to be waiting for a VERY SHORT period of time.
//      keep thread alive, busy waiting on lock (i.e., with yield)
struct spinlock_amd
{
    void lock()
    {
        for (;;)
        {
            bool was_locked = locked.load(std::memory_order_relaxed);
            if (!was_locked && locked.compare_exchange_weak(was_locked, true, std::memory_order_acquire))
                break;
            _mm_pause();
        }
    }
    void unlock()
    {
        locked.store(false, std::memory_order_release);
    }
 
private:
    std::atomic<bool> locked{false};
};

int main() {
    // Random number generator
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution dist(10, 20);

    // Create vector of random numbers
    std::vector<int> v;
    std::generate_n(std::back_inserter(v), 1 << 20,
        [&]() { return dist(mt); });

    // Acquire lock to access the list
    pthread_spinlock_t spinlock;
    pthread_spin_init(&spinlock, 0);

    // Function that removes items from the list in parallel
    auto work = [&]() {
        // run until there are no more items
        while (true) {
            // Grab the lock before doing anything
            pthread_spin_lock(&spinlock);

            // Check if there are no more items
            if (v.empty()) {
                pthread_spin_unlock(&spinlock);
                break;
            }

            // Remove item from the list
            v.pop_back();
            pthread_spin_unlock(&spinlock);
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
