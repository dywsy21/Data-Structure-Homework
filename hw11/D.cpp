#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

struct Node {
    char val; bool is_end;
    unordered_map<char, Node*> children;
    Node(char v): val(v), is_end(false) {}
};

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        Node* root = new Node('#'); // the ultimate root of all nodes
        bool found_flag = false;
        while(n--) {
            string s; cin >> s;
            if(not found_flag) {
                Node* cur = root; bool flag = false; // flag manages "100 10" cases, where the substring comes later
                for(char c: s) {
                    if(cur->children.count(c)) {
                        flag = true;
                        cur = cur->children[c];
                        if(cur->is_end) found_flag = true;
                    }
                    else {
                        flag = false;
                        Node* new_node = new Node(c);
                        cur->children.insert({c, new_node});
                        cur = new_node;
                    }
                }
                cur->is_end = true;
                if(flag) found_flag = true;
            }
        }
        if(found_flag) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }


    // system("pause");
    return 0;
}

// or:

#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

struct Node {
    char val; bool is_end;
    unordered_map<char, Node*> children;
    Node(char v): val(v), is_end(false) {}
};

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        Node* root = new Node('#'); // the ultimate root of all nodes
        bool found_flag = false;
        while(n--) {
            string s; cin >> s;
            if(not found_flag) {
                Node* cur = root;
                for(int i {}; i < s.size(); i++) {
                    char c = s[i];
                    if(cur->children.count(c)) {
                        cur = cur->children[c];
                        if(cur->is_end or i == s.size() - 1){
                            found_flag = true;
                            break;
                        }
                    }
                    else {
                        Node* new_node = new Node(c);
                        cur->children.insert({c, new_node});
                        cur = new_node;
                    }
                }
                cur->is_end = true;
            }
        }
        if(found_flag) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }


    // system("pause");
    return 0;
}