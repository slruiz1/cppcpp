#include <bits/stdc++.h>

using namespace std;

class TimeSeries
{
    vector<pair<time_t, double>> m_ts;
    size_t m_size = 0;
public:
    TimeSeries(size_t window)
        : m_ts(window)
    {}
    
    void AddValue(time_t time, double value);
    double GetValue(time_t time) const;    
    void Print(bool sorted) const;
};

void TimeSeries::AddValue(time_t time, double value) {
    const auto K = m_ts.size();
    m_ts[m_size % K] = make_pair(time, value);
    //printf("Added: m_ts[%lu] = %ld, %.2f\n", m_size % K, time, value);
    m_size++;
}

double TimeSeries::GetValue(time_t time) const {
    // Perform a binary search on circular sorted array
#if 1
    int low = 0, high = m_ts.size() - 1;
    while (low <= high) {
        // calculate middle index
        const int mid = low + ((high - low) >> 1);

        // check for target at mid, assume there are no multiple matches.
        if (m_ts[mid].first == time)
            return m_ts[mid].second;

        // check sorted half
        if (m_ts[low].first <= m_ts[mid].first) {
            if (time >= m_ts[low].first && time < m_ts[mid].first)
                high = mid - 1; // search left half
            else
                low = mid + 1;  // search right half
        }
        // Right half must be sorted
        else {
            if (time > m_ts[mid].first && time <= m_ts[high].first)
                low = mid + 1;  // search right half
            else
                high = mid - 1; // search left half
        }
    }
#else
    // This only works with a sorted array
    const auto citer = std::lower_bound(m_ts.begin(), m_ts.end(), make_pair(time, 0.0d),
        [](const pair<time_t, double> a, const pair<time_t, double> b) {
            return a.first < b.first;
        });
    if (citer != m_ts.end() && citer->first == time) {
        return citer->second;
    }
#endif
    return -1.00;
}

void TimeSeries::Print(bool sorted) const
{
    const auto K = m_ts.size();
    if (!sorted) {
        printf("unsorted, current size: %lu\n", m_size);
        for (size_t i = 0; i < K; i++) {
            auto [time, value] = m_ts[i];
            printf("m_ts[%lu] = %ld, %.2f\n", i, time, value);
        }
        return;
    }

    // compute start of the circular array
    auto start = m_size > K ? (m_size % K) : 0;
    auto count = min(K, m_size);
    for (size_t i = 0; i < count; i++) {
        auto [time, value] = m_ts[(start + i) % K];
        printf("m_ts[%lu] = %ld, %.2f\n", i, time, value);
    }
}

int main()
{
    int num;
    cin >> num;
    TimeSeries ts(10);
    time_t now = time(nullptr);
    printf(">> now: %ld\n", now);
    for (int i= 0; i < num; i++) {
        ts.AddValue(now + i, i);
    }
    ts.Print(true);
    ts.Print(false);
    auto val = ts.GetValue(now+5);
    printf("m_ts[%lu] = %.2f, vs. 5.00\n", now+5, val);
    return 0;
}
