#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int w, h, n; cin >> w >> h >> n;
    set<int> ws, hs;
    multiset<int> w_lengths, h_lengths;
    ws.insert(0); ws.insert(w);
    hs.insert(0); hs.insert(h);
    w_lengths.insert(w);
    h_lengths.insert(h);

    while(n--) {
        char op; int a; cin >> op >> a;
        set<int>& working_set = (op == 'H' ? hs : ws);
        multiset<int>& working_lengths = (op == 'H' ? h_lengths : w_lengths);

        auto it = working_set.lower_bound(a);
        int upper = *it; int lower = *prev(it); // *it is in (lower, upper] 
        working_set.insert(a);
        working_lengths.erase(working_lengths.find(upper - lower));
        working_lengths.insert(a - lower);
        working_lengths.insert(upper - a);

        // *rbegin() is the largest element
        cout << (*w_lengths.rbegin()) * (*h_lengths.rbegin()) << '\n';
    }

    // system("pause");
    return 0;
}