#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

struct Node {
    int val;
    vector<Node*> children;
    Node(int val) {this->val = val;}
};

int sum = 0;
int calculate(Node* root) {
    if(!root) return 0;
    for(auto node: root->children) root->val += calculate(node);
    sum += root->val + 1;
    return root->val;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<Node*> nodes(n + 1, new Node(-1));
    for(int i {2}; i <= n; i++) {
        int parent; cin >> parent;
        nodes[parent]->children.push_back(nodes[i]);
    }
    for(int i {1}; i <= n; i++) cin >> nodes[i]->val;
    
    calculate(nodes[1]);
    cout << sum;


    // system("pause");
    return 0;
}