#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cin; using std::cout; using std::endl;
using std::vector; using std::string;

int main() {
    string s; // 数字序列
    cin >> s;
    vector<int> nums; // 存储数字序列
    vector<int> occurence(10, 0); // 每个数字剩余的个数
    for (int i = 0; i < s.size(); i++) {
        nums.push_back(s[i] - '0');
        occurence[s[i] - '0']++; // 统计每个数字出现的次数
    }

    vector<int> remove_times(10, 0); // 储存1-9分别需要删除的个数，即要从time[i]个中删除digits[i]个
    for (int i = 1; i < 10; i++) cin >> remove_times[i];

    vector<int> ans; // 最终删完的结果
    for (int i = 0; i < nums.size(); i++) {
        if (remove_times[nums[i]] < occurence[nums[i]]) { // 要删除的数量 小于 现在nums[i]剩余的个数，则可以先不删，入栈
            while (!ans.empty() && ans.back() < nums[i] && remove_times[ans.back()] > 0) {
                remove_times[ans.back()]--; // 入栈前，删除栈顶所有比它小且“可删”的数字
                ans.pop_back();
            }
            ans.push_back(nums[i]);
        } else remove_times[nums[i]]--; // 如果当前数字必须要删，则直接删掉
        occurence[nums[i]]--; // 每次遍历到nums[i]，则nums[i]的个数减1
    }
    for (int element : ans) cout << element;
    return 0;
    // 总结：排在后面的数字能够争取到机会的条件，是前面的数字被大数字弹掉（导致digits[i]变小）
    // 前面的数字弹掉几个，后面就被允许进来几个，这样就保证了后面的数字要进来，就一定是跟在大数字后面（911好于119）
}