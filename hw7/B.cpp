#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

const int N = 1e5 + 7;
vector<int> nums(N), temp(N);

int merge(int left, int right) {
    int mid = (left + right) / 2;
    int i = left, j = mid + 1, k = left;
    int inv_count = 0;

    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) temp[k++] = nums[i++];
        else {
            temp[k++] = nums[j++];
            inv_count += mid - i + 1; // 左边[i, mid]里的数都比右边的当前数大，形成逆序对
        }
    }

    // 以下两行只有一行会被执行，所以顺序无所谓
    while (i <= mid) temp[k++] = nums[i++];
    while (j <= right) temp[k++] = nums[j++];

    for (i = left; i <= right; ++i) nums[i] = temp[i];
    
    return inv_count;
}

int mergeSort(int left, int right) {
    int inv_count = 0;
    if (right > left) {
        int mid = (left + right) / 2;
        inv_count += mergeSort(left, mid);
        inv_count += mergeSort(mid + 1, right);
        inv_count += merge(left, right);
    }
    return inv_count;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> nums[i];
    int ans = mergeSort(0, n - 1) - k;
    cout << (ans >= 0 ? ans : 0);

    // system("pause");
    return 0;
}