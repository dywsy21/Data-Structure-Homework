// 声明: 参考了尚书同学的思路
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long
#pragma GCC optimize(3)

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, s; cin >> n >> s;
	int a[n]; for (int i {}; i < n; i++) cin >> a[i];
    unordered_map<int, int> hashmap;

	int left = n / 2, right = n - n / 2, ans = 0;

    // Use binary expression to generate all possible sums
	for (int i {}; i < (1 << left); i++) {
		int sum = 0;
		for (int pw {}; pw < left; pw++) if ((1 << pw) & i) sum += a[pw];
		hashmap[sum]++;
	}

	for (int i {}; i < (1 << right); i++) {
		int sum = 0;
		for (int pw {}; pw < right; pw++) if ((1 << pw) & i) sum += a[pw + left];
		ans += hashmap[s - sum];
	}
	cout << ans;

    // system("pause");
    return 0;
}