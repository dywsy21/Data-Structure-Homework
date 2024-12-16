// referred to https://www.geeksforgeeks.org/avl-tree-set-1-insertion/ for AVLTree implementation
#include <bits/stdc++.h>
using namespace std;
#define int long long

class AVLTree {
    struct AVLNode {
        int key, height, size;
        AVLNode *left, *right;
        AVLNode(int k) : key(k), height(1), size(1), left(nullptr), right(nullptr) {}
    };

    AVLNode* root;

    int height(AVLNode* node) {
        return node ? node->height : 0;
    }

    int size(AVLNode* node) {
        return node ? node->size : 0;
    }

    void update_size_height(AVLNode* node) {
        if (node) {
            node->height = 1 + max(height(node->left), height(node->right));
            node->size = 1 + size(node->left) + size(node->right);
        }
    }

    AVLNode* rotateRight(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;
        x->right = y;
        y->left = T2;
        update_size_height(y);
        update_size_height(x);
        return x;
    }

    AVLNode* rotateLeft(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;
        y->left = x;
        x->right = T2;
        update_size_height(x);
        update_size_height(y);
        return y;
    }

    int getBalance(AVLNode* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    AVLNode* insert(AVLNode* node, int key) {
        if (!node) return new AVLNode(key);
        if (key < node->key) node->left = insert(node->left, key);
        else node->right = insert(node->right, key);
        update_size_height(node);
        int balance = getBalance(node);
        if (balance > 1 && key < node->left->key) return rotateRight(node);
        if (balance < -1 && key > node->right->key) return rotateLeft(node);
        if (balance > 1 && key > node->left->key) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (balance < -1 && key < node->right->key) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        return node;
    }

    AVLNode* minValueNode(AVLNode* node) {
        AVLNode* current = node;
        while (current->left) current = current->left;
        return current;
    }

    AVLNode* erase(AVLNode* root, int key) {
        if (!root) return root;
        if (key < root->key) root->left = erase(root->left, key);
        else if (key > root->key) root->right = erase(root->right, key);
        else {
            if (!root->left || !root->right) {
                AVLNode* temp = root->left ? root->left : root->right;
                if (!temp) {
                    temp = root;
                    root = nullptr;
                } else *root = *temp;
                delete temp;
            } else {
                AVLNode* temp = minValueNode(root->right);
                root->key = temp->key;
                root->right = erase(root->right, temp->key);
            }
        }
        if (!root) return root;
        update_size_height(root);
        int balance = getBalance(root);
        if (balance > 1 && getBalance(root->left) >= 0) return rotateRight(root);
        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
        if (balance < -1 && getBalance(root->right) <= 0) return rotateLeft(root);
        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
        return root;
    }

    int findKthLargest(AVLNode* node, int k) {
        int rightSize = size(node->right);
        if (k == rightSize + 1) return node->key;
        if (k <= rightSize) return findKthLargest(node->right, k);
        return findKthLargest(node->left, k - rightSize - 1);
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int key) {
        root = insert(root, key);
    }

    void erase(int key) {
        root = erase(root, key);
    }

    int findKthLargest(int k) {
        return findKthLargest(root, k);
    }

    int size() {
        return size(root);
    }

    int min_val() {
        return minValueNode(root)->key;
    }
};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    AVLTree tree;
    int n, salary_min; cin >> n >> salary_min;
    int total_left = 0;
    int cumulative_add = 0;

    while (n--) {
        char op; int k; cin >> op >> k;
        if (op == 'I' && k >= salary_min) tree.insert(k - cumulative_add);
        if (op == 'A') cumulative_add += k;
        if (op == 'S') {
            cumulative_add -= k;
            while (tree.size() && tree.min_val() + cumulative_add < salary_min) {
                tree.erase(tree.min_val());
                total_left++;
            }
        }
        if (op == 'F') {
            if (k > tree.size()) cout << -1 << '\n';
            else cout << tree.findKthLargest(k) + cumulative_add << '\n';
        }
    }

    cout << total_left;
    // system("pause");
    return 0;
}