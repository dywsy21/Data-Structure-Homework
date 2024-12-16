#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    set<pair<int, int>> s;
    s.insert({1e8, 1});
    while(n--){
        int id, prowess; cin >> id >> prowess;
        auto it = s.lower_bound({prowess, 0});
        if (it == s.end()) --it;
        else if (it != s.begin() && (prowess - prev(it)->first <= it->first - prowess)) --it;
        
        cout << id << " " << it->second << '\n';
        s.insert({prowess, id});
    }

    system("pause");
    return 0;
}