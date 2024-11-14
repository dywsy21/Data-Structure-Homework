#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define int long long

int hanoi_steps(int disk, int from, int to, vector<int>& pos) { // returns the number of steps already taken before moving the "disk" from "from" to "to"
    if (disk == 0) return 0;
    int aux = 6 - from - to; // 剩余的第三个柱子
    if (pos[disk] == from) return hanoi_steps(disk - 1, from, aux, pos); // 还没移动的部分
    else if (pos[disk] == to) {         
        int already_taken_steps = (1LL << (disk - 1)), steps_taken_of_previous_disk = hanoi_steps(disk - 1, aux, to, pos); // 2^(disk-1)
        if(steps_taken_of_previous_disk == -1) return -1;
        else return already_taken_steps + steps_taken_of_previous_disk; // 已经移动了的部分
    } else return -1;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int a, b, c;
    cin >> a;
    vector<int> pos(50);
    for (int i = 0; i < a; i++) {
        int radius;
        cin >> radius;
        pos[radius] = 1; // 圆盘在A柱
    }

    cin >> b;
    for (int i = 0; i < b; i++) {
        int radius;
        cin >> radius;
        pos[radius] = 2; // 圆盘在B柱
    }

    cin >> c;
    for (int i = 0; i < c; i++) {
        int radius;
        cin >> radius;
        pos[radius] = 3; // 圆盘在C柱
    }

    pos.push_back(0);

    int n = a + b + c;
    int steps_taken = hanoi_steps(n, 1, 3, pos);

    if (steps_taken == -1) cout << "No";
    else cout << (1LL << n) - 1 - steps_taken;
    
    return 0;
}