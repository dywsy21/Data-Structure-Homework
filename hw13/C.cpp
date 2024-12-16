#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

const int N = 1e5 + 7;
int a[N], t[N], p[N], w[N];

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, v1, v2; cin >> n >> v1 >> v2;
    for(int i {1}; i <= n; i++) cin >> a[i] >> t[i] >> p[i] >> w[i];

    // 第一组 -> cal1, 第二组 -> cal2 对组1的同学查cal2, 对组2的同学查cal1

    vector<int> cal1, cal2;
    for(int i {1}; i <= n; i++) {
        if(a[i] == 1) cal1.push_back(v1 * p[i] - v1 * v2 * t[i]);
        if(a[i] == 2) cal2.push_back(v2 * p[i] - v1 * v2 * t[i]);
    }

    sort(cal1.begin(), cal1.end());
    sort(cal2.begin(), cal2.end());

    for(int i {1}; i <= n; i++) {
        if(a[i] == 1) {
            int low_index = lower_bound(cal2.begin(), cal2.end(), v1 * p[i] - v1 * v2 * t[i]) - cal2.begin();
            int high_index = upper_bound(cal2.begin(), cal2.end(), v1 * p[i] - v1 * v2 * t[i] + v1 * w[i]) - cal2.begin();
            cout << high_index - low_index << '\n';
        }
        if(a[i] == 2) {
            int low_index = lower_bound(cal1.begin(), cal1.end(), v2 * p[i] - v1 * v2 * t[i]) - cal1.begin();
            int high_index = upper_bound(cal1.begin(), cal1.end(), v2 * p[i] - v1 * v2 * t[i] + v2 * w[i]) - cal1.begin();
            cout << high_index - low_index << '\n';
        }
    }




    // system("pause");
    return 0;
}