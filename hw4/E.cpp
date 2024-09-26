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

#ifdef DEBUG
        cout << "Processing string: " << s << endl;
#endif

        for(char c: s) {
#ifdef DEBUG
            cout << "Current character: " << c << ", v1[index]: " << v1[index] << ", index: " << index << endl;
#endif
            if(v1[index] == c){
                index = (index + 1) % s.length(); v2 += (c);
#ifdef DEBUG
                cout << "Characters matched. Incremented index: " << index << ", v2: " << v2 << endl;
#endif
            } 
            else {
                index = 0; v1 += v2;
                v2.clear(); v1 += c;
#ifdef DEBUG
                cout << "Characters did not match. Reset index, updated v1: " << v1 << endl;
#endif
            }
        }
        cout << (int)s.length() - index << '\n';
#ifdef DEBUG
        cout << "Result for current string: " << (int)s.length() - index << endl;
#endif
    }


    // system("pause");
    return 0;
}
