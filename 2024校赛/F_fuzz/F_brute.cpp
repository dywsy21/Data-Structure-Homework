#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long c;
    cin >> n >> c;
    vector<long long> a(n), b(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];

    long long max_total = LLONG_MIN;

    for(int mask = 0; mask < (1 << n); ++mask) {
        long long prof_chi = 0, prof_math = 0;
        long long last_decrease_chi = c, last_decrease_math = c;

        for(int i = 0; i < n; ++i) {
            bool review_chi = (mask & (1 << i)); 
            if(review_chi) {
                prof_chi += a[i];
                prof_math -= last_decrease_math;
                last_decrease_math *= 2;
                last_decrease_chi = c;
            } else {
                prof_math += b[i];
                prof_chi -= last_decrease_chi;
                last_decrease_chi *= 2;
                last_decrease_math = c;
            }
        }
        long long total = prof_chi + prof_math;
        max_total = max(max_total, total);
    }
    cout << max_total << endl;
    return 0;
}
