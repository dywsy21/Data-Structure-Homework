#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e6 + 7;

int a[N], ans[N], stk[2 * N], stk2[N];
bool already_powered_up[N];

signed main() {
    int n, top = 0; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n; i; i--) {
        int top2 = 0;
        while (top && a[i] > a[stk[top]]) {
            if (already_powered_up[stk[top]]) ans[stk[top--]] = i + 1; // already 爆气ed once, we have the answer here, pop out the var
            else stk2[++top2] = stk[top--]; // store the stack
        }
        stk[++top] = i;
        while (top2) { // restore the stack
            stk[++top] = stk2[top2];
            already_powered_up[stk2[top2--]] = true;
        }
    }
    while (top) ans[stk[top--]] = 1;
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    return 0;
}