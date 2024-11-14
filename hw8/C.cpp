#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // 每次要删时从左到右遍历，找到第一个后面跟着的数 > 自己 的位置删掉即可
    string s; cin >> s;
    int a[10]; for(int i {1}; i < 10; i++) cin >> a[i];

    for(int i {9}; i; i--) {
        char cur_num = i + '0';
        while(a[i]--) {
            bool found = false; int pos = 0;
            for(int j {0}; j < s.size(); j++) {
                if(s[j] == cur_num) {
                    pos = j;
                    if(s[j + 1] > cur_num) {
                        found = true;
                        s.erase(j, 1);
                        break;
                    }
                }
            }
            if(not found and s[pos] == cur_num) s.erase(pos, 1);
        }
    }

    cout << s;
    // system("pause");
    return 0;
}