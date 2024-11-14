#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

int trap(vector<int> &height) // 就以`3 2 1 4`为例子就能理解
{
    stack<int> st; // 单调栈，栈中存放下标
    int cnt = 0;   // 记录答案的计数器
    for (int i = 0; i < height.size(); i++) {
        while (not st.empty() and height[i] >= height[st.top()]) { // 一层一层地叠上去
            int low_height = height[st.top()]; // 低处高度
            st.pop();
            if (st.empty()) break; // 如果此时栈空，说明当前高度高于全部高度，此时暂无法积水
            int high_height = min(height[i], height[st.top()]); // 高处高度取当前高度和上一高度的小值
            cnt += (i - st.top() - 1) * (high_height - low_height); // 距离 * 高度差  注意此处的st.top()和上面的不是一个东西
        }
        st.push(i); // 当前位置入栈
    }
    return cnt;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    int sum = 0;

    vector<int> nearest_ge_right(n), nearest_ge_left(n);
    vector<pair<int, int>> max_stk(n); // val, identifier

    for (int i{n - 1}; i >= 0; i--)
    {
        bool found = false;
        for (int j{max_stk.size() - 1}; j >= 0; j--)
        {
            if (max_stk[j].first >= v[i])
            {
                found = true;
                nearest_ge_right[i] = max_stk[j].second;
                break;
            }
        }
        if (!found)
            nearest_ge_right[i] = -1;
        while (!max_stk.empty() && max_stk.back().first <= v[i])
            max_stk.pop_back();
        max_stk.emplace_back(v[i], i);
    }

    // for(int &i : nearest_ge_right) cout << i << ' ';
    // cout << endl;

    int cur_right_end = -1, i = 0;
    while (i < n)
    {
        int height = v[i];
        cur_right_end = nearest_ge_right[i];
        while (i < cur_right_end)
        {
            // cout << "At " << i << ", sum += " << height - v[i] << endl;
            sum += (height - v[i]);
            v[i++] = height;
        }
        if (cur_right_end == -1)
            i++;
    }

    max_stk.clear();
    for (int i{}; i < n; i++)
    {
        bool found = false;
        for (int j{max_stk.size() - 1}; j >= 0; j--)
        {
            if (max_stk[j].first >= v[i])
            {
                found = true;
                nearest_ge_left[i] = max_stk[j].second;
                break;
            }
        }
        if (!found)
            nearest_ge_left[i] = n + 1;
        while (!max_stk.empty() && max_stk.back().first <= v[i])
            max_stk.pop_back();
        max_stk.emplace_back(v[i], i);
    }

    // for(int &i : nearest_g_left) cout << i << ' ';
    // cout << endl;

    int cur_left_end = n + 1;
    i = n - 1;
    while (i >= 0)
    {
        int height = v[i];
        cur_left_end = nearest_ge_left[i];
        while (i > cur_left_end)
        {
            // cout << "At " << i << ", sum += " << height - v[i] << endl;
            sum += (height - v[i--]);
        }
        if (cur_left_end == n + 1)
            i--;
    }

    cout << sum;

    // system("pause");
    return 0;
}
