#include <iostream>
#include <deque>
#include <climits> 
using namespace std;

void printKMax(int arr[], int n, int k){
    int left = n;
    while (left >= k) {
        int start = n-left;
        int max=INT_MIN;
        for (int j=0; j < k; ++j) {
            int i = arr[start+j];
            if (max < i) {
                max = i;
            }
        }
        left--;
        cout << max << " ";
    }
    cout << endl;
    cin.ignore();
#if SLOW
    deque<int> dq(&arr[0], &arr[n]);
printf("\n|~~> size: %lu, k: %d\n", dq.size(), k);
    while (dq.size() >= (size_t)k) {
        int max=INT_MIN;
        for (int j=0; j < k; ++j) {
            int i = dq[j];
            if (max < i) {
                max = i;
            }
        }
        dq.pop_front();
        cout << max << " ";
    }
    cout << endl;
#endif
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
