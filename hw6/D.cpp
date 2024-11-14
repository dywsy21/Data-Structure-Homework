#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

vector<int> max_bucket_capacities(int n, vector<int>& a) {
    vector<int> left(n, -1);  // 左边第一个比当前木板小的木板位置
    vector<int> right(n, n);  // 右边第一个比当前木板小的木板位置
    vector<int> ret(n);

    // 使用单调栈计算左边界
    stack<int> stk1, stk2;
    for(int i = 0; i < n; i++) {
        while (!stk1.empty() && a[stk1.top()] >= a[i]) stk1.pop();
        left[i] = stk1.empty() ? -1 : stk1.top();
        stk1.push(i);
    }

    // 使用单调栈计算右边界
    for(int i = n - 1; i >= 0; i--) {
        while (!stk2.empty() && a[stk2.top()] >= a[i]) stk2.pop();
        right[i] = stk2.empty() ? n : stk2.top();
        stk2.push(i);
    }

    // 根据左右边界计算每个长度的最大最小值
    for(int i = 0; i < n; i++) {
        int length = right[i] - left[i] - 1;  // 当前木板可以作为最小值的区间长度
        ret[length - 1] = max(ret[length - 1], a[i]);
    }

    // 之前应该要对index在 0..length 内的ret的值都重设一遍的，这样也能解决问题，而且更快
    for(int i = n - 2; i >= 0; i--) ret[i] = max(ret[i], ret[i + 1]);
    
    return ret;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n); for(int &i: a) cin >> i;

    vector<int> result = max_bucket_capacities(n, a);
    for(int i = 0; i < n; i++) cout << result[i] << ' ';
    
    // system("pause");
    return 0;
}