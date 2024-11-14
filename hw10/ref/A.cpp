#include <iostream>
using namespace std;
#define int long long

int n, m;

int getSize(int x) {
    int size = 0, l = x, r = x;
    while (l <= n) {
        size += min(r, n) - l + 1;
        l = l * 2;
        r = r * 2 + 1;
    }
    return size;
}

int getRank(int x) {
    int rank = 1, curr = x;
    while (curr > 1) {
        if (curr % 2) rank += getSize(curr - 1) + 1; 
        else rank++;
        curr /= 2;
    }
    return rank;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    while (m--) {
        int x; cin >> x;
        cout << getRank(x) << endl;
    }
    return 0;
}