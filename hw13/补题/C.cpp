// #include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
#define int long long
#pragma GCC optimize(3)

const int N = 3007;
string s, t;
int pw1[N], pw2[N], base1 = 233, base2 = 239;

signed main() {
    int _, __; cin >> _ >> __;
    cin >> s >> t;

    int sz = max(s.size(), t.size());

    int cur_pw1 = 1, cur_pw2 = 1;
    for(int i {}; i < N; i++) {
        pw1[i] = cur_pw1;
        cur_pw1 *= base1;
    }

    int ans = 0;
    for(int k{1}; k <= sz; k++) {
        unordered_map<int, int> counter1, counter2;

        // compute hashes for s
        int prev1[26] = {0};
        int cur_hash1 = 0;
        for(int i = 0; i < s.size(); i++) {
            int ch_add = s[i] - 'a';
            cur_hash1 -= pw1[ch_add] * prev1[ch_add];
            prev1[ch_add]++;
            cur_hash1 += pw1[ch_add] * prev1[ch_add];

            if(i >= k) {
                int ch_remove = s[i - k] - 'a';
                cur_hash1 -= pw1[ch_remove] * prev1[ch_remove];
                prev1[ch_remove]--;
                cur_hash1 += pw1[ch_remove] * prev1[ch_remove];
            }
            if(i >= k - 1) {
                counter1[cur_hash1]++;
            }
        }

        // compute hashes for t
        memset(prev1, 0, sizeof(prev1));
        cur_hash1 = 0;
        for(int i = 0; i < t.size(); i++) {
            int ch_add = t[i] - 'a';
            cur_hash1 -= pw1[ch_add] * prev1[ch_add];
            prev1[ch_add]++;
            cur_hash1 += pw1[ch_add] * prev1[ch_add];

            if(i >= k) {
                int ch_remove = t[i - k] - 'a';
                cur_hash1 -= pw1[ch_remove] * prev1[ch_remove];
                prev1[ch_remove]--;
                cur_hash1 += pw1[ch_remove] * prev1[ch_remove];
            }
            if(i >= k - 1) {
                counter2[cur_hash1]++;
            }
        }

        // count matching hashes
        if(counter1.size() > counter2.size()) swap(counter1, counter2);
        for(auto& [key, value] : counter1) {
            ans += value * counter2[key];
        }
    }

    cout << ans;

    return 0;
}