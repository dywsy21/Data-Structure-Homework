#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
// using namespace __gnu_pbds;
#define int long long
// use O3 optimization
#pragma GCC optimize("O3")

#define INF 999999999999999999
const int N = 5e5 + 7;
int a[N], aux[N];
int n;

void solve() {
    int a_i = 0, aux_i = 0, aux_max_i = -1, ans = 0;
    for(int i {}; i < n - 1; i++) {
        int a1 = a[a_i], a2 = a[a_i + 1];
        int aux1 = aux_i > aux_max_i ? INF : aux[aux_i], aux2 = aux_i + 1 > aux_max_i ? INF : aux[aux_i + 1];

        int load;
        if(a1 <= aux1) {
            load = a1;
            a_i++;
            if(a2 <= aux1) {
                load += a2;
                a_i++;
            } else {
                load += aux1;
                aux_i++;
            }
        } else {
            load = aux1;
            aux_i++;
            if(a1 <= aux2) {
                load += a1;
                a_i++;
            } else {
                load += aux2;
                aux_i++;
            }
        }

        ans += load;
        aux[++aux_max_i] = load;
    }

    if(ans % 2) cout << (ans / 2) << ".5\n";
    else cout << (ans / 2) << ".0\n";
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; t--;
    cin >> n;
    for(int i {}; i < n; i++) cin >> a[i];
    a[n] = a[n + 1] = INF;
    solve();

    while(t--) {
        int m; cin >> m;
        while(m--) {
            int u, v; cin >> u >> v;
            a[u - 1] = v;
        }
        solve();
    }

    return 0;
}