#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long



signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    vector<int> next(s.size(), 0);

    for(int i {1}; i < s.size(); i++) {
        int j = next[i - 1];
        while(s[i] != s[j] && j) j = next[j - 1];
        if(s[i] == s[j]) next[i] = j + 1;
    }

    for(int n: next) cout << n << ' ';

    // system("pause");
    return 0;
}