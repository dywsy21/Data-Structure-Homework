#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

bool match(char a, char b) {
    switch(a) {
        case '(': switch(b) {
            case ')': return true; break;
            case ']': return false; break;
            case '}': return false; break;
            case '>': return false; break;
        } break;

        case '[': switch(b) {
            case ')': return false; break;
            case ']': return true; break;
            case '}': return false; break;
            case '>': return false; break;
        } break;

        case '{': switch(b) {
            case ')': return false; break;
            case ']': return false; break;
            case '}': return true; break;
            case '>': return false; break;
        } break;

        case '<': switch(b) {
            case ')': return false; break;
            case ']': return false; break;
            case '}': return false; break;
            case '>': return true; break;
        } break;
    }

    throw "Invalid input";
    return false;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    stack<char> stk; int ret = 0;
    for(char c: s) {
        if(c == '(' || c == '[' || c == '{' || c == '<') stk.push(c);
        else {
            if(stk.empty()) {
                cout << "Impossible"; return 0;
            }
            char top = stk.top(); stk.pop();
            if(!match(top, c)) ret++;
        }
    }
    if(!stk.empty()) cout << "Impossible";
    else cout << ret;


    // system("pause");
    return 0;
}