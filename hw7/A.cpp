#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >> n;

    vector<int> A;
    int lastans = 0, sum_of_ans = 0;

    while(n--) {
        int a, b; cin >> a >> b;

        int op = lastans ^ a;
        int u = lastans ^ b;

        if (op == 1) A.push_back(u);
        else if (op == 2) {
            multiset<int> window(A.end() - u, A.end());
            int max_value = *window.rbegin(); // Get the maximum element

            lastans = max_value;
            sum_of_ans += max_value;
        }
    }

    cout << sum_of_ans;

    return 0;
}
