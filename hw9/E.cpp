#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define int long long

typedef unordered_map<int, int> hash_table;

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, k; cin >> n >> k;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    
    hash_table count;
    int unique_count = 0, left = 0, ans = 0;

    for(int right = 0; right < n; right++) {
        if(count[a[right]] == 0) unique_count++;
        count[a[right]]++;

        while(unique_count >= k) {
            ans += (n - right);
            count[a[left]]--;
            if(count[a[left]] == 0) unique_count--;
            left++;
        }
    }

    cout << ans;

    // system("pause");
    return 0;
}
