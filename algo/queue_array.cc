#include <bits/stdc++.h>

using namespace std;

// Example 9.6
// Template for First-In-First-Out list

template<typename T, int maxsize>
class fifo_queue {
    T* head = list, * tail = list;
    int n = 0; // size
    T list[maxsize]{}; // circular buffer

public:
    //fifo_queue(const fifo_queue&) = delete;
    //fifo_queue& operator=(const fifo_queue&) = delete;

    bool put(T const& x) {
        if (n >= maxsize) {
            return false; // list is full 
        }
        *head++ = x;
        ++n;
        if (head >= list + maxsize) {
            head = list; // wrap around
        }
        return true; 
    }

    T get() {
        if (n < 1) {
            return T(); // queue is empty!
        }
        T* p = tail;
        ++tail;
        if (tail >= list + maxsize) {
            tail = list; // wrap around
        }
        --n;
        return *p;
    }

    int getNum() const {
        return n;
    }
};

template <typename T, int maxsize>
class FIFOQueue {
    protected:
        T * head = list, * tail = list; // Pointers to current head and tail
        int n = 0; // Number of objects in list
        T list[maxsize]{}; // Circular buffer
    public:
        bool put(T const & x) { // Put object into list
            if (n >= maxsize) {
                return false; // Return false if list full
            }
            n++; // Increment count
            *head = x; // Copy x to list
            head++; // Increment head pointer
            if (head >= list + maxsize) {
                head = list; // Wrap around
            }
            return true; // Return true if success
        }
        T get() { // Get object from list
            if (n <= 0) {
                // Put an error message here: list empty
                return T(0); // return zero object if possible
            }
            n--; // Decrement count
            T * p = tail; // Pointer to object
            tail++; // Increment tail pointer
            if (tail >= list + maxsize) {
                tail = list; // Wrap around
            }
            return *p; // Return object
        }
        int getNum() const { // Tell number of objects in list
            return n;
        }
};

int main() {
    // Example of use:
    //FIFOQueue<int, 100> myQ;
    fifo_queue<int, 100> myQ;
    // put numbers in
    for (int i = 0; i < 5; i++) {
        myQ.put(i*10);
    }
    // get numbers out in same order
    while (myQ.getNum() > 0) {
        printf("\n%i ", myQ.get());
    }
}
