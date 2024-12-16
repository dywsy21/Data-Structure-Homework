#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

string s;
const int base1 = 233, base2 = 197, mod1 = 1e9 + 7, mod2 = 1e9 + 9, N = 1e5 + 7;
int a[N], b[N], p1[N], p2[N];

bool is_equal(int l1, int r1, int l2, int r2) {
    // First hash check
    int h1 = (a[r1] - a[l1 - 1] * p1[r1 - l1 + 1] % mod1 + mod1) % mod1;
    int h2 = (a[r2] - a[l2 - 1] * p1[r2 - l2 + 1] % mod1 + mod1) % mod1;

    // Second hash check
    int h3 = (b[r1] - b[l1 - 1] * p2[r1 - l1 + 1] % mod2 + mod2) % mod2;
    int h4 = (b[r2] - b[l2 - 1] * p2[r2 - l2 + 1] % mod2 + mod2) % mod2;
    return h1 == h2 && h3 == h4;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s; s = " " + s;
    int n = s.size();
    p1[0] = p2[0] = 1;
    for(int i = 1; i <= n; i++) {
        a[i] = (a[i - 1] * base1 + s[i]) % mod1;
        b[i] = (b[i - 1] * base2 + s[i]) % mod2;
        p1[i] = (p1[i - 1] * base1) % mod1;
        p2[i] = (p2[i - 1] * base2) % mod2;
    }

    cout << is_equal(1, 3, 4, 6) << endl;

    system("pause");
    return 0;
}