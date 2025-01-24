#include <bits/stdc++.h>

using namespace std;

#if 0
template <typename T, int maxsize>
class lifo_stack {
    int n = 0;
    int max = INT_MIN;
    T a[maxsize] {};
public:
    bool push(const T& x) {
        if (n >= maxsize) {
            return false;
        }
        if (n == 0) {
            max = x;
            a[n] = x;
        } else if (x > max) {
            a[n] = (x << 1) - max;
            max = x;
        } else {
            a[n] = x;
        }
        ++n;
        printf("PUSH %d, max: %d\n", x, max);
        return true;
    }
    T pop() {
        if (n < 1) {
            return T();
        }
        --n;
        if (a[n] > max) {
            const T curr = max;
            max = (max << 1) - a[n]; // restore previous
            printf("\nPOP %d, max: %d\n", curr, max);
            return curr;
        }

        printf("\nPOP[%d] %d\n", n, a[n]);
        return a[n]; // return obj
    }
    size_t size() const {
        return n;
    }

    const T get_max() const {
        if (n < 1) {
            return T();
        }
        return (a[n-1] > max) ? max : a[n-1];
    }
};

// Example 9.5
// Template for Last-In-First-Out list
template <typename T, int maxsize>
class LIFOStack {
    protected:
        int n = 0; // Number of objects in list
        T list[maxsize]{}; // Array of objects
    public:
        bool push(T const & x) { // Put object into list
            if (n >= maxsize) {
                return false; // Return false if list full
            }
            list[n] = x;
            n++; // Increment count
            return true; // Return true if success
        }
        T pop() { // Get object from list
            if (n <= 0) {
                // Error: list empty
                // Put error message here: list empty
                return T(0);
            }
            n--; // Decrement count
            return list[n]; // Return object
        }

        int size() const { // Tell number of objects in list
            return n;
        }
};
#endif

template <typename T, int maxsize>
class lifo_stack {
    int n = 0;
    int n_max = 0;
    T a[maxsize] {};
    T max[maxsize] {};
public:
    bool push(const T& x) {
        if (n >= maxsize) {
            return false;
        }
        if (n == 0) {
            max[n_max++] = x;
        } else if (x > max[n_max-1]) {
            max[n_max++] = x;
        } else {
            a[n] = x;
        }
        a[n++] = x;
        printf("PUSH %d, max: %d\n", x, max[n_max-1]);
        return true;
    }

    T pop() {
        if (n < 1) {
            return T();
        }
        --n;
        if (a[n] == max[n_max-1]) {
            --n_max;
            printf("\nPOP %d, max: %d\n", a[n], max[n_max-1]);
        }

        printf("\nPOP[%d] %d\n", n, a[n]);
        return a[n]; // return obj
    }

    size_t size() const {
        return n;
    }

    const T get_max() const {
        if (n_max < 1) {
            return T();
        }
        return max[n_max-1];
    }
};

int main() {
    // ...
    // Example of use:
    //LIFOStack<int, 100> myQ;
    lifo_stack<int, 100> myQ;
    // put numbers in
    for (int i = 0; i < 5; i++) {
        myQ.push(i*10);
    }
    printf("\n%d\n", myQ.get_max());
    //myQ.push(INT_MAX-1);
    myQ.push(200);
    myQ.push(200);
    printf("|---> %d\n", myQ.get_max());
    myQ.pop();
    printf("|---> %d\n", myQ.get_max());

    // get numbers out in reverse order
    while (myQ.size() > 0) {
        printf("\n%i ", myQ.pop());
    }

    return 0;
}
