#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m; cin >> m;
    stack<int> max_nums;
    while(m--) {
        string s; cin >> s;
        int ret = 0;
        if(s == "pop"){
            if(max_nums.empty()) ret = -1;
            else {
                max_nums.pop();
                if(max_nums.empty()) ret = -1;
                else ret = max_nums.top();
            }
        }
        else if(s == "push") {
            int num; cin >> num;
            if(max_nums.empty()) ret = num;
            else ret = max(max_nums.top(), num);
            max_nums.push(ret);
        }
        if(ret == -1) cout << "empty\n";
        else cout << ret << '\n';
    }


    // system("pause");
    return 0;
}