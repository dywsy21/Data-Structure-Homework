#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> preorder, inorder;

Node* buildTree(int preL, int preR, int inL, int inR) {
    if (preL > preR || inL > inR) return nullptr;
    int rootVal = preorder[preL];
    Node* root = new Node(rootVal);
    int rootIndex = find(inorder.begin() + inL, inorder.begin() + inR + 1, rootVal) - inorder.begin();
    int leftTreeSize = rootIndex - inL;
    root->left = buildTree(preL + 1, preL + leftTreeSize, inL, rootIndex - 1);
    root->right = buildTree(preL + leftTreeSize + 1, preR, rootIndex + 1, inR);
    return root;
}

void postorderTraversal(Node* root) {
    if (!root) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->val << ' ';
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
    preorder.resize(n); inorder.resize(n);
    for(int i {}; i < n; ++i) cin >> preorder[i];
    for(int i {}; i < n; ++i) cin >> inorder[i];
    
    Node* root = buildTree(0, n - 1, 0, n - 1); // [preL, preR], [inL, inR]
    postorderTraversal(root);

    // system("pause");
    return 0;
}