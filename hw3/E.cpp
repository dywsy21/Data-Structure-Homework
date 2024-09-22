#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int m; cin >> m;
    vector<unordered_map<char, vector<int>>> pos(26);
    vector<unordered_map<int, int>> lower_bound(26);

    for (int i = 0; i < s.size(); ++i) {
        char c = s[i];
        pos[c - 'a'][c].push_back(i);
    }

    for (int i = 0; i < 26; ++i) {
        int index = 0;
        for (int j = 0; j <= s.size(); ++j) {
            while (index < pos[i]['a' + i].size() && pos[i]['a' + i][index] < j) {
                ++index;
            }
            lower_bound[i][j] = index;
        }
    }

    while (m--) {
        int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
        bool isomorphic = true;
        unordered_set<char> chars1, chars2;

        for (int i = 0; i < 26; ++i) {
            if (lower_bound[i][r1 + 1] > lower_bound[i][l1]) {
                chars1.insert('a' + i);
            }
            if (lower_bound[i][r2 + 1] > lower_bound[i][l2]) {
                chars2.insert('a' + i);
            }
        }

        if (chars1 != chars2) {
            isomorphic = false;
        } else {
            for (char c : chars1) {
                unordered_set<int> positions1, positions2;
                for (int j = lower_bound[c - 'a'][l1]; j < lower_bound[c - 'a'][r1 + 1]; ++j) {
                    positions1.insert(pos[c - 'a'][c][j] - l1);
                }
                for (int j = lower_bound[c - 'a'][l2]; j < lower_bound[c - 'a'][r2 + 1]; ++j) {
                    positions2.insert(pos[c - 'a'][c][j] - l2);
                }
                if (positions1 != positions2) {
                    isomorphic = false;
                    break;
                }
            }
        }
        cout << (isomorphic ? "Yes" : "No") << endl;
    }

    return 0;
}
