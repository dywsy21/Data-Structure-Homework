#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

const int N = 1e6 + 7; int p[N];

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) cin >> p[i];

    // sk stores k smallest elements, s_aux stores the rest elements in the window with length of m
    multiset<int> sk, s_aux; int cur_sum = 0;

    for(int i = 1; i <= m; i++) {
        sk.insert(p[i]);
        cur_sum += p[i];
    }

    while(sk.size() > k) {
        auto it = prev(sk.end());
        cur_sum -= *it;
        s_aux.insert(*it);
        sk.erase(it);
    }

    cout << cur_sum << " ";

    for(int i = m + 1; i <= n; i++) {
        int out = p[i - m], in = p[i];

        // maintain sk and s_aux. out is either in sk or s_aux, remove it
        auto it = sk.find(out);
        if(it != sk.end()) {
            sk.erase(it);
            cur_sum -= out;
        } 
        else s_aux.erase(s_aux.find(out));
        
        // insert in into sk or s_aux
        sk.insert(in); cur_sum += in;
        if(sk.size() > k) {
            auto it = prev(sk.end());
            cur_sum -= *it;
            s_aux.insert(*it);
            sk.erase(it);
        }

        // use s_aux to get the correct sk
        while(!s_aux.empty() && *s_aux.begin() < *prev(sk.end())) {
            auto it_bigger = prev(sk.end());
            auto it_smaller = s_aux.begin();
            cur_sum += *it_smaller; cur_sum -= *it_bigger;
            sk.insert(*it_smaller); s_aux.erase(it_smaller); 
            s_aux.insert(*it_bigger); sk.erase(it_bigger); 
        }

        cout << cur_sum << " ";
    }

    return 0;
}