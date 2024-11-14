#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int unsigned int

stack<int> num_stk; stack<char> op_stk;

int fast_pow(int n, int m) { // return n ** m
    int ans = 1;
    while(m) {
        if(m & 1) ans *= n;
        n *= n; m >>= 1;
    }
    return ans;
}

int get_priority(char op) {
    switch(op) {
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '^': return 3;
        case '(': return 4;
    }
    throw invalid_argument("Invalid operator");
}

struct Token {
    int num; char op;
    bool is_num;
    Token(int n) {num = n; is_num = true;}
    Token(char c) {op = c; is_num = false;}
    bool is_higher_than(char op) {
        assert(!is_num);
        return get_priority(this->op) > get_priority(op);
    }
};

inline bool is_operator(char c) {
    return c == '(' or c == ')' or c == '+' or c == '-' or c == '*' or c == '^';
}

auto tokenize(const string& s) {
    int i = 0; vector<Token> ret;
    while(i < s.size()) {
        if(is_operator(s[i])){
            ret.push_back(Token(s[i++])); continue;
        } 
        string num_str;
        while(isdigit(s[i])) num_str.push_back(s[i++]);
        int num; istringstream iss(num_str); iss >> num;
        ret.push_back(Token(num));
    }
    return ret;
}

void calculate_one_round() {
    // only deal with one round of calculation
    char op = op_stk.top();
    op_stk.pop();
    
    int b = num_stk.top(); num_stk.pop();
    int a = num_stk.top(); num_stk.pop();
    
    int result;
    switch(op) {
        case '+': result = a + b; break;
        case '-': result = a - b; break;
        case '*': result = a * b; break;
        case '^': result = fast_pow(a, b); break;
        default: throw invalid_argument("Unsupported operator");
    }
    num_stk.push(result);
}

inline void calculate_with_higher_priority_than(char op) {
    while(!(op_stk.empty() || op_stk.top() == '(' || Token(op).is_higher_than(op_stk.top()))) calculate_one_round();
}

inline void calculate_within_parentheses() { 
    // upon calling, the two stacks are ready for post-order calculation, thanks to `calculate_with_higher_priority_than`
    while (!op_stk.empty() && op_stk.top() != '(') calculate_one_round();
    op_stk.pop(); // pop '('
}

inline void calculate_remaining() {
    // upon calling, the two stacks are ready for post-order calculation, thanks to `calculate_with_higher_priority_than`
    while (!op_stk.empty()) calculate_one_round();
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    auto tokens = tokenize(s);

    for (auto token : tokens) {
        if (token.is_num) num_stk.push(token.num);
        else {
            char op = token.op;
            if (op == '(' || op == '^') op_stk.push(op);
            else if (op == ')') calculate_within_parentheses();
            else {
                calculate_with_higher_priority_than(op);
                op_stk.push(op);  // 当前操作符压入操作符栈
            }
        }
    }

    calculate_remaining();  
    cout << num_stk.top();

    return 0;
}
