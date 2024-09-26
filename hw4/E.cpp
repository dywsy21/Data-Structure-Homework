/*Description
ZZR 喜欢周期循环，看到不是周期循环的字符串就很不爽。
现在 ZZR 得到一个字符串，可以在字符串末尾添加若干任意字符。
请你帮 ZZR 想想，最少添加多少个字符，才能使得字符串变得周期循环(即存在一个循环节至少循环两次)。
Format
Input
第一行一个整数 T 代表测试数据的组数。
接下来 T 行每行一个字符串，由小写字母组成，字符串的长度为 工。
Output
每组数据输出一行表示最少添加的字符数量。
Samples
输入样例
3
ppp
pipmachinelearning
Copy
输出样例
日
Copy
I
15
Limitation
1 ≤T ≤ 100, 3 ≤≤ 10'.
样例解释:ppp 为周期循环，循环节为 p，循环3次*/

#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

// #define DEBUG

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) {
        string s; cin >> s;
        int n = s.size();
        vector<int> prefix(n, 0);
        int len = 0;

        for (int i = 1; i < n; i++) {
            while (len > 0 && s[i] != s[len]) {
                len = prefix[len - 1];
            }
            if (s[i] == s[len]) {
                len++;
            }
            prefix[i] = len;
        }

        int cycle_length = n - prefix[n - 1];
        if (n % cycle_length == 0 && cycle_length < n) {
            cout << 0 << '\n';
        } else {
            cout << cycle_length - (n % cycle_length) << '\n';
        }
    }


    // system("pause");
    return 0;
}
