#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

struct Node {
    int val;
    Node *left, *right;
    Node(int val) {this->val = val;}
};

void traverse(Node* root) {
    if(root and root->val != -1) {
        cout << root->val << ' ';
        traverse(root->right);
        traverse(root->left);
    }
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<Node*> nodes; nodes.push_back(new Node(0));
    nodes.reserve(m + 1); // without it, the program may MLE, wtf god know why
    for(int i {1}; i <= m; i++) {
        string s; cin >> s;
        int val;
        if(s == "null") val = -1;
        else val = atoi(s.c_str());
        Node* node = new Node(val);
        nodes.push_back(node);
        if(i % 2) nodes[i / 2]->right = node;
        else nodes[i / 2]->left = node;
    } 

    traverse(nodes[1]);
    // system("pause");
    return 0;
}