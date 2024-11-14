#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;

    int matching_pos[s.size()]; stack<pair<char, int>> pos_stk;
    for(int i {}; i < s.size(); i++) {
        if(s[i] == '[' || s[i] == '(') pos_stk.emplace(s[i], i);
        if((s[i] == ']' && pos_stk.top().first == '[') || (s[i] == ')' && pos_stk.top().first == '(')) {
            auto pos_pair = pos_stk.top(); pos_stk.pop();
            matching_pos[pos_pair.second] = i;
            matching_pos[i] = pos_pair.second;
        }
    }

    int cur_index = 0, direction = 1; bool is_transforming = 0; 

    auto judge_char = [&](int cur_index) {
        if(!is_transforming) return s[cur_index];
        if(s[cur_index] >= 'A' && s[cur_index] <= 'Z') return (char)(s[cur_index] - 'A' + 'a');
        if(s[cur_index] >= 'a' && s[cur_index] <= 'z') return (char)(s[cur_index] - 'a' + 'A');
    };

    while(cur_index < s.size()) {
        switch(s[cur_index]) {
            case '(': case ')':
                is_transforming ^= 1; break;
            case '[': case ']':
                cur_index = matching_pos[cur_index];
                direction *= -1; break;
            default: cout << judge_char(cur_index);
        }
        cur_index += direction;
    }

    // system("pause");
    return 0;
}