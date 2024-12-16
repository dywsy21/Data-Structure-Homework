#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

// 当且仅当s里有“LR”且除了这两个以外其他灯都已被照亮时，交换可行
// 只需寻找最靠右的L和最靠左的R即可

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    int l = -1, r = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'L') l = i;
        if (s[i] == 'R' && r == -1) r = i;
    }
    if(l == -1 || r == -1){
        cout << -1;
        return 0;
    }
    if(l > r) {
        cout << 0;
        return 0;
    }
    if(l == r - 1) {
        cout << l + 1;
        return 0;
    }
    else {
        cout << -1;
        return 0;
    }
    


    // system("pause");
    return 0;
}