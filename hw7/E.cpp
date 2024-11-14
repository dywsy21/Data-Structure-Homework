#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

const int N = 2e5 + 7;
int a[N], b[N], psum_of_b[N];

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i {}; i < n; i++) cin >> a[i];
    for (int i {}; i < m; i++) cin >> b[i];

    sort(a, a + n); sort(b, b + m);

    psum_of_b[0] = b[0];
    for (int i = 1; i < m; i++) psum_of_b[i] = psum_of_b[i - 1] + b[i];

    int ans {};
    // binary search the position of a[i] in b, namely the number of elements in b that are <= a[i]
    for (int i = 0; i < n; i++){
        int pos = upper_bound(b, b + m, a[i]) - b;
        ans += pos * a[i] - (pos == 0 ? 0 : psum_of_b[pos - 1]);
        ans += (psum_of_b[m - 1] - psum_of_b[pos - 1]) - (m - pos) * a[i];
    }
    cout << ans;

    // system("pause");
    return 0;
}