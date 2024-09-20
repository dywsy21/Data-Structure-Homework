#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Node {
    int val; Node* next = nullptr; Node* prev = nullptr;
    Node(int v) {val = v;}
};

struct StaticList {
    vector<Node*> node_ptrs;
    StaticList(int n) {
        for(int i {1}; i <= n; i++) {
            Node* node_ptr = new Node(i);
            node_ptrs.push_back(node_ptr);
            if(i > 1) {
                node_ptr->prev = node_ptrs[i - 1];
                node_ptrs[i - 1]->next = node_ptr;
            }
        }
    }

    int operator[](int index) {
        return (node_ptrs[index])->val;
    }
};

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    deque<int> dq;



    system("pause");
    return 0;
}