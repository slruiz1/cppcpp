#include <bits/stdc++.h>

using namespace std;

// what will this code print? NOTHING
// when will it stop? when process is killed by OOM.
// which memory is allocated (Virtual or Physical) Memory hierarchy of OS? Physical from the glibc heap.

int main() {
        //int c;
        int cnt=0;
        while(1) {
                cnt++;
                char* m = static_cast<char*>(malloc(100));
                //*m = 'x';
                if ( m == nullptr) {
                        // This never get executed because OOM killer kills this process.
                        printf ("Unable to allocate memory, error(%d): %s, m: %p\n", errno, strerror(errno), m);
                        throw bad_alloc();
                } 
                //if (cnt % 1000000)
                //        cin >> c;
        }
        return 0; 
}

