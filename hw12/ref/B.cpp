#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds; // GNU PBDS namespace
using namespace std;

// 使用 pair 模拟 multiset，ID 确保元素唯一性
typedef tree<
    pair<int, int>, // pair<value, unique_id>
    null_type,
    less<pair<int, int>>, // 按值和唯一 ID 排序
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_multiset;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n, min, offset = 0, leave = 0;
    cin >> n >> min;

    ordered_multiset salary; // 使用 GNU PBDS 的 ordered_multiset
    int unique_id = 0;       // 保证每个元素唯一性

    while (n--) {
        char op; int k; cin >> op >> k;

        switch (op) {
            case 'A': {
                offset += k;
                break;
            }
            case 'S': {
                offset -= k;
                int minSalary = min - offset;

                // 使用 while 循环删除小于 minSalary 的元素
                while (!salary.empty() && salary.begin()->first < minSalary) {
                    salary.erase(salary.begin());
                    leave++; // 统计离开的员工数量
                }
                break;
            }
            case 'I': {
                if (k >= min) salary.insert({k - offset, unique_id++}); // 插入新元素，带唯一 ID
                break;
            }
            case 'F': {
                if ((int)salary.size() < k) cout << -1 << '\n';
                else {
                    // 查询排名为 k 的元素（从大到小，第 k 大）
                    auto result = *salary.find_by_order(salary.size() - k);
                    cout << result.first + offset << '\n'; // 输出值，忽略 ID
                }
                break;
            }
            default:
                break; // 防止非预期的操作符
        }
    }
    cout << leave;
    return 0;
}