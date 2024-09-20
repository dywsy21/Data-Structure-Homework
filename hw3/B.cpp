#include <bits/stdc++.h>
#include <ext/rope>
using namespace std;
#define int long long
using namespace __gnu_cxx;

// struct Node {
//     int val; Node* next = nullptr; Node* prev = nullptr;
//     Node(int v) {val = v;}
// };

// struct StaticList {
//     vector<Node*> node_ptrs;
//     StaticList(int n) {
//         for(int i {1}; i <= n; i++) {
//             Node* node_ptr = new Node(i);
//             node_ptrs.push_back(node_ptr);
//             if(i > 1) {
//                 node_ptr->prev = node_ptrs[i - 1];
//                 node_ptrs[i - 1]->next = node_ptr;
//             }
//         }
//     }

//     int operator[](int index) {
//         return (node_ptrs[index])->val;
//     }
// };

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    rope<int> r;
    int n, m;
    cin >> n >> m;
    vector<int> sequence(n);
    iota(sequence.begin(), sequence.end(), 1); // Fill with 1 to n

    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        reverse(sequence.begin() + l - 1, sequence.begin() + r);
        vector<int> temp(sequence.begin() + l - 1, sequence.begin() + r);
        sequence.erase(sequence.begin() + l - 1, sequence.begin() + r);
        sequence.insert(sequence.end(), temp.begin(), temp.end());
    }

    for (int num : sequence) {
        cout << num;
    }
    cout << endl;
    return 0;
}
