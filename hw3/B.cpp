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

template <typename T>
void reverse(rope<T>& r) {
    // reverse manually
    int n = r.size();
    for (int i = 0; i < n / 2; ++i) {
        swap(r.mutable_reference_at(i), r.mutable_reference_at(n - i - 1));
    }
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    rope<int> sequence;

    for (int i = 1; i <= n; ++i) {
        sequence.push_back(i);
    }

    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        rope<int> sub = sequence.substr(l - 1, r - l + 1);
        sequence.erase(l - 1, r - l + 1);
        reverse(sub);
        sequence.append(sub);
    }

    for (int i = 0; i < sequence.size(); ++i) {
        cout << sequence[i] << " ";
    }

    return 0;
}
