#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Enemy {
    int a, b; // a: damage, b: heal
    Enemy(int a, int b) : a(a), b(b) {}
};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, x; cin >> n >> x;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    vector<Enemy> enemies;
    for(int i = 0; i < n; i++) enemies.emplace_back(a[i], b[i]);
    // 净收益 >= 0的放前面，按a从小到大排序；净收益 < 0的放后面，按b从大到小排序
    sort(enemies.begin(), enemies.end(), [](const Enemy &e1, const Enemy &e2) { // true: e1 < e2, false: e1 > e2
        int profit1 = e1.b - e1.a, profit2 = e2.b - e2.a;
        if(profit1 >= 0 && profit2 >= 0) return e1.a < e2.a;
        if(profit1 < 0 && profit2 < 0) return e1.b > e2.b;
        return profit1 > profit2;
    });

    for(int i = 0; i < n; i++) {
        x -= enemies[i].a;
        if(x <= 0) {
            cout << "NO";
            return 0;
        }
        x += enemies[i].b; 
    }

    cout << "YES";
    return 0;
}
