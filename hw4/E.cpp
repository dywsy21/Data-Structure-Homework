#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

const int N = 1e5 + 7;

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) {
        string s; cin >> s;
        string v1(N, '0'), v2(N, '0'); int index = 0;
        // v1.reserve(N); v2.reserve(N);
        for(char c: s) {
            if(v1[index] == c){
                index = (index + 1) % s.length(); v2 += (c);
            } 
            else {
                index = 0; v1 += v2;
                v2.clear(); v1 += c;
            }
        }
        cout << (int)s.length() - index << '\n';
    }


    // system("pause");
    return 0;
}