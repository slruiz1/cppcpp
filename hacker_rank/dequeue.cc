#include <iostream>
#include <deque>
#include <climits> 
using namespace std;

// Implement a custom queue with max tracking

void printKMax(int arr[], int n, int k){
    deque<int> max_q;
    deque<int> q;
    max_q.emplace_back(INT_MIN);
    int left = n;
    while (left > 0 || !max_q.empty()) {
        // Fill subarray
        if (left > 0) {
            const int start = n-left;
            const int end = min(k,left);
            for (int j=0; j < end; ++j) {
                const int i = arr[start+j];
                // Enqueue
                q.push_back(i);
                while (!max_q.empty() && max_q.back() < i) {
                    max_q.pop_back();
                }
                max_q.push_back(i);
//printf(">>> %d/%d. PUSH(%d), max: %d\n", start+j, end, i, max_q.front());
                // --
                left--;
                if (q.size() == (size_t)k) {
                    break;
                }
            }
        } else if (q.size() < (size_t)k) {
            break;
        }
        // Dequeue
        cout << max_q.front() << " ";
        if (q.front() == max_q.front()) {
            max_q.pop_front();
        }
//printf("<<< POP: %d, left: %d, max: %d\n", q.front(), left, max_q.front());
        q.pop_front();
    }
    cout << endl;
}

int main(){
 	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}
