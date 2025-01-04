#include <bits/stdc++.h>

using namespace std;

vector<string> permute_string(std::string s) {
        vector<string> perms;
        sort(s.begin(), s.end());
        do {
                perms.push_back(s);
        } while (std::next_permutation(s.begin(), s.end()));
        return perms;
}

vector<int> compute_prefix_function(const std::string& p) {
        const size_t m = p.length();
        vector<int> pf(m);
        pf[0] = 0; // always 0 because the first character has no proper prefix.
        int k = 0; // stores the length of the current candidate for the longest proper prefix suffix.
        for (size_t q = 1; q < m; ++q) {
                //int k = pf[q - 1];
                while (k > 0 && p[k] != p[q]) {
                        k = pf[k - 1];
                }
                if (p[k] == p[q]) {
                        ++k;
                }
                pf[q] = k;
                //printf("pf[%ld] = %d\n", q, pf[q]);
        }
        return pf;
}

#if 0
Index: 0 1 2 3 4 5 6 7 8
Pattern: A B A B C A B A B
Prefix Function: 0 0 1 2 0 1 2 3 4
#endif

int count_substr(string_view t, const std::string& p) {
        vector<int> pf = compute_prefix_function(p); // calculate the KMP prefix function
        //for (const int i : pf) { printf("%d ", i); }
        //puts("\n");
        //fflush(stdout);
        const int m = p.size();
        int cnt = 0;    // ocurrence count
        int q = 0;      // number of chars matched
        for (size_t i = 0; i < t.length(); ++i) {
                while (q > 0 && p[q] != t[i]) {
                        q = pf[q - 1];      // next char does not match, use LPS to skip chars
                }
                if (p[q] == t[i]) {
                        ++q;    // next char matches
                }
                if (q == m) {
                        printf("Pattern occurs in %.*s, with shift: %lu\n", (int)t.size(), t.data(), i + 1 - m);
                        q = pf[q - 1]; // look for the next match, use LPS to skip chars
                        cnt++;
                }
        }
        return cnt; 
}

#if 0
int count_substr(string_view t, const std::string& p) {
        int cnt = 0;
        auto pos = string_view::npos;
        while ((pos = t.find(p)) != string_view::npos) {
                cnt++;
                t.remove_prefix(pos + 1);
                //while (!t.empty() && t[0] != p[0])
                //        t.remove_prefix(1);
                //printf("||~> %.*s, t.empty(): %d, pos: %lu\n", (int)t.length(), t.data(), t.empty(), pos);
                //fflush(stdout);
        }
        return cnt; 
}
#endif

int main()
{
#if 0
        string m ="bacbababacacbab";
        string n = "ababaca";
        const int cnt = count_substr(m, n);
        cout << n << " " << cnt << endl;
#else
        //string m ="aabababbaababab";
        //string n = "baa";
        string m = "ABABDABACDABABCABAB";
        string n = "ABABCABAB";
        // Find the count of all sub string of n which are in m,
        //   e.g. aab, aba, baa = 2 + 4 + 1 = 7
        vector<string> v = permute_string(n);
        for (const auto& s : v) {
                const int cnt = count_substr(m, s);
                if (cnt)
                        cout << s << " " << cnt << endl;
        } 
#endif
        cout << endl;
        //cout << "sorted: " << n << endl;
        return 0;
}
