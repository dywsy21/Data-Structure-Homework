#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string generateRandomString(int length) {
    string s;
    for (int i = 0; i < length; i++) {
        s += (rand() % 9) + '1';
    }
    return s;
}

vector<int> generateRandomDeletions(const string &s) {
    vector<int> count(10, 0);
    for (char c : s) {
        count[c - '0']++;
    }

    vector<int> a(10, 0);
    for (int i = 1; i <= 9; i++) {
        if (count[i] > 0) {
            a[i] = rand() % (count[i] + 1); // 确保删除数量不超过出现次数
        }
    }
    return a;
}

string mySolution(string s, vector<int> a) {
    string s2 = s; auto a2 = a;
    for(int i = 9; i > 0; i--) {
        char cur_num = i + '0';
        while(a[i]--) {
            bool found = false; 
            int pos = 0;
            for(int j = 0; j < s.size(); j++) {
                if(s[j] == cur_num) {
                    pos = j;
                    if(j + 1 < s.size() && s[j + 1] > cur_num) {
                        found = true;
                        s.erase(j, 1);
                        break;
                    }
                }
            }
            if(!found && s[pos] == cur_num) s.erase(pos, 1);
        }
    }
    string results1 = s;
    s = s2; a = a2;
    for(int i = 1; i <= 9; i++) {
        char cur_num = i + '0';
        while(a[i]--) {
            bool found = false; 
            int pos = 0;
            for(int j = 0; j < s.size(); j++) {
                if(s[j] == cur_num) {
                    pos = j;
                    if(j + 1 < s.size() && s[j + 1] > cur_num) {
                        found = true;
                        s.erase(j, 1);
                        break;
                    }
                }
            }
            if(!found && s[pos] == cur_num) s.erase(pos, 1);
        }
    }
    return max(results1, s);
}

void generateCombinations(string &s, vector<int> &a, int index, string current, string &best, vector<int> &used) {
    if (index == s.size()) {
        if (used == a) {
            best = max(best, current);
        }
        return;
    }
    
    // 当前字符不删除
    generateCombinations(s, a, index + 1, current + s[index], best, used);

    // 当前字符删除
    int digit = s[index] - '0';
    if (used[digit] < a[digit]) {
        used[digit]++;
        generateCombinations(s, a, index + 1, current, best, used);
        used[digit]--; // 回溯
    }
}

string bruteForceSolution(string s, vector<int> a) {
    string best = "";
    vector<int> used(10, 0);
    generateCombinations(s, a, 0, "", best, used);
    return best;
}

int main() {
    srand(time(0));
    string bruteresult, myresult, s;
    vector<int> a;

    // 随机生成测试数据
    do {
        s = generateRandomString(6); // 生成长度为10的随机字符串
        a = generateRandomDeletions(s);
        bruteresult = bruteForceSolution(s, a);
        myresult = mySolution(s, a);
    } while(bruteresult == myresult);

    cout << "String: " << s << endl;
    cout << "Deletions: ";
    for (int i = 1; i <= 9; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "Brute force result: " << bruteresult << endl;
    cout << "My solution result: " << myresult << endl;

    return 0;
}
