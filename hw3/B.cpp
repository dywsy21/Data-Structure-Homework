// #include <bits/stdc++.h>
// #include <ext/rope>
// using namespace std;
// #define int long long
// using namespace __gnu_cxx;

// // struct Node {
// //     int val; Node* next = nullptr; Node* prev = nullptr;
// //     Node(int v) {val = v;}
// // };

// // struct StaticList {
// //     vector<Node*> node_ptrs;
// //     StaticList(int n) {
// //         for(int i {1}; i <= n; i++) {
// //             Node* node_ptr = new Node(i);
// //             node_ptrs.push_back(node_ptr);
// //             if(i > 1) {
// //                 node_ptr->prev = node_ptrs[i - 1];
// //                 node_ptrs[i - 1]->next = node_ptr;
// //             }
// //         }
// //     }

// //     int operator[](int index) {
// //         return (node_ptrs[index])->val;
// //     }
// // };

// template <typename T>
// void reverse(rope<T>& r) {
//     // reverse manually
//     int n = r.size();
//     for (int i = 0; i < n / 2; ++i) {
//         swap(r.mutable_reference_at(i), r.mutable_reference_at(n - i - 1));
//     }
// }

// signed main(){
//     ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//     int n, m;
//     cin >> n >> m;
//     rope<int> sequence;

//     for (int i = 1; i <= n; ++i) {
//         sequence.push_back(n + 1 - i);
//     }

//     for (int i = 0; i < m; ++i) {
//         int l, r;
//         cin >> l >> r;
//         rope<int> sub = sequence.substr(n - r, r - l + 1);
//         sequence.erase(n - r, r - l + 1);
//         // insert sub directly to the beginning
//         sequence.insert(0, sub);
//     }

//     for (int i = n - 1; i >= 0; i--) {
//         cout << sequence[i] << " ";
//     }

//     return 0;
// }
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

void print(rope<int>& r) {
    for (int i = 0; i < r.size(); ++i) {
        cout << r[i] << " ";
    }
    cout << endl;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    rope<int> sequence, rev_sequence;

    for (int i = 1; i <= n; ++i) {
        sequence.push_back(i);
        rev_sequence.push_back(n + 1 - i);
    }

    for (int i = 0; i < m; ++i) {
        // cout << "i = " << i << endl;
        int l, r;
        cin >> l >> r;
        rope<int> sub = sequence.substr(l - 1, r - l + 1);
        sequence.erase(l - 1, r - l + 1);

        // print(sequence); print(sub);
        
        rope<int> rev_sub = rev_sequence.substr(n - r, r - l + 1);
        rev_sequence.erase(n - r, r - l + 1);

        // print(rev_sequence); print(rev_sub);

        sequence.append(rev_sub);
        rev_sequence.insert(0, sub);

        // sequence.append(rev_sequence.substr(n - r, r - l + 1));
        // rev_sequence.insert(0, sequence.substr(l - 1, r - l + 1));
        // sequence.erase(l - 1, r - l + 1);
        // rev_sequence.erase(n - l + 1, r - l + 1);

        // print(sequence);
        // print(rev_sequence);
        // cout << endl;
    }

    print(sequence);

    return 0;
}