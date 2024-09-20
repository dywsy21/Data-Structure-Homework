#include <bits/stdc++.h>
using namespace std;
#define int long long

#define N (size_t)(1e5 + 7)
int a[N];

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for(int i {}; i < n; i++) cin >> a[i]; 

    unordered_map<int, int> hashmap;
    for(int i {}; i < n; i++) {
        if(hashmap.count(a[i])) hashmap[a[i]] = -1;
        hashmap.emplace(a[i], 0);
    }

    vector<int> ret;

    for(int i {}; i < n; i++) {
        if(hashmap[a[i]] != -1) ret.push_back(a[i]);
    }


    for(int i {}; i < ret.size(); i++) {
        cout << ret[i] << ' ';
    }


    system("pause");
    return 0;
}