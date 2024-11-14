#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> v(n); for (int &i : v) cin >> i;
    
    vector<pair<int, int>> max_stk(n); // val, identifier
    for(int i {}; i < n; i++) {
        bool found = false;
        for(int j {max_stk.size() - 1}; j >= 0; j--) {
            if(max_stk[j].first > v[i]) {
                found = true;
                cout << max_stk[j].second + 1 << ' ';
                break;
            }
        }
        if(!found) cout << 0 << ' ';
        while(!max_stk.empty() && max_stk.back().first <= v[i]) max_stk.pop_back();
        max_stk.emplace_back(v[i], i);
    }


    // system("pause");
    return 0;
}