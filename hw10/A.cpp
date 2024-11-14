#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

int n;
// calculate the number of nodes in the subtree with root x
long long countNodes(long long x) {
    long long cnt = 0;
    long long left = x, right = x;
    while(left <= n){
        cnt += min(n, right) - left + 1;
        left = left * 2;
        right = right * 2 + 1;
    }
    return cnt;
}

// Function to calculate the rank of node x in pre-order traversal
int getRank(int x) {
    if(x == 1) return 1;
    int rank = 1;
    long long current = 1;
    while(current != x){
        long long left = current * 2;
        long long right = current * 2 + 1;
        long long leftSubtreeSize = countNodes(left);

        if(x >= left && x < left + leftSubtreeSize){
            // Go to left child
            current = left;
            rank += 1;
        }
        else{
            // Go to right child
            rank += 1 + leftSubtreeSize;
            current = right;
        }

        // Safety check to prevent infinite loops
        if(current > n){
            // Node x does not exist in the tree
            return -1; // or handle appropriately
        }
    }
    return rank;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m; cin >> n >> m;
    while(m--) {
        int x; cin >> x;
        cout << getRank(x) << '\n';
    }
    // system("pause");
    return 0;
}