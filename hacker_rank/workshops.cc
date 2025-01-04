#include<bits/stdc++.h>
#if 0
8
1 2 3 0 5 5 8 8
1 1 1 6 2 4 1 2
A: 5

9
1 2 3 0 5 6 8 9 10
1 1 1 6 5 1 1 3  1
A: 6


2
1 1
2 1
A: 1

2
0 0
0 0
A: 2

2
2 0
1 1
A: 2

7
1 3 0 5 5 8 8
1 1 6 2 4 1 2
A: 4

6
1 3 0 5 5 8
1 1 6 2 4 1
A: 4

6
1 3 0 5 6 8
1 1 6 5 1 1
A: 4
#endif

using namespace std;
struct Workshop {
    int start_time = 0;
    int duration = 0;
    int end_time = 0;
};
struct Available_Workshops {
    int n = 0;
    vector<Workshop> arr{0};
};

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops

Available_Workshops* initialize(int start_time[], int duration[], int n) {
    Available_Workshops* aw = new Available_Workshops;
    aw->n = n;
    vector<Workshop>& arr = aw->arr;
    arr.resize(n);
    for (int i=0; i<n; ++i) {
        arr[i].start_time = start_time[i];
        arr[i].duration = duration[i];
        arr[i].end_time = start_time[i] + duration[i];
    }
    sort(arr.begin(), arr.end(),
        [](Workshop& w1, Workshop& w2) -> bool {
            if (w1.start_time == w2.start_time) {
                return w1.duration < w2.duration;
            }
            return w1.end_time < w2.end_time;
    });

    aw->arr = arr;
    return aw;
}
int CalculateMaxWorkshops(Available_Workshops* aw) {
    if (!aw ||aw->n == 0)
        return 0;
    if (aw->n == 1)
        return 1;
    const auto& arr = aw->arr;
    int count = 0;
    int last_end_time = 0;
    for (const auto& wc : arr) {
        if (wc.start_time >= last_end_time) {
            count++;
            last_end_time = wc.end_time;
        }
    }
    return count;
}

int main() {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
