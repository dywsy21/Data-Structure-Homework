#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i {}; i < n; i++) cin >> a[i];

    vector<int> left_least(n, -1), right_least(n, n), left_most(n, -1), right_most(n, n);
    stack<int> stk1, stk2, stk3, stk4;

    for(int i {}; i < n; i++) {
        while(not stk1.empty() and a[stk1.top()] >= a[i]) stk1.pop();
        left_least[i] = stk1.empty() ? -1 : stk1.top();
        stk1.push(i);
    }

    for(int i {n - 1}; i >= 0; i--) {
        while(not stk2.empty() and a[stk2.top()] > a[i]) stk2.pop();
        right_least[i] = stk2.empty() ? n : stk2.top();
        stk2.push(i);
    }

    for(int i {}; i < n; i++) {
        while(not stk3.empty() and a[stk3.top()] <= a[i]) stk3.pop();
        left_most[i] = stk3.empty() ? -1 : stk3.top();
        stk3.push(i);
    }

    for(int i {n - 1}; i >= 0; i--) {
        while(not stk4.empty() and a[stk4.top()] < a[i]) stk4.pop();
        right_most[i] = stk4.empty() ? n : stk4.top();
        stk4.push(i);
    }

    // for(int i {}; i < n; i++) cout << right_most[i] << ' '; cout << endl;
    // for(int i {}; i < n; i++) cout << left_most[i] << ' '; cout << endl;
    // for(int i {}; i < n; i++) cout << right_least[i] << ' '; cout << endl;
    // for(int i {}; i < n; i++) cout << left_least[i] << ' '; cout << endl;




    int ans = 0;
    for(int i {}; i < n; i++) {
        ans += (right_most[i] - i) * (i - left_most[i]) * a[i];
        ans -= (right_least[i] - i) * (i - left_least[i]) * a[i];
    }
    cout << ans;

    return 0;
}