#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long
#define MAXN 1000010

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    vector<int> stk;
    int m = 0, n, a, b, sum = 0, lastans = 0, v, op, ary[MAXN];
    cin >> n;
    while (n--) {
        cin >> a >> b;
        op = lastans ^ a;
        v = lastans ^ b;
        if (op == 1) {
            m++;
            while (!stk.empty() && v > ary[stk.back()]) stk.pop_back();
            stk.push_back(m);
            ary[m] = v;
        }
        else {
            // lower_bound: find the first element which >= m - v + 1
            int idx = lower_bound(stk.begin(), stk.end(), m - v + 1) - stk.begin();
            sum += ary[stk[idx]];
            lastans = ary[stk[idx]];
        }
    }
    cout << sum;

    // system("pause");
    return 0;
}
