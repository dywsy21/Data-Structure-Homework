#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    stack<int> stk;
    while(1) {
        char c; cin >> c;
        string s; s.push_back(c);
        while(isdigit(c)) {
            cin >> c; 
            if(c != '.') s += c;
        }
        if(isdigit(s[0])) {
            istringstream iss(s); 
            int num; 
            iss >> num;
            stk.push(num);
        }
        else {
            if(c == '@') break;
            int num2 = stk.top(); stk.pop();
            int num1 = stk.top(); stk.pop();
            switch(c) {
                case '+': stk.push(num1 + num2); break;
                case '-': stk.push(num1 - num2); break;
                case '*': stk.push(num1 * num2); break;
                case '/': stk.push(num1 / num2); break;
            }
        }
    }

    cout << stk.top();

    // system("pause");
    return 0;
}